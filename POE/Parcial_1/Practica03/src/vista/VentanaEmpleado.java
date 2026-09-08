package vista;

import javax.swing.*;
import java.awt.*;

public class VentanaEmpleado {
    private JFrame ventana = null;
    private JTextField txtNombre = null;
    private JTextField txtPuesto = null;
    private JTextField txtPagoHora = null;
    private JTextField txtHorasTrabajadasMes = null;
    private JButton btnSalarioMensual = null;
    private JLabel lblInfo = null;

    public VentanaEmpleado() {
        ventana = new JFrame("Practica03");
        txtNombre = new JTextField(10);
        txtPuesto = new JTextField(10);
        txtPagoHora = new JTextField(10);
        txtHorasTrabajadasMes = new JTextField(10);
        btnSalarioMensual = new JButton("Calcular Salario Mensual");
        lblInfo = new JLabel();
    }

    public void dibujarVentana(){
        ventana.setLayout(new FlowLayout());
        ventana.setSize(800, 1000);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ventana.add(new JLabel("Nombre:"));
        ventana.add(txtNombre);
        ventana.add(new JLabel("Puesto:"));
        ventana.add(txtPuesto);
        ventana.add(new JLabel("Pago hora:"));
        ventana.add(txtPagoHora);
        ventana.add(new JLabel("Horas trabajadas mes:"));
        ventana.add(txtHorasTrabajadasMes);
        ventana.add(btnSalarioMensual);
        ventana.add(lblInfo);

        ventana.setVisible(true);
    }

    public JFrame getVentana() {
        return ventana;
    }

    public JTextField getTxtNombre() {
        return txtNombre;
    }

    public JTextField getTxtPuesto() {
        return txtPuesto;
    }

    public JTextField getTxtPagoHora() {
        return txtPagoHora;
    }

    public JTextField getTxtHorasTrabajadasMes() {
        return txtHorasTrabajadasMes;
    }

    public JButton getBtnSalarioMensual() {
        return btnSalarioMensual;
    }

    public JLabel getLblInfo() {
        return lblInfo;
    }
}
