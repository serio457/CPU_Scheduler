// FILE: CPU_Scheduler.c
//

/// SOURCES
///https://www.geeksforgeeks.org/find-largest-among-three-different-positive-numbers-using-command-line-argument/
//FCFS

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
