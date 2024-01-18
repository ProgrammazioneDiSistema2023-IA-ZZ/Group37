#include "barrier.h"

int barrier_create(int n, int nproc, char *name)
{
  if (n <= 0 || n >= MAX_BARRIERS)
  {
    return -1;
  }
  if (nproc <= 0)
  {
    return -1;
  }

  struct barrier *b = &barriers[n];

  b->nproc = nproc;
  b->name = name;

  initlock(&b->lock, "barrier");
  return 0;
}

int barrier_wait(int n)
{
  if (n < 0 || n >= MAX_BARRIERS)
  {
    return -1;
  }

  struct barrier *b = &barriers[n];

  // inizio zona critica
  acquire(&b->lock);
  b->nproc--;

  if (b->nproc == 0)
  {
    wakeup(b);
  }

  else
  {
    sleep(b, &b->lock);
  }

  // fine zona critica
  release(&b->lock);
  return 0;
}