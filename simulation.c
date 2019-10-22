/*  Fran, Perry, Nick
    Transy U
    FILE: simulation.c
    Creates a list of simulated processes
    Brings in the parameters to simulate and the length of the list. Returns an array of process structs
    Generating random numbers: https://www.geeksforgeeks.org/generating-random-number-range-c/
*/

#include "PCB.h"
#include "simulation.h"

void simulate (SBOOL arrival, SBOOL burst, int count, PCB list[]) {
  char PCBName[5];
    for (int i = 0; i < count; i++) {
	sprintf(PCBName, "p%i", i);
	makePCB(PCBName, makeArrival(arrival, i), makeBurst(burst, i+1), makePriority(i+2), list, i);
    }
}

int makeArrival (SBOOL simArrival, int seed) {
    if (simArrival) 
        return getRandom(seed, UPPER_ARRIVAL, LOWER_ARRIVAL);
    else 
        return seed*5;
}
int makeBurst (SBOOL simBurst, int seed) {
    if (simBurst) 
        return getRandom(seed, UPPER_BURST, LOWER_BURST);
    else 
        return 20;
}
int makePriority (int seed) {
  return getRandom(seed, UPPER_PRIORITY, LOWER_PRIORITY);
}
int getRandom (int seed, int upper, int lower) {
    srand(time(0)*(seed+1));
    return (rand() % (upper - lower + 1)) + lower;
}
