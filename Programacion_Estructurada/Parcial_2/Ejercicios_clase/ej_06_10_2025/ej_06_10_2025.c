#include <stdio.h>

void leerCadena(char *, char *);
int main()
{

    char c[100], *cT;
    leerCadena(&c[0], c);
    cT = c;
    printf("%s", cT);
    return 0;
}
void leerCadena(char *cadena, char *c)
{
    // printf("\n%x  |  %x", cadena, c);
    fgets(cadena, 100, stdin);
}