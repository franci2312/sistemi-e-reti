# NCURSES
Ncurses permette di visualizzare a schermo un'interfaccia "grafica", gestendo posizionamento, colori, finesrre separate e scrittura.

### Convenzioni generali di ncurses
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