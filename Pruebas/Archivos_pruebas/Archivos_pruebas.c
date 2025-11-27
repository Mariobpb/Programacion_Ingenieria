#include <stdio.h>
#include <stdlib.h>

void guardarArchivo(char *, int *, int);
void leerArchivo(char *, int *, int);

int main()
{
    int nums[50];
    for (int i = 0; i < 50; i++)
        nums[i] = rand();
    guardarArchivo("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Pruebas\\Archivos_pruebas\\arc.bin", nums, 50);
    leerArchivo
}
void guardarArchivo(char *path, int *array, int n)
{
    FILE *f;
    fopen(path, "wb");
    fwrite(array, sizeof(int), n, f);
    fclose(f);
}
void leerArchivo(char *path, int *array, int n)
{
    FILE *f;
    fopen(path, "rb");
    fseek(f, 1, 1);
    fread
    fclose(f);
}
