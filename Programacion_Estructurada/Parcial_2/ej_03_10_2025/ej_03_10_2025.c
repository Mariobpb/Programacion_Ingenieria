#include <stdio.h>

void leerCadena(char *cad);
void mostrarCantPalabras(char *cad);

int main()
{
    char cad[50];
    leerCadena(cad);
    mostrarCantPalabras(cad);
    return 0;
}

void leerCadena(char *cad)
{
    printf("Ingrese una cadena:\n");
    fgets(cad, 50, stdin);
}
int contarPalabras(char *cad)
{
    int i = 0, palabras = 0, palabraIniciada = 0;
    while (cad[i] != '\n')
    {
        if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z'))
            palabraIniciada = 1;
        if (cad[i+1] == ' ' || cad[i+1] == '\0'){
            pa
        }
    }
    return palabras;
}
void mostrarCantPalabras(char *cad)
{
    printf("%s", cad);
}