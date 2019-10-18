/*  Fran, Perry, Nick
    Transy U
    FILE: simulation.c
    Creates a list of simulated processes
    Brings in the parameters to simulate and the length of the list. Returns an array of process structs
*/

#include "simulation.h"

void simulate (BOOL arrival, BOOL burst, int count, PCB *list) {
    srand(time(0));
    for (int i = 0; i < count; i++) {
        strcpy(PCB.name, "p");
        strcpy(PCB.name[1], i);
        if (arrival) {
            PCB.arrivalTime = getRandom(LOWER_ARRIVAL);
        }
        else {
            PCB.arribalTime = i*5;
        }
        if (burst) {
            PCB.burstTime = getRandom(LOWER_BURST);
        }
        else {
            PCB.burstTime = 20;
        }
    }
}

int getRandom (int lower) {
    return (rand() % (UPPER - lower + 1)) + lower;
}
