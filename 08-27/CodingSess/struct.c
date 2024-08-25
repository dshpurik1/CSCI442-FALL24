#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point point = {0,5};

    printf("x: %d\n", point.x);
    printf("y: %d\n", point.y);  

    return 0;
}