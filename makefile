CPU_Sched: CPU_Sched.o 
	gcc -o CPU_Sched CPU_Sched.o
CPU_Sched.o: CPU_Sched.c CPU_Sched.h
	gcc -c CPU_Sched.c
PCB.o: PCB.c PCB.h
	gcc -c PCB.c
Queue.o: Queue.c Queue.h
	gcc -c Queue.c
simulation.0: simulation.c simulation.h
	gcc -c simulation.c
