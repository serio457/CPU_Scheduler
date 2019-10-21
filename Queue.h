#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "PCB.h"

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
int front(struct Queue* queue);

void sortByArrival (struct PCB *array, int size);
void sortByBurst (struct PCB *array, int size);
void sortByPriority (struct PCB *array, int size);
void lexigraphicalTieBreaker (struct PCB *array, int i, int j);
int rear(struct Queue* queue);
