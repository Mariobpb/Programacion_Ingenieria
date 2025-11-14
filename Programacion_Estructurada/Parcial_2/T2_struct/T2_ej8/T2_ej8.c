/*
Crea una función void cambiarEdad(Persona *p, int nuevaEdad) que modifique directamente el valor
de edad usando punteros.
*/

#include <stdio.h>

typedef struct
{
    char nombre[50];
    int edad;
    float altura;
} Persona;

void cambiarEdad(Persona *p, int nuevaEdad);

int main()
{
    Persona p = {"Mario", 25, 1.86};
    printf("Edad inicial: %d\n", p.edad);
    cambiarEdad(&p, 21);
    printf("Edad modificada: %d\n", p.edad);
    return 0;
}

void cambiarEdad(Persona *p, int nuevaEdad){
    p->edad = nuevaEdad;
}