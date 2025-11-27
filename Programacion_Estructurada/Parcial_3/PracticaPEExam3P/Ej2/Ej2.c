/*
Ej2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rutaPersonasBin[] = "C:\\Users\\mario\\OneDrive\\Documentos\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\PracticaPEExam3P\\Ej2\\archivo.bin";
char rutaPersonasTxt[] = "C:\\Users\\mario\\OneDrive\\Documentos\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\PracticaPEExam3P\\Ej2\\archivo.txt";

typedef struct
{
    char nombre[50];
    char correo[50];
    int edad;
    int registro;
} Persona;

void ingresarPersona(Persona *p);
void mostrarLista(Persona *lista, int n);
void guardarArchivoBin(char *path, Persona *lista, int n);
void guardarArchivoTxt(char *path, Persona *lista, int n);
Persona *leerArchivoBin(char *path, int *n);
Persona *leerArchivoTxt(char *path, int *n);
int numPersonasArchivo(char *path);
void mostrarArchivo(char *path);

int main()
{
    int n = 0;
    Persona *lista;

    printf("Cantidad de personas: ");
    scanf("%d", &n);
    getchar();

    lista = malloc(n * sizeof(Persona));

    for (int i = 0; i < n; i++)
    {
        printf("\nPersona #%d\n", i + 1);
        ingresarPersona(&lista[i]);
    }

    guardarArchivoBin(rutaPersonasBin, lista, n);

    int opcion;
    do
    {
        printf("\n\n1. Mostrar lista completa (desde archivo)");
        printf("\n2. Agregar Persona");
        printf("\n3. Actualizar archivo txt");
        printf("\n0. Salir\nOpcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
            mostrarLista(lista, n);
            break;
        case 2:
            /* code */
            break;
        default:
            break;
        }
    } while (opcion != 0);

    free(lista);
    free(listaDesdeArchivo);

    return 0;
}

void ingresarPersona(Persona *p)
{
    printf("Nombre: ");
    fgets(p->nombre, 50, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    printf("Correo: ");
    fgets(p->correo, 50, stdin);
    p->correo[strcspn(p->correo, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &p->edad);
    getchar();

    printf("Registro: ");
    scanf("%d", &p->registro);
    getchar();
}

void mostrarLista(Persona *lista, int n)
{
    printf("\n------------------------- PERSONAS -------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNombre: %s", lista[i].nombre);
        printf("\nCorreo: %s", lista[i].correo);
        printf("\nEdad: %d", lista[i].edad);
        printf("\nRegistro: %d\n", lista[i].registro);
    }
}

void guardarArchivoBin(char *path, Persona *lista, int n)
{
    FILE *f = fopen(path, "wb");
    if (!f)
    {
        printf("Error al guardar\n");
        return;
    }
    fwrite(lista, sizeof(Persona), n, f);
    fclose(f);
}

Persona *leerArchivoBin(char *path, int *n)
{
    FILE *f = fopen(path, "rb");
    if (!f)
    {
        printf("Error al leer dirección: %s\n", path);
        return NULL;
    }
    Persona *lista = malloc((*n) * sizeof(Persona));
    fread(lista, sizeof(Persona), *n, f);
    fclose(f);
    return lista;
}
