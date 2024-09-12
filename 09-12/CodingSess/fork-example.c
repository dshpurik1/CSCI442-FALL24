
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

// Use this example to see the individual parent and child processes
// within the OS by running the 'htop' command to see all active
// processes. 

// Because we are subtracting 1 many times, it will force the process
// to stay active in our processors hence why two processors will
// have full utilization

int main(int argc, char *argv[]) {
	pid_t cpid = fork();

    printf(" %d\n", cpid);
    long int i = 1000000000000000;
    while (i != 0) {
        i -= 1;
    }

    return 0;
}