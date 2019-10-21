// FILE: CPU_Scheduler.c
//

/// SOURCES
///https://www.geeksforgeeks.org/find-largest-among-three-different-positive-numbers-using-command-line-argument/
//FCFS
// Code for testing non-digits in specified quanta: https://stackoverflow.com/questions/10166157/check-if-entire-array-of-characters-in-c-are-only-numbers-return-true-if-yes



#include "CPUSched.h"

//
BOOL missingParameter(int numArgs, int currentArg); // DO WE NEED THIS?
//

int main (int argc, char *argv[]) {
  if (argc > 12) {
    printf("ERROR: TOO MANY ARGUMENTS\n");
    return 0;
  }

  //initialize all of the flag values to their defualtschar type[10] = "FCFS
  char type[10] = "FCFS";
  int quanta = 10;
  BOOL preemptive = FALSE;
  char infile[100] = "process.in";
  char outfile[100] = "process.out";
  BOOL simulationFlag = FALSE;
  BOOL arrivalFlag = FALSE;
  BOOL burstFlag = FALSE;
  int simCount = -1;

  //bool for testing for a missing PARAMETER
  BOOL missingParam = FALSE;
  int nextIndex;

  for (int i = 0; i < argc; i++) {
    //tests for type argument
    if (!strcasecmp(argv[i], "-type")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      strcpy (type, argv[i+1]);
      if (!((!strcasecmp(argv[i+1], "FCFS")) || (!strcasecmp(argv[i+1], "RR")) || (!strcmp(argv[i+1], "SJF")) || (!strcmp(argv[i+1], "priority")))) {
	printf ("ERROR: INVALID TYPE. VALID TYPES INCLUDE: FCFS, RR, SJF, priority\n");
	return 0;
      }
    }
    //tests for quanta value
    if (!strcasecmp(argv[i], "-quanta")) {
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
    if (!strcasecmp(argv[i], "-preemptive")) {
      preemptive = TRUE;
    }

    if (!strcasecmp(argv[i], "-infile")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      strcpy(infile, argv[i+1]);
    }

    if (!strcasecmp(argv[i], "-outfile")) {
      if (argc <= i+1) {
	printf ("ERROR: MISSING PARAMETER.\n");
	return 0;
      }
      strcpy(outfile, argv[i+1]);
    }
  
    printf ("Type string: %s\n", type);
    printf ("quanta number: %d\n", quanta);
    if (preemptive) {
      printf ("preemptive: true\n");
    }
    if (!preemptive) {
      printf ("preemptive: false\n");
    }
    printf ("INFILE name: %s\n", infile);
    printf ("OUTFILE name: %s\n", outfile);

    //setting up variables
    FILE *file;
    char processName[10];
    int arrival, burst, priority;
    int c, numProcesses=0;
    struct PCB processes[500];
    // unclear if the above code is still needed
    if (!strcasecmp(argv[i], "-outfile")) {
      strcpy(outfile, argv[i+1]);
    }

    if (!strcasecmp(argv[i], "-simulation")) {
      simulationFlag = TRUE;
      for (int j = 1; j < 4 && argv[i+j]; i++) {
	if (!strcasecmp(argv[i+1], "arrival")) {
	  arrivalFlag = TRUE;
	}
	if (!strcasecmp(argv[i+1], "burst")) {
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

    printf ("Type string: %s\n", type);
    printf ("quanta number: %d\n", quanta);
    if (preemptive) {
      printf ("preemptive: true\n");
    }
    if (!preemptive) {
      printf ("preemptive: false\n");
    }
    printf ("INFILE name: %s\n", infile);
    printf ("OUTFILE name: %s\n", outfile);
    if (simulationFlag) {
      printf ("Simulation: true\n");
      if (arrivalFlag) {
	printf ("\tSimulating arrival: true\n");
      }
      if (burstFlag) {
	printf ("\tSimulating burst: true\n");
      }
      printf ("\tSimulation count: %i", simCount);
    }

    //read from an infile
    if (!simulate) {
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
      }
      fclose(file);

      //sort the array of PCB's based on the specified sort type
      if (strcasecmp(type, "FCFS") == 0) {
	sortByArrival (processes, numProcesses);
      }
      else if (strcasecmp(type, "SJF") == 0) {
	sortByBurst (processes, numProcesses);
      }
      //else if (strcasecmp(type, "RR") == 0) {
      //  sortByArrival (processes, numProcesses);
      //}
      else {
	sortByPriority (processes, numProcesses);
      }


      //test whats in the array
      int p = 0;
      while (p < numProcesses) {
	printf ("PCB: %s %d %d %d\n", processes[p].name, processes[p].arrivalTime, processes[p].burstTime, processes[p].priority);
	p++;
      }
    }
    printf ("\n");
  }
}
// KEEP OR NAH?
//
//
//FUNCTIONS

BOOL missingParameter(int numArgs, int currentArg) {
  if (numArgs <= currentArg) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}


//
