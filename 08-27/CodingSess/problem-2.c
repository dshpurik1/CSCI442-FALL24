
#include <stdio.h>

// Problem Statement:
//  1. Declare two long variables and print the sum as a long

int main(int argc, char *argv[]) {
    long int x = 2147483646;
    long int y = 3;
    long int sum = x + y;

    printf("2147483646 + 3 = %ld\n", sum);
    
    return 0;
}