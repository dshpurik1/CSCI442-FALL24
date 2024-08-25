#include <stdio.h>

int main() {
    int num = 10;      // A normal integer variable
    int *ptr = &num;   // A pointer variable that stores the address of num

    printf("Value of num ..................... %d\n", num);                   // Prints the value of num
    printf("Value of ptr dereferenced ........ %d\n", *ptr);                  // Prints the value at the address refercened by ptr
    printf("Value of ptr value dereferenced .. %d\n", *&*ptr);                // Prints the value at 
    
    printf("Address of num ................... %p\n", &num);                  // Prints the address of num
    printf("Value of ptr ..................... %p\n", ptr);                   // Prints the value of ptr 
    printf("Address of ptr ................... %p\n", &ptr);                  // Prints the address of ptr
    printf("Value referenced by value at ptr . %p\n", *&ptr);                 // Prints the address of the value  


    *ptr = 20;                                                // Changes the value at the address stored in ptr (which changes num)
    printf("New value of num: %d\n", num);                // Prints the new value of num

    ptr = 20;
    printf("Address of ptr: %p\n", ptr);        // ptr was declared as a address so we just set the address to be 20 (0x14)
    printf("New value of ptr: %d\n", *ptr);     // Produce a segmentation fault (ptr is no longer connected to num)

    return 0;
}