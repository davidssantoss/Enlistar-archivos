#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
*
*@author: David s.
*
*/

int main(int argc, char *argv[]) {
	/* Arreglo de caracteres en donde se introduce la ruta del directorio*/
	char dirn[50];
	/*Un tipo que de dato que representa la secuencia/flujo de un directorio*/
    DIR *dir = NULL;
    /** Estructura  del tipo dirent
    
    *struct dirent{
	*	long		d_ino;		 Always zero. 
	*	unsigned short	d_reclen;	 Always zero. 
	*	unsigned short	d_namlen;	 Length of name in d_name. 
	*	char		d_name[260];  [FILENAME_MAX] */ /* File name. 
	*}; 
	*/
    struct dirent *drnt = NULL;

    printf("Digite la ruta del directorio: ");
    /*obtiene el valor digitado de la ruta*/
    gets(dirn);
    
	/*utiliza la funcion opendir para abrir la ruta de un directorio */
    dir=opendir(dirn); /*asigna dir la ruta ya digitada*/
    if(dir){
        printf("Salida:\n");
        while(drnt = readdir(dir)){
            printf("%-10s\t", drnt->d_name, "\n"); /* imprime los archivos del directorio*/
        }
        closedir(dir);
    }
    else{
        printf("No se puede abrir el archivo '%s'\n", dirn, "\n");
    }
    system ("\n PAUSE");
	return 0;
}
