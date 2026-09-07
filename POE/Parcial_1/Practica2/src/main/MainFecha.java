package main;

import controlador.ControladorFecha;
import modelo.Fecha;
import vista.VentanaFecha;

public class MainFecha {
    public static void main(String[] args) {
        Fecha objFecha = new Fecha();
        VentanaFecha vtnFecha = new VentanaFecha();
        ControladorFecha ctrlFecha = new ControladorFecha(objFecha, vtnFecha);

        vtnFecha.dibujarVentana();
    }
}
