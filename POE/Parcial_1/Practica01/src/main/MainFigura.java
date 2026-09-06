package main;

import controlador.ControladorFigura;
import modelo.Figura;
import vista.VentanaFigura;


public class MainFigura {
    public static void main(String[] args) {
        Figura objFigura1 = new Figura();
        VentanaFigura vtnFigura1 = new VentanaFigura();
        ControladorFigura ctrlFigura1 = new ControladorFigura(objFigura1, vtnFigura1);
        
        vtnFigura1.dibujarVentana();
    }
}
