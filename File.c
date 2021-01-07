#include <stdio.h>
#include "File.h"

File init_File() {
    return NULL;
}

int is_empty(File l) {
    return (l == NULL);
}

File Malloc_Node(Proccesus ps) {
    File l = NULL;

    l = (File) malloc(sizeof(node));

    if (l == NULL) {
        perror("out of memory");
        exit(EXIT_FAILURE);
    }
    l->p = ps;
    l->next = l;
    l->prev = l;
    return l;
}

File enFile(File l, Proccesus ps) {
    File temp, last;
    temp = Malloc_Node(ps);

    if (is_empty(l))
        return temp;

    last = l->prev;

    temp->next = l;
    l->prev = temp;
    temp->prev = last;
    last->next = temp;

    return l;
}

File enFile_PRIO(File l, Proccesus ps) {
    File f = l, temp;
    temp = Malloc_Node(ps);

    if (is_empty(l))
        return temp;

    if (l->p.PRIO < ps.PRIO) {
        l = enFile(l, ps);
        return l->prev;
    }

    while (l->next != f && l->next->p.PRIO >= ps.PRIO)
        l = l->next;

    l = l->next;
    enFile(l, ps);

    return f;
}

File enFile_TEMP_COURT(File l, Proccesus ps) {
    File f = l, temp;
    temp = Malloc_Node(ps);

    if (is_empty(l))
        return temp;
    //	printf(" [%d %d]",l->p.CT,ps.CT);
    if (l->p.CT > ps.CT) {

        l = enFile(l, ps);
        return l->prev;
    }

    while (l->next != f && l->next->p.CT <= ps.CT)
        l = l->next;

    l = l->next;
    enFile(l, ps);

    return f;
}

File enFile_TEMP_RESTANT_COURT(File l, Proccesus ps) {
    File f = l, temp;
    temp = Malloc_Node(ps);

    if (is_empty(l))
        return temp;

    if (l->p.CTL > ps.CTL) {
        l = enFile(l, ps);
        return l->prev;
    }

    while (l->next != f && l->next->p.CTL <= ps.CTL)
        l = l->next;

    l = l->next;
    enFile(l, ps);

    return f;
}


Proccesus peek(File f) {
    return f->p;
}

File deFile(File l) {
    File temp;

    if (is_empty(l))
        return l;

    if (l == l->next) {
        free(l);
        return (File) NULL;
    }

    temp = l->next;
    l->next->prev = l->prev;
    l->prev->next = l->next;

    free(l);

    return temp;
}

void print_File(File l) {
    File temp;
    if (is_empty(l)) {
        printf("         File vide ");
        return;
    }

    temp = l;
    printf("         contenue de la file ");
    do {
        printf("| P%d ", temp->p.Num);
        temp = temp->next;
    } while (temp != l);
    printf("|");
} /**/
