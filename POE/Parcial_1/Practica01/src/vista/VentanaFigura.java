package vista;

import java.awt.FlowLayout;
import javax.swing.JFrame;

public class VentanaFigura {

    private JFrame vtn;

    public void dibujarVentana() {
        vtn = new JFrame();
        vtn.setLayout(new FlowLayout());
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        vtn.setSize(1000, 1500);
        vtn = new JFrame("Practica01");

        vtn.setVisible(true);
    }
}
