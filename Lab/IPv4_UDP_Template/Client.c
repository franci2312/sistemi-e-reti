#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Lunghezza massima buffer
#define BUF_LEN 255
// Porta a cui collegarsi
#define SERVICEPORT 1100
// Indirizzo IPv4 a cui collegarsi
char SERVICENAME[] = "127.0.0.1";

int main () {

    // Guardare il file Server.c per spiegazioni delle funzioni

    struct sockaddr_in local_addr,remote_addr;
    int sock;
    unsigned int recvlen;
    char data_buffer [BUF_LEN];
    // Mantiene informazioni su un certo host (ci interessa il campo h_addr_list[0], cioe il suo indirizzo IPv4)
    struct hostent *h;

    // Crea socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (sock <= 0) {
        perror ("Errore creazione socket");
        exit (2);
    }

    // Imposta gli attributi dell'indirizzo locale (in questo caso ogni interfaccia su ogni porta)
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(INADDR_ANY);
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind socket
    if (bind (sock, (struct sockaddr*)&local_addr, sizeof(local_addr)) < 0) {
        perror ("Bind error - ");
        close(sock);
        exit (4);
    }

    // Imposta gli attributi dell'indirizzo remoto (famiglia AF_INET e porta a cui collegarsi)
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(SERVICEPORT);

    // la funzione gethostbyname() prende in input una stringa e ritorna le informazioni di essa
    // se è un indirizzo IPv4 o un nome di dominio
    h = gethostbyname(SERVICENAME);
    // Imposta l'indirizzo remoto a quello fornito dalla funzione
    remote_addr.sin_addr.s_addr = *((int*) h->h_addr_list[0]);

    // Invia pacchetto (32 byte)
    if (sendto (sock, data_buffer, 32, 0, (struct sockaddr*)&remote_addr, sizeof(remote_addr)) < 0) {
        perror ("SendTo Error");
        close(sock);
        exit (16);
    }

    // Riceve pacchetto
    recvlen = sizeof(remote_addr);
    recvlen = recvfrom (sock, data_buffer, BUF_LEN, 0, (struct sockaddr*)&remote_addr, &recvlen);
    if (recvlen < 0) {
        perror ("RecvFrom Error");
        close(sock);
        exit (8);
    }

    // Chiude socket
    close (sock);

    return 0;
}
// Francesco Milova