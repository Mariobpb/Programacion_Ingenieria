/*
Crea una función void mostrarPersona(Persona p) que reciba una estructura Persona e imprima sus
campos.
*/

#include <stdio.h>

typedef struct
{
    char nombre[50];
    int edad;
    float altura;
} Persona;

void mostrarPersona(Persona p);

int main()
{
    Persona p = {"Mario", 21, 1.86};
    mostrarPersona(p);
    return 0;
}

void mostrarPersona(Persona p){
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d anios\n", p.edad);
    printf("Altura: %.2fm\n", p.altura);
}