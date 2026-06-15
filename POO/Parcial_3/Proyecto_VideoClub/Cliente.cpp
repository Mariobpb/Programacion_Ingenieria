#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "Persona.cpp"
#include "Pelicula.cpp"
#include "Videojuego.cpp"

using namespace std;

class Cliente : public Persona
{
private:
    static int contadorClientes;
    int clienteID;
    int pelisRentadas;
    int videojuegosRentados;

public:
    Cliente();
    Cliente(string nombre, string domicilio, int telefono, string RFC);
    ~Cliente();

    int getClienteID();
    void setClienteID(int);

    int getPelisRentadas();
    void setPelisRentadas(int);

    int getVideojuegosRentados();
    void setVideojuegosRentados(int);

    bool verificarLimite(Pelicula *pelicula);
    bool verificarLimite(Videojuego *videojuego);

    void mostrarInfo() override;
};
int Cliente::contadorClientes = 0;

Cliente::Cliente()
{
    Cliente::contadorClientes++;
    this->clienteID = Cliente::contadorClientes;
    this->pelisRentadas = 0;
    this->videojuegosRentados = 0;
}
Cliente::Cliente(string nombre, string domicilio, int telefono, string RFC) : Persona(nombre, domicilio, telefono, RFC)
{
    Cliente::contadorClientes++;
    this->clienteID = Cliente::contadorClientes;
    this->pelisRentadas = 0;
    this->videojuegosRentados = 0;
}
Cliente::~Cliente()
{
}

int Cliente::getClienteID()
{
    return this->clienteID;
}
void Cliente::setClienteID(int clienteID)
{
    this->clienteID = clienteID;
}

int Cliente::getPelisRentadas()
{
    return this->pelisRentadas;
}
void Cliente::setPelisRentadas(int pelisRentadas)
{
    this->pelisRentadas = pelisRentadas;
}

int Cliente::getVideojuegosRentados()
{
    return this->videojuegosRentados;
}
void Cliente::setVideojuegosRentados(int videojuegosRentados)
{
    this->videojuegosRentados = videojuegosRentados;
}

bool Cliente::verificarLimite(Pelicula* pelicula) {
    return this->pelisRentadas < 2;
}
bool Cliente::verificarLimite(Videojuego* videojuego) {
    return this->videojuegosRentados < 2;
}

void Cliente::mostrarInfo()
{
    cout << fixed << setprecision(2);
    impColor(string("\n\tID:                     ") + to_string(getClienteID()), VERDE);
    impColor(string("\n\tNombre:                 ") + getNombre(), VERDE);
    impColor(string("\n\tDomicilio:              ") + getDomicilio(), VERDE);
    impColor(string("\n\tTelefono:               ") + to_string(getTelefono()), VERDE);
    impColor(string("\n\tRFC:                    ") + getRFC(), VERDE);
    impColor(string("\n\tPeliculas Rentadas:     ") + to_string(getPelisRentadas()), VERDE);
    impColor(string("\n\tVideojuegos Rentados:   ") + to_string(getVideojuegosRentados()), VERDE);
}