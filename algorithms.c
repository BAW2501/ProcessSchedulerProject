#include <stdio.h>
#include "algorithms.h"

#define All_Arrived(i, n) ((i) >= (n))
#define Is_Time_TO_Arrive(ps, clock) ((ps).AT <= (clock))
#define Higher_Prio_Arriving(ps1, ps2 , clock) (((ps1).AT < (clock) + (ps2).CTL) && ((ps1).PRIO > (ps2).PRIO))
#define Shorter_Time_Arriving(ps1, ps2, clock) ((ps1).AT < (clock) + (ps2).CTL && (ps1).CTL < (ps2).CTL - ((ps1).AT-(clock)) )
#define Bigger_Than_Quantum(ps, q) ((ps).CTL > quantum)
#define Not_Done(ps) ((ps).CTL > 0)

void FIFO(CPU *P, Proccesus Ps_tab[], int n) {
    File f = init_File();
    Proccesus ps;
    float TEM = 0, TAM = 0, TO;
    int i = 0, meanwhile;

    printf("\n\t appuyez sur une touche pour parcourir le deroulement \n");

    while (!All_Arrived(i, n) || !is_empty(f)) {
        printf("\n\t%3d +--------+ ", P->T_Clock);

        while (!All_Arrived(i, n) && Is_Time_TO_Arrive(Ps_tab[i], P->T_Clock))
            f = enFile(f, Ps_tab[i++]);

        print_File(f);
        Insert_Pause();
        if (!is_empty(f)) {
            ps = peek(f);
            f = deFile(f);
            printf("\n\t    | P%3d   | ", ps.Num);
            Alloc_Proccesus(P, &ps, ps.CTL);
            TEM += (float) (P->T_Clock - ps.AT) / (float)n;
            TAM += (float) (P->T_Clock - ps.AT - ps.CT) / (float)n;
        } else {

            printf("\n\t    |        | ");
            meanwhile = Ps_tab[i].AT - P->T_Clock;
            Sleep_for(P, meanwhile);
        }
        print_File(f);
        Insert_Pause();
    }
    printf("\n\t%3d +--------+ ", P->T_Clock);
    print_File(f);
    Insert_Pause();
    TO = (float) P->A_Clock / (float)P->T_Clock;

    printf("\n\n\t TEM= %.2f\n\t TAM= %.2f\n\t TO= %d%%", TEM, TAM, (int) (TO * 100));
}

void PRIORITE(CPU *P, Proccesus Ps_tab[], int n) {
    File f = init_File();
    Proccesus ps;
    float TEM = 0, TAM = 0, TO;
    int i = 0, meanwhile;

    printf("\n\t appuyez sur une touche pour parcourir le deroulement \n");

    while (!All_Arrived(i, n) || !is_empty(f)) {
        printf("\n\t%3d +--------+  ", P->T_Clock);

        while (!All_Arrived(i, n) && Is_Time_TO_Arrive(Ps_tab[i], P->T_Clock))
            f = enFile_PRIO(f, Ps_tab[i++]);

        print_File(f);
        Insert_Pause();

        if (!is_empty(f)) {
            ps = peek(f);
            f = deFile(f);
            printf("\n\t    | P%3d   |  ", ps.Num);
            Alloc_Proccesus(P, &ps, ps.CTL);
            TEM += (float) (P->T_Clock - ps.AT) / (float)n;
            TAM += (float) (P->T_Clock - ps.AT - ps.CT) / (float)n;
        } else {

            printf("\n\t    |        |  ");
            meanwhile = Ps_tab[i].AT - P->T_Clock;
            Sleep_for(P, meanwhile);
        }
        print_File(f);
        Insert_Pause();
    }
    printf("\n\t%3d +--------+ ", P->T_Clock);
    TO = (float) P->A_Clock / (float)P->T_Clock;

    printf("\n\n\t TEM= %.2f\n\t TAM= %.2f\n\t TO= %d%%", TEM, TAM, (int) (TO * 100));
}

void TEMP_COURT(CPU *P, Proccesus Ps_tab[], int n) {
    File f = init_File();
    Proccesus ps;
    float TEM = 0, TAM = 0, TO;
    int i = 0, meanwhile;

    printf("\n\t appuyez sur une touche pour parcourir le deroulement \n");

    while (!All_Arrived(i, n) || !is_empty(f)) {
        printf("\n\t%3d +--------+  ", P->T_Clock);

        while (!All_Arrived(i, n) && Is_Time_TO_Arrive(Ps_tab[i], P->T_Clock)) {
            f = enFile_TEMP_COURT(f, Ps_tab[i++]);
        }

        print_File(f);
        Insert_Pause();
        if (!is_empty(f)) {
            ps = peek(f);
            f = deFile(f);
            printf("\n\t    | P%3d   |  ", ps.Num);
            Alloc_Proccesus(P, &ps, ps.CTL);
            TEM += (float) (P->T_Clock - ps.AT) / (float)n;
            TAM += (float) (P->T_Clock - ps.AT - ps.CT) / (float)n;
        } else {

            printf("\n\t    |        |  ");
            meanwhile = Ps_tab[i].AT - P->T_Clock;
            Sleep_for(P, meanwhile);
        }
        print_File(f);
        Insert_Pause();
    }
    printf("\n\t%3d +--------+ ", P->T_Clock);
    TO = (float) P->A_Clock / (float)P->T_Clock;

    printf("\n\n\t TEM= %.2f\n\t TAM= %.2f\n\t TO= %d%%", TEM, TAM, (int) (TO * 100));
}

void PRIORITE_PREEM(CPU *P, Proccesus Ps_tab[], int n) {
    File f = init_File();
    Proccesus ps;
    float TEM = 0, TAM = 0, TO;
    int i = 0, meanwhile;

    Sort_Processus_PRIO(Ps_tab, n);

    printf("\n\t appuyez sur une touche pour parcourir le deroulement \n");

    while (!All_Arrived(i, n) || !is_empty(f)) {
        printf("\n\t%3d +--------+  ", P->T_Clock);

        while (!All_Arrived(i, n) && Is_Time_TO_Arrive(Ps_tab[i], P->T_Clock))
            f = enFile_PRIO(f, Ps_tab[i++]);

        print_File(f);
        Insert_Pause();
        if (!is_empty(f)) {
            ps = peek(f);
            f = deFile(f);
            printf("\n\t    | P%3d   |  ", ps.Num);

            if (!All_Arrived(i, n) && Higher_Prio_Arriving(Ps_tab[i], ps, P->T_Clock)) {
                meanwhile = Ps_tab[i].AT - P->T_Clock;
                Alloc_Proccesus(P, &ps, meanwhile);
                f = enFile_PRIO(f, ps);
            } else {
                Alloc_Proccesus(P, &ps, ps.CTL);
                TEM += (float) (P->T_Clock - ps.AT) / (float)n;
                TAM += (float) (P->T_Clock - ps.AT - ps.CT) / (float)n;
            }
        } else {

            printf("\n\t    |        |  ");
            meanwhile = Ps_tab[i].AT - P->T_Clock;
            Sleep_for(P, meanwhile);
        }
        print_File(f);
        Insert_Pause();
    }
    printf("\n\t%3d +--------+ ", P->T_Clock);
    TO = (float) P->A_Clock / (float)P->T_Clock;

    printf("\n\n\t TEM= %.2f\n\t TAM= %.2f\n\t TO= %d%%", TEM, TAM, (int) (TO * 100));
}

void TEMP_RESTANT_PLUS_COURT(CPU *P, Proccesus Ps_tab[], int n) {
    File f = init_File();
    Proccesus ps;
    float TEM = 0, TAM = 0, TO;
    int i = 0, meanwhile;

    Sort_Processus_CTL(Ps_tab, n);

    printf("\n\t appuyez sur une touche pour parcourir le deroulement \n");

    while (!All_Arrived(i, n) || !is_empty(f)) {
        printf("\n\t%3d +--------+  ", P->T_Clock);
        while (!All_Arrived(i, n) && Is_Time_TO_Arrive(Ps_tab[i], P->T_Clock))
            f = enFile_TEMP_RESTANT_COURT(f, Ps_tab[i++]);

        print_File(f);
        Insert_Pause();
        if (!is_empty(f)) {
            ps = peek(f);
            f = deFile(f);
            printf("\n\t    | P%3d   |  ", ps.Num);

            if (!All_Arrived(i, n) && Shorter_Time_Arriving(Ps_tab[i], ps, P->T_Clock)) {
                meanwhile = Ps_tab[i].AT - P->T_Clock;
                Alloc_Proccesus(P, &ps, meanwhile);
                f = enFile_TEMP_RESTANT_COURT(f, ps);
            } else {
                Alloc_Proccesus(P, &ps, ps.CTL);
                TEM += (float) (P->T_Clock - ps.AT) / (float)n;
                TAM += (float) (P->T_Clock - ps.AT - ps.CT) / (float)n;
            }
        } else {

            printf("\n\t    |        |  ");
            meanwhile = Ps_tab[i].AT - P->T_Clock;
            Sleep_for(P, meanwhile);
        }
        print_File(f);
        Insert_Pause();
    }
    printf("\n\t%3d +--------+ ", P->T_Clock);
    TO = (float) P->A_Clock / (float)P->T_Clock;

    printf("\n\n\t TEM= %.2f\n\t TAM= %.2f\n\t TO= %d%%", TEM, TAM, (int) (TO * 100));
}

void ROUND_ROBIN(CPU *P, Proccesus Ps_tab[], int n, int quantum) {
    File f = init_File();
    Proccesus ps = init_Processus();
    float TEM = 0, TAM = 0, TO;
    int i = 0, meanwhile;

    printf("\n\t appuyez sur une touche pour parcourir le deroulement \n");

    while (!All_Arrived(i, n) || !is_empty(f)) {
        printf("\n\t%3d +--------+  ", P->T_Clock);

        while (!All_Arrived(i, n) && Is_Time_TO_Arrive(Ps_tab[i], P->T_Clock))
            f = enFile(f, Ps_tab[i++]);
        print_File(f);
        Insert_Pause();
        if (!is_empty(f)) {
            ps = peek(f);
            f = deFile(f);
            printf("\n\t    | P%3d   |  ", ps.Num);

            if (Bigger_Than_Quantum(ps, quantum)) {
                Alloc_Proccesus(P, &ps, quantum);

                while (!All_Arrived(i, n) && Ps_tab[i].AT < P->T_Clock)
                    f = enFile(f, Ps_tab[i++]);
                f = enFile(f, ps);
            } else {
                Alloc_Proccesus(P, &ps, ps.CTL);
                TEM += (float) (P->T_Clock - ps.AT) / (float)n;
                TAM += (float) (P->T_Clock - ps.AT - ps.CT) / (float)n;
            }
        } else {

            printf("\n\t    |        |  ");
            meanwhile = Ps_tab[i].AT - P->T_Clock;
            Sleep_for(P, meanwhile);
        }
        print_File(f);
        Insert_Pause();
    }
    printf("\n\t%3d +--------+ ", P->T_Clock);
    TO = (float) P->A_Clock / (float)P->T_Clock;

    printf("\n\n\t TEM= %.2f\n\t TAM= %.2f\n\t TO= %d%%", TEM, TAM, (int) (TO * 100));
}
