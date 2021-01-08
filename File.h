
#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include "Structs.h"

typedef struct node {
    Proccesus p;
    struct node *next;
    struct node *prev;
} node;

typedef node *File;

File init_File();                                //o(1)
int is_empty(File);                              //o(1)
File Malloc_Node(Proccesus p);                   //o(1)
File enFile(File, Proccesus);                    //o(1)
File enFile_PRIO(File, Proccesus);               //max o(n)
File enFile_TEMP_COURT(File, Proccesus);         //max o(n)
File enFile_TEMP_RESTANT_COURT(File, Proccesus); //max o(n)
Proccesus peek(File);                            //o(1)
File deFile(File);                               //o(1)
void print_File(File);                           //o(n)

#endif
