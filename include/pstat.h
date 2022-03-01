#ifndef _PSTAT_H_ 
#define _PSTAT_H_ 
 
#include "param.h" 
 
struct pstat { 
  int inuse[NPROC];   // whether this slot of the process table is in use (1 or 0) 
  int pid[NPROC];     // the PID of each process  
  char name[16][NPROC]; // the name of each process
  int priority[NPROC]; // the priority of each process
}; 
 
#endif // _PSTAT_H_