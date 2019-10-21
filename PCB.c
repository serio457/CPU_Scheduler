// FILE: PCB.c
// Operating Systems, Fall 2019
//

#include "PCB.h"

void addToArray (struct PCB pcb, struct PCB array[], int index) {
    array[index] = pcb;
}

void makePCB (char name[], int arrival, int burst, int priority, struct PCB array[], int count) {
    struct PCB pcb;
    strcpy (pcb.name, name);
    pcb.arrivalTime = arrival;
    pcb.burstTime = burst;
    pcb.priority = priority;
    addToArray (pcb, array, count);
}







//
