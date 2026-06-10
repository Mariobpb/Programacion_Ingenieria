#pragma once
#include <iostream>
#include <limits>

using namespace std;

#define LIMPIAR "\033[2J\033[H"
#define RESET "\033[0m"
#define BLANCO "\033[97m"
#define ROJO "\033[31m"
#define MAGENTA "\033[95m"
#define VERDE "\033[32m"
#define AMARILLO "\033[93m"
#define AZUL "\033[34m"
#define CIAN "\033[96m"

void limpiarPantalla()
{
    cout << LIMPIAR << AMARILLO << "\n\n================================= ENTRETENIMIENTO FELIZ =================================\n\n"
         << RESET;
}
void impColor(string texto, string color)
{
    cout << RESET << color << texto << RESET;
}
void esperarEnter()
{
    impColor("\n\n\nPresione ENTER para continuar...", BLANCO);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
string leerString()
{
    string s;
    cout << BLANCO;
    cin >> s;
    cout << RESET;
    return s;
}
int leerInt()
{
    int i;
    cout << BLANCO;
    cin >> i;
    cout << RESET;
    return i;
}
double leerDouble()
{
    double d;
    cout << BLANCO;
    cin >> d;
    cout << RESET;
    return d;
}