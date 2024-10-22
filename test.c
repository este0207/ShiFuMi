#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // 1. Ouvrir le fichier avec fopen()
    FILE* file = fopen("mon_fichier", "w+"); // Ouvre un fichier en écriture et lecture
    
    if (file != NULL) {
        int age = 25;
        // 2. Lire le fichier avec fprintf()
        fprintf(file, "Salut le monde j'ai %d ans\n",age);

        char buf[255];
        memset(buf,0,255);

        // 3. Reposition le curseur du fichier au début pour pouvoir lire le fichier depuis le début
        fseek(file,0,SEEK_SET);

        // 4. Utiliser fread() pour lire le fichier
        fread(buf,1,255,file);

        // J'affiche le buf remplit par fread()
        printf("%s\n",buf);
        
        fclose(file); // 5. Ferme le fichier
    }
    return 0;
}