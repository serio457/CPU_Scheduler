/*  Fran, Perry, Nick
    Transy U
    FILE: simulation.c
    Creates a list of simulated processes
    Brings in the parameters to simulate and the length of the list. Returns an array of process structs
    Generating random numbers: https://www.geeksforgeeks.org/generating-random-number-range-c/
*/

#include "PCB.h"
#include "simulation.h"
/*
int main (void) {
  struct PCB list[500];
  simulate(TRUE, TRUE, 20, list);
  for (int i = 0; i <20; i++)
    printf("Name: %s\tArrival: %i\tBurst: %i\tPriority: %i\n", list[i].name, list[i].arrivalTime, list[i].burstTime, list[i].priority);
}
*/

///Generates a list of randomized PCB objects
///Arrival and burst are randomized if the corrisponding flags are true
void simulate (SBOOL arrival, SBOOL burst, int count, struct PCB list[]) {
  char PCBName[5];
    for (int i = 0; i < count; i++) {
	sprintf(PCBName, "p%i", i);
	makePCB(PCBName, makeArrival(arrival, i), makeBurst(burst, i+1), makePriority(i+2), list, i);
    }
}

///Simulates arrival time
///If arrival is not to be randomized, it defaults to i*5
int makeArrival (SBOOL simArrival, int seed) {
    if (simArrival) 
        return getRandom(seed, UPPER_ARRIVAL, LOWER_ARRIVAL);
    else 
        return seed*5;
}

///Simulates burst time
///If burst is not to be randomized, it defaults to 20
int makeBurst (SBOOL simBurst, int seed) {
    if (simBurst) 
        return getRandom(seed, UPPER_BURST, LOWER_BURST);
    else 
        return 20;
}

///Simulates priority
//priority is always randomized 
int makePriority (int seed) {
  return getRandom(seed, UPPER_PRIORITY, LOWER_PRIORITY);
}

///Returns a "random" number
///Uses the current time and a seeding number to generate the number
int getRandom (int seed, int upper, int lower) {
    srand(time(0)*(seed+1));
    return (rand() % (upper - lower + 1)) + lower;
}
