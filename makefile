CPUSched: CPUSched.o PCB.o queue.o simulation.o PCB.h
	gcc -o CPUSched CPUSched.o PCB.o queue.o simulation.o
CPUSched.o: CPUSched.c CPUSched.h  PCB.h
	gcc -c CPUSched.c
PCB.o: PCB.c PCB.h
	gcc -c PCB.c
queue.o: queue.c queue.h PCB.h
	gcc -c queue.c
simulation.o: simulation.c simulation.h PCB.h
	gcc -c simulation.c
