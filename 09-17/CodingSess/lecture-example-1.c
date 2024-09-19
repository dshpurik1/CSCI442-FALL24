
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("PID for main(): %d\n", getpid());
    for (int i = 0; i < 3; i++) {        
        if(fork()==0) {
            printf("i: %d PID for Child: %d with Parent PID: %d\n", i, getpid(), getppid());
        }
        else {
            printf("i: %d PID for Parent: %d\n", i, getpid());
        }  
    }

    return 0;
}