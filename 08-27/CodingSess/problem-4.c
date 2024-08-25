
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Problem Statement:
//  1. Now allow the user to enter the values to add as arguments and print the sum as an integer
//  2. Assume a dumb user (incorrect number of arguments and/or invalid arguments and/or values larger than long (64 bits))
//  3. Print userful error messages to stderr if there is a invalid argument

int main(int argc, char *argv[]) {
    if (argc != 3) {                    
        fprintf(stderr, "error: invalid amount of arguments; expected 2\n");
        return 1;
    }

    char *firstNumInvalidChars, *secondNumInvalidChars;    //stores address of invalid characters from strtol() --see `man strtol 3`
    
    errno = 0;
    long int firstNum = strtol(argv[1], &firstNumInvalidChars, 10);    //convert argv[1] string to int using strtol on base 10
    long int secondNum = strtol(argv[2], &secondNumInvalidChars, 10);    //convert argv[2] string to int using strtol on base 10
    
    if (errno != 0) {
        perror("error: string to integer conversion failed\n");
        return -1;
    }

    if (firstNumInvalidChars == argv[1] || *firstNumInvalidChars != '\0') {
        fprintf(stderr, "error: argument one was invalid\n");
        return 1;
    }
    else if (secondNumInvalidChars == argv[2] || *secondNumInvalidChars != '\0') {
        fprintf(stderr, "error: argument two was invalid\n");
        return 1;
    }

    long int sum = firstNum + secondNum;

    printf("%ld + %ld = %ld\n", firstNum, secondNum, sum);
    
    return 0;
}