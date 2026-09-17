#include <stdio.h>

int main() {
    int base = 10;
    int altura = 6;
    int area = 0;
    
    asm volatile (
        "movl %[base], %%eax \n\t"
        "imull %[altura], %%eax \n\t"
        "sarl $1, %%eax \n\t"
        "movl %%eax, %[area] \n\t"
        
        : [area] "=r" (area)
        : [base] "r" (base),
          [altura] "r" (altura)
        : "eax", "cc"
    );
    
    printf("Base:   %d\n", base);
    printf("Altura: %d\n", altura);
    printf("Area: %d\n", area);

    return 0;
}