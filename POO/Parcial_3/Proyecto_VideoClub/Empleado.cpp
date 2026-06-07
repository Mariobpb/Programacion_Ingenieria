#include <iostream>
#include <string>

#include "Persona.cpp"

using namespace std;

class Empleado : public Persona, public Mostrable
{
private:
    int empleadoID;
    double salarioBase; // Valor fijo: 2000
    double comision;

public:
    Empleado();
    Empleado(string nombre, string domicilio, int telefono, string RFC, int empleadoID);
    ~Empleado();


    int getEmpleadoID();
    void getEmpleadoID(int);

    double getSalarioBase();
    void getSalarioBase(double);

    double getComision();
    void getComision(double);

    
    double calcularSalario();
    void agregarComision(double);
    void mostrarInfo() override;
};