/*
usando la funcion 
malloc

1.para leer una cadena , que debe ser guardada en el puntero usado en malloc.
2.agustar la memoria usada por el size de la cadena, mediante un segundo puntero al cual se le asigna memoria para exactamente el size de la cadena.
3.copiar el contenido de la primer memoria a la segunda memoria.
4.imprimir el contenido de la segunda memoria posicion por posicion 
5.liberar ambas memorias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *cad, *cadC;
    cad = (char *)malloc(100 * sizeof(char));
    if (cad == NULL) {
        printf("Error");
        return 1;
    }

    printf("Ingrese una cadena: ");
    fgets(cad, 100, stdin);
    cad[strcspn(cad, "\n")] = '\0';
    
    cadC = (char *)malloc(strlen(cad) + 1 * sizeof(char));
    if (cadC == NULL) {
        printf("Error");
        free(cad);
        return 1;
    }

    strcpy(cadC, cad);

    for (int i = 0; i <= strlen(cadC) - 1; i++) {
        printf("cadena[%d] = %c\n", i, cad[i]);
    }
    
    free(cad);
    free(cadC);

    return 0;
}
