## Come è formata una CPU
Il codice nel computer è scritto in binario e viene eseguito dalla CPU, che contiene CU e ALU
La Control Unit (CU) esegue il fetch delle istruzioni (preleva da mem. centrale e legge)
la Arithmetic Logic Unit (ALU) esegue le istruzioni
## Tipologie di istruzioni
Varie tipologie di istruzioni:
- Trasferimento controllo e salto (Es. jmp \[salto], call \[chiama funzione], ret \[return])
- Trasferimento dati e I/O (Es. in, out \[comunicazione con il bus I/O])
- Aritmetico-logiche (Es. xor, add, div)
- Controllo CPU e miste (Es. hlt \[ferma la CPU], nop \[non fa nulla])
## ISTRUZIONI E REGISTRI
Istruzione formata da opcode e parametri (numeri o indirizzi)
esempio:  (eax è l'indirizzo dell'accumulatore)
```
05               09                  (è uguale a)   ADD           eax              ,     9
opcode di ADD    argomento                          istruzione    registro             numero
(intel e AMD)   (indirizz. imm.)                                  (ind. intrinseco)
 --------- CODICE MACCHINA ---------               ------------- CODICE ASSEMBLY -------------
 ```
Registro = cella di memoria che contiene un numero o info speciali della cpu
Esempi di registri speciali:
- FLAGS (contiene dati su stato overflow e altro)
- PC (program counter)(contiene indirizzo istruzione attuale)
(istruzione attuale ~= riga di codice attuale)
- Accumulatore (Contiene risultato delle operazioni aritmetiche (esempio è EAX su CPU intel/amd a 32 bit))
- Stack pointer (Contiene puntatore al frame della subroutine (funzione) in esecuzione attuale)
## LO STACK
Frame composto da variabili locali e indirizzi di ritorno
(quando viene chiamato ret, la cpu prende l'indirizzo da cui continuare dallo stack))
(Es. 1A.s)[./es/1A.s]
quando "call pippo" viene eseguito, l'indirizzo dell'istruzione "mov ebx, eax" viene pushato sullo stack
e il program counter viene impostato all'indirizzo dell'istruzione "mov eax,0". Quando viene chiamato "ret"
la CPU esegue un pop dello stack e prende l'indirizzo di ritorno (indirizzo di "mov ebx, eax") e continua
partendo dall' istruzione "mov ebx, eax".
è abbastanza simile a questo codice in c (Es. 1B.c)[./es/1B.c]
## TIPO DI INDIRIZZAMENTO
Vari metodi di indirizzamento:
- Intrinseco
	esempio l'istruzione ADD, che aggiunge il parametro all'accumulatore EAX. La CPU sa che la istruzione 05 (opcode di ADD)
	vuol dire "Aggiungi quello che c'è dopo all'accumulatore" e non ha bisogno di sapere il suo indirizzo
- Immediato
	esempio 10 o 5. La CPU prende l'argomento dall'istruzione così com'è e non ha bisogno di vedere il suo indirizzo
	(è una costante e non una variabile)
- Diretto
	esempio "ebx" in "mov ebx, eax". La CPU prende il valore e lo usa per cercare la relativa locazione in memoria.
###### FRANCESCO MILOVA