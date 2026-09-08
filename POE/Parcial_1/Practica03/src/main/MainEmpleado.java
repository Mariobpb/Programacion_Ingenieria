package main;

import controlador.ControladorEmpleado;
import modelo.Empleado;
import vista.VentanaEmpleado;

public class MainEmpleado {
    public static void main(String[] args) {
        Empleado objEmpleado = new Empleado();
        VentanaEmpleado vtnEmpleado = new VentanaEmpleado();
        ControladorEmpleado ctrlEmpleado = new ControladorEmpleado(objEmpleado, vtnEmpleado);

        vtnEmpleado.dibujarVentana();
    }
}
