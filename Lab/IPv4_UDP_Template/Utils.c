// Funzioni utili

// Da indirizzo IP a stringa
void IP_ADDR_ToString(){

    // necessita di <arpa/inet.h> per funzionare
    // Converte un indirizzo (famiglia AF_INET, quindi IPv4) nella sua rappresentazione come stringa
    // Richiede un puntatore all'indirizzo, un buffer in cui mettere la stringa e la sua lunghezza
    // nel caso di IPv4 INET_ADDRSTRLEN può essere usato per dimensionare il buffer (è la lunghezza massima necessaria)
    char indirizzo_come_stringa[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(indirizzo_dato.sin_addr), indirizzo_come_stringa, INET_ADDRSTRLEN);
    printf("Indirizzo IPv4: %s", indirizzo_come_stringa);

}
// Francesco Milova