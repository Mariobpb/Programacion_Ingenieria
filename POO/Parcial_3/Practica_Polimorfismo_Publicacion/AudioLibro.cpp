using namespace std;


class AudioLibro : public Publicacion
{
private:
    int minutos;
    string presentacion;

public:
    AudioLibro();
    AudioLibro(string titulo, string autor, double precio, int minutos, string presentacion);

    int getMinutos();
    string getPresentacion();

    void setMinutos(int minutos);
    void setPresentacion(string presentacion);

    string mostrarInformacion();
};

AudioLibro::AudioLibro()
{
    this->minutos = 0;
    this->presentacion = "PRESENTACION NO ASIGNADA";
}
AudioLibro::AudioLibro(string titulo, string autor, double precio, int minutos, string presentacion) : Publicacion(titulo, autor, precio)
{
    this->presentacion = "PRESENTACION NO ASIGNADA";
}

int AudioLibro::getMinutos()
{
    return this->minutos;
}
string AudioLibro::getPresentacion()
{
    return this->presentacion;
}

void AudioLibro::setMinutos(int minutos)
{
    this->minutos = minutos;
}
void AudioLibro::setPresentacion(string presentacion)
{
    if (presentacion == "CD" || presentacion == "Podcast")
        this->presentacion = presentacion;
    else
        cout << "ERROR: debe de asignar el valor de Blanda o Dura";
}

string AudioLibro::mostrarInformacion()
{
    return "\n----- AUDIO LIBRO -----\nTitulo: " + getTitulo() + "\nAutor: " + getAutor() + "\nPrecio: $" + to_string(getPrecio()) 
    + "\nDuracion: " + to_string(getMinutos()) + " minutos\nPresentacion: " + getPresentacion() + "\n";
}