#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3

int screen (){
    printf("---------------------- ShiFuMi ! --------------------\n");
        printf("1.PIERRE\n");
        printf("2.FEUILLE\n");
        printf("3.CISEAUX\n");
        printf("4.SAUVEGARDE\n");
        printf("0.Quitter\n");
        printf("-----------------------------------------------------\n");
}

void name ( char* nom1, char* nom2, char* c ){



    while (1)
    {
    printf("Entrez le nom du joueur N°1: ");
    fgets(nom1, sizeof(nom1), stdin);

    printf("Entrez le nom du joueur N°2: ");
    fgets(nom2, sizeof(nom2), stdin);

    nom1[strlen(nom1)-1] = 0; // retire le caractère \n
    nom2[strlen(nom2)-1] = 0; // retire le caractère \n



    if (nom1[0] >= 92 && nom1[0] <= 122) {
        nom1[0] = nom1[0] - 32;
    }

    if (nom2[0] >= 92 && nom2[0] <= 122) {
        nom2[0] = nom2[0] - 32;
    }

    printf("%s\n", nom1);
    printf("%s\n", nom2);

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
    }

int main(){
    char nom1[28];
    char nom2[28];
    char c[28];
    char choix[5];
    int scorea = 0;
    int scoreb = 0;
    int i = 0;
    int a = 0;
    int b = 0;

    name(nom1, nom2, c);
    while (1)
    {

        srand(time(NULL));
    
        screen ();
        printf("Entrez votre choix %s :", nom1);
        fgets(choix, sizeof(choix), stdin);
        a = atoi(choix);

        switch (a)
        {
            case 1:
                printf("Vous avez choisi PIERRE\n");
                break;
            case 2:
                printf("Vous avez choisi FEUILLE\n");
                break;
            case 3:
                printf("Vous avez choisi CISEAUX\n");
                break;
            case 4:
                printf("Sauvegarde\n");
                FILE* file = fopen("BDD.txt", "r+"); // Ouvre un fichier en écriture et lecture 
                fscanf(file,"%s %d", nom1, &scorea);
                fscanf(file,"%s %d", nom2, &scoreb);
                fclose(file);
                continue;
            case 0:
                printf("Merci d'avoir joue !\n");

                printf("%s : Reussite(s) : %d\n", nom1, scorea);
                printf("%s : Reussite(s) : %d\n", nom2, scoreb);
                printf("Entrer pour quitter\n");

                getchar();

                system("clear");
                return 0;
                break;
            default:
                printf("choix invalide, reessayez\n");
                break;
        }
        

        system("clear");
        screen ();
        printf("Entrez votre choix %s :", nom2);
        fgets(choix, sizeof(choix), stdin);
        b = atoi(choix);


        switch (b)
        {
            case 1:
                printf("Vous avez choisi PIERRE\n");
                break;
            case 2:
                printf("Vous avez choisi FEUILLE\n");
                break;
            case 3:
                printf("Vous avez choisi CISEAUX\n");
                break;
            case 0:
                printf("Merci d'avoir joue !\n");

                printf("%s : Reussite(s) : %d\n", nom1, scorea);
                printf("%s : Reussite(s) : %d\n", nom2, scoreb);
                printf("Entrer pour quitter\n");

                getchar();

                system("clear");
                return 0;
            default:
                printf("choix invalide, reessayez\n");
                break;
        }

        system("clear");
        printf("3\n");
        sleep(1);
        printf("2\n");
        sleep(1);
        printf("1\n");
        sleep(1);


        switch (a) {
            case PIERRE:
                switch (b) {
                    case FEUILLE:
                        printf("FEUILLE bat PIERRE\n");
                        scoreb++;
                        break;
                    case CISEAUX:
                        printf("PIERRE bat CISEAUX\n");
                        scorea++;
                        break;
                    default:
                        printf("Egalite\n");
                        break;
                }
                break;
            case FEUILLE:
                switch (b) {
                    case PIERRE:
                        printf("PIERRE bat FEUILLE\n");
                        scorea++;
                        break;
                    case CISEAUX:
                        printf("FEUILLE bat CISEAUX\n");
                        scoreb++;
                        break;
                    default:
                        printf("Egalite\n");
                        break;
                }
                break;
            case CISEAUX:
                switch (b) {
                    case PIERRE:
                        printf("PIERRE bat CISEAUX\n");
                        scoreb++;
                        break;
                    case FEUILLE:
                        printf("FEUILLE bat PIERRE\n");
                        scorea++;
                        break;
                    default:
                        printf("Egalite\n");
                        break;
                }
                break;
            default:
                printf("Erreur\n");
                break;
        }

        printf("%s : %d\n", nom1, scorea);
        printf("%s : %d\n", nom2, scoreb);

        printf("Entrer pour continuer\n");
        getchar();

        // 1. Ouvrir le fichier avec fopen()
        FILE* file = fopen("BDD.txt", "w+"); // Ouvre un fichier en écriture et lecture
        
        if (file != NULL) {
        // 2. Lire le fichier avec fprintf()
        fprintf(file, "%s %d\n",nom1, scorea);
        fprintf(file, "%s %d\n",nom2, scoreb);

        char buf[255];
        memset(buf,0,255);
        
        // 3. Reposition le curseur du fichier au début pour pouvoir lire le fichier depuis le début
        fseek(file,0,SEEK_SET);

        // 4. Utiliser fread() pour lire le fichier
        fread(buf,1,255,file);
        
        fclose(file); // 5. Ferme le fichier

    }
}
    return 0;

}
