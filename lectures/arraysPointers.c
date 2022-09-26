#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 3; // gives us a place in memory with enough space for x
    // &x -> will give us the location in memory
    // *x -> is the opposite. given and address, returns the value.

    int *y;
    y = &x;

    int w = 5;
    w = x;
    x = w + 1;

    // print y
    printf("y is %p\n", y);

    // print the value of y
    printf("y is %d\n", *y);

    // print the address of y
    printf("y is %p\n", &y);

    *y = *y + 1;
    printf("y is %d\n", *y);
    printf("x is now %d\n", x);

    int *a;
    a = malloc(1000 * sizeof(int)); // but a is not int, it's the addresss of an integer!
    *(a + 1);                       // doesn't access the next byte, rather the next integer
    // can also write this as a[1]

    // syntactic sugar
    *(a + 41) == a[41];
    (*a) + 1; // int at a (+ 1)
    
    *(a + 41) = 20;
    printf("val at a[41]: %d\n", a[41]);

    // sometimes we write
    a = (int *)malloc(1000 * sizeof(int));

    // deallocccatee to prevent memory leak
    free(a);

    return 0;
}