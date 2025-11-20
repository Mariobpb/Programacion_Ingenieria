#include <stdio.h>

int main()
{
    char cad[50], cad2;
    printf("\n\nIngrese cadena\n");
    fgets(cad, 50, stdin);
    FILE *f;
    f = fopen("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\archivos_07_11_2025\\archivito.txt", "w");
    int i = 0;
    while (cad[i] != '\n')
    {
        if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z'))
            fputc(cad[i], f);
        i++;
    }
    fclose(f);
    f = fopen("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\archivos_07_11_2025\\archivito.txt", "r");
    while ((cad2 = fgetc(f)) != EOF){
        printf("%c", cad2);
    }
    fclose(f);
    return 0;
}