/*
Usa un arreglo de caracteres (string). Prototipo: void invertirCadena(char texto[]); Debe mostrar la
cadena invertida, por ejemplo: 'Hola' → 'aloH'.
*/

#include <stdio.h>

void invertirCadena(char texto[]);

int main()
{
    char cad[100];
    printf("Ingrese una cadena de texto: ");
    fgets(cad, 100, stdin);
    invertirCadena(cad);
    return 0;
}

void invertirCadena(char texto[])
{
    int i = 0;
    while (texto[i] != '\0' && texto[i] != '\n')
        i++;
    i--;
    printf("Cadena invertida: ");
    while (i >= 0)
    {
        printf("%c", texto[i]);
        i--;
    }
    printf("\n");
}
