#ifndef LIST_H
#define LIST_H

#include "types.h"

struct proclist {
    void* pid;               // process id
    struct proclist *prev, *next;   // puntatori al processo precedente e successivo
};

void init_list      (struct proclist*);
void list_push_left (struct proclist*,  struct proclist*);
void list_push_right(struct proclist* , struct proclist*);
void list_delete    (struct proclist*);
int  list_is_empty  (struct proclist*);
void list_cleanup   (struct proclist*);

int list_pop_left   (struct proclist*);

#endif