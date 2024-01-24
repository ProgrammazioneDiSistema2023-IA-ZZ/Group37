# Programmazione di Sistema - Progetto

Questa repository contiene il codice per il progetto del corso di Programmazione di Sistema del Gruppo 37.

## Implementazioni

Sono state implementate le seguenti funzionalità:

- **Semafori** - implementati in `semaphore.c` e `semaphore.h` per la sincronizzazione tra processi
- **Barriere** - implementate in `barrier.c` e `barrier.h` per il coordinamento di processi 
- **Input** - implementato in `input.c` e `input.h` per la gestione dell'input da tastiera

Per abilitare le system call sono state aggiunte le definizioni necessarie in `syscall.c`, `syscall.h`, `sysproc.c`, `usys.s` e nel Makefile.

## Utilizzo

Per compilare ed eseguire il sistema:

```
make clean    # pulisce la compilazione precedente
make          # compila il codice 
make qemu-nox # esegue in QEMU
```

## Testing

Sono disponibili i seguenti programmi di test:

- `test_semaphore` - 4 processi figli con 2 token 
- `test_barrier` - 5 processi figli in attesa sulla barriera
- `test_input` - test dell'input da tastiera

## Autori

- Marco Lampis s317978
- Davide Vilella s315327

## Licenza

Questo progetto è rilasciato sotto licenza MIT.
