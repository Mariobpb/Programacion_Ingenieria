#include <stdio.h>

void leerCadena(char *c);
void reemplazarEDtoNull(char *c);
void mostrarPalabras(char *c);
int contarPalabras(char *c);
int recorrerPalabra(char *c, int p);
int recorrerEspacios(char *c, int p);

int main()
{
    char cad[50];
    leerCadena(cad);
    mostrarPalabras(cad);
    return 0;
}

void leerCadena(char *c)
{
    printf("Ingrese una cadena:\n");
    fgets(c, 50, stdin);
    reemplazarEDtoNull(c);
}
void reemplazarEDtoNull(char *c)
{
    int i = 0;
    while (c[i] != '\n')
        i++;
    c[i] = '\0';
}
void mostrarPalabras(char *c)
{
    printf("El texto tiene %d palabras", contarPalabras(c));
}
int contarPalabras(char *c)
{
    int numPal = 0, i = 0;
    while (c[i] != '\0')
    {
        i = recorrerEspacios(c, i);
        int aux = i;
        i = recorrerPalabra(c, i);
        if (i != aux)
            numPal++;
    }
    return numPal;
}
int recorrerEspacios(char *c, int p)
{
    while (c[p] != '\0' && c[p] == ' ')
        p++;
    return p;
}
int recorrerPalabra(char *c, int p)
{
    while (c[p] != ' ' && c[p] != '\0')
        p++;
    return p;
}