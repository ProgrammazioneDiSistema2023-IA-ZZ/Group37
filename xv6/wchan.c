#include "wchan.h"
#include "defs.h"

/*
#include "types.h"
#include "stdbool.h"
#include "stddef.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "fs.h"
*/

struct wchan* wchan_create(const char *name){
	struct wchan *wc;

	wc = (struct wchan*) kalloc();
	if (wc == NULL) {
		return NULL;
	}

	initlock(&wc->wc_lock, "wchan lock");   // inizializza il lock
	init_list(&wc->wc_list);                // inizializza la lista dei processi

	wc->name = name;
	return wc;
}