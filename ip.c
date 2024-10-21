#include <stdio.h>
#include "common.h"
#include "ip.h"

// Analyser l'entête IP
void analyserIP(char *trame, IP *ip) 
{
    ip->version = (trame[0] >> 4) & 0x0F;  // Les 4 premiers bits
    ip->IHL = trame[0] & 0x0F;              // Les 4 derniers bits
    ip->typeOfService = trame[1];
    ip->totalLength = (trame[2] << 8) | trame[3];
    ip->identification = (trame[4] << 8) | trame[5];
    ip->flags = (trame[6] >> 5) & 0x07;    // Les 3 premiers bits
    ip->fragmentOffset = ((trame[6] & 0x1F) << 8) | trame[7];
    ip->timeToLive = trame[8];
    ip->protocol = trame[9];
    ip->HeaderChecksum = (trame[10] << 8) | trame[11];
    ip->sourceIP = (trame[12] << 24) | (trame[13] << 16) | (trame[14] << 8) | trame[15];
    ip->destinationIP = (trame[16] << 24) | (trame[17] << 16) | (trame[18] << 8) | trame[19];
}

// Afficher une adresse IP au format xxx.xxx.xxx.xxx
void afficherIPAddress(unsigned int address)
{
    printf("%d.%d.%d.%d",
           (address >> 24) & 0xFF,
           (address >> 16) & 0xFF,
           (address >> 8) & 0xFF,
           address & 0xFF);
}

// Afficher l'entête IP
void afficherIP(IP ip)
{
    printf("IP:\n");
    printf("    version: %d\n", ip.version);
    printf("    IHL: %d\n", ip.IHL);
    printf("    typeOfService: %d\n", ip.typeOfService);
    printf("    totalLength: %d\n", ip.totalLength);
    printf("    identification: %d\n", ip.identification);
    printf("    flags: %d\n", ip.flags);
    printf("    fragmentOffset: %d\n", ip.fragmentOffset);
    printf("    timeToLive: %d\n", ip.timeToLive);
    printf("    protocol: %d\n", ip.protocol);
    printf("    HeaderChecksum: %d\n", ip.HeaderChecksum);
    printf("    sourceIP: ");
    afficherIPAddress(ip.sourceIP);
    printf("\n    destinationIP: ");
    afficherIPAddress(ip.destinationIP);
    printf("\n");
}