package controlador;

import modelo.Figura;
import vista.VentanaFigura;


public class ControladorFigura {
    private Figura figura;
    private VentanaFigura ventanaFigura;

    public ControladorFigura(Figura figura, VentanaFigura ventanaFigura) {
        this.figura = figura;
        this.ventanaFigura = ventanaFigura;
    }
}
