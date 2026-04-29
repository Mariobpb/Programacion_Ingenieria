#include <iostream>
#include <string>
#include "VehiculoRodante.cpp"
#include "Camion.cpp"
#include "Automovil.cpp"
#include "Mecanico.cpp"

using namespace std;

int main() {
    //Se crean dos objetos de la clase Camion
    Camion objCamion1;

    //Se crea un objeto de la clase Automovil
    Automovil objauto;

    //Se crea un objeto de la clase Mecanico
    Mecanico objMec;

    //Para el objeto objCamion1 se asignan los atributos a través de los metodos set
    objCamion1.setRuedas(18);
    objCamion1.setPasajeros(2);
    objMec.definirCarga(objCamion1);

    //Para el objeto objauto se asignan los atributos a través de los métodos set
    objauto.setRuedas(4);
    objauto.setTipoCarro(camioneta);
    objMec.definirPasajeros(objauto);

    //Se muestran los datos del objeto objauto
    objauto.mostrar();
    cout << endl;
    
    //Se muestran los datos del objeto objcamion1
    objCamion1.mostrar();
    cout << endl;

    //Se muestran los datos del objeto objauto
    objauto.mostrar();
    cout << endl;

    return 0;
}