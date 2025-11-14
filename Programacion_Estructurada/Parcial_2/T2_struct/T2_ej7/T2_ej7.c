/*
Define typedef struct { int dia, mes, anio; } Fecha; y typedef struct { char nombre[30]; Fecha nacimiento;
} Persona; Luego pide al usuario ingresar una fecha de nacimiento e imprímela con formato
dd/mm/aaaa.
*/

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[30];
    Fecha nacimiento;
} Persona;

void ingresarPersona(Persona *p);
void ingresarFecha(Fecha *f);

int main()
{
    Persona p;
    ingresarPersona(&p);
    printf("\n%s\nFecha nacimiento: %d/%d/%d\n", p.nombre, p.nacimiento.dia, p.nacimiento.mes, p.nacimiento.anio);
    return 0;
}
void ingresarPersona(Persona *p){
    printf("Ingrese nombre: ");
    scanf("%s", p->nombre);
    ingresarFecha(&p->nacimiento);
}
void ingresarFecha(Fecha *f){
    printf("Dia: ");
    scanf("%d", &f->dia);
    printf("Mes: ");
    scanf("%d", &f->mes);
    printf("Anio: ");
    scanf("%d", &f->anio);
}