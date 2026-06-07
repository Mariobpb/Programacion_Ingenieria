
using namespace std;

class Alumno : public Persona
{
private:
    string registro;
    float promedio;
    float calMat;
    float calProgra;
    float calAlgebra;

public:
    Alumno();
    Alumno(string, int, string, string, float, float, float);

    string getRegistro();
    float getPromedio();
    float getCalMat();
    float getCalProgra();
    float getCalAlgebra();

    void setRegistro(string);
    void setPromedio(float);
    void setCalMat(float);
    void setCalProgra(float);
    void setCalAlgebra(float);

    void leerValores();
    void calcular_promedio();
    void cambiar_estatus(string);
    void imprimir_valores();
    float obtener_promedio();
};

Alumno::Alumno()
{
    this->promedio = 0;
}

Alumno::Alumno(string nombre, int edad, string carrera,
               string registro, float calMat, float calProgra, float calAlgebra) : Persona(nombre, edad, carrera)
{
    this->registro = registro;
    this->calMat = calMat;
    this->calProgra = calProgra;
    this->calAlgebra = calAlgebra;
    this->promedio = 0;
}

string Alumno::getRegistro() { return this->registro; }
float Alumno::getPromedio() { return this->promedio; }
float Alumno::getCalMat() { return this->calMat; }
float Alumno::getCalProgra() { return this->calProgra; }
float Alumno::getCalAlgebra() { return this->calAlgebra; }

void Alumno::setRegistro(string registro) { this->registro = registro; }
void Alumno::setPromedio(float promedio) { this->promedio = promedio; }
void Alumno::setCalMat(float calMat) { this->calMat = calMat; }
void Alumno::setCalProgra(float calProgra) { this->calProgra = calProgra; }
void Alumno::setCalAlgebra(float calAlgebra) { this->calAlgebra = calAlgebra; }

void Alumno::leerValores()
{
    string nombre, carrera;
    int edad;
    string registro;
    float calMat, calProgra, calAlgebra;

    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el registro: ";
    cin >> registro;
    cout << "Ingrese la carrera: ";
    cin >> carrera;
    cout << "Ingrese la calificacion de matematicas: ";
    cin >> calMat;
    cout << "Ingrese la calificacion de programacion: ";
    cin >> calProgra;
    cout << "Ingrese la calificacion de algebra: ";
    cin >> calAlgebra;

    setNombre(nombre);
    setEdad(edad);
    setRegistro(registro);
    setCarrera(carrera);
    setCalMat(calMat);
    setCalProgra(calProgra);
    setCalAlgebra(calAlgebra);
}

void Alumno::calcular_promedio()
{
    setPromedio(obtener_promedio());
    cout << "\nEl promedio de " << getNombre() << " es: " << getPromedio() << endl;
}

void Alumno::cambiar_estatus(string estatus)
{
    setEstatus(estatus);
}

void Alumno::imprimir_valores()
{
    cout << "################# VALORES DEL ALUMNO #################\n" << endl;
    cout << "\tNombre: | " << getNombre() << " |" << endl;
    cout << "\tEdad: | " << getEdad() << " |" << endl;
    cout << "\tRegistro: | " << getRegistro() << " |" << endl;
    cout << "\tCarrera: | " << getCarrera() << " |" << endl;
    cout << "\tCalificacion de Matematicas: | " << getCalMat() << " |" << endl;
    cout << "\tCalificacion de Programacion: | " << getCalProgra() << " |" << endl;
    cout << "\tCalificacion de Algebra: | " << getCalAlgebra() << " |" << endl;
    cout << "\tPromedio: | " << getPromedio() << " |" << endl;
    cout << "\tEstatus: | " << getEstatus() << " |" << endl;
    cout << "\n################# VALORES DEL ALUMNO #################" << endl;
}

float Alumno::obtener_promedio()
{
    return (getCalMat() + getCalProgra() + getCalAlgebra()) / 3;
}