/*
Prototipo: float celsiusAFahrenheit(float c); Fórmula: °F = (°C × 1.8) + 32
*/

#include <stdio.h>

float celsiusAFahrenheit(float);

int main()
{
    float c = 26.5;
    printf("%.2f = %.2f°F\n", c, celsiusAFahrenheit(c));
    return 0;
}
float celsiusAFahrenheit(float c)
{
    return (c * 1.8) + 32;
}