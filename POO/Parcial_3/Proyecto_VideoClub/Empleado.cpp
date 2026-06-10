#pragma once
#include <iostream>
#include <string>

#include "Persona.cpp"

using namespace std;

class Empleado : public Persona
{
private:
    static int contadorEmpleados;
    int empleadoID;
    double salarioBase;
    double comision;

public:
    Empleado();
    Empleado(string nombre, string domicilio, int telefono, string RFC);
    ~Empleado();

    int getEmpleadoID();
    void setEmpleadoID(int);

    double getSalarioBase();
    void setSalarioBase(double);

    double getComision();
    void setComision(double);

    double calcularSalario();
    void agregarComision(double);
    void mostrarInfo() override;
};

int Empleado::contadorEmpleados = 0;

Empleado::Empleado() : Persona()
{
    Empleado::contadorEmpleados++;
    this->empleadoID = Empleado::contadorEmpleados;
    this->salarioBase = 2000;
    this->comision = 0;
}

Empleado::Empleado(string nombre, string domicilio, int telefono, string RFC) : Persona(nombre, domicilio, telefono, RFC)
{
    Empleado::contadorEmpleados++;
    this->empleadoID = Empleado::contadorEmpleados;
    this->salarioBase = 2000;
    this->comision = 0;
}

Empleado::~Empleado() {}

int Empleado::getEmpleadoID()
{
    return this->empleadoID;
}
void Empleado::setEmpleadoID(int id)
{
    this->empleadoID = id;
}

double Empleado::getSalarioBase()
{
    return this->salarioBase;
}
void Empleado::setSalarioBase(double salario)
{
    this->salarioBase = salario;
}

double Empleado::getComision()
{
    return this->comision;
}
void Empleado::setComision(double comision)
{
    this->comision = comision;
}

double Empleado::calcularSalario()
{
    return this->salarioBase + this->comision;
}
void Empleado::agregarComision(double monto)
{
    this->comision += monto;
}

void Empleado::mostrarInfo()
{
    impColor(string("\n\tID:               ") + to_string(getEmpleadoID()), VERDE);
    impColor(string("\n\tNombre:           ") + getNombre(), VERDE);
    impColor(string("\n\tDomicilio:        ") + getDomicilio(), VERDE);
    impColor(string("\n\tTelefono:         ") + to_string(getTelefono()), VERDE);
    impColor(string("\n\tRFC:              ") + getRFC(), VERDE);
    impColor(string("\n\tSalario Base:    $") + to_string(getSalarioBase()), VERDE);
    impColor(string("\n\tComisiones:      $") + to_string(getComision()), VERDE);
    impColor(string("\n\tSalario Total:   $") + to_string(calcularSalario()), VERDE);
}