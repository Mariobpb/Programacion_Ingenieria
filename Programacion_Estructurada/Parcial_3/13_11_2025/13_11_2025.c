#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *cad, *cadC;
    cad = malloc(50 * sizeof(char));
    printf("\n\nIntroduzca Cadena ");
    fgets(cad, 50, stdin);
    cadC = malloc(strlen(cad) * sizeof(char));
    strcpy(cadC, cad);
    printf("\nCadena: |%s|\nCadenaC: |%s|", cad, cadC);
    free(cad);
    free(cadC);
}