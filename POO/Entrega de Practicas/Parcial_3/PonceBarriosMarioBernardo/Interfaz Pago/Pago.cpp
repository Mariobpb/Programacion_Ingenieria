#include <string>

using namespace std;

class Pago {
    public:
    virtual void realizarPago(double monto) = 0;
    virtual string obtenerMetodoPago() = 0;

    virtual ~Pago() = default;
};