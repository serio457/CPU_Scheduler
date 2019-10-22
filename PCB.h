#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct {
  char name[5];
  BOOL inQueue;
  int arrivalTime, burstTime, priority;
}PCB;

void addToArray (PCB pcb, PCB array[], int count);
void makePCB (char name[], int arrival, int burst, int priority, PCB array[], int count);
//PCB compareName (PCB pcb1, PCB pcb2);
//PCB compareAT (PCB pcb1, PCB pcb2);
//PCB compareBT (PCB pcb1, PCB pcb2);
//PCB comparePriority (PCB pcb1, PCB pcb2);
