package main;

import controlador.ControladorCuentaBanco;
import modelo.CuentaBanco;
import vista.VentanaCuentaBanco;

public class MainCuentaBanco {
    public static void main(String[] args) {
        CuentaBanco objCuentaBanco = new CuentaBanco();
        VentanaCuentaBanco ventana = new VentanaCuentaBanco();
        ControladorCuentaBanco ctrlCuentaBanco = new ControladorCuentaBanco(objCuentaBanco, ventana);

        ventana.dibujarVentana();
    }
}
