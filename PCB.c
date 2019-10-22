// FILE: PCB.c
// Operating Systems, Fall 2019
//

#include "PCB.h"

void addToArray (PCB pcb, PCB array[], int index) {
    array[index] = pcb;
}

void makePCB (char name[], int arrival, int burst, int priority, PCB array[], int count) {
    PCB pcb;
    strcpy (pcb.name, name);
    pcb.arrivalTime = arrival;
    pcb.burstTime = burst;
    pcb.priority = priority;
    pcb.inQueue = FALSE;
    addToArray (pcb, array, count);
}







//
