#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;

    printf("Introduce los siguientes valores:\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    if (a == 0) {
        printf("Solución indefinida");
    } else {
        float discriminante = (b*b) - (4*a*c);

        if (discriminante > 0) {
            float x1 = ((b*-1) + sqrt(discriminante)) / (2*a);
            float x2 = ((b*-1) - sqrt(discriminante)) / (2*a);
            printf("x1 = %.4f\n", x1);
            printf("x2 = %.4f", x2);
        }
        else if (discriminante == 0) {
            float x = (b*-1) / (2*a);
            printf("x = %.4f", x);
        }
        else {
            float real = (b*-1) / (2*a);
            float imaginaria = sqrt((discriminante*-1)) / (2*a);
            printf("x1 = %.4f + %.4fi\n", real, imaginaria);
            printf("x2 = %.4f - %.4fi", real, imaginaria);
        }

    }

    return 0;
}