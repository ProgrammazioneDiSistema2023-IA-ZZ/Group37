#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#include "types.h"
#include "list.h"
#include "param.h"
#include "spinlock.h"
#include "stddef.h"
#include "stdbool.h"

#define MAX_PROC 32
#define MAX_SEM  32 


struct semaphore {
    const char *name;
    int count;
    struct spinlock lock;
    void* queue[MAX_PROC];
    unsigned int tail;
    unsigned int current;
};

struct semaphore semaphores[MAX_SEM];

int sem_create(int s, char *name, int initial_count);
int sem_wait(int s);
int sem_signal(int s);

#endif