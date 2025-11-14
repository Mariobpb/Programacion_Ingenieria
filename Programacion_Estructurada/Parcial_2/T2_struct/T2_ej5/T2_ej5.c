/*
Crea un typedef struct llamado Alumno con los campos char nombre[30] y float calificaciones[3]. Luego
calcula el promedio de las tres calificaciones con una función.
*/

#include <stdio.h>

typedef struct
{
    char nombre[30];
    float calificaciones[3];
} Alumno;

float calcularPrm(Alumno a);

int main()
{
    Alumno a = {"Mario", {93, 70, 85}};
    printf("Promedio: %.2f\n", calcularPrm(a));
    return 0;
}

float calcularPrm(Alumno a)
{
    float suma = 0;
    for (int i = 0; i < 3; i++)
        suma += a.calificaciones[i];
    return suma / 3;
}