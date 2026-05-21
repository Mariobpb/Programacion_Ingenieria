using namespace std;

class Tablet : public DispositivoElectronico
{
private:
    double pulgadas;
    bool encendido;

public:
    Tablet();
    Tablet(double);

    double getPulgadas();
    void setPulgadas(double);
    bool getEncendido();
    void setEncendido(bool);

    void encender() override;
    void apagar() override;
    void mostrarEstado() override;
};
Tablet::Tablet()
{
    this->pulgadas = 0;
    this->encendido = false;
}
Tablet::Tablet(double pulgadas)
{
    this->pulgadas = pulgadas;
    this->encendido = false;
}

double Tablet::getPulgadas()
{
    return this->pulgadas;
}
void Tablet::setPulgadas(double pulgadas)
{
    this->pulgadas = pulgadas;
}
bool Tablet::getEncendido()
{
    return this->encendido;
}
void Tablet::setEncendido(bool encendido)
{
    this->encendido = encendido;
}

void Tablet::encender()
{
    setEncendido(true);
    cout << "\n\tLa Tablet se ha encendido" << endl;
}
void Tablet::apagar()
{
    setEncendido(false);
    cout << "\n\tLa Tablet se ha apagado" << endl;
}
void Tablet::mostrarEstado()
{
    cout << "\n======= Informacion de Tablet =======" << endl;
    cout << "\tPulgadas: " << getPulgadas() << "in" << endl;
    cout << "\tEstado: ";
    if (getEncendido())
        cout << "Encendido" << endl;
    else
        cout << "Apagado" << endl;
    cout << "=======================================" << endl;
}