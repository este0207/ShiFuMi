#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3

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

    system("clear");

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

    while (1)
    {
        srand(time(NULL));
    
        system("clear");
        printf("---------------------- ShiFuMi ! --------------------\n");
        printf("1.PIERRE\n");
        printf("2.FEUILLE\n");
        printf("3.CISEAUX\n");
        printf("4.scores\n");
        printf("0.Quitter\n");
        printf("-----------------------------------------------------\n");
        printf("Entrez votre choix %s :", nom1);
        fgets(choix, sizeof(choix), stdin);
        a = atoi(choix);

        if (a == 1)
        {
            printf("Vous avez choisi PIERRE\n");
        }
        else if (a == 2)
        {
           printf("Vous avez choisi FEUILLE\n");
        }
        else if (a == 3)
        {
            printf("Vous avez choisi CISEAUX\n");
        }
        else if (a == 0)
        {
            printf("Merci d'avoir joue !\n");

            printf("%s : Reussite(s) : %d\n", nom1, scorea);
            printf("%s : Reussite(s) : %d\n", nom2, scoreb);
            printf("Entrer pour quitter\n");

            getchar();

            system("clear");
            break;
        }
        

        system("clear");
        printf("---------------------- ShiFuMi ! --------------------\n");
        printf("1.PIERRE\n");
        printf("2.FEUILLE\n");
        printf("3.CISEAUX\n");
        printf("0.Quitter\n");
        printf("-----------------------------------------------------\n");
        printf("Entrez votre choix %s :", nom2);
        fgets(choix, sizeof(choix), stdin);
        b = atoi(choix);



        if (b == 1)
        {
            printf("Vous avez choisi PIERRE\n");
        }
        else if (b == 2)
        {
           printf("Vous avez choisi FEUILLE\n");
        }
        else if (b == 3)
        {
            printf("Vous avez choisi CISEAUX\n");
        }
        else if (b == 0)
        {
            system("clear");
            return 0;
        }

        system("clear");

        printf("3\n");
        sleep(1);
        printf("2\n");
        sleep(1);
        printf("1\n");
        sleep(1);


        if (a == b)
        {
            printf("Egalite\n");
            sleep(5);
        }
        else if (a == PIERRE && b == FEUILLE)
        {
            printf("FEUILLE bat PIERRE\n");
            scoreb++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
         else if (b == PIERRE && a == FEUILLE)
        {
            printf("FEUILLE bat PIERRE\n");
            scorea++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
        else if (a == PIERRE && b == CISEAUX)
        {
            printf("PIERRE bat CISEAUX\n");
            scorea++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
         else if (b == PIERRE && a == CISEAUX)
        {
            printf("PIERRE bat CISEAUX\n");
            scoreb++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
        else if (a == FEUILLE && b == PIERRE)
        {
            printf("PIERRE bat FEUILLE\n");
            scorea++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
         else if (b == FEUILLE && a == PIERRE)
        {
            printf("PIERRE bat FEUILLE\n");
            scoreb++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
        else if (a == FEUILLE && b == CISEAUX)
        {
            printf("FEUILLE bat CISEAUX\n");
            scoreb++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(4);
        }
         else if (b == FEUILLE && a == CISEAUX)
        {
            printf("FEUILLE bat CISEAUX\n");
            scorea++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(4);
        }
        else if (a == CISEAUX && b == PIERRE)
        {
            printf("PIERRE bat CISEAUX\n");
            scoreb++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
         else if (b == CISEAUX && a == PIERRE)
        {
            printf("PIERRE bat CISEAUX\n");
            scorea++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
        else if (a == CISEAUX && b == FEUILLE)
        {
            printf("FEUILLE bat PIERRE\n");
            scorea++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }
        else if (b == CISEAUX && a == FEUILLE)
        {
            printf("FEUILLE bat PIERRE\n");
            scoreb++;
            printf("%s : %d\n", nom1, scorea);
            printf("%s : %d\n", nom2, scoreb);
            sleep(5);
        }

        }

    // 1. Ouvrir le fichier avec fopen()
    FILE* file = fopen("BDD.txt", "w+"); // Ouvre un fichier en écriture et lecture
    
    if (file != NULL) {
        // 2. Lire le fichier avec fprintf()
        fprintf(file, "%s %d\n",nom1, scorea);
        fprintf(file, "%s %d",nom2, scoreb);

        char buf[255];
        memset(buf,0,255);
        
        // 3. Reposition le curseur du fichier au début pour pouvoir lire le fichier depuis le début
        fseek(file,0,SEEK_SET);

        // 4. Utiliser fread() pour lire le fichier
        fread(buf,1,255,file);

        // J'affiche le buf remplit par fread()
        printf(file, "%s %d\n",nom1, scorea);
        printf(file, "%s %d",nom2, scoreb);
        
        fclose(file); // 5. Ferme le fichier



        // FILE *fptr = fopen("save.txt", "r");
        // if(fptr == NULL) {
        //     printf("Error opening file\n");
        //     return;
        // }
        // fscanf(fptr, "Player1 :%[^\n]\n", nom1);
        // fscanf(fptr, "Score1 :%d\n", scorea);
        // fscanf(fptr, "Player2 :%[^\n]\n", nom2);
        // fscanf(fptr, "Score2 :%d\n", scoreb);
        // fclose(fptr); // close the file

    }
    return 0;
}





