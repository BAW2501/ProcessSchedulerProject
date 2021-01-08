#ifndef UTILITY_H
#define UTILITY_H

#include "Structs.h"

#define ACTIVE 1
#define INACTIVE 0

CPU init_CPU();

//allocate for the active time
void Alloc_Proccesus(CPU *, Proccesus *, int);

//sleepfor for the inactivetime
void Sleep_for(CPU *, int);

Proccesus init_Processus();

Proccesus *Scan_Processus(int);

void Sort_Processus(Proccesus *, int);

void Sort_Processus_PRIO(Proccesus *, int);

void Sort_Processus_CTL(Proccesus *, int);

void Print_Processus(Proccesus *, int);

void Insert_Pause();

#endif
