#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct CPU {
    //active or not 1/0
    int Stat;
    //CPU time >0
    int T_Clock;
    //active cpu time >0
    int A_Clock;
} CPU;

typedef struct Proccesus {
    //P ID
    int Num;

    //P arrival time >0
    int AT;

    //P calc time >0
    int CT;
    //P calc time left for Preemtive algorithms and RR
    int CTL;
    //P priority >0 && <=5
    int PRIO;
} Proccesus;

#endif
