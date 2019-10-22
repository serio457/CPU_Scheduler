/*  Fran, Perry, Nick
    Transy U
    FILE: simulation.h
    Header file for simulation.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "PCB.h"

#define TRUE 1
#define FALSE 0

typedef int SBOOL;

///Lower bounds for number generation
#define LOWER_ARRIVAL 0
#define LOWER_BURST 1
#define LOWER_PRIORITY 0

///Upper bounds for number generation
#define UPPER_ARRIVAL 100
#define UPPER_BURST 100
#define UPPER_PRIORITY 1023

///Function prototypes
void simulate (SBOOL arrival, SBOOL burst, int count, PCB list[]);
int makeArrival (SBOOL simArrival, int seed);
int makeBurst (SBOOL simBurst, int seed);
int makePriority (int seed);
int getRandom (int seed, int upper, int lower);
