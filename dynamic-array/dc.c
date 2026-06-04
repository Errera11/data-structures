#include "dc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_array(DynamicArray *arr, int initial_capacity) {
    arr->p = (void **)malloc(initial_capacity * sizeof(void *)); 

    if (arr->p ==NULL)
        return;

    arr->capacity = initial_capacity;
    arr->size = 0;

    for (int i = 0; i < arr->capacity; i++) {
        arr->p[i] = NULL;
    }
}

void free_array(DynamicArray *arr) {
    free(arr->p);
}

void resize_array(DynamicArray *arr) {
   int k = 2;

   void *temp = arr->p;
   int new_capacity = arr->capacity * k;
   void *new_p = malloc(new_capacity * sizeof(void *));
   arr->p = memcpy(new_p, arr->p, arr->size * sizeof(void *));

   free(temp);
}

void *pop(DynamicArray *arr) {
    int last_idx = arr->size - 1;

    if (last_idx < 0) 
        return NULL;

   void *temp = arr->p[last_idx];
   
   arr->p[last_idx] = NULL;
    arr->size -= 1;

   return temp;
}

void push(DynamicArray *arr, void *d) {
    int next_idx = arr->size;
        
    if (next_idx >= arr->capacity)
        resize_array(arr);

    arr->size++;
    arr->p[next_idx] = d;
}

void print(DynamicArray *arr) {
    if (arr == NULL) return;
    for (int i = 0; i < arr->size; i++) {
        printf("Data addr: %p\n", (void *)arr->p[i]);
    }
}
