# NCURSES FUNCTION REFERENCE <!-- omit in toc -->
> Lefunzioni sono divise in vari blocchi.  
> Le varianti mv, w e mvw sono solo accennate,  
> la convenzione del passaggio dei parametri è  
> ([finestra], [y], [x], \<argomenti funzione normale\>)  
> [vedi introduzione]

## Indice <!-- omit in toc -->

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
// Varianti: w
```
```c
napms(int time);
// Mette in pausa il programma per time millisecondi
// Varianti: No
```
```c
timeout(int n);
// Fa in modo che le chiamate a getch() aspettino n millisecondi prima di 
// ritornare. Se negativo, il programma attende per sempre. Se 0, getch()
// ritorna ERR in caso l'utente non stia premendo nulla. Se il delay termina
// e l'utente non ha immesso nulla, ritorna ERR. [ERR è una costante di ncurses]
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
### Input
```c
int scanw(char *format, ...);
// è l'equivalente di scanf, ma per ncurses (stesso utilizzo e parametri)
// Ritorna ERR in caso di errore, altrimenti il numero
// di variabili impostate
// Varianti: mv, w, mvw
```
```c
char getch();
// Ottiene un carattere senza aspettare invio
// Varianti: mv, w, mvw
```
```c
getnstr(char *out_string, int max_len);
// Salva una stringa in out_string con o senza spazi di lunghezza massima max_len
// Il carattere newline viene rimosso
// Varianti: mv, w, mvw
```
```c
getstr(char *out_string);
// Salva una stringa di lunghezza illimitata in out_string con o senza spazi
// Il carattere newline viene rimosso
// Varianti: mv, w, mvw
```

### Output
```c
printw(char *format, ...);
// Funziona esattamente come un printf.
// Varianti: mv, w, mvw
```
```c
addch(char c);
// Stampa il carattere c a schermo nella posizione del cursore.
// Varianti: mv, w, mvw
```
```c
refresh();
// Alcuni comandi possono non essere immediatamente inviati allo schermo
// quando chiamati. refresh() invia tutti i comandi ancora non stampati a schermo
// al terminale per stamparli.
// Varianti: w
```
### Finestre
```c
WINDOW *win;
// dichiara (senza inizializzare [vedi sotto]) una finestra chiamata win.
// Varianti: No
```
```c
win = newwin(int lines, int cols, int y, int x);
// inizializza win a una finestra con lines righe e cols colonne
// y e x sono il punto in alto a sinistra occupato dalla finestra
// Varianti: No
```
```c
mvwin(WINDOW *win, int y, int x);
// Muove la finestra (x,y è il punto in alto a sinistra nuovo)
// Varianti: No
```
```c
delwin(WINDOW *win);
// Elimina la finestra (senza rimuoverla dallo schermo, fare refresh())
// Varianti: No
```
```c
wrefresh(WINDOW *win);
// Aggiorna la finestra (e la sposta se è stato eseguito mvwin)
// Varianti: No
```
```c
scrollok(WINDOW *win, int value);
// value agisce come un bool (0,1). a 1 abilita lo scrolling della finestra.
// Varianti: No
```
```c
werase(WINDOW *win);
// Pulisce la finestra
// Varianti: No
```

### Bordi
```c
box(WINDOW *win, char vertical, char horizontal);
// Aggiunge un bordo alla finestra (occupa 0,0 della finestra)
// vertical e horizontal sono i caratteri usati come bordo
// Varianti: No
```
```c
// TODO: #1 FIXME
WINDOW *win = newwin(10,20,1,1);
WINDOW *win_border = newwin(12,22,0,0);
box(win_border,ACS_VLINE,ACS_HLINE);
// Crea una finestra win 10x20 con bordo esterno in alto a sinistra.
// Varianti: No
```