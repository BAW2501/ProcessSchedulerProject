#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Utility.h"

CPU init_CPU() {
    CPU p;
    p.Stat = INACTIVE;
    p.A_Clock = 0;
    p.T_Clock = 0;

    return p;
}

void Alloc_Proccesus(CPU *p, Proccesus *ps, int time) {
    p->Stat = ACTIVE;
    p->A_Clock += time;
    p->T_Clock += time;
    ps->CTL -= time;
}

void Sleep_for(CPU *p, int time) {
    p->Stat = INACTIVE;
    p->T_Clock += time;
}

Proccesus *Scan_Processus(int n) {
    Proccesus *tab = NULL;
    int i;

    tab = (Proccesus *) malloc((size_t) n * sizeof(Proccesus));

    if (tab == NULL) {
        perror("MEM ERR");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        printf("\n\tEntrer P%d : ", i);
        tab[i].Num = i;

        printf("\n\tTemp Arrivee : ");
        do
            scanf("%d", &tab[i].AT);
        while (tab[i].AT < 0);

        printf("\tTemp de Calcul : ");
        do
            scanf("%d", &tab[i].CT);
        while (tab[i].CT <= 0);

        tab[i].CTL = tab[i].CT;

        printf("\tPriorite : (1-5) ");
        do
            scanf("%d", &tab[i].PRIO);
        while (tab[i].PRIO <= 0 || tab[i].PRIO > 5);
    }
    return tab;
}

Proccesus init_Processus() {
    Proccesus temp;
    temp.Num = 0;
    temp.AT = 0;
    temp.CT = 0;
    temp.CTL = 0;
    temp.PRIO = 0;
    return temp;
}

void Sort_Processus(Proccesus *tab, int n) {

    int i, j;
    Proccesus temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (tab[j].AT > tab[j + 1].AT) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
}

void Sort_Processus_PRIO(Proccesus *tab, int n) {

    int i, j;
    Proccesus temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (tab[j].AT == tab[j + 1].AT && tab[j].PRIO < tab[j + 1].PRIO) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
}

void Sort_Processus_CTL(Proccesus *tab, int n) {

    int i, j;
    Proccesus temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (tab[j].AT == tab[j + 1].AT && tab[j].CTL > tab[j + 1].CTL) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
}

void Print_Processus(Proccesus *tab, int n) {
    int i;
    printf("\n\t+-----------------+-----------------+-----------------+-----------------+");
    printf("\n\t|   Processus     | Temp de arrivee |  Temp de calcul |     Priorite    |");
    printf("\n\t+-----------------+-----------------+-----------------+-----------------+");

    for (i = 0; i < n; i++) {

        printf("\n\t|       %3d       |       %3d       |       %3d       |       %3d       |", tab[i].Num, tab[i].AT,
               tab[i].CT, tab[i].PRIO);
        printf("\n\t+-----------------+-----------------+-----------------+-----------------+");
    }

    printf("\n");
}

void Insert_Pause() {
    getch();
}
