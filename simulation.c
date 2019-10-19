/*  Fran, Perry, Nick
    Transy U
    FILE: simulation.c
    Creates a list of simulated processes
    Brings in the parameters to simulate and the length of the list. Returns an array of process structs
    Generating random numbers: https://www.geeksforgeeks.org/generating-random-number-range-c/
*/

#include "simulation.h"

///Generates a list of randomized PCB objects
///Arrival and burst are randomized if the corrisponding flags are true
void simulate (SBOOL arrival, SBOOL burst, int count, struct PCB list[]) {
  char PCBName[5];
    for (int i = 0; i < count; i++) {
	sprintf(PCBName, "p%i", i);
	makePCB(PCBName, makeArrival(arrival, i), makeBurst(burst, i), makePriority(), list, i);
    }
}

///Simulates arrival time
///If arrival is not to be randomized, it defaults to i*5
int makeArrival (SBOOL simArrival, int i) {
    if (simArrival) 
        return getRandom(i, UPPER_ARRIVAL, LOWER_ARRIVAL);
    else 
        return i*5;
}

///Simulates burst time
///If burst is not to be randomized, it defaults to 20
int makeBurst (SBOOL simBurst) {
    if (simBurst) 
        return getRandom(i, UPPER_BURST, LOWER_BURST);
    else 
        return 20;
}

///Simulates priority
//priority is always randomized 
int makePriority (int i) {
    return getRandom(i, UPPER_PRIORITY, LOWER_PRIORITY);
}

///Returns a "random" number
///Uses the current time and a seeding number to generate the number
int getRandom (int seed, int upper, int lower) {
    srand(time(0)*(seed+1));
    return (rand() % (upper - lower + 1)) + lower;
}
