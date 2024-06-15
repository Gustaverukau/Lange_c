#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//FONCTION 1 QUI DEMANDE L'IDENTIQUE
int identite()
{
    // Demande � l'utilisateur d'entrer son nom
    char nom[50];
    printf("Entrez votre nom  au complet : ");
    scanf("%s", nom);

    // Demande � l'utilisateur d'entrer son num�ro de t�l�phone
    char numero[15];
    printf("Entrez votre numero de telephone : ");
    scanf("%s", numero);

    // G�n�re un code de quatre chiffres al�atoirement
    srand(time(NULL));
    int code = rand() % 9000 + 1000;

    // �crit les informations dans un fichier texte
    FILE *fichier = fopen("informations.txt", "a");
    if (fichier != NULL)
    {
        fprintf(fichier, "Nom : %s\n", nom);
        fprintf(fichier, "Num�ro de t�l�phone : %s\n", numero);
        fprintf(fichier, "Code : %d\n", code);
        fclose(fichier);
        //printf("Les informations ont �t� enregistr�es dans le fichier informations.txt.\n");
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    return 0;
}


// Structure pour stocker la destination et son prix
struct Destination
{
    char nom[20];
    int jour;
    int mois;
    double prix;
};

// Fonction pour saisir la destination et le prix
int saisirDestination(struct Destination *utilisateur)
{
    int choix;
    do
    {
        printf("Entrez votre destination (1. Lubumbashi, 2. Kolwezi, 3. Likasi, 4. Fungurume) : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 1:
                strcpy(utilisateur->nom, "Lubumbashi");
                utilisateur->prix = 50.0;
                break;
            case 2:
                strcpy(utilisateur->nom, "Kolwezi");
                utilisateur->prix = 70.0;
                break;
            case 3:
                strcpy(utilisateur->nom, "Likasi");
                utilisateur->prix = 25.0;
                break;
            case 4:
                strcpy(utilisateur->nom, "Fungurume");
                utilisateur->prix = 60.0;
                break;
            default:
                printf("Choix incorrect ! Veuillez r�essayer.\n");
                continue;
        }
        return 1; // Destination saisie avec succ�s
    } while (1);
}

int main()
{
    struct Destination utilisateur;
    if (saisirDestination(&utilisateur))
    {
        printf("Vous avez choisi la destination : %s\n", utilisateur.nom);
        printf("Le prix pour cette destination est de %.2lf $.\n", utilisateur.prix);
    }
    else
    {
        printf("Erreur lors de la saisie de la destination.\n");
    }

    return 0;
}


    // �crit la destination dans le fichier
    FILE *fichier = fopen("informations.txt", "a"); // Ouvre le fichier en mode ajout
    if (fichier != NULL)
    {
        fprintf(fichier, "destination : %s\n", utilisateur.nom);
        fprintf(fichier, "date : %d/%d\n", utilisateur.jour, utilisateur.mois);

        fclose(fichier);
        //printf("Destination enregistr�e dans destinations.txt.\n");
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    return 0;
}

//FONCTION 3 bus
// Structure pour repr�senter un bus
struct Bus
{
    int numero;
    int sieges_disponibles;
};

// Structure pour repr�senter une r�servation
struct Reservation
{
    int numero_bus;
    char emplacement[20]; // devant, au milieu, derri�re
};

int bus()
{
    // D�finition de 5 bus
    struct Bus buses[10];
    for (int i = 0; i < 10; ++i)
    {
        buses[i].numero = i + 1;
        buses[i].sieges_disponibles = 20;
    }

    // Demande � l'utilisateur de saisir le num�ro du bus et l'emplacement
    struct Reservation reservation;
    printf("Entrez le numero du bus (1 a 10) : ");
    scanf("%d", &reservation.numero_bus);
    printf("Entrez l'emplacement (devant, au milieu, derriere) : ");
    scanf("%s", reservation.emplacement);

    // V�rification de la disponibilit� des si�ges
    if (reservation.numero_bus < 1 || reservation.numero_bus > 10)
    {
        printf("Numero de bus invalide.\n");
        return 1;
    }
    if (buses[reservation.numero_bus - 1].sieges_disponibles == 0)
    {
        printf("Desole, tous les sieges sont deja reserves pour ce bus.\n");
        return 1;
    }

    // Met � jour le nombre de si�ges disponibles
    buses[reservation.numero_bus - 1].sieges_disponibles--;

    // Enregistre la r�servation dans un fichier
    FILE *fichier = fopen("informations.txt", "a");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    fprintf(fichier, "Bus %d : , Emplacement %s\n", reservation.numero_bus, reservation.emplacement);
    fclose(fichier);

    //printf("R�servation effectu�e avec succ�s !\n");

    return 0;
}

//FONCTION 3 PAYER
// Structure pour stocker les informations de r�servation
struct Reservationn
{
    char reseau[20];
    int montant;
};

int payer()
{
    // Cr�ation d'une instance de la structure Reservation
    struct Reservationn reservation;

    // Demande � l'utilisateur de saisir le r�seau

    int choix_reseau;
    do
    {
        printf("Entrez le r�seau (1. airtelmoney, 2. mpesa, 3. orangemoney) : ");
        scanf("%d", &choix_reseau);

        switch(choix_reseau)
        {
        case 1:
            strcpy(reservation.reseau, "airtelmoney");
            break;
        case 2:
            strcpy(reservation.reseau, "mpesa");
            break;
        case 3:
            strcpy(reservation.reseau, "orangemoney");
            break;
        default:
            printf("Erreur!");
            continue;
        }
        if(choix_reseau==1 || choix_reseau==2 || choix_reseau==3)
        {
            break;
        }
    }
    while(1);

    // Demande � l'utilisateur de saisir le montant


    do
    {
        printf("Entrez le montant en franc (40000) : ");
        scanf("%d", &reservation.montant);

        // V�rification du montant
        if (reservation.montant != 40000)
        {
            printf("Montant incorrect. Veuillez r�essayer avec 40000 francs.\n");
            continue; // Quitte le programme avec un code d'erreur
        }
        else
        {
            break;
        }
    }
    while(1);

    // �criture dans le fichier reservation.txt
    FILE *fichier = fopen("informations.txt", "a");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    fprintf(fichier, "R�seau : %s, Montant : %d francs\n", reservation.reseau, reservation.montant);
    fclose(fichier);

    //printf("R�servation enregistr�e dans le fichier reservation.txt.\n");

    return 0;
}


