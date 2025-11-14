/*
Ejemplo: 5! = 5 × 4 × 3 × 2 × 1 = 120. Prototipo: long factorial(int n);
*/

#include <stdio.h>

long factorial(int);

int main()
{
    int num = 10;
    printf("%d! = %ld\n", num, factorial(num));
    return 0;
}

long factorial(int n){
    long res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}