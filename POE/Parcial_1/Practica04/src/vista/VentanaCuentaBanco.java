package vista;

import java.awt.*;
import javax.swing.*;

public class VentanaCuentaBanco {

    private JFrame vtn;
    private CardLayout tarjeta;
    private JPanel panel;

    private JButton btnMenuCrear;
    private JButton btnMenuImprimir;
    private JButton btnMenuAbonar;
    private JButton btnMenuRetirar;
    private JButton btnMenuSalir;

    private JTextField txtNombreC;
    private JTextField txtNumeroC;
    private JTextField txtSaldoInicial;
    private JButton btnGuardarCuenta;

    private JTextField txtAbonar;
    private JButton btnConfirmarAbono;

    private JTextField txtRetirar;
    private JButton btnConfirmarRetiro;

    private JTextArea txtInfo;

    public VentanaCuentaBanco() {
        vtn = new JFrame("Práctica 04 - Gestión Cuenta Bancaria");
        btnMenuCrear = new JButton("1. Crear Cuenta");
        btnMenuImprimir = new JButton("2. Imprimir Datos");
        btnMenuAbonar = new JButton("3. Abonar");
        btnMenuRetirar = new JButton("4. Retirar");
        btnMenuSalir = new JButton("5. Salir");

        txtNombreC = new JTextField();
        txtNumeroC = new JTextField();
        txtSaldoInicial = new JTextField();
        btnGuardarCuenta = new JButton("Guardar Cuenta");

        txtInfo = new JTextArea();

        txtAbonar = new JTextField(10);
        btnConfirmarAbono = new JButton("Realizar Abono");

        txtRetirar = new JTextField(10);
        btnConfirmarRetiro = new JButton("Realizar Retiro");
    }

    public void dibujarVentana() {
        vtn.setLayout(new BorderLayout());
        tarjeta = new CardLayout();
        panel = new JPanel(tarjeta);

        vtn.setSize(900, 500);
        vtn.setLocationRelativeTo(null);
        vtn.setResizable(false);
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        JPanel panelMenu = new JPanel(new GridLayout(1, 5, 25, 5));
        panelMenu.setBorder(BorderFactory.createTitledBorder("Menú"));

        panelMenu.add(btnMenuCrear);
        panelMenu.add(btnMenuImprimir);
        panelMenu.add(btnMenuAbonar);
        panelMenu.add(btnMenuRetirar);
        panelMenu.add(btnMenuSalir);

        vtn.add(panelMenu, BorderLayout.NORTH);


        JPanel cardCrear = new JPanel(new GridLayout(4, 2, 10, 10));
        cardCrear.setBorder(BorderFactory.createTitledBorder("Crear Nueva Cuenta"));

        txtNombreC.setFont(new Font("Arial", Font.BOLD, 14));
        txtNumeroC.setFont(new Font("Arial", Font.BOLD, 14));
        txtSaldoInicial.setFont(new Font("Arial", Font.BOLD, 14));

        cardCrear.add(new JLabel(" Nombre del Cliente:"));
        cardCrear.add(txtNombreC);
        cardCrear.add(new JLabel(" Número de Cuenta:"));
        cardCrear.add(txtNumeroC);
        cardCrear.add(new JLabel(" Saldo Inicial:"));
        cardCrear.add(txtSaldoInicial);
        cardCrear.add(btnGuardarCuenta);


        JPanel cardImprimir = new JPanel(new BorderLayout());
        cardImprimir.setBorder(BorderFactory.createTitledBorder("Información de la Cuenta"));

        txtInfo.setEditable(false);

        cardImprimir.add(txtInfo);


        JPanel cardAbonar = new JPanel(new FlowLayout(FlowLayout.LEFT, 15, 20));
        cardAbonar.setBorder(BorderFactory.createTitledBorder("Abonar a la Cuenta"));

        cardAbonar.add(new JLabel("Monto a Abonar: $"));
        cardAbonar.add(txtAbonar);
        cardAbonar.add(btnConfirmarAbono);


        JPanel cardRetirar = new JPanel(new FlowLayout(FlowLayout.LEFT, 15, 20));
        cardRetirar.setBorder(BorderFactory.createTitledBorder("Retirar de la Cuenta"));

        cardRetirar.add(new JLabel("Monto a Retirar: $"));
        cardRetirar.add(txtRetirar);
        cardRetirar.add(btnConfirmarRetiro);


        panel.add(cardCrear, "CARD_CREAR");
        panel.add(cardImprimir, "CARD_IMPRIMIR");
        panel.add(cardAbonar, "CARD_ABONAR");
        panel.add(cardRetirar, "CARD_RETIRAR");

        vtn.add(panel, BorderLayout.CENTER);
        vtn.setVisible(true);
    }

    public JButton getBtnMenuCrear() { return btnMenuCrear; }
    public JButton getBtnMenuImprimir() { return btnMenuImprimir; }
    public JButton getBtnMenuAbonar() { return btnMenuAbonar; }
    public JButton getBtnMenuRetirar() { return btnMenuRetirar; }
    public JButton getBtnMenuSalir() { return btnMenuSalir; }
    public JTextField getTxtNombreC() { return txtNombreC; }
    public JTextField getTxtNumeroC() { return txtNumeroC; }
    public JTextField getTxtSaldoInicial() { return txtSaldoInicial; }
    public JButton getBtnGuardarCuenta() { return btnGuardarCuenta; }
    public JTextField getTxtAbonar() { return txtAbonar; }
    public JButton getBtnConfirmarAbono() { return btnConfirmarAbono; }
    public JTextField getTxtRetirar() { return txtRetirar; }
    public JButton getBtnConfirmarRetiro() { return btnConfirmarRetiro; }
    public JTextArea getTxtInfo() { return txtInfo; }

    public void mostrarTarjeta(String nombreTarjeta) {
        tarjeta.show(panel, nombreTarjeta);
    }
}