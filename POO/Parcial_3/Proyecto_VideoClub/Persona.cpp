#pragma once
#include <iostream>
#include <string>

#include "UI.cpp"
#include "Mostrable.cpp"

using namespace std;

class Persona : public Mostrable
{
protected:
    string nombre;
    string domicilio;
    int telefono;
    string RFC;

public:
    Persona();
    Persona(string nombre, string domicilio, int telefono, string RFC);
    virtual ~Persona();

    string getNombre();
    void setNombre(string);

    string getDomicilio();
    void setDomicilio(string);

    int getTelefono();
    void setTelefono(int);

    string getRFC();
    void setRFC(string);

    void mostrarInfo() override = 0;
};

Persona::Persona()
{
    this->nombre = "SIN ASIGNAR";
    this->domicilio = "SIN ASIGNAR";
    this->telefono = -1;
    this->RFC = "SIN ASIGNAR";
}

Persona::Persona(string nombre, string domicilio, int telefono, string RFC)
{
    this->nombre = nombre;
    this->domicilio = domicilio;
    this->telefono = telefono;
    this->RFC = RFC;
}

Persona::~Persona() {}

string Persona::getNombre()
{
    return this->nombre;
}
void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Persona::getDomicilio()
{
    return this->domicilio;
}
void Persona::setDomicilio(string domicilio)
{
    this->domicilio = domicilio;
}

int Persona::getTelefono()
{
    return this->telefono;
}
void Persona::setTelefono(int telefono)
{
    this->telefono = telefono;
}

string Persona::getRFC()
{
    return this->RFC;
}
void Persona::setRFC(string RFC)
{
    this->RFC = RFC;
}