#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Mostrable.cpp"
#include "UI.cpp"
#include "Persona.cpp"
#include "Cliente.cpp"
#include "Empleado.cpp"
#include "Producto.cpp"
#include "Pelicula.cpp"
#include "Videojuego.cpp"
#include "Transaccion.cpp"

using namespace std;

string contrasena = "A25310234";

class Menu
{
private:
    vector<Persona *> personas;
    vector<Producto *> productos;
    vector<Transaccion> transacciones;

public:
    bool validarContrasena();
    void menuPrincipal();
    void menuPeliculaVideojuego();
    void menuCliente();
    void menuEmpleado();
    void menuVentaRenta();
};

bool Menu::validarContrasena()
{
    string contrasenaIngresada;
    cout << RESET << LIMPIAR << AMARILLO << "\n\n\nIngrese la contrasenia del sistema: " << BLANCO;
    cin >> contrasenaIngresada;
    if (contrasenaIngresada != contrasena)
        return true;
    return false;
}

void Menu::menuPrincipal()
{
    int opcion;
    //while (validarContrasena());
    do
    {
        limpiarPantalla();
        impColor("\n=============== MENU PRINCIPAL ===============\n\n", CIAN);
        impColor("\n\t1. CLIENTES", CIAN);
        impColor("\n\t2. PELICULAS Y VIDEOJUEGOS", CIAN);
        impColor("\n\t3. EMPLEADOS", CIAN);
        impColor("\n\t4. REALIZAR RENTA O VENTA", CIAN);
        impColor("\n\t5. SALIR", CIAN);
        impColor("\n\nIngrese su opcion: ", AMARILLO);
        opcion = leerInt();
        switch (opcion)
        {
        case 1:
            menuCliente();
            break;
        case 2:
            menuPeliculaVideojuego();
            break;
        case 3:
            menuEmpleado();
            break;
        case 4:
            menuVentaRenta();
            break;
        default:
            break;
        }
    } while (opcion != 5);
}

void Menu::menuPeliculaVideojuego()
{
    int opcion;
    do
    {
        limpiarPantalla();
        impColor("\n=============== MENU PELICULAS Y VIDEOJUEGOS ===============\n\n", MAGENTA);
        impColor("\n\t1. REGISTRAR PRODUCTO (PELICULA / VIDEOJUEGO)", MAGENTA);
        impColor("\n\t2. CONSULTAR POR NOMBRE", MAGENTA);
        impColor("\n\t3. CONSULTAR POR ID", MAGENTA);
        impColor("\n\t4. MODIFICAR PRODUCTO", MAGENTA);
        impColor("\n\t5. MOSTRAR LISTA DE PRODUCTOS", MAGENTA);
        impColor("\n\t6. REGRESAR AL MENU PRINCIPAL", MAGENTA);
        impColor("\n\nIngrese su opcion: ", AMARILLO);
        opcion = leerInt();
        switch (opcion)
        {
        case 1:
        {
            limpiarPantalla();
            impColor("\n============== REGISTRAR NUEVO PRODUCTO ==============\n", VERDE);
            impColor("¿Que desea registrar?\n1. Pelicula\n2. Videojuego\nSeleccione una opcion: ", VERDE);
            int tipo = leerInt();

            if (tipo != 1 && tipo != 2)
            {
                impColor("\nOpcion no valida.\n", ROJO);
                esperarEnter();
                break;
            }

            string nombre, genero;
            int copias;
            double pVenta, pRenta;

            impColor("Nombre del titulo: ", VERDE);
            nombre = leerString();
            impColor("Genero: ", VERDE);
            genero = leerString();
            impColor("Numero de copias: ", VERDE);
            copias = leerInt();
            impColor("Precio de Venta: $", VERDE);
            cout << BLANCO;
            cin >> pVenta;
            impColor("Precio de Renta: $", VERDE);
            cout << BLANCO;
            cin >> pRenta;

            if (tipo == 1)
            {
                string director;
                impColor("Director de la pelicula: ", VERDE);
                director = leerString();
                Pelicula *nuevaPeli = new Pelicula(copias, nombre, genero, pVenta, pRenta, director);
                productos.push_back(nuevaPeli);
                impColor("\nPelicula registrada con exito. ID Asignado: " + to_string(nuevaPeli->getID()) + "\n", VERDE);
            }
            else
            {
                Videojuego *nuevoJuego = new Videojuego(copias, nombre, genero, pVenta, pRenta);
                productos.push_back(nuevoJuego);
                impColor("\nVideojuego registrado con exito. ID Asignado: " + to_string(nuevoJuego->getID()) + "\n", VERDE);
            }
            esperarEnter();
            break;
        }
        case 2:
        {
            limpiarPantalla();
            impColor("\n============== CONSULTAR PRODUCTO POR NOMBRE ==============\n", VERDE);
            impColor("Ingrese el nombre del producto a buscar: ", AMARILLO);
            string busqueda = leerString();
            bool encontrado = false;
            for (Producto *p : productos)
            {
                if (p->getNombre() == busqueda)
                {
                    p->mostrarInfo();
                    encontrado = true;
                    impColor("\n----------------------------------------\n", VERDE);
                }
            }
            if (!encontrado)
                impColor("\nNo se encontraron productos con ese nombre.\n", ROJO);
            esperarEnter();
            break;
        }
        case 3:
        {
            limpiarPantalla();
            impColor("\n============== CONSULTAR PRODUCTO POR ID ==============\n", VERDE);
            impColor("Ingrese el ID del producto a buscar: ", AMARILLO);
            int ID = leerInt();
            bool encontrado = false;
            for (Producto *p : productos)
            {
                if (p->getID() == ID)
                {
                    encontrado = true;
                    impColor("\nDATOS DEL PRODUCTO:\n", VERDE);
                    p->mostrarInfo();
                    break;
                }
            }
            if (!encontrado)
                impColor("\nNo se ha encontrado un producto con ese ID.\n", ROJO);
            esperarEnter();
            break;
        }
        case 4:
        {
            limpiarPantalla();
            impColor("\n============== MODIFICAR PRODUCTO ==============\n", VERDE);
            impColor("Ingrese el ID del producto a modificar: ", AMARILLO);
            int ID = leerInt();
            Producto *objetivo = nullptr;
            for (Producto *p : productos)
            {
                if (p->getID() == ID)
                {
                    objetivo = p;
                    break;
                }
            }
            if (objetivo != nullptr)
            {
                string nNombre, nGenero;
                int nCopias;
                double nVenta, nRenta;

                impColor("Nuevo Nombre: ", VERDE);
                nNombre = leerString();
                objetivo->setNombre(nNombre);
                impColor("Nuevo Genero: ", VERDE);
                nGenero = leerString();
                objetivo->setGenero(nGenero);
                impColor("Nuevo Numero de Copias: ", VERDE);
                nCopias = leerInt();
                objetivo->setNumCopia(nCopias);
                impColor("Nuevo Precio Venta: $", VERDE);
                cout << BLANCO;
                cin >> nVenta;
                objetivo->setPrecioVenta(nVenta);
                impColor("Nuevo Precio Renta: $", VERDE);
                cout << BLANCO;
                cin >> nRenta;
                objetivo->setPrecioRenta(nRenta);

                Pelicula *peli = dynamic_cast<Pelicula *>(objetivo);
                if (peli != nullptr)
                {
                    string nDirector;
                    impColor("Nuevo Director: ", VERDE);
                    nDirector = leerString();
                    peli->setDirector(nDirector);
                }

                impColor("\nProducto modificado correctamente.\n", VERDE);
            }
            else
                impColor("\nProducto no localizado.\n", ROJO);
            esperarEnter();
            break;
        }
        case 5:
        {
            limpiarPantalla();
            impColor("\n============== LISTA DE PRODUCTOS EN INVENTARIO ==============\n", VERDE);
            if (productos.empty())
            {
                impColor("\nSin productos registrados en el sistema.\n", ROJO);
            }
            else
            {
                for (Producto *p : productos)
                {
                    p->mostrarInfo();
                    impColor("\n\n--------------------------------------------------\n", VERDE);
                }
            }
            esperarEnter();
            break;
        }
        default:
            break;
        }
    } while (opcion != 6);
}

void Menu::menuCliente()
{
    int opcion;
    do
    {
        limpiarPantalla();
        impColor("\n=============== MENU CLIENTE ===============\n\n", MAGENTA);
        impColor("\n\t1. REGISTRAR CLIENTE", MAGENTA);
        impColor("\n\t2. CONSULTAR POR NOMBRE", MAGENTA);
        impColor("\n\t3. CONSULTAR POR ID", MAGENTA);
        impColor("\n\t4. MODIFICAR CLIENTE", MAGENTA);
        impColor("\n\t5. MOSTRAR LISTA DE CLIENTES", MAGENTA);
        impColor("\n\t6. REGRESAR AL MENU PRINCIPAL", MAGENTA);
        impColor("\n\nIngrese su opcion: ", AMARILLO);
        opcion = leerInt();
        switch (opcion)
        {
        case 1:
        {
            limpiarPantalla();
            impColor("\n============== REGISTRAR CLIENTE ==============\n", VERDE);
            Cliente *nuevoCliente = new Cliente();

            impColor("Nombre:\t", VERDE);
            nuevoCliente->setNombre(leerString());
            impColor("Domicilio:\t", VERDE);
            nuevoCliente->setDomicilio(leerString());
            impColor("Telefono:\t", VERDE);
            nuevoCliente->setTelefono(leerInt());
            impColor("RFC:\t", VERDE);
            nuevoCliente->setRFC(leerString());

            personas.push_back(nuevoCliente);
            impColor("\nCliente registrado con exito.\nID Asignado: " + to_string(nuevoCliente->getClienteID()) + "\n", VERDE);
            esperarEnter();
            break;
        }
        case 2:
        {
            limpiarPantalla();
            impColor("\n============== CONSULTAR CLIENTE POR NOMBRE ==============\n", VERDE);
            impColor("Ingrese el nombre a buscar: ", AMARILLO);
            string busqueda = leerString();
            bool encontrado = false;
            for (Persona *p : personas)
            {
                Cliente *c = dynamic_cast<Cliente *>(p);
                if (c != nullptr && c->getNombre() == busqueda)
                {
                    c->mostrarInfo();
                    encontrado = true;
                    cout << "\n----------------------------------------\n";
                }
            }
            if (!encontrado)
                impColor("\nNo se encontraron clientes con ese nombre.\n", ROJO);
            esperarEnter();
            break;
        }
        case 3:
        {
            limpiarPantalla();
            impColor("\n============== CONSULTAR CLIENTE POR ID ==============\n", VERDE);
            impColor("Ingrese el ID del cliente a buscar: ", AMARILLO);
            int ID = leerInt();
            bool clienteEncontrado = false;
            for (Persona *p : personas)
            {
                Cliente *c = dynamic_cast<Cliente *>(p);
                if ((c != nullptr) && (c->getClienteID() == ID))
                {
                    clienteEncontrado = true;
                    impColor("\nDATOS DEL CLIENTE:\n", VERDE);
                    c->mostrarInfo();
                    break;
                }
            }
            if (!clienteEncontrado)
                impColor("\nNo se ha encontrado el cliente\n", ROJO);
            esperarEnter();
            break;
        }
        case 4:
        {
            limpiarPantalla();
            impColor("\n============== MODIFICAR CLIENTE ==============\n", VERDE);
            impColor("Ingrese el ID del cliente a modificar: ", AMARILLO);
            int ID = leerInt();
            Cliente *objetivo = nullptr;
            for (Persona *p : personas)
            {
                Cliente *c = dynamic_cast<Cliente *>(p);
                if (c != nullptr && c->getClienteID() == ID)
                {
                    objetivo = c;
                    break;
                }
            }
            if (objetivo != nullptr)
            {
                impColor("Nuevo Nombre:\t", VERDE);
                objetivo->setNombre(leerString());
                impColor("Nuevo Domicilio:\t", VERDE);
                objetivo->setDomicilio(leerString());
                impColor("Nuevo Telefono:\t", VERDE);
                objetivo->setTelefono(leerInt());
                impColor("Nuevo RFC:\t", VERDE);
                objetivo->setRFC(leerString());
                impColor("\nCliente modificado de forma correcta.\n", VERDE);
            }
            else
                impColor("\nCliente no localizado.\n", ROJO);
            esperarEnter();
            break;
        }
        case 5:
        {
            limpiarPantalla();
            impColor("\n============== LISTA DE CLIENTES ==============\n", VERDE);
            bool hayClientes = false;
            for (Persona *p : personas)
            {
                Cliente *c = dynamic_cast<Cliente *>(p);
                if (c != nullptr)
                {
                    hayClientes = true;
                    c->mostrarInfo();
                    impColor("\n\n----------------------------------------\n", VERDE);
                }
            }
            if (!hayClientes)
                impColor("\nSin clientes registrados en el sistema\n", ROJO);
            esperarEnter();
            break;
        }
        default:
            break;
        }
    } while (opcion != 6);
}

void Menu::menuEmpleado()
{
    int opcion;
    do
    {
        limpiarPantalla();
        impColor("\n=============== MENU EMPLEADO ===============\n\n", MAGENTA);
        impColor("\n\t1. REGISTRAR EMPLEADO", MAGENTA);
        impColor("\n\t2. CONSULTAR POR NOMBRE", MAGENTA);
        impColor("\n\t3. CONSULTAR POR ID", MAGENTA);
        impColor("\n\t4. MOSTRAR LISTA DE EMPLEADOS", MAGENTA);
        impColor("\n\t5. REGRESAR AL MENU PRINCIPAL", MAGENTA);
        impColor("\n\nIngrese su opcion: ", AMARILLO);
        opcion = leerInt();
        switch (opcion)
        {
        case 1:
        {
            limpiarPantalla();
            impColor("\n============== REGISTRAR EMPLEADO ==============\n", VERDE);
            Empleado *nuevoEmp = new Empleado();

            impColor("Nombre:\t", VERDE);
            nuevoEmp->setNombre(leerString());
            impColor("Domicilio:\t", VERDE);
            nuevoEmp->setDomicilio(leerString());
            impColor("Telefono:\t", VERDE);
            nuevoEmp->setTelefono(leerInt());
            impColor("RFC:\t", VERDE);
            nuevoEmp->setRFC(leerString());

            personas.push_back(nuevoEmp);
            impColor("\nEmpleado registrado con exito.\nID Asignado: " + to_string(nuevoEmp->getEmpleadoID()) + "\n", VERDE);
            esperarEnter();
            break;
        }
        case 2:
        {
            limpiarPantalla();
            impColor("\n============== CONSULTAR EMPLEADO POR NOMBRE ==============\n", CIAN);
            impColor("Ingrese el nombre a buscar: ", AMARILLO);
            string busqueda = leerString();
            bool encontrado = false;
            for (Persona *p : personas)
            {
                Empleado *e = dynamic_cast<Empleado *>(p);
                if (e != nullptr && e->getNombre() == busqueda)
                {
                    e->mostrarInfo();
                    encontrado = true;
                    cout << "\n----------------------------------------\n";
                }
            }
            if (!encontrado)
                impColor("\nNo se encontraron empleados con ese nombre.\n", ROJO);
            esperarEnter();
            break;
        }
        case 3:
        {
            limpiarPantalla();
            impColor("\n============== CONSULTAR EMPLEADO POR ID ==============\n", CIAN);
            impColor("Ingrese el ID del empleado: ", AMARILLO);
            int ID = leerInt();
            bool encontrado = false;
            for (Persona *p : personas)
            {
                Empleado *e = dynamic_cast<Empleado *>(p);
                if (e != nullptr && e->getEmpleadoID() == ID)
                {
                    e->mostrarInfo();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                impColor("\nEmpleado no encontrado.\n", ROJO);
            esperarEnter();
            break;
        }
        case 4:
        {
            limpiarPantalla();
            impColor("\n============== LISTA DE EMPLEADOS ==============\n", CIAN);
            bool hayEmpleados = false;
            for (Persona *p : personas)
            {
                Empleado *e = dynamic_cast<Empleado *>(p);
                if (e != nullptr)
                {
                    hayEmpleados = true;
                    e->mostrarInfo();
                    impColor("\n\n----------------------------------------\n", CIAN);
                }
            }
            if (!hayEmpleados)
                impColor("\nSin empleados registrados en el sistema\n", ROJO);
            esperarEnter();
            break;
        }
        default:
            break;
        }
    } while (opcion != 5);
}
void Menu::menuVentaRenta()
{
    limpiarPantalla();
    impColor("\n============== REALIZAR UNA RENTA / VENTA ==============\n", MAGENTA);

    // 1. VALIDACIÓN: Verificar que existan entidades registradas
    bool hayEmpleado = false;
    bool hayCliente = false;
    for (Persona* p : personas) {
        if (dynamic_cast<Empleado*>(p) != nullptr) hayEmpleado = true;
        if (dynamic_cast<Cliente*>(p) != nullptr) hayCliente = true;
    }

    if (!hayEmpleado || !hayCliente) {
        impColor("\nError: Debe existir al menos un Empleado y un Cliente en el sistema.\n", ROJO);
        esperarEnter();
        return;
    }

    // 2. LOGIN: Solicitar y validar Empleado
    impColor("Ingrese el código del Empleado: ", AMARILLO);
    int empID = leerInt();
    Empleado* empleadoActivo = nullptr;
    for (Persona* p : personas) {
        Empleado* e = dynamic_cast<Empleado*>(p);
        if (e != nullptr && e->getEmpleadoID() == empID) {
            empleadoActivo = e;
            break;
        }
    }
    if (empleadoActivo == nullptr) {
        impColor("\nCódigo de empleado no válido.\n", ROJO);
        esperarEnter();
        return;
    }

    // 3. LOGIN: Solicitar y validar Cliente
    impColor("Ingrese el código del Cliente: ", AMARILLO);
    int cliID = leerInt();
    Cliente* clienteActivo = nullptr;
    for (Persona* p : personas) {
        Cliente* c = dynamic_cast<Cliente*>(p);
        if (c != nullptr && c->getClienteID() == cliID) {
            clienteActivo = c;
            break;
        }
    }
    if (clienteActivo == nullptr) {
        impColor("\nCódigo de cliente no válido.\n", ROJO);
        esperarEnter();
        return;
    }

    double totalFolio = 0.0;
    int continuarProceso = 1;
    int folioActual = transacciones.size() + 1; 

    do {
        limpiarPantalla();
        impColor("\n============== AGREGAR TITULO AL FOLIO: " + to_string(folioActual) + " ==============\n", VERDE);
        
        impColor("Ingrese el código de la Película o Videojuego: ", AMARILLO);
        int prodID = leerInt();

        Producto* productoSeleccionado = nullptr;
        for (Producto* p : productos) {
            if (p->getID() == prodID) {
                productoSeleccionado = p;
                break;
            }
        }

        if (productoSeleccionado == nullptr) {
            impColor("\nEl código de producto no existe en el inventario.\n", ROJO);
        }
        // CORRECCIÓN: Validar disponibilidad basándose en el número de copias físicas restantes
        else if (productoSeleccionado->getNumCopia() <= 0) {
            impColor("\nLo sentimos, no quedan copias disponibles de este título.\n", ROJO);
        }
        else {
            impColor("\n¿Qué operación desea realizar?\n1. Renta\n2. Venta\nSeleccione una opción: ", AMARILLO);
            int tipoOperacion = leerInt();

            if (tipoOperacion != 1 && tipoOperacion != 2) {
                impColor("\nOpción de transacción inválida.\n", ROJO);
            }
            else {
                Modo modoActual = (tipoOperacion == 1) ? Renta : Venta;
                double costoItem = (modoActual == Renta) ? productoSeleccionado->getPrecioRenta() : productoSeleccionado->getPrecioVenta();
                bool esPelicula = (dynamic_cast<Pelicula*>(productoSeleccionado) != nullptr);

                // CORRECCIÓN: Validar el límite de rentas del cliente basándose en productos que siguen rentados actualmente
                if (modoActual == Renta) {
                    int rentasActivasMismoTipo = 0;
                    for (const Transaccion& t : transacciones) {
                        if (t.getClienteID() == cliID && t.getModoTransaccion() == Renta) {
                            for (Producto* pBuscado : productos) {
                                // Solo contamos la renta si el producto sigue teniendo estatus de "Rentada"
                                if (pBuscado->getID() == t.getProductoID() && pBuscado->getEstado() == Rentada) {
                                    bool busqEsPelicula = (dynamic_cast<Pelicula*>(pBuscado) != nullptr);
                                    if (esPelicula == busqEsPelicula) {
                                        rentasActivasMismoTipo++;
                                    }
                                }
                            }
                        }
                    }

                    if (rentasActivasMismoTipo >= 2) {
                        impColor("\nError: El cliente ya tiene 2 " + string(esPelicula ? "películas" : "videojuegos") + " rentados activamente.\n", ROJO);
                        esperarEnter();
                        continue;
                    }
                }

                // Despliegue automático de costo
                impColor("\nCosto calculado: $" + to_string(costoItem), CIAN);
                impColor("\n¿Aceptar y confirmar movimiento? (1 = Sí, 2 = No): ", AMARILLO);
                int confirmar = leerInt();

                if (confirmar == 1) {
                    // CORRECCIÓN: Reducir el inventario físico de copias del producto
                    productoSeleccionado->setNumCopia(productoSeleccionado->getNumCopia() - 1);
                    
                    // Si las copias llegan a 0, actualizamos su estatus global
                    if(productoSeleccionado->getNumCopia() == 0) {
                        productoSeleccionado->setEstado(modoActual == Renta ? Rentada : Vendida);
                    }

                    // Abonar comisión del 5% al empleado
                    double comisionCalculada = costoItem * 0.05;
                    empleadoActivo->agregarComision(comisionCalculada);

                    // Registrar la transacción
                    Transaccion t(folioActual, cliID, empID, prodID, modoActual);
                    transacciones.push_back(t);

                    totalFolio += costoItem;
                    impColor("\n¡Producto añadido con éxito al registro!\n", VERDE);
                } else {
                    impColor("\nMovimiento cancelado.\n", ROJO);
                }
            }
        }

        impColor("\n¿Quiere rentar o comprar otra película/videojuego? (1 = Sí, 2 = No): ", AMARILLO);
        continuarProceso = leerInt();

    } while (continuarProceso == 1);

    // Muestra de cuenta final neta
    limpiarPantalla();
    impColor("\n=================== TRANSACCIÓN FINALIZADA ===================\n", CIAN);
    impColor("\n\tFolio de Operación:   " + to_string(folioActual), BLANCO);
    impColor("\n\tCódigo del Cliente:   " + to_string(cliID), BLANCO);
    impColor("\n\tCódigo del Empleado:  " + to_string(empID), BLANCO);
    impColor("\n\t------------------------------------------------", CIAN);
    impColor("\n\tTOTAL NETO A PAGAR:  $" + to_string(totalFolio), VERDE);
    impColor("\n==============================================================\n", CIAN);
    esperarEnter();
}