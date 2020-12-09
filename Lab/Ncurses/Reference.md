# NCURSES FUNCTION REFERENCE
> Lefunzioni sono divise in vari blocchi.  
> Le varianti mv, w e mvw sono solo accennate,  
> la convenzione del passaggio dei parametri è  
> ([finestra], [y], [x], \<argomenti funzione normale\>)  

## Indice

### Init
```c
initscr();
// Esegue l'inizializzazione di ncurses
// Varianti: No
```
```c
endwin();
// Termina ncurses
// Varianti: No
```

### Cursore
```c
curs_set(n);
// Imposta il cursore da invisibile (0) a molto visibile (2)
// Varianti: No
```
```c
move(int y, int x);
// Muove il cursore a un punto
// Varianti: w
```

### Utils
```c
echo();
noecho();
// Abilita o disabilita la scrittura a schermo dei
// caratteri dati dall'utente (noecho è usato comunemente
// nell'input di password)
// Varianti: No
```
```c
cbreak();
nocbreak();
// cbreak rimuove la necessità di aspettare il tasto invio
// quando l'utente preme un carattere per passarlo al
// programma (ad esempio in un gioco usare cbreak permette 
// di ricevere i caratteri senza aspettare l'invio).
// nocbreak riabilita l'opzione
// Varianti: No
```
```c
clear();
// pulisce lo schermo
// Varianti: No
```
```c
napms(int time);
// Mette in pausa il programma per time millisecondi
// Varianti: No
```

### Colori
```c
LISTA COLORI
// COLOR_BLACK
// COLOR_RED
// COLOR_GREEN
// COLOR_YELLOW
// COLOR_MAGENTA
// COLOR_BLUE
// COLOR_CYAN
// COLOR_WHITE
```
```c
start_color();
// Abilita i colori
// Varianti: No
```
```c
init_pair(short pair, short f, short b);
// pair è un numero da 1 a 7 che indica l'indice dello stile
// f e b sono dei colori (COLOR_X) rispettivamente del carattere e dello sfondo
// Per applicare i colori guardare la sezione attributi
// Varianti: No
```
```c
bkgd(COLOR_PAIR(n));
// Imposta i colori della finestra a quelli definiti nello 
// stile di indice n [v. init_pair]
// Varianti: w
```