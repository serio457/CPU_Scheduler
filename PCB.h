#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

//struct for PCB's, holds name, a Bool to see if it's been put into the queue, and the associated variables
typedef struct {
  char name[5];
  BOOL inQueue;
  int arrivalTime, burstTime, priority;
}PCB;

//adds a copy of a PCB into an array
void addToArray (PCB pcb, PCB array[], int count);
//takes in PCB values from the infile and puts them appropriately into a PCB, which is automatically added to an array
void makePCB (char name[], int arrival, int burst, int priority, PCB array[], int count);

