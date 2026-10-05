package vista;

import controlador.ControlVentana2;

import javax.swing.*;
import java.awt.*;

public class Ventana2 {
    private Ventana1 vtn1;
    private JFrame vtn2 = null;
    private JButton btnIrAvtn1 = null;
    private ControlVentana2 control = null;

    public Ventana2 (Ventana1 vtn1){
        vtn2 = new JFrame("Ventana 2");
        vtn2.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        vtn2.setSize(300,100);
        vtn2.setResizable(false);
        this.vtn1 = vtn1;
    }

    public void dibujarVentana() {
        btnIrAvtn1 = new JButton("Ir a Ventana 1");

        vtn2.setLayout(new FlowLayout());
        vtn2.add(btnIrAvtn1);
        vtn2.setVisible(true);
        control = new ControlVentana2(this);
    }

    public Ventana1 getVtn1() {
        return vtn1;
    }

    public JFrame getVtn2() {
        return vtn2;
    }

    public JButton getBtnIrAvtn1() {
        return btnIrAvtn1;
    }
}
