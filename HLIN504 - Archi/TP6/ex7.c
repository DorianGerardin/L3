#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int parcours(char* rep, int indent) {
    DIR * repCourant = opendir(rep);
    if (repCourant == NULL) {
        fprintf(stderr, "impossible d'ouvrir le répertoire : %s\n", rep);
        return -1;
    }
    char *chemin = (char *)malloc(1024);
    struct dirent *entree;
    struct stat etat;
    while ((entree = readdir(repCourant)) != NULL) {
        strcat(strcat(strcpy(chemin, rep), "/"), entree -> d_name);
        if(lstat(chemin, &etat) < 0) {
            fprintf()
        }
    }
    {
        /* code */
    }
    
}

int main(){

}