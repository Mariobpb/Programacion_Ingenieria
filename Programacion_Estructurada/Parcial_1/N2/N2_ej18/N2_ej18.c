/*
Ejercicio 18: Bucles con if 6. Ecuación de 2º grado.
Realizar un programa que pida los tres coeficientes de una ecuación de 2º grado y calcule
las dos soluciones aunque estas sean números imaginarios. Después de calcular las soluciones,
el programa dará la opción de seguir resolviendo ecuaciones: Continuar (pulse C)? / Salir (pulse
S)?.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2, discriminante;
    char opcion = 'C';
    do
    {
        printf("\nIntroduce los siguientes valores:\n");
        printf("a: ");
        scanf("%f", &a);
        printf("b: ");
        scanf("%f", &b);
        printf("c: ");
        scanf("%f", &c);

        if (a == 0)
            printf("Solución indefinida");
        else
        {
            discriminante = (b * b) - (4 * a * c);

            if (discriminante > 0)
            {
                x1 = ((b * -1) + sqrt(discriminante)) / (2 * a);
                x2 = ((b * -1) - sqrt(discriminante)) / (2 * a);
                printf("x1 = %.4f\n", x1);
                printf("x2 = %.4f", x2);
            }
            else if (discriminante == 0)
            {
                x1 = (b * -1) / (2 * a);
                printf("x = %.4f", x1);
            }
            else
            {
                float real = (b * -1) / (2 * a);
                float imaginaria = sqrt((discriminante * -1)) / (2 * a);
                printf("x1 = %.4f + %.4fi\n", real, imaginaria);
                printf("x2 = %.4f - %.4fi", real, imaginaria);
            }
        }
        printf("\nContinuar (pulse C)? / Salir (pulse S)?: ");
        scanf(" %c", &opcion);
    } while (opcion == 'C');

    return 0;
}
