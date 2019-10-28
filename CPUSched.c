/* Fran, Perry, Nick 
   Transy U
   FILE: CPUSched.c
   Main scheduler file
   Takes in optional flags to sort a list of processes
   Can also simulate faux processes for testing
   Returns the Average Wait Time in specified outfile, or in processes.out

   Missing/Broken Features:
   -v: just not enough time :/
   preemption: due to rehashing of queue, see queue.c for more info aka queue.c -v :)
   

   SOURCES
   Code for how to do bubble sort: https://www.geeksforgeeks.org/bubble-sort/
   https://www.geeksforgeeks.org/find-largest-among-three-different-positive-numbers-using-command-line-argument/
   FCFS
   Code for testing non-digits in specified quanta: https://stackoverflow.com/questions/10166157/check-if-entire-array-of-characters-in-c-are-only-numbers-return-true-if-yes
*/


#include "CPUSched.h"

int main (int argc, char *argv[]) {
  if (argc > 12) {
    printf("ERROR: TOO MANY ARGUMENTS\n");
    return 0;
  }

  //initialize all of the flag values to their defualts
  char type[10] = "FCFS";
  int quanta = 10;
  BOOL preemptive = FALSE;
  char infile[100] = "process.in";
  char outfile[100] = "process.out";
  BOOL simulationFlag = FALSE;
  BOOL arrivalFlag = FALSE;
  BOOL burstFlag = FALSE;
  int simCount = -1;
  BOOL verbose = FALSE;

  for (int i = 0; i < argc; i++) {
    //Tests for type argument
    //Defaults to FCFS
    if (!strcmp(argv[i], "-type")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      strcpy (type, argv[i+1]);
      if (!((!strcasecmp(argv[i+1], "FCFS")) || (!strcasecmp(argv[i+1], "RR")) || (!strcasecmp(argv[i+1], "SJF")) || (!strcmp(argv[i+1], "priority")))) {
	printf ("ERROR: INVALID TYPE. VALID TYPES INCLUDE: FCFS, RR, SJF, priority\n");
	return 0;
      }
    }
    //tests for quanta value
    if (!strcmp(argv[i], "-quanta")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      // Code for testing non-digits in specified quanta from https://stackoverflow.com/questions/10166157/check-if-entire-array-of-characters-in-c-are-only-numbers-return-true-if-yes
      int j;
      const int len = strlen(argv[i+1]);
      char quantaString[len];
      strcpy (quantaString, argv[i+1]);
      for (j = 0; j < len; j++) {
	if (!isdigit(quantaString[j])) {
	  printf ("ERROR: NON_DIGITS IN QUANTA. QUANTA MUST BE A POSITIVE, NON-ZERO INTEGER.\n");
	  return 0;
	}
      }
      quanta = atoi(argv[i+1]);
      if (quanta==0) {
	printf ("ERROR: QUANTA MUST BE A POSITIVE, NON-ZERO INTEGER\n");
	return 0;
      }
    }
    //tests for preemptive flag
    if (!strcmp(argv[i], "-preemptive")) {
      preemptive = TRUE;
    }

    if (!strcmp(argv[i], "-infile")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      strcpy(infile, argv[i+1]);
    }

    if (!strcmp(argv[i], "-outfile")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      strcpy(outfile, argv[i+1]);
    }

    if (!strcmp(argv[i], "-simulation")) {
      simulationFlag = TRUE;
      for (int j = 1; j < 4 && argv[i+j]; i++) {
	if (!strcmp(argv[i+1], "arrival")) {
	  arrivalFlag = TRUE;
	}
	if (!strcmp(argv[i+1], "burst")) {
	  burstFlag = TRUE;
	}
	const int len = strlen(argv[i+j]);
	char countString[len];
	BOOL validNumber = TRUE;
	strcpy (countString, argv[i+j]);
	for (int k = 0; k < len && validNumber; k++) {
	  if (!isdigit(countString[k])) {
	    validNumber = FALSE;
	  }
	}
	if (validNumber) {
	  simCount = atoi(argv[i+j]);
	}
      }
      if (simCount == -1) {
	printf ("ERROR: MISSING SIMULATION COUNT. PLEASE SPECIFY A POSITIVE, NON-ZERO NUMBER.\n");
	return 0;
      }
    }

    if (!strcmp(argv[i], "-v")) {
      verbose = TRUE;
    }
      
  }
    
  //setting up variables
  FILE *file;
  char processName[10];
  int arrival, burst, priority;
  int c, numProcesses;
  PCB processes[500];
  Queue queue; 
  double avgWait;
  
  //read from an infile
  if (!simulationFlag) {
    numProcesses = 0;
    file = fopen (infile, "r");
    if (file) {
      while (fscanf(file, "%d", &c) != EOF) {
	//take in the line & save values
	fscanf(file, "%s %d %d %d", processName, &arrival, &burst, &priority);
	//make a PCB with the read data and store it in an array
	makePCB (processName, arrival, burst, priority, processes, numProcesses);
	//increment the number of processes
	numProcesses++;
      }
    fclose(file);
    }
    else {
      printf("ERROR: FILE NOT FOUND");
      return 0;
    }
  }
  else {
    numProcesses = simCount;
    simulate (arrivalFlag, burstFlag, numProcesses, processes);
  }

  sortByArrival (processes, numProcesses);
  if (strcasecmp (type, "FCFS") == 0) {
    putIntoQ (&queue, processes, numProcesses);
    avgWait = calcAverageWait (queue);
  }

  if (strcasecmp (type, "SJF") == 0) {
    SJF (processes, &queue, numProcesses);
    avgWait = calcAverageWait (queue);
  }

  if (strcmp (type, "priority") == 0) {
    prioritySort (processes, &queue, numProcesses);
    avgWait = calcAverageWait (queue);
  }
  
  file = fopen (outfile, "w+");
  if (file) {
    fprintf (file, "Average Wait Time: %f\n", avgWait);
    if (verbose)
      for (int i = 0; i < numProcesses; i++)
	fprintf (file, "%s %d %d %d\n", queue.list[i].name, queue.list[i].arrivalTime, queue.list[i].burstTime, queue.list[i].priority);
    fclose(file);
  }
  return 0;
}


