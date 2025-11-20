/*
en escencia es lo mismo que el  ejercicio "memoria dinamica 1", solo que ahora debe usar 

realloc

para ajustar el espacio inicial , al espacio real ocupado por la cadena ingresada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *cad;
    int size;
    cad = (char *)malloc(100 * sizeof(char));
    if (cad == NULL) {
        printf("Error");
        return 1;
    }
    
    printf("Ingrese una cadena: ");
    fgets(cad, 100, stdin);

    cad[strcspn(cad, "\n")] = '\0';
    size = strlen(cad) + 1;
    
    cad = (char *)realloc(cad, size * sizeof(char));
    if (cad == NULL) {
        printf("Error");
        return 1;
    }
    
    printf("\nCadena:\n");
    for (int i = 0; i < size - 1; i++) {
        printf("cadena[%d] = %c\n", i, cad[i]);
    }
    free(cad);

    return 0;
}
