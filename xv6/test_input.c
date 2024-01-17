/***************************************************
                    TEST INPUT
File di test per verificare il corretto funzionamento
delle system call getint() e getchar().
***************************************************/

#include "types.h"
#include "user.h"

int main(int argc, char* argv[]){
    int n1, n2, n3;
    
    printf(1, "*********************************\n");
    printf(1, "          TEST INPUT \n");
    printf(1, "*********************************\n\n");

    printf(1, "Inserisci un numero: ");
    n1 = getint();
    
    printf(1, "Inserisci un secondo numero: ");
    n2 = getint();
    
    // viene effettuata la somma dei numeri
    n3 = n1 + n2;
    
    printf(1, "La somma dei due numeri e': %d\n", n3);
    
    printf(1, "\nInserisci un carattere: ");
    char c = getchar();
    printf(1, "Il carattere inserito e': %c\n\n", c);
   
    printf(1, "*********************************\n");
    printf(1, "     TEST INPUT COMPLETED\n");
    printf(1, "*********************************\n\n");
    exit();
}