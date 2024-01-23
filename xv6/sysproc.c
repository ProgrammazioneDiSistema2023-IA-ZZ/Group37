#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

#include "test_g37.h" // GROUP37 EDITS


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// GROUP37 EDITS ====================
int sys_test_g37(void) {
  test_g37();
  return 0;
}

int sys_sem_create(void) {
  uint i;
  char* name;
  int sem;

  argint(0, &sem);
  if (sem < 0) return -1;
  
  argstr(1, (char**) &name);
  argint(2, (int*) &i);
  return sem_create(sem, name, i);
}

int sys_sem_wait(void) {
  int sem;
  argint(0, &sem);
  if (sem < 0) return -1;

  return sem_wait(sem);
}

int sys_sem_signal(void) {
  int sem;
  argint(0, &sem);
  if (sem < 0) return -1;

  return sem_signal(sem);
}

int sys_barrier_create(void) {
  int barrier;
  int nproc;
  char* name;
  
  argint(0, &barrier);
  if (barrier < 0) return -1;

  argint(1, &nproc);
  argstr(2, (char**) &name);
  return barrier_create(barrier, nproc, name);
}

int sys_barrier_wait(void) {
  int barrier;
  argint(0, &barrier);
  if (barrier < 0) return -1;

  return barrier_wait(barrier);
}
// =================================
