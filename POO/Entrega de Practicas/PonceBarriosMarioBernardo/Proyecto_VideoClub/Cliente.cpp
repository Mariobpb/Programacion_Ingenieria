#include <iostream>
#include <string>

#include "Persona.cpp"

using namespace std;

class Cliente : public Persona, public Mostrable {
    private:
        int clienteID;
        int pelisRentadas;
        int videojuegosRentados;

    public:
        Cliente();
        Cliente(string nombre, string domicilio, int telefono, string RFC, int clienteID);
        ~Cliente();

        int getClienteID();
        void setClienteID(int);

        int getPelisRentadas();
        void setPelisRentadas(int);

        int getVideojuegosRentados();
        void setVideojuegosRentados(int);

        void mostrarInfo() override;
};