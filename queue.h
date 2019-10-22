#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "PCB.h"

// A structure to represent a queue
typedef struct{
  PCB list[500];
  int count;
} Queue;

//takes in an array of PCB's and sorts them by arrival, lowest arrival being first in the list.
void sortByArrival (PCB *array, int size);

//breaks a tie between two PCB's in an array, swapping them if the latter is greater than the former
void lexigraphicalTieBreaker (PCB *array, int i, int j);

//puts a copy of a PCB from the initial PCB array into the next available spot in the Queue
void putIntoQ (Queue *queue, PCB *array, int PCBCount);

//sorts an array of PCB's and puts them into a Queue in scheduled order by simplest job first
void SJF (PCB *array, Queue *queue, int count);

//swaps two PCB's by address
void swap (PCB *a, PCB *b);

//sorts an array of PCB's and puts them into a Queue in scheduled order by priority
void prioritySort (PCB *array, Queue *queue, int count);

//calculates the average wait time 
double calcAverageWait (Queue queue
