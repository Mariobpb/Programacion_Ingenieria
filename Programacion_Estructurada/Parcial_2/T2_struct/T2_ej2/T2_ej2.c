/*
Usa el typedef struct del ejercicio anterior, pero ahora inicializa una persona con datos específicos (por
ejemplo, 'Luis', 25, 1.75) y muestra sus datos.
*/

#include <stdio.h>

typedef struct
{
    char nombre[50];
    int edad;
    float altura;
} Persona;

int main()
{
    Persona p = {"Mario", 21, 1.86};
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d anios\n", p.edad);
    printf("Altura: %.2fm\n", p.altura);
    return 0;
}