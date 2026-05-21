using namespace std;

class DispositivoElectronico
{
    public:
    virtual void encender() = 0;
    virtual void apagar() = 0;
    virtual void mostrarEstado() = 0;
};