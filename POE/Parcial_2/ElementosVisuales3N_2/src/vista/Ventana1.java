package vista;

import controlador.ControlVentana1;

import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.*;


public class Ventana1 {
    private JFrame vtn1 = null;
    private JButton btnIrAvtn2 = null;
    private ControlVentana1 control = null;

    public Ventana1 (){
        vtn1 = new JFrame("Ventana 1");
        vtn1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtn1.setSize(500,300);
        vtn1.setResizable(false);
    }

    public void dibujarVentana() {
        btnIrAvtn2 = new JButton("Ir a Ventana 2");

        vtn1.setLayout(new FlowLayout());
        vtn1.add(btnIrAvtn2);
        vtn1.setVisible(true);

        control = new ControlVentana1(this);
    }

    public JFrame getVtn1() {
        return vtn1;
    }

    public JButton getBtnIrAvtn2() {
        return btnIrAvtn2;
    }
}
