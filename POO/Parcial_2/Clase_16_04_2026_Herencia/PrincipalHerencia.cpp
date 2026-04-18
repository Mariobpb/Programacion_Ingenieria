#include <iostream>
#include "VehiculoRodante.cpp"
#include "Camion.cpp"
//#include "Automovil.cpp"

using namespace std;

int main() {
    //Se crean dos objetos de la clase Camion
    Camion objCamion1, objCamion2;

    //Para el objeto objCamion1 se asignan los atributos a través de los metodos set
    objCamion1.setRuedas(18);
    objCamion1.setPasajeros(2);
    objCamion1.setCarga(3200);

    //Para el objeto objCamion2 se asignan los atributos a través de los metodos set
    objCamion2.setRuedas(6);
    objCamion2.setPasajeros(3);
    objCamion2.setCarga(1200);

    //Se muestran los datos del objeto objcamion1
    objCamion1.mostrar();
    cout << endl;

    //Se muestran los datos del objeto objcamion2
    objCamion2.mostrar();
    cout << endl;

    return 0;
}