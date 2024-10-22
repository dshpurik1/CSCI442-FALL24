
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


struct thread_data{
    int id;
    char* message;
};


void* print_data(void* arg) {
    thread_data* data = (thread_data*)arg;
    printf("Thread %d: %s\n", data->id, data->message);
    return NULL;
}


int main() {
    pthread_t t1, t2;
    thread_data td1 = {1, "Hello from Thread 1"};
    thread_data td2 = {2, "Hello from Thread 2"};

    pthread_create(&t1, NULL, print_data, &td1);
    pthread_create(&t2, NULL, print_data, &td2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
