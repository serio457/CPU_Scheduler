CPUSched: CPUSched.o PCB.o Queue.o simulation.o
	gcc -o CPUSched CPUSched.o PCB.o Queue.o simulation.o
CPUSched.o: CPUSched.c CPUSched.h PCB.h
	gcc -c CPUSched.c
PCB.o: PCB.c PCB.h
	gcc -c PCB.c
Queue.o: Queue.c Queue.h PCB.h
	gcc -c Queue.c
simulation.o: simulation.c simulation.h PCB.h
	gcc -c simulation.c
