#include "types.h"
#include "stat.h"
#include "user.h"

// funzione che prende in input un carattere
char getchar(){
    char buf[1];
    read(0, buf, 1);
    return buf[0];
}

// funzione che prende in input un intero
int getint(){
	char buffer [256];	// buffer di input utente
	int segno = 1;  	// segno del risultato
	int risultato = 0;	// risultato finale  
	int cont = 0;      
	
	// input dell'utente con la chiamata di sistema
	gets(&buffer, 256);

	// tengo traccia del segno
	if (buffer[0] == '-'){
		segno = -1;  
		cont++;  
	}

    while(buffer[cont] != '\0' ){
		char cifra = buffer[cont] - '0';
		
		// se non è un numero, esco
        if(cifra < 0 || cifra > 9) break ;

        risultato = risultato*10 + cifra;
		cont = cont + 1;
    }
	
	risultato = risultato * segno;
	return risultato;
}
