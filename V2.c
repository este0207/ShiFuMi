#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define Pierre 1
#define Feuille 2
#define Ciseaux 0

int main(){
    char nom[28];
    char c[28];
    char choix[5];
    int score = 0;
    int i = 0;
    int a = 0;

    system("clear");

    while (1)
    {
    printf("Entrez votre nom : ");
    fgets(nom, sizeof(nom), stdin);
    printf("%s\n", nom);

    printf("Y/YES or N/NO ? ");
    fgets(c, sizeof(c), stdin);

    if (c[0] == 'Y' || c[0] == 'y')
    {
        break;
    }

    if (c[0] == 'N' || c[0] == 'n')
    {
        system("clear");
    }
    }

    while (1)
    {
        srand(time(NULL));
    
    system("clear");
        printf("---------------------- ShiFuMi ! --------------------\n");
        printf("1.Pierre\n");
        printf("2.Feuille\n");
        printf("3.Ciseaux\n");
        printf("0.Quitter\n");
        printf("-----------------------------------------------------\n");
        printf("Entrez votre choix : ");
        fgets(choix, sizeof(choix), stdin);
        a = atoi(choix);

        int r = (int)rand() % 3; //generer un nombre aleatoire entre 0 et 2

        if (a == 1)
        {
            printf("Vous avez choisi Pierre\n");
            printf("3\n");
            sleep(1);
            printf("2\n");
            sleep(1);
            printf("1\n");
            sleep(1);

            if (r == 0)
            {
                system("clear");
                printf("C'est un ciseaux\n");
                sleep(1);
                score++;
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
            else if (r == 1)
            {
                system("clear");
                printf("C'est une pierre\n");
                printf("egalitée\n");
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
            else if (r == 2)
            {
                system("clear");
                printf("C'est une feuille\n");
                printf("Perdu\n");
                score--;
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
        }
        else if (a == 2)
        {
           printf("Vous avez choisi Feuille\n");
            printf("3\n");
            sleep(1);
            printf("2\n");
            sleep(1);
            printf("1\n");
            sleep(1);

            if (r == 2)
            {
                system("clear");
                printf("C'est une feuille\n");
                printf("egalitée\n");
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
            else if (r == 1)
            {
                system("clear");
                printf("C'est une pierre\n");
                sleep(1);
                score++;
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
            else if (r == 0)
            {
                system("clear");
                printf("C'est un ciseaux\n");
                printf("Perdu\n");
                score--;
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
        }
        else if (a == 3)
         {
            printf("Vous avez choisi Ciseaux\n");
            printf("3\n");
            sleep(1);
            printf("2\n");
            sleep(1);
            printf("1\n");
            sleep(1);

            if (r == 1)
            {
                system("clear");
                printf("C'est une pierre\n");
                printf("Perdu\n");
                sleep(1);
                score--;
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
            else if (r == 0)
            {
                system("clear");
                printf("C'est un ciseaux\n");
                printf("egalitée\n");
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
            else if (r == 2)
            {
                system("clear");
                printf("C'est une feuille\n");
                printf("Gagner\n");
                score++;
                printf("%s a un score de = %d\n", nom, score);
                sleep(2);
            }
        }
        else if (a == 0)
        {
            printf("Au revoir\n");
            printf("Votre score finale %s = %d", nom, score);
            return 0;
        }
    }
    return 0;

}