
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Problem Statement:
//  1. Now allow the user to also specify a file to append the sum of the long integers to
//    a. Follow the format SUM: var1 + var2 = sum
//  2. Assume a dumb user (incorrect number of arguments and/or invalid arguments and/or values larger than long (64 bits), invalid file)
//  3. Print userful error messages to stderr if there is a invalid argument and do not write anything to the file

// CHALLENGE: If you finish this early, now set it up so that you read the file first and make sure that the user hasn't already asked for a computation.
//            To do this, open the file, read each line and see if the arguments match that line. If they do, let the user know that the computation is 
//            already in the file. If not, then append the new computation to the file.
//            SEE challenge.c FOR ADDITIONAL TOOLS

// Useful system calls:
//  1. fopen()
//  2. fclose()
//  3. fprintf()

int main(int argc, char *argv[]) {
    //TODO: Implement Me!!!

    return 0;
}