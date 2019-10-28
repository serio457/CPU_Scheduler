/* Fran, Perry, Nick 
   Transy U
   FILE: queue.c
*/

////Code from: https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

// C program for array implementation of queue

#include "queue.h"


double calcAverageWait (Queue queue) {
  int burstSum = 0, indvWait;
  double avgWait, waitSum = 0, count = 0;
  for (int i=0; i < queue.count; i++) {
    indvWait = burstSum - queue.list[i].arrivalTime;
    //a condition to compensate for idle time that could arise in the execution of the queue
    if (indvWait < 0) {
      indvWait = 0;
      burstSum = burstSum + (queue.list[i].arrivalTime - burstSum);
    }
    burstSum = burstSum + queue.list[i].burstTime;
    waitSum = waitSum + indvWait;
    count++;
  }
  avgWait = waitSum/count;
  return avgWait;
}
//code for sorting from https://en.wikiversity.org/wiki/C_Source_Code/Sorting_array_in_ascending_and_descending_order
void sortByArrival (PCB *array, int size) {
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
	{
	  if (array[j].arrivalTime > array[i].arrivalTime)
	    {
	      PCB temp = array[i];
	      array[i] = array[j];
	      array[j] = temp;
	    }
	  else if (array[j].arrivalTime == array[i].arrivalTime) {
	    lexigraphicalTieBreaker (array, i, j);
	  }
	}
    }
}

void lexigraphicalTieBreaker (PCB *array, int i, int j) {
  int comparison = strcmp (array[j].name, array[i].name);
  if (comparison > 0) {
    PCB temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void putIntoQ (Queue *queue, PCB *array, int PCBCount) {
  for (int i = 0; i < PCBCount; i++) {
    addToArray (array[i], queue->list, i);
  }
  queue->count = PCBCount;
}

void SJF (PCB *array, Queue *queue, int count) {
  //sets up variables to keep track of the sum of bursts of PCB's that have been put onto the queue.
  int burstSum = 0, lastBurst;
  PCB temp;
  //this for loop searches through the PCB's in the array to find the one that will run first
  for (int i = 1; i < count - 1 && (array[0].arrivalTime == array[i].arrivalTime); i++) {
    if (array[0].burstTime == array[i].burstTime) {
      lexigraphicalTieBreaker (array, 0, i);
    }
    else {
      if (array[0].burstTime < array[i].burstTime) {
	swap (&array[0], &array[i]);
      }
    }
  }
  //put the first process into the queue and record the burst time
  temp = array[0];
  queue->list[0] = temp;
  queue->count = 1;
  array[0].inQueue = TRUE;
  lastBurst = temp.burstTime;
  burstSum = burstSum + lastBurst;
  //goes through the rest of the array, finding the next process to run and putting a copy of it into the next open spot in the Queue
  for (int i = 1; i < count; i++) {
    if (!array[i].inQueue) {
      for (int k = i +1; k < count; k++) {
	if (array[k].arrivalTime <= burstSum) {
	  if (array[i].burstTime >= array[k].burstTime) {
	    if (array[i].burstTime == array[k].burstTime) {
	      lexigraphicalTieBreaker (array, k, i);
	    }
	    else {
	      swap (&array[i], &array[k]);
	    }
	  }
	}
      }
      //record the last process put onto the queue
      lastBurst = array[i].burstTime;
      burstSum = burstSum + lastBurst;
      queue->list[queue->count] = array[i];
      queue->count++;
      array[i].inQueue = TRUE;
    }
  }
}


void prioritySort (PCB *array, Queue *queue, int count) {
  //see comments in SJF, function is the same other than the type of comparison done, this doing by priority and SJF doing simplest job first
  int burstSum = 0, lastBurst;
  PCB temp;
  for (int i = 1; i < count - 1 && (array[0].arrivalTime == array[i].arrivalTime); i++) {
    if (array[0].priority == array[i].priority) {
      lexigraphicalTieBreaker (array, i, 0);
    }
    else {
      if (array[0].priority < array[i].priority) {
	swap (&array[0], &array[i]);
      }
    }
  }
  temp = array[0];
  queue->list[0] = temp;
  queue->count = 1;
  array[0].inQueue = TRUE;
  lastBurst = temp.burstTime;
  burstSum = burstSum + lastBurst;

  for (int i = 1; i < count; i++) {
    if (!array[i].inQueue) {
      for (int k = i +1; k < count; k++) {
	if (array[k].arrivalTime <= burstSum) {
	  if (array[i].priority <= array[k].priority) {
	    if (array[i].priority == array[k].priority) {
	      lexigraphicalTieBreaker (array, k, i);
	    }
	    else {
	      swap (&array[i], &array[k]);
	    }
	  }
	}
      }
      lastBurst = array[i].burstTime;
      burstSum = burstSum + lastBurst;
      queue->list[queue->count] = array[i];
      queue->count++;
      array[i].inQueue = TRUE;
    }
  }
}



void swap (PCB *a, PCB *b) {
  PCB temp;
  temp = *a;
  *a = *b;
  *b = temp;
}