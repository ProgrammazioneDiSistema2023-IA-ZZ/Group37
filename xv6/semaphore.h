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
    // struct proclist queue;
    void* queue[MAX_PROC];
    unsigned int tail;
    unsigned int current;
};

struct semaphore semaphores[MAX_SEM];

struct semaphore* sem_create(int s, char *name, int initial_count);
void sem_wait(int s);
void sem_signal(int s);


#endif