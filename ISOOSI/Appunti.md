## Il sistema ISO/OSI
ISO = International Standards Organization
OSI = Open System Interconnect
Il sistema ISO/OSI è un'insieme di standard che copre tipi di connessione fisica
e tipi di comunicazione. Il tutto è suddiviso in 7 livelli, che comunicano con quello
precedente e successivo (tranne 1 e 7).
```
L7                      L7
L6                      L6
L5                      L5
L4                      L4
L3<-- - LOGICAMENTE- -->L3
L2                      L2
L1<--------FILO-------->L1
```
## I livelli

Ogni livello non interferisce coi dati di quelli di livello superiore.

L1 = Physical Layer 
    (Trasmette bit da una macchina all'altra adiacente nel miglior modo possibile)
L2 = Connection Layer
    (Codifica i dati di L3 in bit da dare a L1 aggiungendo informazioni)
    (Controlla che il dato sia ricevuto dall'altra macchina)
    (Restituisce a L3 il buffer corretto)
L3 = Network Layer
    (Consente una comunicazione anche tra macchine non direttamente connesse)
    (Deve distinguere messaggi relativi a macchine diverse)
    (Individuare in maniera univoca le varie macchine della rete)
L4 = Transport Layer
    (Gestisce comunicazioni monodirezionali e bidirezionali)
    (Può usare più linee per una sola trasmissione e otternere velocità migliori)
    (Riordina i dati)
L5 = Session Layer
    (Mette a disposizione l'infrastruttura per cui il programma può iniziare o ricevere annullamenti di sessione)
L6 = Presentation Layer
    (Tradurre la codifica del documento fra 2 formati differenti)
    (Trasformare codifica da big endian a little endian)
L7 = Application Layer
    (Il programma)
     + Parte custom (La parte scritta specifica)
     + Parte standard (Standardizzata da ISO/OSI)

Fra i programmi standard si menzionano:
Terminale virtuale = Riga di comando di ISO/OSI compatibile con curses (tty cioé teletype)
File & Directory Services = Sistema di directory e file da remoto (con upload e download)
Directory Service = Trova informazioni in un elenco distribuito (Ad esempio un elenco telefonico)
LDAP = Lightweight directory access Protocol (Sistema di accesso a un Directory Service)
Mail Services = Consente l'invio e la ricezione di mail