#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char a[10];
    static int score = 0;
    
    printf("Jeu du pierre-feuille-ciseaux\n");// titre du jeux
    while (score < 3)
    {
        int r = (int)rand() % 3; //generer un nombre aleatoire entre 0 et 2
        char* tab[3] = {"pierre", "papier", "ciseaux"};
        printf("3\n");
        sleep(1);
        printf("2\n");
        sleep(1);
        printf("1\n");
        sleep(1);
        
        scanf("%s", a);

        printf("%s\n", tab[r]);
        if (strcmp(a, tab[r]) == 0) {
            printf("egal\n");
        }
        else if (strcmp(a, "pierre") == 0 && strcmp(tab[r], "ciseaux") == 0) {
            printf("Bravo\n");
            score++;
        }
        else if (strcmp(a, "ciseaux") == 0 && strcmp(tab[r], "papier") == 0) {
            printf("Bravo\n");
            score++;
        }
        else if (strcmp(a, "papier") == 0 && strcmp(tab[r], "pierre") == 0) {
            printf("Bravo\n");
            score++;
        }
        else if (a != tab[r]) {
            printf("Erreur\n");
        }
        else
        {
            printf("Dommage\n");
        }
    }

    printf("Score final: %d\n",score);

}
