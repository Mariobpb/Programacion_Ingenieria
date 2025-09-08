/*
Ejercicio 5: Media, mayor y menor de un conjunto fijo.
Realizar un programa que pida las notas de 40 alumnos por pantalla y muestre un menú
de opciones: 1. Listar notas, 2.Calcular la media, 3.Calcular el menor, 4.Calcular el
mayor.
*/

#include <stdio.h>

int cantAlumnos = 40;

void listarNotas(int *cals);
float calcularMedia(int *cals);
int calcularMenor(int *cals);
int calcularMayor(int *cals);

int main()
{
    int calificaciones[cantAlumnos], opcion;
    for (int i = 0; i < cantAlumnos; i++)
    {
        printf("Ingrese la calificacion del alumno #%d: ", i + 1);
        scanf("%d", &calificaciones[i]);
    }
    do
    {
        printf("\n\nQué desea hacer?\n1. Listar notas, 2.Calcular la media, 3.Calcular el menor, 4.Calcular el mayor, 5.Salir:  ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            listarNotas(calificaciones);
            break;
        case 2:
            printf("\nMedia de calificaciones: %.2f\n", calcularMedia(calificaciones));
            break;
        case 3:
            printf("\nMenor calificacion: %d\n", calcularMenor(calificaciones));
            break;
        case 4:
            printf("\nMayor calificacion: %d\n", calcularMayor(calificaciones));
            break;
        default:
            break;
        }
    } while (opcion != 5);

    return 0;
}

void listarNotas(int *cals)
{
    printf("\nNotas:\n");
    for (int i = 0; i < cantAlumnos; i++)
    {
        printf("\nAlumno #%d: %d", i + 1, cals[i]);
    }
}
float calcularMedia(int *cals)
{
    float res = 0;
    for (int i = 0; i < cantAlumnos; i++)
        res += cals[i];
    return res / (float)cantAlumnos;
}
int calcularMenor(int *cals)
{
    int numMenor = cals[0];
    for (int i = 0; i < cantAlumnos; i++)
    {
        if (cals[i] < numMenor)
            numMenor = cals[i];
    }
    return numMenor;
}
int calcularMayor(int *cals)
{
    int numMayor = cals[0];
    for (int i = 0; i < cantAlumnos; i++)
    {
        if (cals[i] > numMayor)
            numMayor = cals[i];
    }
    return numMayor;
}