#include <iostream>
#include <string>
#include <vector>
// Incluir las clases que implementan la interfaz
#include "DispositivoElectronico.cpp"
#include "Telefono.cpp"
#include "Laptop.cpp"
#include "Tablet.cpp"

using namespace std;
int main()
{
    // Crear un vector de punteros a la interfaz
    vector<DispositivoElectronico *> dispositivos = {
        new Telefono("Samsung"),
        new Laptop("HP Pavilion"),
        new Tablet(10.5)};
    // Encender y mostrar estado
    cout << "=== Encendiendo dispositivos ===" << endl;
    for (DispositivoElectronico *dispositivo : dispositivos)
    {
        dispositivo->encender();
        dispositivo->mostrarEstado();
    }

    cout << "\n=== Apagando dispositivos ===" << endl;
    // Apagar y mostrar estado
    for (DispositivoElectronico *dispositivo : dispositivos)
    {
        dispositivo->apagar();
        dispositivo->mostrarEstado();
    }

    // Liberar memoria
    for (DispositivoElectronico *dispositivo : dispositivos)
    {
        delete dispositivo;
    }
    return 0;
}