#include <stdio.h>
#include <string.h>
#include "common.h"
#include "ethernet.h"

// Analyser l'entête Ethernet
void analyserEthernet(char *trame, Ethernet *ethernet) 
{    
    memcpy(&ethernet->destination, trame, 6);
    memcpy(&ethernet->source, &trame[6], 6);
    ethernet->longueur = MAKE_SHORT(trame[12], trame[13]);
}

// Afficher une adresse Ethernet / MAC
// Affichage de l'adresse MAC en format xx:xx:xx:xx:xx:xx
void afficherAdresseEthernet(char *adresse)
{
    printf("%02X:%02X:%02X:%02X:%02X:%02X",
           adresse[0], adresse[1], adresse[2],
           adresse[3], adresse[4], adresse[5]);
}

// Afficher l'entête Ethernet
void afficherEthernet(Ethernet ethernet)
{
    printf("Ethernet:\n");
    printf("    destination: ");
    afficherAdresseEthernet(ethernet.destination);
    printf("\n");
    printf("    source: ");
    afficherAdresseEthernet(ethernet.source);
    printf("\n");
    printf("    longueur: %d\n", ethernet.longueur);
}