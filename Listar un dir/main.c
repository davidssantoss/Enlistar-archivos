#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
*
*@author: David s.
*
**/

int main(int argc, char *argv[]) {
	char dirn[50];
    DIR *dir = NULL;
    struct dirent *drnt = NULL;

    printf("Digite la ruta del directorio: ");
    gets(dirn);
    

    dir=opendir(dirn);
    if(dir){
        printf("Salida:\n");
        while(drnt = readdir(dir)){
            printf("%-10s\t", drnt->d_name, "\n");
        }
        closedir(dir);
    }
    else{
        printf("No se puede abrir el archivo '%s'\n", dirn, "\n");
    }
    system ("PAUSE");
	return 0;
}
