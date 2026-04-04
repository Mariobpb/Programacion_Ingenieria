#include <iostream>
using namespace std;

class Empleado
{
private:
    string nombre;
    string puesto;
    double pagoHora;
    double horasTrabajadasMes;
    double salarioMensual;

public:
    string getNombre();
    void setNombre(string nombre);
    string getPuesto();
    void setPuesto(string puesto);
    double getPagoHora();
    void setPagoHora(double pagoHora);
    double getHorasTrabajadasMes();
    void setHorasTrabajadasMes(double horasTrabajadasMes);
    double getSalarioMensual();
    void setSalarioMensual(double salarioMensual);

    void capturarDatosTrabajador();
    double obtenerSalarioMensual();
    void imprimirDatosTrabajador();
};

string Empleado::getNombre()
{
    return this->nombre;
}
void Empleado::setNombre(string nombre)
{
    this->nombre = nombre;
}
string Empleado::getPuesto()
{
    return this->puesto;
}
void Empleado::setPuesto(string puesto)
{
    this->puesto = puesto;
}
double Empleado::getPagoHora()
{
    return this->pagoHora;
}
void Empleado::setPagoHora(double pagoHora)
{
    this->pagoHora = pagoHora;
}
double Empleado::getHorasTrabajadasMes()
{
    return this->horasTrabajadasMes;
}
void Empleado::setHorasTrabajadasMes(double horasTrabajadasMes)
{
    this->horasTrabajadasMes = horasTrabajadasMes;
}
double Empleado::getSalarioMensual()
{
    return this->salarioMensual;
}
void Empleado::setSalarioMensual(double salarioMensual)
{
    this->salarioMensual = salarioMensual;
}
void Empleado::capturarDatosTrabajador()
{
    string nombre, puesto;
    double pagoHora, horasTrabajadasMes;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese puesto: ";
    cin >> puesto;
    cout << "Ingrese su pago por hora: ";
    cin >> pagoHora;
    cout << "Ingrese las horas trabajadas: ";
    cin >> horasTrabajadasMes;

    setNombre(nombre);
    setPuesto(puesto);
    setPagoHora(pagoHora);
    setHorasTrabajadasMes(horasTrabajadasMes);
}
double Empleado::obtenerSalarioMensual()
{
    double salarioMensual = getPagoHora() * getHorasTrabajadasMes();
    if (getHorasTrabajadasMes() >= 100 && getHorasTrabajadasMes() <= 200)
    {
        salarioMensual *= 1.1;
    }
    else if (getHorasTrabajadasMes() >= 201 && getHorasTrabajadasMes() <= 220)
    {
        salarioMensual *= 1.2;
    }
    else if (getHorasTrabajadasMes() >= 221 && getHorasTrabajadasMes() <= 230)
    {
        salarioMensual *= 1.3;
    }
    return salarioMensual *= 0.84;
}
void Empleado::imprimirDatosTrabajador()
{
    cout << "================== INFORMACION ==================" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Puesto: " << getPuesto() << endl;
    cout << "Pago por hora: " << getPagoHora() << endl;
    cout << "Horas trabajadas en el mes: " << getHorasTrabajadasMes() << endl;
    cout << "Salario mensual: " << obtenerSalarioMensual() << "$" << endl;
}

int main()
{
    Empleado objEmpleado;
    objEmpleado.capturarDatosTrabajador();
    objEmpleado.imprimirDatosTrabajador();
}