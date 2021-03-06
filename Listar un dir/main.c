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
    char nombreArchivo[50];
		void renameFiles(char *archivo, char *dirn);
    const char * toUpperCase(char *archivo);
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
            renameFiles(drnt->d_name, &dirn);
        }
        closedir(dir);
    }
    else{
        printf("No se puede abrir el archivo '%s'\n", dirn, "\n");
    }
    system ("\n PAUSE");
	return 0;
}

void renameFiles(char *archivo, char *dirn)
{
	FILE *file;
	file = fopen(archivo, "w");
	char *nuevoNombre = toUpperCase(archivo);
	printf("archivo en mayus: %s ", *nuevoNombre);
	if(rename(archivo, *nuevoNombre)==0) /* Renombramos el archivo */
        printf("El archivo se renombro satisfactoriamente\n");
    else
        printf("No se pudo renombrar el archivo\n");
}


const char * toUpperCase(char *file_name)
{
  char * name;
  name = strtok(file_name,":");

  // Convert to upper case
  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }
	return name;
}
