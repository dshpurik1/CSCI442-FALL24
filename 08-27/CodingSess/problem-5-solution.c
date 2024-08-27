
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
    if (argc != 4) {                    
        fprintf(stderr, "error: invalid amount of arguments; expected 3\n");
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

    FILE *fout = fopen(argv[3], "a");
    if (fout == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
		return 1;
    }

    long int sum = firstNum + secondNum;

    fprintf(fout, "SUM: %ld + %ld = %ld\n", firstNum, secondNum, sum);

    fclose(fout);
    
    return 0;
}