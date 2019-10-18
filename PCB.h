#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

<<<<<<< HEAD
struct PCB { 
    char name[100]; 
    int arrivalTime, burstTime, priority; 
};

PCB compareName (PCB pcb1, PCB pcb2);
PCB compareAT (PCB pcb1, PCB pcb2);
PCB compareBT (PCB pcb1, PCB pcb2);
PCB comparePriority (PCB pcb1, PCB pcb2);
=======
struct PCB {
    char name[5];
    int arrivalTime, burstTime, priority;
};

void addToArray (struct PCB pcb, struct PCB array[], int count);
void makePCB (char name[], int arrival, int burst, int priority, struct PCB array[], int count);
void sortByArrival (struct PCB array[], int size);
void sortByBurst (struct PCB array[], int size);
void sortByPriority (struct PCB array[], int size);
void lexigraphicalTieBreaker (struct PCB array[], int i, int j);
//PCB compareName (PCB pcb1, PCB pcb2);
//PCB compareAT (PCB pcb1, PCB pcb2);
//PCB compareBT (PCB pcb1, PCB pcb2);
//PCB comparePriority (PCB pcb1, PCB pcb2);
>>>>>>> perry
