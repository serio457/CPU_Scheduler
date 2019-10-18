/*  Fran, Perry, Nick
    Transy U
    FILE: simulation.h
    Header file for simulation.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PCB.h"

///Lower bounds for number generation
#define LOWER_ARRIVAL 0
#define LOWER_BURST 1
#define LOWER_PRIORITY 0

///Upper bounds for number generation
#define UPPER_ARRIVAL 100
#define UPPER_BURST 100
#define UPPER_PRIORITY 1023

///Function prototypes
void simulate (BOOL arrival, BOOL burst, int count, struct PCB list[]);
int makeArrival (BOOL simArrival, int i);
int makeBurst (BOOL simBurst);
int makePriority (int i);
int getRandom (int seed, int upper, int lower);
