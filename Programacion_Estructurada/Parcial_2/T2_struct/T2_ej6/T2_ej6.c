/*
Declara un arreglo de 5 estructuras Persona e inicializa cada elemento. Luego, muestra en pantalla el
nombre de la persona con mayor edad.
*/

#include <stdio.h>

typedef struct
{
    char nombre[50];
    int edad;
    float altura;
} Persona;

void ingresarPersona(Persona *p);
Persona personaMayor(Persona ps[], int n);

int main()
{
    Persona personas[5];
    for (int i = 0; i < 5; i++)
        ingresarPersona(&personas[i]);
    printf("La persona mayor es: %s\n", personaMayor(personas, 5).nombre);
    return 0;
}

void ingresarPersona(Persona *p){
    printf("Nombre: ");
    scanf("%s", p->nombre);
    printf("Edad: ");
    scanf("%d", &p->edad);
    printf("Altura: ");
    scanf("%f", &p->altura);
}
Persona personaMayor(Persona ps[], int n){
    Persona mayor = ps[0];
    for (int i = 1; i < n; i++)
    {
        if (ps[i].edad > mayor.edad)
            mayor = ps[i];
    }
    return mayor;
}