
#include <stdio.h>
#include <stdlib.h>

// Problem Statement:
//  1. Now allow the user to enter the values to add as arguments and print the sum as an integer
//  2. Assume a smart user

// Useful system calls:
//  1. strtol()

int main(int argc, char *argv[]) {
    char *firstNumInvalidChars, *secondNumInvalidChars;    //stores address of invalid characters from strtol() --see `man strtol 3`
    
    long int firstNum = strtol(argv[1], &firstNumInvalidChars, 10);    //convert argv[1] string to int using strtol on base 10
    long int secondNum = strtol(argv[2], &secondNumInvalidChars, 10);    //convert argv[2] string to int using strtol on base 10
    
    long int sum = firstNum + secondNum;

    printf("%ld + %ld = %ld\n", firstNum, secondNum, sum);
    
    return 0;
}