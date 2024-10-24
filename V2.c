#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define Pierre 1
#define Feuille 2
#define Ciseaux 0

void screen ( char* nom ){
    system("clear");
        printf("---------------------- ShiFuMi ! --------------------\n");
        printf("%s ?\n", nom);
        printf("1.Pierre\n");
        printf("2.Feuille\n");
        printf("3.Ciseaux\n");
        printf("4.Charger\n");
        printf("0.Quitter\n");
        printf("-----------------------------------------------------\n");
        printf("Entrez votre choix : ");
}
int main(){
    char nom[28];
    char c[28];
    char choix[5];
    int score = 0;
    int pc_score = 0;

    system("clear");

    while (1) {
        printf("Entrez votre nom : ");
        fgets(nom, sizeof(nom), stdin);
        printf("%s\n", nom);

        nom[strlen(nom)-1] = 0; // retire le caractère \n

        printf("Y/YES or N/NO ? ");
        fgets(c, sizeof(c), stdin);

        if (c[0] == 'Y' || c[0] == 'y') {
            break;
        }

        if (c[0] == 'N' || c[0] == 'n') {
            system("clear");
        }
    }

    while (1) {
        srand(time(NULL));
    
        screen( nom );

        fgets(choix, sizeof(choix), stdin);
        int a = atoi(choix);

        int r = rand() % 3; // générer un nombre aléatoire entre 0 et 2

        system ("clear");
        switch (a) {
            case 1:
                printf("%s fait Pierre !\n", nom);
                break;
            case 2:
                printf("%s fait Feuille !\n", nom);
                break;
            case 3:
                printf("%s fait Ciseaux !\n", nom);
                break;
            case 4:
                printf("Charger\n");
                FILE* file = fopen(nom, "r+"); // Ouvre un fichier en écriture et lecture 
                fscanf(file,"%s %d\n", nom, &score);
                fclose(file);
                continue;
            case 0:
                printf("Au revoir\n");
                printf("Victoires :\n%s : %d\nPC : %d\n", nom, score, pc_score);
                printf("---------------------- GAME OVER ! --------------------\n");
                return 0;
            default:
                printf("Choix invalide\n");
                continue;
        }
        
        printf("3\n");
        sleep(1);
        printf("2\n");
        sleep(1);
        printf("1\n\n");
        sleep(1);

        switch (r) {
            case Pierre:
                printf("PC a fait Pierre !\n\n");
                break;
            case Feuille:
                printf("PC a fait Feuille !\n\n");
                break;
            case Ciseaux:
                printf("PC a fait Ciseaux !\n\n");
                break;
        }

        if (a == r) {
            printf("Egalité !\n");
        } else if ((a == Pierre && r == Ciseaux) || (a == Feuille && r == Pierre) || (a == Ciseaux && r == Feuille)) {
            printf("%s à GAGNE !\n\n", nom);
            score++;
        } else {
            printf("PC à GAGNE !\n\n");
            pc_score++;
        }

        printf("Victoires :\n%s : %d\nPC : %d\n\n", nom, score, pc_score);
        printf("Entrer pour continuer\n");
        getchar();

     // 1. Ouvrir le fichier avec fopen()
        FILE* file = fopen(nom, "w+"); // Ouvre un fichier en écriture et lecture
        
        if (file != NULL) {
        // 2. Lire le fichier avec fprintf()
        fprintf(file, "%s %d\n",nom, score);

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