using namespace std;

class Laptop : public DispositivoElectronico
{
private:
    string modelo;
    bool encendido;

public:
    Laptop();
    Laptop(string);

    string getModelo();
    void setModelo(string);
    bool getEncendido();
    void setEncendido(bool);

    void encender() override;
    void apagar() override;
    void mostrarEstado() override;
};
Laptop::Laptop()
{
    this->modelo = "SIN MODELO";
    this->encendido = false;
}
Laptop::Laptop(string modelo)
{
    this->modelo = modelo;
    this->encendido = false;
}

string Laptop::getModelo()
{
    return this->modelo;
}
void Laptop::setModelo(string modelo)
{
    this->modelo = modelo;
}
bool Laptop::getEncendido()
{
    return this->encendido;
}
void Laptop::setEncendido(bool encendido)
{
    this->encendido = encendido;
}

void Laptop::encender()
{
    setEncendido(true);
    cout << "\n\tLa laptop se ha encendido" << endl;
}
void Laptop::apagar()
{
    setEncendido(false);
    cout << "\n\tLa laptop se ha apagado" << endl;
}
void Laptop::mostrarEstado()
{
    cout << "\n======= Informacion de laptop =======" << endl;
    cout << "\tModelo: " << getModelo() << endl;
    cout << "\tEstado: ";
    if (getEncendido())
        cout << "Encendido" << endl;
    else
        cout << "Apagado" << endl;
    cout << "=======================================" << endl;
}