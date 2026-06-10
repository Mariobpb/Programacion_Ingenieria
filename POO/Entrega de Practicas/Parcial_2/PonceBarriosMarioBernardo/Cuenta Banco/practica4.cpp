#include <iostream>
using namespace std;

class CuentaBanco
{
private:
    string nombreC;
    string numeroC;
    double saldoC;

public:
    CuentaBanco();

    string getNombreC();
    void setNombreC(string nombreC);
    string getNumeroC();
    void setNumeroC(string numeroC);
    double getSaldoC();
    void setSaldoC(double saldoC);

    void capturarDatos();
    void imprimirDatos();
    void abonar_cuenta(double cantidad);
    void retirarCuenta(double cantidad);
    void mostrarMenu();
};
CuentaBanco::CuentaBanco()
{
    this->nombreC = "Sin nombre";
    this->numeroC = "Sin cuenta";
    this->saldoC = 0;
}

string CuentaBanco::getNombreC()
{
    return this->nombreC;
}
void CuentaBanco::setNombreC(string nombreC)
{
    this->nombreC = nombreC;
}
string CuentaBanco::getNumeroC()
{
    return this->numeroC;
}
void CuentaBanco::setNumeroC(string numeroC)
{
    this->numeroC = numeroC;
}
double CuentaBanco::getSaldoC()
{
    return this->saldoC;
}
void CuentaBanco::setSaldoC(double saldoC)
{
    this->saldoC = saldoC;
}

void CuentaBanco::capturarDatos()
{
    string nombre, numero;
    double saldo;
    cout << "\nIngrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese el numero de cuenta: ";
    cin >> numero;
    cout << "Ingrese el saldo inicial: ";
    cin >> saldo;

    setNombreC(nombre);
    setNumeroC(numero);
    setSaldoC(saldo);
}
void CuentaBanco::imprimirDatos()
{
    cout << "\n\n\n\t================== INFORMACION ==================" << endl;
    cout << "\tNombre: " << getNombreC() << endl;
    cout << "\tNumero de cuenta: " << getNumeroC() << endl;
    cout << "\tSaldo de cuenta: " << getSaldoC() << endl;
}
void CuentaBanco::abonar_cuenta(double cantidad)
{
    setSaldoC(getSaldoC() + cantidad);
    cout << "Saldo de cuenta actualizado\nSaldo actual: " << getSaldoC();
}
void CuentaBanco::retirarCuenta(double cantidad)
{
    if (cantidad > getSaldoC())
    {
        cout << "Saldo insuficiente para el retiro" << endl;
    }
    else
    {
        setSaldoC(getSaldoC() - cantidad);
        cout << "Saldo retirado: " << cantidad << endl;
        cout << "Saldo actual: " << getSaldoC() << endl;
    }
}
void CuentaBanco::mostrarMenu()
{
    int opcion, cantidad;
    do
    {
        cout << "\n\n\n\t\t\tSistema de manejo de Cuenta Bancaria\n\n";
        cout << "\t1. Crear la cuenta bancaria" << endl;
        cout << "\t2. Imprimir datos de la cuenta bancaria" << endl;
        cout << "\t3. Abonar a la cuenta bancaria" << endl;
        cout << "\t4. Retirar de la cuenta bancaria" << endl;
        cout << "\t5. Salir del sistema" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            capturarDatos();
            break;
        case 2:
            imprimirDatos();
            break;
        case 3:
            cout << "Ingresa la cantidad a abonar: ";
            cin >> cantidad;
            abonar_cuenta(cantidad);
            break;
        case 4:
            cout << "Ingresa la cantidad a retirar: ";
            cin >> cantidad;
            retirarCuenta(cantidad);
            break;
        case 5:
            cout << "\nHasta luego\n"
                 << endl;
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
    } while (opcion != 5);
}

int main()
{
    CuentaBanco objCuenta;
    objCuenta.mostrarMenu();
}