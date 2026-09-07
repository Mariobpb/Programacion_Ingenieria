package controlador;

import modelo.Figura;
import vista.VentanaFigura;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class ControladorFigura implements ActionListener {
    private Figura figura;
    private VentanaFigura ventanaFigura;

    public ControladorFigura(Figura figura, VentanaFigura ventanaFigura) {
        this.figura = figura;
        this.ventanaFigura = ventanaFigura;

        this.ventanaFigura.getBtnCalcular().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == ventanaFigura.getBtnCalcular()){
            figura.setAlto(Double.parseDouble(ventanaFigura.getTxtAlto().getText()));
            figura.setAncho(Double.parseDouble(ventanaFigura.getTxtAncho().getText()));
            figura.setLargo(Double.parseDouble(ventanaFigura.getTxtLargo().getText()));
            figura.setVolumen(figura.obtenerVolumen());

            ventanaFigura.getTxtAlto().setText(String.valueOf(figura.getAlto()));
            ventanaFigura.getTxtAncho().setText(String.valueOf(figura.getAncho()));
            ventanaFigura.getTxtLargo().setText(String.valueOf(figura.getLargo()));
            ventanaFigura.getLblRes().setText("Volumen: " + String.valueOf(figura.getVolumen()) + " u^3");
        }
    }
}
