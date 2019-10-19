CPUSched: CPUSched.o 
	gcc -o CPUSched CPUSched.o
CPUSched.o: CPUSched.c CPUSched.h
	gcc -c CPUSched.c
PCB.o: PCB.c PCB.h
	gcc -c PCB.c
Queue.o: Queue.c Queue.h
	gcc -c Queue.c
simulation.0: simulation.c simulation.h
	gcc -c simulation.c
