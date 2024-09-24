#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

// General Tips:
//    Memory safety is not important here so feel free to hardcode buffer values and use memory unsafe
//    functions like strlen() and friends
//
//
//
// Challenge 1: 
//    1. Open a file called "output.txt" (either create it or just open it for writing only. 
//       See "man open 3" for the two flags you need to use.) 
//    2. Write "Challenge 1 complete\n" to the file and close the it.
//    
//    You will need to use the open(), write(), and close() system calls
//             
// 
// Challenge 2:
//    1. Modify the program so that two processes (a parent and child process) 
//       write to the file "Child Process was here" and "Parent process was here" respectively. 
//       Order does not matter.
//    2. Finally write "Challenge 2 complete\n" after both processes compeleted their write operations.
// 
//    You will need to use the open(), write(), fork(), exit(), waitpid(), and close().
//
//
// Challenge 3:
//    1. Modify the program so that the child process prints to the file via the printf() command instead of the open() call.
//    2. Remember that each process has its own independent file descriptors including a default STDIN, STDOUT, STDERR
//    3. Finally write "Challenge 3 complete\n" after both processes completed their writing operations.
//   
//    You will need to use the open(), write() (for the parent only), fork(), dup2(), exit(), waitpid(), and close().
//
// 
// Challenge 4:
//    1. Similar to D1 activities, modify the program to send a message from the parent process to the child process
//       to then be printed to the file using printf().
//    2. The message can be declared as ```char *message = "Hello from parent";```
//    
//    You will need to use the open(), pipe(), write() (for the parent only), fork(), dup2(), read(), exit(), waitpid(), close(), 


int main(int argc, char *argv[]) {

    return 0;
}