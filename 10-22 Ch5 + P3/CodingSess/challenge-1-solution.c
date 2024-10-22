
#include <pthread.h>
#include <stdio.h>

// General Tips:
//    1. Don't worry about memory safety. Screw it up however you want as long as you get the results.
//    2. Reference man pages for what parameters api calls need
//    3. Feel free to work with your neighbors and ask questions!
//
//
//
// Challenge 1: 
//    1. Write a program that creates two threads. 
//       Each thread should print a unique message ("Thread 1" and "Thread 2").
//    2. Your program will have a critical section of code where you can pass arguments.
//    3. Use pthread_create and pthread_join to kick off multiple threads and to join them back together.   
//    4. Your printing code should look like this `printf("Thread Message: %s\n", (char*)arg);`


void* print_message(void* arg) {
    printf("Thread Message: %s\n", (char*)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, print_message, "Thread 1");
    pthread_create(&t2, NULL, print_message, "Thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}