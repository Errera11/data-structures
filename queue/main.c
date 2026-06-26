#include <stdio.h>
#include "queue.h"

int main() {
    Queue *q = init();

    int a = 1;
    float b = 2.5;
    char *c = "hello";

    printf("Before push\n");
    print(q);
    
    push(q, &a);
    push(q, &b);
    push(q, c);

    printf("After push\n");
    print(q);

    void *p = pop(q);
    printf("Popped item ptr: %p\n", p);

    printf("After pop\n");
    print(q);

    return 0;
}
