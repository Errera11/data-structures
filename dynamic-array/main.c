#include "dc.c"
#include <stdio.h>

int main() {
    int a = 5;
    char s[] = "hello";
    float b = 3.14;

    DynamicArray arr;

    init_array(&arr, 2);

    push(&arr, &a);
    push(&arr, s);
    push(&arr, &b);

    print(&arr);

    float *c = pop(&arr);
    printf("Popped val: %f\n", *c);

    print(&arr);

    return 0;
}


