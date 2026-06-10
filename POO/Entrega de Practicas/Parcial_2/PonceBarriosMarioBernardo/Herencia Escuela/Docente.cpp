
using namespace std;

class Docente : public Persona
{
private:
    int numNomina;
    float salario;
    float horasTrab;

public:
    Docente();

    int getNumNomina();
    float getSalario();
    float getHorasTrab();

    void setNumNomina(int);
    void setSalario(float);
    void setHorasTrab(float);

    void leer_valores();
    void imprimir_valores();
    void calcular_salario();
    float obtener_salario();
    void cambiar_estatus(string);
};

Docente::Docente(){
    this->salario = 0;
}

int Docente::getNumNomina(){ return this->numNomina; }
float Docente::getSalario(){ return this->salario; }
float Docente::getHorasTrab(){ return this->horasTrab; }

void Docente::setNumNomina(int numNomina){ this->numNomina = numNomina; }
void Docente::setSalario(float salario){ this->salario = salario; }
void Docente::setHorasTrab(float horasTrab){ this->horasTrab = horasTrab; }

void Docente::leer_valores()
{
    string nombre, carrera;
    int edad;
    int numNomina;
    float horasTrab;

    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese la carrera: ";
    cin >> carrera;
    cout << "Ingrese el numero de nomina: ";
    cin >> numNomina;
    cout << "Ingrese las horas trabajadas: ";
    cin >> horasTrab;

    setNombre(nombre);
    setEdad(edad);
    setCarrera(carrera);
    setNumNomina(numNomina);
    setHorasTrab(horasTrab);
}

void Docente::imprimir_valores()
{
    cout << "################# VALORES DEL DOCENTE #################\n" << endl;
    cout << "\tNombre: | " << getNombre() << " |" << endl;
    cout << "\tEdad: | " << getEdad() << " |" << endl;
    cout << "\tCarrera: | " << getCarrera() << " |" << endl;
    cout << "\tNumero de Nomina: | " << getNumNomina() << " |" << endl;
    cout << "\tHoras trabajadas: | " << getHorasTrab() << " |" << endl;
    cout << "\tSalario: | " << getSalario() << " |" << endl;
    cout << "\tEstatus: | " << getEstatus() << " |" << endl;
    cout << "\n################# VALORES DEL DOCENTE #################" << endl;
}

void Docente::calcular_salario()
{
    setSalario(obtener_salario());
    cout << "\nEl salario de " << getNombre() << " es: " << getSalario() << endl;
}

float Docente::obtener_salario()
{
    return getHorasTrab() * 80;
}

void Docente::cambiar_estatus(string estatus)
{
    setEstatus(estatus);
}