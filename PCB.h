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
//PCB compareName (PCB pcb1, PCB pcb2);
//PCB compareAT (PCB pcb1, PCB pcb2);
//PCB compareBT (PCB pcb1, PCB pcb2);
//PCB comparePriority (PCB pcb1, PCB pcb2);
>>>>>>> perry
