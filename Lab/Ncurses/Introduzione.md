# NCURSES
Ncurses permette di visualizzare a schermo un'interfaccia "grafica", gestendo posizionamento, colori, finesrre separate e scrittura.

### Convenzioni generali di ncurses

#### Init e chiusura ncurses
Per avviare ncurses bisogna 


#### Formato coordinate
Il formato delle coordinate di un punto (X,Y) nel piano viene rappresentato indicando prima la Y, poi la X. le costanti COLS e LINES indicano rispettivamente il numero di colonne (X massima + 1) e di righe (Y massima + 1). 


Coordinate in formato (X,Y):
```
(   0   ,   0   )---------------------(   0   , COLS-1)
        |                                     |
        |                                     |
        |                                     |
        |                                     |
(LINES-1,   0   )---------------------(LINES-1, COLS-1)
```

Esempio:
```
Per muoversi nell'angolo in basso a destra bisogna usare move(COLS-1,LINES-1);
```


#### Formato funzioni
le funzioni di ncurses possono essere eseguite su una finestra e contemporaneamente muovere il cursore.
Esempio con funzione func:
```c
// MV = muovi prima di eseguire
// W  = esegui tutto su finestra

// Esempi:
func(...);            // Esegui func()
mvfunc(y,x,...);      // Muovi cursore a (x,y) sullo schermo ed esegui func()
wfunc(win,...);       // esegui func() all'interno della finesta win
mvwfunc(win,y,x,...); // muovi il cursore a (x,y) sulla finestra win ed esegui func()
```

#### Le funzioni sono indicate nella reference