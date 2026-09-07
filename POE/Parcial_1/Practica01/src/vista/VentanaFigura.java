package vista;

import java.awt.FlowLayout;
import javax.swing.*;

public class VentanaFigura {

    private JFrame vtn;
    private JTextField txtLargo = null;
    private JTextField txtAncho = null;
    private JTextField txtAlto = null;
    private JButton btnCalcular = null;
    private JLabel lblRes = null;

    public VentanaFigura() {
        vtn = new JFrame("Practica01");
        txtLargo = new JTextField();
        txtAncho = new JTextField();
        txtAlto = new JTextField();
        btnCalcular = new JButton();
        lblRes = new JLabel();
    }

    public void dibujarVentana() {
        vtn.setLayout(new FlowLayout());
        vtn.setSize(800, 1000);
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        txtLargo.setColumns(10);
        txtAncho.setColumns(10);
        txtAlto.setColumns(10);
        btnCalcular.setText("Calcular Volumen");

        vtn.add(new JLabel("Largo:"));
        vtn.add(txtLargo);
        vtn.add(new JLabel("Ancho:"));
        vtn.add(txtAncho);
        vtn.add(new JLabel("Alto:"));
        vtn.add(txtAlto);
        vtn.add(btnCalcular);
        vtn.add(lblRes);

        vtn.setVisible(true);
    }

    public JFrame getVtn() {
        return vtn;
    }

    public JTextField getTxtLargo() {
        return txtLargo;
    }

    public JTextField getTxtAncho() {
        return txtAncho;
    }

    public JTextField getTxtAlto() {
        return txtAlto;
    }

    public JButton getBtnCalcular() {
        return btnCalcular;
    }

    public JLabel getLblRes() {
        return lblRes;
    }
}
