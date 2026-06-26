#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define CAPACITY 1

// init queue
Queue *init() {
    Queue *q = (Queue*) malloc(sizeof(Queue));

    if (q == NULL) return NULL;

    q->capacity = CAPACITY;
    q->size = 0;
    q->queue_array = malloc(sizeof(void *) * CAPACITY);

    if (q->queue_array == NULL) {
        free(q);
        return NULL;
    }

    return q;
}

void shift_array(void **p, int size) {
    for (int i = 0; i < size - 1; i++) {
        int new_idx = i + 1;
        p[i] = p[new_idx];
    }
}

void *pop(Queue* q) {
    if (q == NULL || q->size == 0) return NULL;
    void *p = q->queue_array[0];

    shift_array(q->queue_array, q->size);
    q->size--;

    return p;
}

void push(Queue* q, void* d) {
    if (q->size + 1 > q->capacity) {
       int new_capacity = q->capacity + 1; 
        void **temp = realloc(q->queue_array, sizeof(void *) * new_capacity); 
    
        if (temp == NULL)
            return;

        q->queue_array = temp;
        q->capacity = new_capacity;
    }

    q->queue_array[q->size] = d;
    q->size++;
}

void print(Queue* q) {
    for (int i = 0; i < q->size; i++) {
        printf("Array el ptr: %p\n", q->queue_array[i]); 
    }
}
