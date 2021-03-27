#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Lunghezza massima buffer
#define BUF_LEN 255
// Porta a cui collegarsi
#define SERVICEPORT 1100

int main () {
    struct sockaddr_in indirizzo_locale,indirizzo_remoto;
    int sock;
    unsigned int recvlen;
    char data_buffer [BUF_LEN];

    // Crea il socket e lo salva nella variabile "sock"
    // Per UDP è AF_INET, SOCK_DGRAM,  IPPROTO_UDP
    // Per TCP è AF_INET, SOCK_STREAM, IPPROTO_TCP
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Se il socket ha valore <=0 non è stato creato correttamente
    if (sock <= 0) {
        // Stampa un messaggio d'errore
        perror ("Errore creazione socket");
        // Esce con codice 2
        exit (2);
    }

    // Imposta gli attributi dell'indirizzo locale
    // AF_INET è la famiglia di protocolli (sempre questa)
    indirizzo_locale.sin_family = AF_INET;
    // Imposta la porta di ascolto o connessione a SERVICEPORT
    indirizzo_locale.sin_port = htons(SERVICEPORT);
    // Imposta l'indirizzo di ascolto o connessione, in questo caso INADDR_ANY (cioe riceve da ogni interfaccia)
    indirizzo_locale.sin_addr.s_addr = htonl(INADDR_ANY);
    // htons e htonl convertono l'ordine dei byte in quello usato dalla rete

    // "Lega" il socket all'indirizzo e porta locale specificati, se è <0 c'è stato un errore
    if (bind (sock, (struct sockaddr*)&indirizzo_locale, sizeof(indirizzo_locale)) < 0) {
        perror ("Bind error");
        // Chiude il socket
        close(sock);
        exit (4);
    }

    // Imposta la lunghezza massima dell'indirizzo remoto da cui viene ricevuta la richiesta
    recvlen = sizeof(indirizzo_remoto);
    // Questa funzione, dato un socket, buffer con max size e indirizzo remoto con max size
    // ritorna il numero di byte ricevuti, e salva l'indirizzo remoto con la sua lunghezza nei puntatori
    recvlen = recvfrom (sock, data_buffer, BUF_LEN, 0, (struct sockaddr*)&indirizzo_remoto, &recvlen);

    // Se ho ricevuto meno di 0 byte ce stato un errore
    if (recvlen < 0) {
        perror ("RecvFrom Error");
        close(sock);
        exit (8);
    }

    // Questa funzione invia tramite un socket dei dati a un indirizzo remoto (in questo caso 32 byte)
    // Se invio meno di 0 byte c'è stato un errore
    if (sendto (sock, data_buffer, 32, 0, (struct sockaddr*)&indirizzo_remoto, sizeof(indirizzo_remoto)) < 0) {
        perror ("SendTo Error");
        close(sock);
        exit (16);
    }

    // Chiudo il socket alla fine del programma
    close (sock);

    return 0;
}
// Francesco Milova
