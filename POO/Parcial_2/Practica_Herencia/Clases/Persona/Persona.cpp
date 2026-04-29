#include "Persona.h"
#include <iostream>

using namespace std;

string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

string Persona::getCarrera() {
    return carrera;
}

string Persona::getEstatus() {
    return estatus;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setCarrera(string carrera) {
    this->carrera = carrera;
}

void Persona::setEstatus(string estatus) {
    this->estatus = estatus;
}