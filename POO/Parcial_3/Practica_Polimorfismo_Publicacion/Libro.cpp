using namespace std;
#include <string>
#include <iostream>
#include "Publicacion.cpp"

class Libro : public Publicacion
{
private:
    int numPaginas;
    string pasta;
    bool validarPasta(string pasta);

public:
    Libro();
    Libro(int numPaginas, string pasta, string titulo, string autor, double precio);

    int getNumPaginas();
    string getPasta();

    void setNumPaginas(int numPaginas);
    void setPasta(string pasta);

    string mostrarInformacion();
};

Libro::Libro()
{
    this->numPaginas = 0;
    this->pasta = "PASTA NO ASIGNADA";
}
Libro::Libro(int numPaginas, string pasta, string titulo, string autor, double precio) : Publicacion(titulo, autor, precio)
{
    this->pasta = "PASTA NO ASIGNADA";
    setPasta(pasta);
    this->numPaginas = numPaginas;
}

int Libro::getNumPaginas() { return this->numPaginas; }
string Libro::getPasta() { return this->pasta; }

void Libro::setNumPaginas(int numPaginas) { this->numPaginas = numPaginas; }
void Libro::setPasta(string pasta)
{
    if (pasta == "Blanda" || pasta == "Dura")
        this->pasta = pasta;
    else
        cout << "ERROR: debe de asignar el valor de Blanda o Dura";
}

string Libro::mostrarInformacion()
{
    return "----- LIBRO -----\nTítulo: " + getTitulo() + "\nAutor: " + getAutor() + "\nPrecio: $" + to_string(getPrecio()) 
    + "\nNumero de páginas: " + to_string(getNumPaginas()) + "\nTipo de pasta: " + getPasta();
}