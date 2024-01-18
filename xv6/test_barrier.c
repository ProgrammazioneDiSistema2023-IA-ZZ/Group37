/***************************************************
                    TEST BARRIER
File di test per verificare il corretto funzionamento
delle barrier.
***************************************************/

#include "types.h"
#include "stat.h"
#include "user.h"


void processo_figlio(int n_bar, int i){
  sleep(100+(i*100));
  printf(1,"figlio %d: in attesa\n", i);
  barrier_wait(n_bar);
  printf(1,"figlio %d: risvegliato\n", i);
  
  // fa terminare il processo in modo che non vengano
  // create dai figli ulteriori fork 
  exit();
}

int main(int argc, char *argv[]){
  printf(1, "*********************************\n");
  printf(1, "        TEST BARRIER\n");
  printf(1, "*********************************\n\n");
  
  int n_bar = 1, n_proc = 5;
  
  
  barrier_create(n_bar, n_proc, "barrier");

  for (int i = 0; i < n_proc; i++){
    int pid = fork();

    // pid > 0 -> parent
    if (pid > 0){
      printf(1, "padre: generato figlio %d\n", i);
    }

    // pid == 0 -> child
    else if (pid == 0){
      processo_figlio(n_bar, i);
    }

    else if (pid < 0){
      printf(1, "Errore nella fork\n");
    }
  }

  
  for (int i = 0; i < n_proc; i++){
    wait();
  }

  printf(1, "\n");
  printf(1, "*********************************\n");
  printf(1, "     TEST BARRIER COMPLETED\n");
  printf(1, "*********************************\n\n");
  exit();
}