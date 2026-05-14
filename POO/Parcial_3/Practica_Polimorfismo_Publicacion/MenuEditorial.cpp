using namespace std;

class MenuEditorial
{
private:
    Libro objLibro;
    AudioLibro objAudio;
    Publicacion *objPublicacion;

public:
    void menuPrincipal();
};
void MenuEditorial::menuPrincipal()
{
    string titulo, autor, pasta, presentacion;
    double precio;
    int numPaginas, minutos;
    int opcion;
    do
    {
        cout << "\n\nMenu Ventas" << endl;
        cout << "1. Registrar un Libro." << endl;
        cout << "2. Registrar un Audio Libro." << endl;
        cout << "3. Realizar una venta." << endl;
        cout << "4. Mostrar informacion de publicaciones." << endl;
        cout << "5. Salir del sistema." << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Titulo del libro:\t";
            cin >> titulo;
            cout << "Autor del libro:\t";
            cin >> autor;
            cout << "Precio del libro:\t";
            cin >> precio;
            cout << "Numero de paginas del libro:\t";
            cin >> numPaginas;
            cout << "Pasta del libro (Blanda/Dura):\t";
            cin >> pasta;
            objLibro.setTitulo(titulo);
            objLibro.setAutor(autor);
            objLibro.setPrecio(precio);
            objLibro.setNumPaginas(numPaginas);
            objLibro.setPasta(pasta);
            break;
        case 2:
            cout << "Titulo del audio libro:\t";
            cin >> titulo;
            cout << "Autor del audio libro:\t";
            cin >> autor;
            cout << "Precio del audio libro:\t";
            cin >> precio;
            cout << "Minutos de duracion del audio libro:\t";
            cin >> minutos;
            cout << "Presentacion del audio libro (CD/Podcast):\t";
            cin >> presentacion;
            objAudio.setTitulo(titulo);
            objAudio.setAutor(autor);
            objAudio.setPrecio(precio);
            objAudio.setMinutos(minutos);
            objAudio.setPresentacion(presentacion);
            break;
        case 3:
            int opcionVenta, cantidad;
            cout << "¿Que desea comprar?" << endl;
            cout << "1. Libro" << endl;
            cout << "2. AudioLibro" << endl;
            cin >> opcionVenta;
            switch (opcionVenta)
            {
            case 1:
                objPublicacion = &objLibro;
                break;
            case 2:
                objPublicacion = &objAudio;
                break;
            default:
                objPublicacion = NULL;
                break;
            }
            cout << "Ingrese la cantidad a comprar:\t";
            cin >> cantidad;
            cout << "\n========= Informacion del producto a comprar =========\n"
                 << objPublicacion->mostrarInformacion() << "\nTotal a pagar:\t" << objPublicacion->getPrecio() * cantidad;
            break;
        case 4:
            objPublicacion = &objLibro;
            cout << objPublicacion->mostrarInformacion();
            objPublicacion = &objAudio;
            cout << objPublicacion->mostrarInformacion();
            break;
        case 5:
            /* code */
            break;
        default:
            break;
        }
    } while (opcion != 5);
}