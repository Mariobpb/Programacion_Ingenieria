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

void ingresarPersona(datosP *p);
void mostrarPersona(datosP p);

int main()
{

    int numDatosP;
    printf("Cuántas personas desea ingresar? ");
    scanf("%d", &numDatosP);

    datosP *personas = malloc(numDatosP * sizeof(datosP));
    if (personas == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Ingresar personas
    for (int i = 0; i < numDatosP; i++)
    {
        printf("\nPersona #%d\n", i + 1);
        ingresarPersona(&personas[i]);
    }

    FILE *arc = fopen("C:\\Users\\mario\\OneDrive\\Documentos\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\Ejercicios_clase\\13_11_2025_v2\\archivito.bin", "wb");
    if (!arc)
    {
        printf("Error\n");
        return 1;
    }
    fwrite(personas, sizeof(datosP), numDatosP, arc);
    fclose(arc);
    free(personas);

    arc = fopen("C:\\Users\\mario\\OneDrive\\Documentos\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\Ejercicios_clase\\13_11_2025_v2\\archivito.bin", "rb");
    if (!arc)
    {
        printf("Error\n");
        return 1;
    }

    int datosPLeidos;
    fread(&datosPLeidos, sizeof(int), 1, arc);

    // Arreglo dinámico para lo leído
    datosP *leidos = malloc(datosPLeidos * sizeof(datosP));
    if (leidos == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    fread(leidos, sizeof(datosP), datosPLeidos, arc);
    fclose(arc);

    // Mostrar datos
    printf("\n\n--- DATOS LEÍDOS DEL ARCHIVO ---\n");
    for (int i = 0; i < datosPLeidos; i++)
    {
        mostrarPersona(leidos[i]);
    }

    free(leidos);

    return 0;
}

void ingresarPersona(datosP *p)
{
    getchar(); // limpiar buffer
    printf("Nombre: ");
    fgets(p->name, 25, stdin);

    printf("Apellido: ");
    fgets(p->lastname, 25, stdin);

    printf("Correo: ");
    fgets(p->email, 30, stdin);

    printf("Edad: ");
    scanf("%d", &p->age);
}

void mostrarPersona(datosP p)
{
    printf("\nNombre: %s", p.name);
    printf("Apellido: %s", p.lastname);
    printf("Correo: %s", p.email);
    printf("Edad: %d\n", p.age);
}
