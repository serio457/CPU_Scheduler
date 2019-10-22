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
///Generates a list of randomized PCB objects
///Arrival and burst are randomized if the corrisponding flags are true
void simulate (SBOOL arrival, SBOOL burst, int count, PCB list[]);

///Simulates arrival time
///If arrival is not to be randomized, it defaults to i*5
int makeArrival (SBOOL simArrival, int seed);

///Simulates burst time
///If burst is not to be randomized, it defaults to 20
int makeBurst (SBOOL simBurst, int seed);

///Simulates priority
//priority is always randomized 
int makePriority (int seed);

///Returns a "random" number
///Uses the current time and a seeding number to generate the number
int getRandom (int seed, int upper, int lower);
