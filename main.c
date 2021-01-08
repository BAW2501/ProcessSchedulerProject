//Belhadj ahmed walid
//Benkahla mohamed
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "File.h"
#include "Utility.h"
#include "algorithms.h"

int main() {
    int n = 0, Continue = 1, Quantum = 0;
    int Option;
    Proccesus *tab = NULL;
    CPU p;

    while (Continue) {
        system("@cls||clear");

        printf("\n\t\td8888b. d8888b.  .d88b.     d88b d88888b  .o88b. d888888b   .d8888. d88888b"
               "\n\t\t88  `8D 88  `8D .8P  Y8.    `8P' 88'     d8P  Y8 `~~88~~'   88'  YP 88'    "
               "\n\t\t88oodD' 88oobY' 88    88     88  88ooooo 8P         88      `8bo.   88ooooo"
               "\n\t\t88~~~   88`8b   88    88     88  88~~~~~ 8b         88        `Y8b. 88~~~~~"
               "\n\t\t88      88 `88. `8b  d8' db. 88  88.     Y8b  d8    88      db   8D 88.    "
               "\n\t\t88      88   YD  `Y88P'  Y8888P  Y88888P  `Y88P'    YP      `8888Y' Y88888P\n\n");

        printf("\n\t pour remplir les processus, entrez 0");
        printf("\n\t Pour choisir l'algorithme FIFO, entrez 1 ");
        printf("\n\t Pour choisir l'algorithme Priorite, entrez 2 ");
        printf("\n\t Pour choisir l'algorithme Temp plus court, entrez 3 ");
        printf("\n\t Pour choisir l'algorithme Priorite Preemtive, entrez 4 ");
        printf("\n\t Pour choisir l'algorithme Temp restant plus court, entrez 5 ");
        printf("\n\t Pour choisir l'algorithme Round Robin, entrez 6 \n ");

        do
            Option = getch();
        while (Option < '0' || Option > '6');

        p = init_CPU();

        system("@cls||clear");

        if (Option == '0') {
            do {
                printf("\n\n\t entrer le nombre des processus : ");
                scanf("%d", &n);
            } while (n <= 0);
            system("@cls||clear");
            tab = Scan_Processus(n);
            system("@cls||clear");
            Sort_Processus(tab, n);
        } else {
            if (tab != NULL) {
                Print_Processus(tab, n);

                switch (Option) {
                    case '1':
                        printf("\n\t\tFIFO : \n ");
                        FIFO(&p, tab, n);
                        break;
                    case '2':
                        printf("\n\t\tPRIORITE : \n ");
                        PRIORITE(&p, tab, n);
                        break;
                    case '3':
                        printf("\n\t\tTEMP PLUS COURT : \n ");
                        TEMP_COURT(&p, tab, n);
                        break;
                    case '4':
                        printf("\n\t\tPRIORITE PREEEMPTIF : \n ");
                        PRIORITE_PREEM(&p, tab, n);
                        break;
                    case '5':
                        printf("\n\t\tTEMP  RESTANT PLUS COURT : \n ");
                        TEMP_RESTANT_PLUS_COURT(&p, tab, n);
                        break;
                    case '6':
                        printf("\n\t\tROUND ROBIN : \n ");
                        do {
                            printf("\n\t Entrer le Quantum  ");
                            scanf("%d", &Quantum);
                        } while (Quantum <= 0);

                        ROUND_ROBIN(&p, tab, n, Quantum);
                        break;
                    default:
                        break;
                }
                do {
                    printf("\n\t continue ? 1/0 \n");
                    scanf("%d", &Continue);
                } while (Continue != 0 && Continue != 1);

            } else
                printf("vous n'avez pas rempli la liste des processus");


        }
    }
    return 0;
}
