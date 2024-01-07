#ifndef _WCHAN_H_
#define _WCHAN_H_

#include "wchan.h"
#include "list.h"
#include "spinlock.h"
#include "stddef.h"     // includes the NULL definition
#include "stdbool.h"    // includes the bool type

struct wchan{
    const char *name;
    struct spinlock wc_lock;
    struct proclist wc_list;
};

/*
 * crea un wchan con un nome definito come costante di caratteri.
*/
struct wchan *wchan_create(const char *name);

/*
 * Distrugge un wchan precedentemente creato. 
*/
void wchan_destroy(struct wchan *wc);

/*
 * Ritorna un valore diverso da zero se non ci sono thread in attesa sul canale.
*/
bool wchan_isempty(struct wchan *wc);

/*
 * lock e unlock del wchan.
*/
void wchan_lock(struct wchan *wc);
void wchan_unlock(struct wchan *wc);

/*
 * Mette in attesa un processo sul wchan passato come parametro. Viene messo in attesa
 * fino a quando non viene svegliato da qualcun altro, a quel punto la funzione ritorna.
 * IL canale deve essere bloccato prima di chiamare questa funzione e sbloccato prima di ritornare.
*/
void wchan_sleep(struct wchan *wc);

/*
 * Sveglia uno o tutti i processi in attesa sul wchan passato come parametro.
*/
void wchan_wakeone(struct wchan *wc);
void wchan_wakeall(struct wchan *wc);


#endif /* _WCHAN_H_ */