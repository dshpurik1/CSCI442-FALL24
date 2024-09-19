#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Problem 2: 
//  Now that you know how to create a child process, use fork() and pipe()
//  to send a simple string message from the parent process to the child process
//  
//  You will need to implement functionality to wait on the child process to
//  finish as well as a pipe to send the message from one process to another.

// Useful fools to use
//  1. fork()
//  2. pipe()
//  3. write()
//  4. waitpid()


int main() {
    // Used to handle non-zero error codes returned from the
    // parent process
    int stat;

    // Our communication pipe will have a read end and write end
    // pipefd[0] = read end
    // pipefd[1] = write end
    int pipefd[2];

    // Creates a communication channel between our seperate 
    // processes (the child and parent processes)
    pipe(pipefd);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process

        // Close unused write end
        close(pipefd[1]); 
        char buffer[100];

        // Reading/printing the message from the communication pipe for a buffer of 100 (not safe, but fine for the example)
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child read at PID: %d the following msg: %s\n", getpid(), buffer);
        
        // Although this is not necessary for this simple program, to clean up 
        // resources, we should close the read end to prevent data leakage
        close(pipefd[0]);
    } else {
        // Parent process


        // Close unused read end
        close(pipefd[0]); 
        char* msg = "Hello from parent!";
        printf("Parent PID: %d\n", getpid());

        // Write the message to the communication pipeline for enough space for the string + null character
        write(pipefd[1], msg, strlen(msg) + 1);
    
        // Because the pipe is treated as a file that data is written to,
        // we must close the write end to signal that parent is done writing
        // to the file. Otherwise, you may cause a deadlock
        close(pipefd[1]); 

        // Not necessasary since we have no code to execute
        // afterwards, but good to include when we do
        // like maybe for Project 2  :)
        waitpid(pid, &stat, 0);
    }

    return 0;
}
