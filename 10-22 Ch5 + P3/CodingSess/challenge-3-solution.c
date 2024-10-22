
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
//             
// 
// Challenge 2:
//    1. Modify the previous program to pass a structure containing an integer and a string to each thread. 
//       The thread should print both values.
//
//
// Challenge 3:
//    1. Write a program where any number of threads specified increment a shared counter.
//    2. Synchronization does not matter here.
//    3. You should convert your program to allow for NUm_THREADS to be created instead of just two.


#define NUM_THREADS 10000

int counter = 0;


void* increment_counter(void* arg) {
    sleep(.5); // Forcing race condition (does nothing for mutexes)
    counter++;
    printf("Thread %ld incremented counter to %d\n", pthread_self(), counter);
    return NULL;
}


int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of counter: %d\n", counter);

    return 0;
}