typedef struct queue {
    int size;
    int capacity;
    void **queue_array;
} Queue;

Queue *init();

void push(Queue* q, void *d);

void *pop(Queue* q);

void print(Queue* q);


