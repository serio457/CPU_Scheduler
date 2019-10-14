
struct PCB { 
    char name[100]; 
    int arrivalTime, burstTime, priority; 
};

PCB compareName (PCB pcb1, PCB pcb2);
PCB compareAT (PCB pcb1, PCB pcb2);
PCB compareBT (PCB pcb1, PCB pcb2);
PCB comparePriority (PCB pcb1, PCB pcb2);