/***************************************************
                    TEST INPUT
File di test per verificare il corretto funzionamento
dei semafori implementati con le system call
sem_create, sem_wait e sem_signal.
***************************************************/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "semaphore.h"


void processo_figlio(int sem, int i){
  sleep(100);
  sem_wait(sem);
  printf(1,"figlio %d: risvegliato\n", i);
  sleep(300);
  printf(1,"figlio %d: ho rilasciato\n", i);
  sem_signal(sem);
  
  // fa terminare il processo in modo che non vengano
  // create dai figli ulteriori fork 
  exit();
}

int main(int argc, char *argv[]){
  printf(1, "*********************************\n");
  printf(1, "        TEST SEMAPHORE\n");
  printf(1, "*********************************\n\n");
  
  int n_sem = 2;
  sem_create(n_sem, "semaforo", 2);

  for (int i = 0; i < 4; i++){
    int pid = fork();

    // pid > 0 -> parent
    if (pid > 0){
      printf(1, "padre: generato figlio %d\n", i);
    }

    // pid == 0 -> child
    else if (pid == 0){
      processo_figlio(n_sem, i);
    }

    else if (pid < 0){
      printf(1, "Errore nella fork\n");
    }
  }

  
  for (int i = 0; i < 4; i++){
    wait();
  }

  printf(1, "\n");
  printf(1, "*********************************\n");
  printf(1, "    TEST SEMAPHORE COMPLETED\n");
  printf(1, "*********************************\n\n");
  exit();
}
