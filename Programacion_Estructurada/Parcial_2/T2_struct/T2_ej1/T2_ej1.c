/*
Crea una estructura llamada Persona con los campos nombre, edad y altura. Declara una variable de
tipo Persona e imprime sus valores.
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
    Persona p;
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
    printf("Altura: %.2f metros\n", p.altura);
    return 0;
}
