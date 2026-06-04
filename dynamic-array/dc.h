typedef void** d_array_ptr;

typedef struct da {
    d_array_ptr p;
    int capacity;
    int size;
} DynamicArray;

void init_array(DynamicArray *arr, int initial_capacity);
void free_array(DynamicArray *arr);
void resize_array(DynamicArray *arr);

void *pop(DynamicArray *arr);
void push(DynamicArray *arr, void* d);

void print(DynamicArray *arr);
