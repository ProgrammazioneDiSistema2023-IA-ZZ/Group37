#ifndef LIST_H
#define LIST_H

#include "types.h"

struct proclist {
    unsigned int pid;               // process id
    struct proclist *prev, *next;   // puntatori al processo precedente e successivo
};

void init_list      (struct proclist*);
void list_push_left (struct proclist*,  struct proclist*);
void list_push_right(struct proclist* , struct proclist*);
void list_delete    (struct proclist*);
int  list_is_empty  (struct proclist*);

int pop(struct proclist*);

#endif