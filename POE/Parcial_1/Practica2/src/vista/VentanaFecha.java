package vista;

import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class VentanaFecha {
    private JFrame vtn = null;
    private JTextField txtDia = null;
    private JTextField txtMes = null;
    private JTextField txtAnio = null;
    private JButton btnVerificar = null;
    private JLabel lblRes = null;

    public VentanaFecha() {
        vtn = new JFrame();
        txtDia = new JTextField();
        txtMes = new JTextField();
        txtAnio = new JTextField();
        btnVerificar = new JButton();
        lblRes = new JLabel();
    }

    public void dibujarVentana() {
        vtn.setLayout(new FlowLayout());
        vtn.setSize(800, 1000);
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        txtDia.setColumns(10);
        txtMes.setColumns(10);
        txtAnio.setColumns(10);
        btnVerificar.setText("Verificar fecha");

        vtn.add(new JLabel("Dia:"));
        vtn.add(txtDia);
        vtn.add(new JLabel("Mes:"));
        vtn.add(txtMes);
        vtn.add(new JLabel("Anio:"));
        vtn.add(txtAnio);
        vtn.add(btnVerificar);
        vtn.add(lblRes);

        vtn.setVisible(true);
    }

    public JFrame getVtn() {
        return vtn;
    }

    public JTextField getTxtDia() {
        return txtDia;
    }

    public JTextField getTxtMes() {
        return txtMes;
    }

    public JTextField getTxtAnio() {
        return txtAnio;
    }

    public JButton getBtnVerificar() {
        return btnVerificar;
    }

    public JLabel getLblRes() {
        return lblRes;
    }
}
