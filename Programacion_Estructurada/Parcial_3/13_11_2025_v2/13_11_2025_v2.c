#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[25];
    char lastname[25];
    char email[30];
    int age;

} datosP;

void ingresarPersona(datosP *);
void mostrarPersona(datosP p);

int main()
{
    datosP *persona, *personasLeidas;
    FILE *arc;
    int numPersona = 3;
    persona = malloc(numPersona * sizeof(datosP));
    for (int i = 0; i < numPersona; i++)
    {
        printf("\n\nPersona #%d", i+1);
        ingresarPersona(persona);
        persona++;
    }

    arc = fopen("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\13_11_2025_v2\\archivito.bin", "wb");

    fwrite(&persona, sizeof(datosP), numPersona, arc);
    fclose(arc);

    arc = fopen("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\13_11_2025_v2\\archivito.bin", "rb");

    int t = fread(personasLeidas, sizeof(datosP), numPersona, arc);
    fclose(arc);

    printf("\n-------------------------------------------Datos del archivo----------------------------------------\n");
    for (int i = 0; i < t; i++)
    {
        mostrarPersona(personasLeidas[i]);
    }
}

void ingresarPersona(datosP *p)
{
    printf("\n\nNombre: ");
    fgets(p->name, 25, stdin);
    printf("Apellido: ");
    fgets(p->lastname, 25, stdin);
    printf("Correo: ");
    fgets(p->email, 30, stdin);
    printf("Edad: ");
    scanf(" %d", &p->age);
    getchar();
}
void mostrarPersona(datosP p)
{
    printf("\nNombre: |%s|", p.name);
    printf("Apellido: |%s|", p.lastname);
    printf("Correo: |%s|", p.email);
    printf("Edad: |%d|\n", p.age);
}