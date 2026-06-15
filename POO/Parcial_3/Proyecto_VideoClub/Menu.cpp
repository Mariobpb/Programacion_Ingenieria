#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    void procesarRentaVenta();
    void devolverProducto();
};

bool Menu::validarContrasena()
{
    string contrasenaIngresada;
    cout << RESET << LIMPIAR;
    impColor("\n================ SEGURIDAD DEL SISTEMA ================\n", AMARILLO);
    impColor("\n\nIngrese la contrasenia del sistema: ", AMARILLO);
    contrasenaIngresada = leerString();

    if (contrasenaIngresada == contrasena)
    {
        impColor("\n\n\nContrasena correcta. Accediendo al sistema...\n", VERDE);
        esperarEnter();
        return true;
    }

    impColor("\n\n\nContrasena incorrecta. Acceso denegado.\n", ROJO);
    esperarEnter();
    return false;
}

void Menu::menuPrincipal()
{
    cout << fixed << setprecision(2);
    int opcion;
    do
    {
        limpiarPantalla();
        impColor("\n================ MENU PRINCIPAL ================\n", AZUL);
        impColor("\n1. Clientes", AZUL);
        impColor("\n2. Peliculas y Videojuegos", AZUL);
        impColor("\n3. Empleados", AZUL);
        impColor("\n4. Realizar Renta / Venta", AZUL);
        impColor("\n5. Salir del Sistema", AZUL);
        impColor("\n\nSeleccione una opcion: ", AMARILLO);
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
        case 5:
            impColor("\nSaliendo del sistema...\n", VERDE);
            break;
        default:
            impColor("\nOpcion no valida. Intente de nuevo.\n", ROJO);
            esperarEnter();
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
        impColor("\n\t5. REPORTES DE PRODUCTOS (DISPONIBLES / RENTADOS / VENDIDOS)", MAGENTA);
        impColor("\n\t6. REGRESAR AL MENU PRINCIPAL", MAGENTA);
        impColor("\n\nIngrese su opcion: ", AMARILLO);
        opcion = leerInt();
        switch (opcion)
        {
        case 1:
        {
            limpiarPantalla();
            impColor("\n============== REGISTRAR NUEVO PRODUCTO ==============\n", VERDE);
            impColor("\nQue desea registrar?", VERDE);
            impColor("\n1. Pelicula", VERDE);
            impColor("\n2. Videojuego", VERDE);
            impColor("\n\nSeleccione una opcion: ", AMARILLO);
            int tipo = leerInt();

            if (tipo != 1 && tipo != 2)
            {
                impColor("\nOpcion no valida.\n", ROJO);
                esperarEnter();
                break;
            }

            string nombre, genero;
            double pVenta, pRenta;

            impColor("Nombre del titulo: ", VERDE);
            nombre = leerString();
            impColor("Genero: ", VERDE);
            genero = leerString();
            impColor("Precio de Venta: $", VERDE);
            pVenta = leerDouble();
            impColor("Precio de Renta: $", VERDE);
            pRenta = leerDouble();

            if (tipo == 1)
            {
                string director;
                impColor("Director de la pelicula: ", VERDE);
                director = leerString();
                Pelicula *nuevaPeli = new Pelicula(nombre, genero, pVenta, pRenta, director);
                productos.push_back(nuevaPeli);
                impColor("\nPelicula registrada con exito. ID Asignado: " + to_string(nuevaPeli->getID()) + "\n", VERDE);
            }
            else
            {
                Videojuego *nuevoJuego = new Videojuego(nombre, genero, pVenta, pRenta);
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

                    impColor("\n\tCopias Disponibles:  '  " + to_string(p->getNumCopia()), VERDE);
                    impColor("\n\tCopias Rentadas:       " + to_string(p->getRentadas()), VERDE);
                    impColor("\n\tCopias Vendidas:       " + to_string(p->getVendidas()), VERDE);

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
                nVenta = leerDouble();
                objetivo->setPrecioVenta(nVenta);
                impColor("Nuevo Precio Renta: $", VERDE);
                nRenta = leerDouble();
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
            int opReporte;
            do
            {
                limpiarPantalla();
                impColor("\n============== REPORTES DE PRODUCTOS ==============\n", CIAN);
                impColor("\n\t1. REPORTE DE PRODUCTOS DISPONIBLES", CIAN);
                impColor("\n\t2. REPORTE DE PRODUCTOS RENTADOS", CIAN);
                impColor("\n\t3. REPORTE DE PRODUCTOS VENDIDOS", CIAN);
                impColor("\n\t4. MOSTRAR TODO EL INVENTARIO", CIAN);
                impColor("\n\t5. REGRESAR AL MENU ANTERIOR", CIAN);
                impColor("\n\nIngrese su opcion: ", AMARILLO);
                opReporte = leerInt();

                if (opReporte >= 1 && opReporte <= 4)
                {
                    limpiarPantalla();
                    string tituloReporte;
                    Estatus estatusBuscado;

                    if (opReporte == 1)
                    {
                        tituloReporte = "DISPONIBLES";
                        estatusBuscado = Disponible;
                    }
                    else if (opReporte == 2)
                    {
                        tituloReporte = "RENTADOS";
                        estatusBuscado = Rentada;
                    }
                    else if (opReporte == 3)
                    {
                        tituloReporte = "VENDIDOS";
                        estatusBuscado = Vendida;
                    }
                    else
                        tituloReporte = "COMPLETO DE INVENTARIO";

                    impColor("\n============== REPORTE DE PRODUCTOS " + tituloReporte + " ==============\n", VERDE);

                    if (productos.empty())
                        impColor("\nSin productos registrados en el sistema.\n", ROJO);
                    else
                    {
                        bool hayCoincidencias = false;
                        for (Producto *p : productos)
                        {

                            if (opReporte == 4 || p->getEstado() == estatusBuscado)
                            {
                                p->mostrarInfo();
                                impColor("\n\n--------------------------------------------------\n", VERDE);
                                hayCoincidencias = true;
                            }
                        }
                        if (!hayCoincidencias)
                            impColor("\nNo se encontraron productos con el estatus de este reporte.\n", ROJO);
                    }
                    esperarEnter();
                }
            } while (opReporte != 5);
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
                    impColor("\n----------------------------------------\n", VERDE);
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
                    impColor("\n----------------------------------------\n", VERDE);
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
    int opcion;
    do
    {
        limpiarPantalla();
        impColor("\n============== RENTAS Y VENTAS ==============\n", MAGENTA);
        impColor("\n1. Registrar una Renta o Venta (Folio)", MAGENTA);
        impColor("\n2. Procesar Devolucion de Producto", MAGENTA);
        impColor("\n3. Volver al Menu Principal", MAGENTA);
        impColor("\n\nSeleccione una opcion: ", AMARILLO);
        opcion = leerInt();

        switch (opcion)
        {
        case 1:
            procesarRentaVenta();
            break;
        case 2:
            devolverProducto();
            break;
        case 3:
            break;
        default:
            impColor("\nOpcion no valida.\n", ROJO);
            esperarEnter();
            break;
        }
    } while (opcion != 3);
}
void Menu::procesarRentaVenta()
{
    limpiarPantalla();
    impColor("\n============== REALIZAR UNA RENTA / VENTA ==============\n\n", VERDE);

    bool hayEmpleados = false;
    bool hayClientes = false;

    for (Persona *p : personas)
    {
        if (dynamic_cast<Empleado *>(p) != nullptr)
            hayEmpleados = true;
        if (dynamic_cast<Cliente *>(p) != nullptr)
            hayClientes = true;
    }

    if (!hayEmpleados || !hayClientes)
    {
        impColor("\nError: Para realizar una operacion es indispensable que exista al menos un Empleado y un Cliente registrados en el sistema.\n", ROJO);
        esperarEnter();
        return;
    }

    impColor("\nIngrese el codigo del Empleado: ", AMARILLO);
    int empID = leerInt();
    Empleado *empleadoActivo = nullptr;
    for (Persona *p : personas)
    {
        Empleado *e = dynamic_cast<Empleado *>(p);
        if (e != nullptr && e->getEmpleadoID() == empID)
        {
            empleadoActivo = e;
            break;
        }
    }
    if (empleadoActivo == nullptr)
    {
        impColor("\nCodigo de empleado no valido.\n", ROJO);
        esperarEnter();
        return;
    }

    impColor("\nIngrese el codigo del Cliente: ", AMARILLO);
    int cliID = leerInt();
    Cliente *clienteActivo = nullptr;
    for (Persona *p : personas)
    {
        Cliente *c = dynamic_cast<Cliente *>(p);
        if (c != nullptr && c->getClienteID() == cliID)
        {
            clienteActivo = c;
            break;
        }
    }
    if (clienteActivo == nullptr)
    {
        impColor("\nCodigo de cliente no valido.\n", ROJO);
        esperarEnter();
        return;
    }

    double totalFolio = 0.0;
    int continuarProceso = 1;
    int folioActual = transacciones.size() + 1;

    do
    {
        limpiarPantalla();
        impColor("\n============== AGREGANDO AL FOLIO: " + to_string(folioActual) + " ==============\n", VERDE);

        impColor("\nIngrese el codigo de la Pelicula o Videojuego: ", AMARILLO);
        int prodID = leerInt();

        Producto *productoSeleccionado = nullptr;
        for (Producto *p : productos)
        {
            if (p->getID() == prodID)
            {
                productoSeleccionado = p;
                break;
            }
        }

        if (productoSeleccionado == nullptr)
            impColor("\nEl codigo de producto no existe en el inventario.\n", ROJO);

        else if (productoSeleccionado->getEstado() == Vendida)
            impColor("\nLo sentimos, este producto ya fue vendido permanentemente.\n", ROJO);

        else if (productoSeleccionado->getNumCopia() <= 0)
            impColor("\nLo sentimos, no quedan copias disponibles de este titulo.\n", ROJO);

        else
        {
            impColor("\nQue operacion desea realizar?", VERDE);
            impColor("\n1. Renta", VERDE);
            impColor("\n2. Venta", VERDE);
            impColor("\n\nSeleccione una opcion: ", AMARILLO);
            int tipoOperacion = leerInt();

            if (tipoOperacion != 1 && tipoOperacion != 2)
                impColor("\nOpciOn de transacciOn invalida.\n", ROJO);
            else
            {
                Modo modoActual = (tipoOperacion == 1) ? Renta : Venta;
                double costoItem = (modoActual == Renta) ? productoSeleccionado->getPrecioRenta() : productoSeleccionado->getPrecioVenta();
                bool esPelicula = (dynamic_cast<Pelicula *>(productoSeleccionado) != nullptr);

                if (modoActual == Renta)
                {
                    Pelicula *peli = dynamic_cast<Pelicula *>(productoSeleccionado);
                    Videojuego *juego = dynamic_cast<Videojuego *>(productoSeleccionado);

                    if (peli)
                    {
                        if (!clienteActivo->verificarLimite(peli))
                        {
                            impColor("\nError: El cliente ya tiene 2 peliculas rentadas activamente.\n", ROJO);
                            esperarEnter();
                            continue;
                        }
                    }
                    else if (juego)
                    {
                        if (!clienteActivo->verificarLimite(juego))
                        {
                            impColor("\nError: El cliente ya tiene 2 videojuegos rentados activamente.\n", ROJO);
                            esperarEnter();
                            continue;
                        }
                    }

                    int maxRentasPermitidasDelTitulo = 5 - productoSeleccionado->getVendidas();
                    if (productoSeleccionado->getRentadas() >= maxRentasPermitidasDelTitulo)
                    {
                        impColor("\nError: Limite de rentas simultaneas (" + to_string(maxRentasPermitidasDelTitulo) + ") alcanzado para este titulo debido a copias vendidas.\n", ROJO);
                        esperarEnter();
                        continue;
                    }
                }

                impColor("\nCosto calculado: $" + to_string(costoItem), BLANCO);
                impColor("\n\nAceptar y confirmar movimiento? (1 = Si, 2 = No): ", AMARILLO);
                int confirmar = leerInt();

                if (confirmar == 1)
                {

                    if (modoActual == Venta)
                    {

                        productoSeleccionado->setNumCopia(productoSeleccionado->getNumCopia() - 1);
                        productoSeleccionado->setVendidas(productoSeleccionado->getVendidas() + 1);

                        if (productoSeleccionado->getNumCopia() == 0)
                        {
                            if (modoActual == Venta)
                            {

                                bool tieneRentasActivas = false;
                                for (const Transaccion &t : transacciones)
                                {

                                    if (t.getProductoID() == prodID && t.getModoTransaccion() == Renta)
                                    {
                                        tieneRentasActivas = true;
                                        break;
                                    }
                                }

                                if (tieneRentasActivas)
                                    productoSeleccionado->setEstado(Rentada);
                                else
                                    productoSeleccionado->setEstado(Vendida);
                            }
                            else
                                productoSeleccionado->setEstado(Rentada);
                        }
                    }
                    else if (modoActual == Renta)
                    {

                        productoSeleccionado->setNumCopia(productoSeleccionado->getNumCopia() - 1);
                        productoSeleccionado->setRentadas(productoSeleccionado->getRentadas() + 1);

                        if (productoSeleccionado->getNumCopia() == 0)
                            productoSeleccionado->setEstado(Rentada);
                        else
                            productoSeleccionado->setEstado(Disponible);

                        if (esPelicula)
                            clienteActivo->setPelisRentadas(clienteActivo->getPelisRentadas() + 1);
                        else
                            clienteActivo->setVideojuegosRentados(clienteActivo->getVideojuegosRentados() + 1);

                        costoItem = productoSeleccionado->getPrecioRenta();
                    }

                    double comisionCalculada = costoItem * 0.05;
                    empleadoActivo->agregarComision(comisionCalculada);

                    Transaccion t(folioActual, cliID, empID, prodID, modoActual);
                    transacciones.push_back(t);

                    totalFolio += costoItem;
                    impColor("\n¡Producto añadido con exito al registro!\n", VERDE);
                }
                else
                    impColor("\nMovimiento cancelado.\n", ROJO);
            }
        }

        impColor("\nQuiere rentar o comprar otra pelicula/videojuego? (1 = Si, 2 = No): ", AMARILLO);
        continuarProceso = leerInt();

    } while (continuarProceso == 1);

    limpiarPantalla();
    impColor("\n=================== TRANSACCION FINALIZADA ===================\\n", CIAN);
    impColor("\n\tFolio de Operacion:   " + to_string(folioActual), BLANCO);
    impColor("\n\tCodigo del Cliente:   " + to_string(cliID), BLANCO);
    impColor("\n\tCodigo del Empleado:  " + to_string(empID), BLANCO);
    impColor("\n\t------------------------------------------------", CIAN);
    impColor("\n\tTOTAL NETO A PAGAR:  $" + to_string(totalFolio), VERDE);
    impColor("\n==============================================================\n", CIAN);
    esperarEnter();
}

void Menu::devolverProducto()
{
    limpiarPantalla();
    impColor("\n============== PROCESAR DEVOLUCION ==============\n", CIAN);
    impColor("\nIngrese el codigo del Cliente que devuelve: ", AMARILLO);
    int cliID = leerInt();
    Cliente *clienteActivo = nullptr;
    for (Persona *p : personas)
    {
        Cliente *c = dynamic_cast<Cliente *>(p);
        if (c != nullptr && c->getClienteID() == cliID)
        {
            clienteActivo = c;
            break;
        }
    }

    if (clienteActivo == nullptr)
    {
        impColor("\nCodigo de cliente no valido.\n", ROJO);
        esperarEnter();
        return;
    }

    if (clienteActivo->getPelisRentadas() == 0 && clienteActivo->getVideojuegosRentados() == 0)
    {
        impColor("\nEste cliente no cuenta con rentas activas en el sistema.\n", ROJO);
        esperarEnter();
        return;
    }

    impColor("Ingrese el codigo del Producto (Pelicula/Videojuego) a devolver: ", AMARILLO);
    int prodID = leerInt();
    Producto *productoSeleccionado = nullptr;
    for (Producto *p : productos)
    {
        if (p->getID() == prodID)
        {
            productoSeleccionado = p;
            break;
        }
    }

    if (productoSeleccionado == nullptr)
    {
        impColor("\nEl codigo de producto no existe en el inventario.\n", ROJO);
        esperarEnter();
        return;
    }

    bool transaccionEncontrada = false;
    for (const Transaccion &t : transacciones)
    {
        if (t.getClienteID() == cliID && t.getProductoID() == prodID && t.getModoTransaccion() == Renta)
        {
            transaccionEncontrada = true;
            break;
        }
    }

    if (!transaccionEncontrada)
    {
        impColor("\nNo se encontro un registro de renta de este producto para el cliente ingresado.\n", ROJO);
        esperarEnter();
        return;
    }

    bool esPelicula = (dynamic_cast<Pelicula *>(productoSeleccionado) != nullptr);

    productoSeleccionado->setNumCopia(productoSeleccionado->getNumCopia() + 1);
    productoSeleccionado->setRentadas(productoSeleccionado->getRentadas() - 1);

    if (productoSeleccionado->getNumCopia() > 0)
        productoSeleccionado->setEstado(Disponible);

    if (esPelicula && (clienteActivo->getPelisRentadas() > 0))
        clienteActivo->setPelisRentadas(clienteActivo->getPelisRentadas() - 1);

    else if (clienteActivo->getVideojuegosRentados() > 0)
        clienteActivo->setVideojuegosRentados(clienteActivo->getVideojuegosRentados() - 1);

    impColor("\n========================================================", VERDE);
    impColor("\n¡Devolucion procesada con exito!", VERDE);
    impColor("\nStock actualizado. El contador del cliente ha sido liberado.", CIAN);
    impColor("\n========================================================\n", VERDE);
    esperarEnter();
}