#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Queue.h"
#include "PCB.h"
#include "simulation.h"
 
#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL missingParameter(int numArgs, int currentArg);
