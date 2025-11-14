/*
Modifica la estructura Persona y escribe un programa que solicite los datos al usuario (scanf) y luego
los muestre en pantalla.
*/

#include <stdio.h>

typedef struct
{
    char nombre[50];
    int edad;
    float altura;
} Persona;

void ingresarPersona(Persona *p);
void mostrarPersona(Persona p);

int main()
{
    Persona p;
    ingresarPersona(&p);
    mostrarPersona(p);
    return 0;
}

void ingresarPersona(Persona *p){
    printf("Ingrese nombre: ");
    scanf("%s", p->nombre);
    printf("Edad: ");
    scanf("%d", &p->edad);
    printf("Altura: ");
    scanf("%f", &p->altura);
}

void mostrarPersona(Persona p){
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d anios\n", p.edad);
    printf("Altura: %.2fm\n", p.altura);
}