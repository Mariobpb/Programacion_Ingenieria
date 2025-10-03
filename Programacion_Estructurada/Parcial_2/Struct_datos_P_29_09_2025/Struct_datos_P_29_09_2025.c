#include <stdio.h>

typedef struct
{
    char name[50];
    char email[50];
    char registro[12];
} datos_P;

datos_P ingresarDatos(void);
int verificarReg(char *r);
void mostrarDatos(datos_P p);

int main()
{
    datos_P grupo[3];
    for (int i = 0; i < 3; i++)
        grupo[i] = ingresarDatos();
    for (int i = 0; i < 3; i++)
        mostrarDatos(grupo[i]);

    return 0;
}
datos_P ingresarDatos(void)
{
    datos_P T;
    printf("nombre: ");
    fgets(T.name, 50, stdin);
    printf("email: ");
    fgets(T.email, 50, stdin);
    do
    {
        printf("registro: ");
        fgets(T.registro, 50, stdin);
    } while (!verificarReg(T.registro));

    return T;
}
int verificarReg(char *r)
{
    int i = 0;
    while (r[i] != '\n')
    {
        if (!((r[i] > '0') && (r[i] < '9')))
            return 0;
        i++;
    }
    return 1;
}
void mostrarDatos(datos_P p)
{
    printf("\nNombre: %sEdad: %sRegistro: %s\n", p.name, p.email, p.registro);
}