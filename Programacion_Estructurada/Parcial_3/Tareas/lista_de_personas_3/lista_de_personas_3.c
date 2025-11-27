/*
25310234 - Mario Bernardo Ponce Barrios

aplicar la tecnica del ejercicio "memoria dinamica 2" al ejercicio "lista de personas 2".

las personas que coincidan con la busqueda deberan guardarlas en un nuevo archivo.

mostrar el contenido del archivo que contiene las personas encontradas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rutaPersonas[] = "C:\\Users\\mario\\OneDrive\\Documentos\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\Tareas\\lista_de_personas_3\\personas.bin";
char rutaPersonasBuscadas[] = "C:\\Users\\mario\\OneDrive\\Documentos\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\Tareas\\lista_de_personas_3\\personas_buscadas.bin";

typedef struct {
    char nombre[50];
    char correo[50];
    int edad;
    int registro;
} Persona;

void ingresarPersona(Persona *p);
void mostrarLista(Persona *lista, int n);
int buscar(Persona *lista, int n, Persona **resultados);
void guardarArchivo(char *nombre, Persona *lista, int n);
Persona* leerArchivo(char *nombre, int *n);
void mostrarArchivo(char *nombre);

int main() {

    int n;
    Persona *lista = NULL;
    Persona *listaDesdeArchivo = NULL;
    Persona *listaBuscada = NULL;

    printf("Cantidad de personas: ");
    scanf("%d", &n);
    getchar();
    
    lista = malloc(n * sizeof(Persona));

    for (int i = 0; i < n; i++) {
        printf("\nPersona #%d\n", i + 1);
        ingresarPersona(&lista[i]);
    }
    
    guardarArchivo(rutaPersonas, lista, n);
    
    int n2 = 0;
    listaDesdeArchivo = leerArchivo(rutaPersonas, &n2);

    int opcion;
    do {
        printf("\n\n1. Mostrar lista completa (desde archivo)");
        printf("\n2. Buscar personas");
        printf("\n0. Salir\nOpcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1) {
            mostrarLista(listaDesdeArchivo, n2);
        }
        else if (opcion == 2) {
            int encontrados = buscar(listaDesdeArchivo, n2, &listaBuscada);

            if (encontrados > 0) {
                int nBuscadas = 0;
                guardarArchivo(rutaPersonasBuscadas, listaBuscada, encontrados);
                Persona *personasBuscadas = leerArchivo(rutaPersonasBuscadas, &nBuscadas);
                mostrarLista(personasBuscadas, nBuscadas);
                free(personasBuscadas);
            }
            free(listaBuscada);
        }

    } while (opcion != 0);

    free(lista);
    free(listaDesdeArchivo);

    return 0;
}

void ingresarPersona(Persona *p) {
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

void mostrarLista(Persona *lista, int n) {
    printf("\n------------------------- PERSONAS -------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("\nNombre: %s", lista[i].nombre);
        printf("\nCorreo: %s", lista[i].correo);
        printf("\nEdad: %d", lista[i].edad);
        printf("\nRegistro: %d\n", lista[i].registro);
    }
}

int buscar(Persona *lista, int n, Persona **resultados) {
    int opcion;
    char texto[50];
    int num;

    *resultados = NULL;
    int encontrados = 0;
    printf("\n------------------------- BUSCAR POR -------------------------\n");
    printf("1. Nombre\n");
    printf("2. Correo\n");
    printf("3. Edad\n");
    printf("4. Registro\nOpcion: ");
    scanf("%d", &opcion);
    getchar();
    if (opcion == 1 || opcion == 2) {
        printf("Texto a buscar: ");
        fgets(texto, 50, stdin);
        texto[strcspn(texto, "\n")] = '\0';
    } else {
        printf("Numero a buscar: ");
        scanf("%d", &num);
        getchar();
    }
    for (int i = 0; i < n; i++) {
        int coincide = 0;
        if (opcion == 1 && strcmp(lista[i].nombre, texto) == 0) coincide = 1;
        if (opcion == 2 && strcmp(lista[i].correo, texto) == 0) coincide = 1;
        if (opcion == 3 && lista[i].edad == num) coincide = 1;
        if (opcion == 4 && lista[i].registro == num) coincide = 1;

        if (coincide) {
            encontrados++;
            *resultados = realloc(*resultados, encontrados * sizeof(Persona));
            (*resultados)[encontrados - 1] = lista[i];
        }
    }
    if (encontrados == 0)
        printf("No se encontraron coincidencias.\n");

    return encontrados;
}

void guardarArchivo(char *arc, Persona *lista, int n) {
    FILE *f = fopen(arc, "wb");
    if (!f) {
        printf("Error al guardar\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, f);
    fwrite(lista, sizeof(Persona), n, f);
    fclose(f);
}

Persona* leerArchivo(char *arc, int *n) {
    FILE *f = fopen(arc, "rb");
    if (!f) {
        printf("Error al leer dirección: %s\n", arc);
        return NULL;
    }
    fread(n, sizeof(int), 1, f);
    Persona *lista = malloc((*n) * sizeof(Persona));
    fread(lista, sizeof(Persona), *n, f);
    fclose(f);
    return lista;
}
