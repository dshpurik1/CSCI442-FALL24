#include <stdio.h>
#include <unistd.h>

// Problem 1: 
//  Using fork(), print the process id (pid) of the child process and
//  parent process 

// Useful fools to use
//  1. fork()
//  2. getpid()

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        
        printf("This is the child process with OS PID %d\n", getpid());
        printf("This is the child process with Program PID %d\n", pid);
    } else {
        // Parent process

        printf("This is the parent process with OS PID %d\n", getpid());
        printf("This is the parent process with Program PID %d\n", pid);
    }

    return 0;
}