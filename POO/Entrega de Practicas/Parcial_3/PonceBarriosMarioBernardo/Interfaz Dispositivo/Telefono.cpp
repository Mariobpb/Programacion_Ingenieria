using namespace std;

class Telefono : public DispositivoElectronico
{
private:
    string marca;
    bool encendido;

public:
    Telefono();
    Telefono(string);

    string getMarca();
    void setMarca(string);
    bool getEncendido();
    void setEncendido(bool);

    void encender() override;
    void apagar() override;
    void mostrarEstado() override;
};
Telefono::Telefono()
{
    this->marca = "SIN MARCA";
    this->encendido = false;
}
Telefono::Telefono(string marca)
{
    this->marca = marca;
    this->encendido = false;
}

string Telefono::getMarca()
{
    return this->marca;
}
void Telefono::setMarca(string marca)
{
    this->marca = marca;
}
bool Telefono::getEncendido()
{
    return this->encendido;
}
void Telefono::setEncendido(bool encendido)
{
    this->encendido = encendido;
}

void Telefono::encender()
{
    setEncendido(true);
    cout << "\n\tEl telefono se ha encendido" << endl;
}
void Telefono::apagar()
{
    setEncendido(false);
    cout << "\n\tEl telefono se ha apagado" << endl;
}
void Telefono::mostrarEstado()
{
    cout << "\n======= Informacion de telefono =======" << endl;
    cout << "\tMarca: " << getMarca() << endl;
    cout << "\tEstado: ";
    if (getEncendido())
        cout << "Encendido" << endl;
    else
        cout << "Apagado" << endl;
    cout << "=======================================" << endl;
}