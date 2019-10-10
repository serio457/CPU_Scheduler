// FILE: CPU_Scheduler.c
//

/// SOURCES
///https://www.geeksforgeeks.org/find-largest-among-three-different-positive-numbers-using-command-line-argument/
//FCFS

<<<<<<< HEAD
#include <stdio.h>
#include <string.h>


int main (int argc, char *argv[]) {
	// char* a = (argv[1]);  
  // char* b = (argv[2]); 
  // char* c = (argv[3]);	  
	// char* d = (argv[4]);
if (argc > 6) { 
	printf("Too many arguments!!!");
	printf ("\n");
	return 0;
}
for (int i = 0; i < argc; i++){
    if (!strcaseqcmp(argv[i], "FCFS") || (!strcasecmp(argv[i], "RR") || (!strcmp(argv[i], "SJF") || (!strcmp(argv[i], "priority")) {
		printf ("Found the first argument, it says %s\n", argv[i]);
	}
      
    if (!strcmp(argv[i], "hello")) {
        printf ("I can also say \"%s\"\n", argv[i]);
    }
      
    if (strcmp(argv[i], "first") && strcmp(argv[i], "hello")) {
        printf ("\"%s\" to you too\n", argv[i])
    }
      
}
// if ()
// 	printf("%s", argv[1]);
// 	printf ("\n");
//   return 0;
// }
=======
#include "CPUSched.h"

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL missingParameter(int numArgs, int currentArg);

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
BOOL simulation = FALSE;

//bool for testing for a missing PARAMETER
BOOL missingParam = FALSE;
int nextIndex;

for (int i = 0; i < argc; i++) {
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
    if (!strcasecmp(argv[i], "-preemptive")) {
        preemptive = TRUE;
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
}

BOOL missingParameter(int numArgs, int currentArg) {
  if (numArgs <= currentArg) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}


//
>>>>>>> perry
