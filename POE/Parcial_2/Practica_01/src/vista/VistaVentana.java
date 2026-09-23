package vista;

import javax.swing.*;
import java.awt.*;

public class VistaVentana {
    private JFrame vista = null;
    private JPanel panelPrincipal = null;
    private JPanel panelCentral = null;
    private JPanel panelSur = null;

    private JPanel panelIng = null;
    private JPanel panelTurno = null;
    private JPanel panelPago = null;

    private JRadioButton rdbIDS = null;
    private JRadioButton rdbIDESI = null;
    private JRadioButton rdbMec = null;
    private JRadioButton rdbInd = null;
    private ButtonGroup btngIng = null;


    public VistaVentana() {
        vista = new JFrame("Practica_01");
        vista.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vista.setSize(600, 400);
        vista.setLocationRelativeTo(null);
        vista.setResizable(false);
    }

    public void dibujarVentana(){
        panelPrincipal = new JPanel();
        panelCentral = new JPanel();
        panelSur = new JPanel();
        panelIng = new JPanel();
        panelTurno = new JPanel();
        panelPago = new JPanel();

        panelPrincipal.setLayout(new BorderLayout(0, 10));
        panelCentral.setLayout(new FlowLayout());
        panelSur.setLayout(new FlowLayout());
        panelIng.setLayout(new BoxLayout(panelIng, BoxLayout.Y_AXIS));
        panelTurno.setLayout(new BoxLayout(panelTurno, BoxLayout.Y_AXIS));
        panelPago.setLayout(new BoxLayout(panelPago, BoxLayout.Y_AXIS));

        panelIng.add(new JLabel("Elije tu ingeniería"));
        panelIng.add(new JTextField(20));

        vista.setVisible(true);
    }
}
