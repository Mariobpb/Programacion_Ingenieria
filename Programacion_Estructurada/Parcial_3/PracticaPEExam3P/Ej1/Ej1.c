/*
1. Registrar N estudiantes y mostrarlos (Funciones + Estructuras)

Crea una estructura Estudiante con nombre, edad y promedio.
En el main, pide al usuario cuántos estudiantes ingresará.
Usa una función para capturar los datos de cada estudiante y otra para imprimirlos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

void capturarDatosEstudiante(Estudiante *);
void mostrarEstudiante(Estudiante);

int main()
{
    Estudiante *estudiantes;
    int numEstudiantes;
    printf("Ingrese la cantidad de estudiante: ");
    scanf("%d", &numEstudiantes);
    getchar();
    estudiantes = malloc(sizeof(Estudiante) * numEstudiantes);
    for (int i = 0; i < numEstudiantes; i++)
    {
        printf("\n\n---------------------Estudiante #%d---------------------\n", i+1);
        capturarDatosEstudiante(&estudiantes[i]);
    }
    printf("\n===========================================IMPRIMIENDO===========================================\n");
    for (int i = 0; i < numEstudiantes; i++)
    {
        printf("\n\n---------------------Estudiante #%d---------------------\n", i+1);
        mostrarEstudiante(estudiantes[i]);
    }
}

void capturarDatosEstudiante(Estudiante *es)
{
    printf("\nNombre: ");
    fgets(es->nombre, 50, stdin);
    es->nombre[strcspn(es->nombre, "\n")] = '\0';
    printf("\nEdad: ");
    scanf("%d", &es->edad);
    getchar();
    printf("\nPromedio: ");
    scanf("%f", &es->promedio);
    getchar();
}

void mostrarEstudiante(Estudiante es){
    printf("\n%s", es.nombre);
    printf("\n%d", es.edad);
    printf("\n%.2f", es.promedio);
}