
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// CHALLENGE: 
//  If you finish this early, now set it up so that you read the file first and make sure that the user hasn't already asked for a computation.
//  To do this, open the file, read each line and see if the arguments match that line. If they do, let the user know that the computation is 
//  already in the file. If not, then append the new computation to the file.

// Useful tools to use:
//  1. fopen()
//  2. fclose()
//  3. fprintf()
//  4. getline()
//  5. sscanf()


struct Sum {
    long int x;
    long int y;
};

struct Sum* extractNum(char *string) {
    long int num1, num2, total;

    sscanf(string, "SUM: %ld + %ld = %ld", &num1, &num2, &total);    //using sscanf to extract into file format SUM: x + y = z

    struct Sum *sum = (struct Sum*) malloc(sizeof(struct Sum));    //storing on heap to practice for Project 1 :)
    sum->x = num1;
    sum->y = num2;
    return sum;
}

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

    size_t buffer = 0;    // buffer for getline()
    char *currLine;    // location for getline to write a line of the file to
    int len;    // total count of chars read in a line    

    FILE *file = fopen(argv[3], "a+");
    if (file == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
		return 1;
    }
    while (!feof(file)) {
		len = getline(&currLine, &buffer, file);
        if (len == -1)
			break;

        struct Sum *sum = extractNum(currLine);
        if ((firstNum == sum->x && secondNum == sum->y) || (firstNum == sum->y && secondNum == sum->x)) {
            printf("Computation already completed and stored in %s.\n", argv[3]);
            free(sum);
            fclose(file);
            return 0;
        }
        free(sum);
    }

    long int sum = firstNum + secondNum;

    fprintf(file, "SUM: %ld + %ld = %ld\n", firstNum, secondNum, sum);
    
    return 0;
}