#include "types.h"
#include "x86.h"
#include "defs.h"
#include "spinlock.h"

#define MAX_BARRIERS 32

struct barrier {
    uint nproc;
    char* name;
    struct spinlock lock;
};

struct barrier barriers[MAX_BARRIERS];

int barrier_create(int, int, char*);
int barrier_wait(int);