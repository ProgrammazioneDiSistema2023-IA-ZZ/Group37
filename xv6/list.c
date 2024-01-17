#include "list.h"

// inizializza la lista
void init_list(struct proclist* head){
    head->pid = -1; // la testa è una sentinella
    head->next = head;
    head->prev = head;
}

// inserisce un elemento in testa
void list_push_left(struct proclist* new, struct proclist* head){
    struct proclist* next = head->next;
    next->prev = new;   // head ? new->next
    new->next  = next;  // head ? new->next
    head->next = new;   // head->new->next
    new->prev  = head;
}

// inserisce un elemento in coda
void list_push_right(struct proclist* new, struct proclist* head){
    struct proclist* prev = head->prev;
    prev->next = new;
    new->prev = prev;
    head->prev = new;
    new->next = head;
}

// rimuove un elemento dalla lista
void list_delete(struct proclist* entry){
    // sconnette gli elementi della lista
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

// restituisce se la lista è vuota
int list_is_empty(struct proclist* head){
   return head->next == head;
}

int list_pop_left(struct proclist* head){
    // controlliamo che la lista non sia vuota
    if(list_is_empty(head))
        return -1;

    // rimuovo l'elemento in testa
    struct proclist* entry = head->next;
    list_delete(entry);

    // ritorno il pid dell'elemento rimosso
    return entry->pid;
}

// funzione che rimuove tutti gli elementi dalla lista
void list_cleanup(struct proclist* head){
    while(!list_is_empty(head))
        list_pop_left(head);
}