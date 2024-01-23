#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "semaphore.h"

int sem_create(int s, char *name, int count)
{
    if (s < 0 || s >= MAX_SEM)
    {
        return -1;
    }
    struct semaphore *sem = &semaphores[s];
    sem->count = count;

    // inizializziamo il lock
    initlock(&sem->lock, "semaphore");

    // inizializziamo la coda di elementi
    for (int j = 0; j < MAX_PROC; j++)
        sem->queue[j] = 0;

    // inizializziamo il nome
    sem->name = name;

    sem->current = 0;
    sem->tail = 0;

    return s;
}

int sem_wait(int s)
{
    if (s < 0 || s >= MAX_SEM)
    {
        return -1;
    }
    // viene recuperato il semaforo di riferimento
    struct semaphore *sem = &semaphores[s];

    // inizio zona critica
    acquire(&sem->lock);

    // struct proclist new;
    sem->queue[sem->tail] = myproc();
    sem->tail = (sem->tail + 1) % MAX_PROC;

    // se il contatore è maggiore di 0, decrementiamo il contatore e usciamo
    while (sem->count == 0)
    {
        sleep(sem, &sem->lock);
    }

    sem->count = sem->count - 1;

    // rilasciamo il lock
    release(&sem->lock);
    
    return 0;
}

int sem_signal(int s)
{
    if (s < 0 || s >= MAX_SEM)
    {
        return -1;
    }
    struct semaphore *sem = &semaphores[s];

    // inizio zona critica
    acquire(&sem->lock);
    sem->count = sem->count + 1;

    sem->current = (sem->current + 1) % MAX_PROC;
    // struct proc* p = sem->queue[sem->current];
    wakeup(sem);

    // rilasciamo il lock
    release(&sem->lock);
    return 0;
}