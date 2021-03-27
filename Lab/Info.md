# Template socket UDP IPv4
Questi file contengono il template per un client e server

## Server flow
Il flow del server è
- Crea socket
- Esegui bind a interfacce e porta
- Ricevi pacchetto da un indirizzo
- Opera sul pacchetto*
- Prepara risposta*
- Invia risposta

Gli step con * non sono inseriti nel file

## Client flow
Il flow del client è
- Crea socket
- Esegui bind a interfacce e porte
- Prepara dettagli indirizzo remoto
- Invia pacchetto all'indirizzo
- Ricevi pacchetto
- Opera sul pacchetto ricevuto*

Gli step con * non sono inseriti nel file
