#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "PCB.h"

// A structure to represent a queue
typedef struct{
  PCB list[500];
  int count;
} Queue;

/*
struct Queue* createQueue(unsigned capacity);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
int front(struct Queue* queue);
*/

void sortByArrival (PCB *array, int size);
void sortByBurst (PCB *array, int size);
void sortByPriority (PCB *array, int size);
void lexigraphicalTieBreaker (PCB *array, int i, int j);
//int rear(Queue queue);
void putIntoQ (Queue *queue, PCB *array, int PCBCount);
