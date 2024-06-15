#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

int main()
{
    printf("BIENVENU CHEZ ROSHA\n=====================\n");
    printf("Faites votre reservation\n=======================\n");

    char reponse;

    do
    {
        identite();
        Destination();
        bus();
        payer();

        printf("\nVoulez-vous faire une autre reservation ? (o/n) : ");
        scanf(" %c", &reponse);
    }
    while (reponse == 'o' || reponse == 'O');

    printf("\nreservation reussi !\n");




    return 0;
}
