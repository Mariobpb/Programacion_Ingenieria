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
    private JButton btnImpFechaCorta = null;
    private JButton btnImpFechaLarga = null;
    private JLabel lblRes = null;

    public VentanaFecha() {
        vtn = new JFrame("Practica01");
        txtDia = new JTextField();
        txtMes = new JTextField();
        txtAnio = new JTextField();
        btnImpFechaCorta = new JButton();
        btnImpFechaLarga = new JButton();
        lblRes = new JLabel();
    }

    public void dibujarVentana() {
        vtn.setLayout(new FlowLayout());
        vtn.setSize(800, 1000);
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        txtDia.setColumns(10);
        txtMes.setColumns(10);
        txtAnio.setColumns(10);
        btnImpFechaCorta.setText("Imprimir fecha corta");
        btnImpFechaLarga.setText("Imprimir fecha larga");

        vtn.add(new JLabel("Dia:"));
        vtn.add(txtDia);
        vtn.add(new JLabel("Mes:"));
        vtn.add(txtMes);
        vtn.add(new JLabel("Anio:"));
        vtn.add(txtAnio);
        vtn.add(btnImpFechaCorta);
        vtn.add(btnImpFechaLarga);
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

    public JButton getBtnImpFechaCorta() {
        return btnImpFechaCorta;
    }

    public JButton getBtnImpFechaLarga() {
        return btnImpFechaLarga;
    }

    public JLabel getLblRes() {
        return lblRes;
    }
}
