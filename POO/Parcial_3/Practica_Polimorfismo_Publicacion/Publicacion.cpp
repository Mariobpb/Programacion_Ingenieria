using namespace std;
#include <string>
#include <iostream>

class Publicacion
{
private:
    string titulo;
    string autor;
    double precio;

public:
    Publicacion();
    Publicacion(string titulo, string autor, double precio);

    string getTitulo();
    string getAutor();
    double getPrecio();

    void setTitulo(string titulo);
    void setAutor(string autor);
    void setPrecio(double precio);

    virtual string mostrarInformacion();
};

Publicacion::Publicacion()
{
    this->titulo = "SIN TÍTULO";
    this->autor = "SIN AUTOR";
    this->precio = 0;
}
Publicacion::Publicacion(string titulo, string autor, double precio)
{
    this->titulo = titulo;
    this->autor = autor;
    this->precio = precio;
}

string Publicacion::getTitulo() { return this->titulo; }
string Publicacion::getAutor() { return this->autor; }
double Publicacion::getPrecio() { return this->precio; }

void Publicacion::setTitulo(string titulo) { this->titulo = titulo; }
void Publicacion::setAutor(string autor) { this->autor = autor; }
void Publicacion::setPrecio(double precio) { this->precio = precio; }

string Publicacion::mostrarInformacion()
{
    return "\nTítulo: " + getTitulo() + "\nAutor: " + getAutor() + "\nPrecio: $" + to_string(getPrecio());
}