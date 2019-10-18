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


//code for sorting from https://en.wikiversity.org/wiki/C_Source_Code/Sorting_array_in_ascending_and_descending_order
void sortByArrival (struct PCB array[], int size) {
  for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j].arrivalTime > array[i].arrivalTime)
			{
				struct PCB temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
      else if (array[j].arrivalTime == array[i].arrivalTime) {
        lexigraphicalTieBreaker (array, i, j);
      }
		}
	}
}

void sortByBurst (struct PCB array[], int size) {
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (array[j].burstTime > array[i].burstTime)
      {
        struct PCB temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void sortByPriority (struct PCB array[], int size) {
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (array[j].priority > array[i].priority)
      {
        struct PCB temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void lexigraphicalTieBreaker (struct PCB array[], int i, int j) {
    int comparison = strcmp (array[j].name, array[i].name);
    if (comparison < 0) {

    }
}




//
