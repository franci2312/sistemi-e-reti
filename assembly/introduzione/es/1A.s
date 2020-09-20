global  _main        ; Imposta la funzione di partenza a "_main"

pippo:               ; Funzione "pippo"
    mov eax, 0       ; Imposta l'accumulatore a 0 (cioè lo azzera in caso un'altra istruzione lo avesse usato)
    mov eax, 10      ; Imposta l'accumulatore a 10
    add eax, 5       ; Aggiunge 5 all'accumulatore      
    ret              ; Ritorna dalla funzione

_main:               ; Funzione "_main"
    call pippo       ; Chiama "pippo"
    mov ebx, eax     ; Sposta l'accumulatore in ebx (che dovrebbe ora essere 15)