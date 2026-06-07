#include <iostream>
#include <string>
#include <vector>

#include "Producto.cpp"
#include "Persona.cpp"

using namespace std;

string contrasena = "A25310234";

#define LIMPIAR "\033[2J\033[H"
#define RESET "\033[0m"
#define BLANCO "\033[97m"
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AMARILLO "\033[93m"
#define AZUL "\033[34m"
#define CIAN "\033[96m"

class Menu
{
private:
    vector<Producto *> productos;
    vector<Persona *> personas;

public:
    bool validarContrasena();

    void menuPrincipal();
    void menuPeliculaVideojuego();
    void menuCliente();
    void menuEmpleado();
    void menuVentaRenta(int clienteID, int empleadoID);
};

bool Menu::validarContrasena()
{
    string contrasenaIngresada;
    cout << RESET << LIMPIAR << AMARILLO << "Ingrese la contrasenia del sistema: " << BLANCO;
    cin >> contrasenaIngresada;
    if (contrasenaIngresada != contrasena)
        return true;
    return false;
}
void Menu::menuPrincipal()
{
    int opcion;
    while (validarContrasena());
    do
    {
        cout << LIMPIAR << AMARILLO << "\n\n================================= ENTRETENIMIENTO FELIZ =================================\n\n"
             << RESET;
        cout << CIAN << "\n=============== MENU PRINCIPAL ===============\n\n"
         << RESET;
        cout << AZUL << "\n\t1. CLIENTES";
        cout << "\n\t2. PELICULAS Y VIDEOJUEGOS";
        cout << "\n\t3. EMPLEADOS";
        cout << "\n\t4. REALIZAR RENTA/VENTA";
        cout << "\n\t5. SALIR DEL SISTEMA" << RESET;
        cout << AMARILLO << "\n\nIngrese su opcion: " << BLANCO;
        cin >> opcion;
        cout << RESET;

        switch (opcion)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    } while (opcion != 5);
}