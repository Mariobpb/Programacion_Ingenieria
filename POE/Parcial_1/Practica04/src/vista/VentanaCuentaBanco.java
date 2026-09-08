package vista;

import java.awt.*;
import javax.swing.*;

public class VentanaCuentaBanco {

    private JFrame vtn;

    // Botones del Menú Lateral (Opciones de la práctica)
    private JButton btnOpCrear;
    private JButton btnOpImprimir;
    private JButton btnOpAbonar;
    private JButton btnOpRetirar;
    private JButton btnOpSalir;

    // Paneles para el CardLayout (Vistas dinámicas)
    private CardLayout cardLayout;
    private JPanel panelCentral;

    // Campos del Formulario "Crear Cuenta"
    private JTextField txtNombreC;
    private JTextField txtNumeroC;
    private JTextField txtSaldoInicial;
    private JButton btnGuardarCuenta;

    // Campos de Formulario "Abonar / Retirar"
    private JTextField txtMontoAbono;
    private JButton btnConfirmarAbono;

    private JTextField txtMontoRetiro;
    private JButton btnConfirmarRetiro;

    // Área de Texto / Salida de Resultados
    private JTextArea txtAreaConsulta;

    public VentanaCuentaBanco() {
        vtn = new JFrame("Práctica 04 - Gestión Cuenta Bancaria");
    }

    public void dibujarVentana() {
        vtn.setLayout(new BorderLayout(10, 10));
        vtn.setSize(750, 450);
        vtn.setLocationRelativeTo(null); // Centrar en pantalla
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // ========================================================
        // 1. MENU LATERAL (Opciones 1 a 5 solicitadas)
        // ========================================================
        JPanel panelMenu = new JPanel(new GridLayout(5, 1, 5, 10));
        panelMenu.setBorder(BorderFactory.createTitledBorder("Menú Opciones"));

        btnOpCrear = new JButton("1. Crear Cuenta");
        btnOpImprimir = new JButton("2. Imprimir Datos");
        btnOpAbonar = new JButton("3. Abonar");
        btnOpRetirar = new JButton("4. Retirar");
        btnOpSalir = new JButton("5. Salir");

        panelMenu.add(btnOpCrear);
        panelMenu.add(btnOpImprimir);
        panelMenu.add(btnOpAbonar);
        panelMenu.add(btnOpRetirar);
        panelMenu.add(btnOpSalir);

        vtn.add(panelMenu, BorderLayout.WEST);

        // ========================================================
        // 2. PANEL CENTRAL (CardLayout para cambiar de pantalla)
        // ========================================================
        cardLayout = new CardLayout();
        panelCentral = new JPanel(cardLayout);
        panelCentral.setBorder(BorderFactory.createEtchedBorder());

        // Card 1: Crear Cuenta
        JPanel cardCrear = new JPanel(new GridLayout(4, 2, 10, 10));
        cardCrear.setBorder(BorderFactory.createTitledBorder("Crear Nueva Cuenta"));
        txtNombreC = new JTextField();
        txtNumeroC = new JTextField();
        txtSaldoInicial = new JTextField();
        btnGuardarCuenta = new JButton("Guardar Cuenta");

        cardCrear.add(new JLabel(" Nombre del Cliente:"));
        cardCrear.add(txtNombreC);
        cardCrear.add(new JLabel(" Número de Cuenta:"));
        cardCrear.add(txtNumeroC);
        cardCrear.add(new JLabel(" Saldo Inicial:"));
        cardCrear.add(txtSaldoInicial);
        cardCrear.add(new JLabel("")); // Espacio vacío
        cardCrear.add(btnGuardarCuenta);

        // Card 2: Imprimir Datos
        JPanel cardImprimir = new JPanel(new BorderLayout());
        cardImprimir.setBorder(BorderFactory.createTitledBorder("Información de la Cuenta"));
        txtAreaConsulta = new JTextArea();
        txtAreaConsulta.setEditable(false);
        cardImprimir.add(new JScrollPane(txtAreaConsulta), BorderLayout.CENTER);

        // Card 3: Abonar
        JPanel cardAbonar = new JPanel(new FlowLayout(FlowLayout.LEFT, 15, 20));
        cardAbonar.setBorder(BorderFactory.createTitledBorder("Abonar a la Cuenta"));
        txtMontoAbono = new JTextField(10);
        btnConfirmarAbono = new JButton("Realizar Abono");
        cardAbonar.add(new JLabel("Monto a Abonar: $"));
        cardAbonar.add(txtMontoAbono);
        cardAbonar.add(btnConfirmarAbono);

        // Card 4: Retirar
        JPanel cardRetirar = new JPanel(new FlowLayout(FlowLayout.LEFT, 15, 20));
        cardRetirar.setBorder(BorderFactory.createTitledBorder("Retirar de la Cuenta"));
        txtMontoRetiro = new JTextField(10);
        btnConfirmarRetiro = new JButton("Realizar Retiro");
        cardRetirar.add(new JLabel("Monto a Retirar: $"));
        cardRetirar.add(txtMontoRetiro);
        cardRetirar.add(btnConfirmarRetiro);

        // Agregar tarjetas al CardLayout con una clave identificadora
        panelCentral.add(cardCrear, "CARD_CREAR");
        panelCentral.add(cardImprimir, "CARD_IMPRIMIR");
        panelCentral.add(cardAbonar, "CARD_ABONAR");
        panelCentral.add(cardRetirar, "CARD_RETIRAR");

        vtn.add(panelCentral, BorderLayout.CENTER);
        vtn.setVisible(true);
    }

    // Método para cambiar la vista visible según la opción elegida
    public void mostrarTarjeta(String nombreTarjeta) {
        cardLayout.show(panelCentral, nombreTarjeta);
    }

    // --- GETTERS DE COMPONENTES ---
    public JButton getBtnOpCrear() { return btnOpCrear; }
    public JButton getBtnOpImprimir() { return btnOpImprimir; }
    public JButton getBtnOpAbonar() { return btnOpAbonar; }
    public JButton getBtnOpRetirar() { return btnOpRetirar; }
    public JButton getBtnOpSalir() { return btnOpSalir; }

    public JTextField getTxtNombreC() { return txtNombreC; }
    public JTextField getTxtNumeroC() { return txtNumeroC; }
    public JTextField getTxtSaldoInicial() { return txtSaldoInicial; }
    public JButton getBtnGuardarCuenta() { return btnGuardarCuenta; }

    public JTextField getTxtMontoAbono() { return txtMontoAbono; }
    public JButton getBtnConfirmarAbono() { return btnConfirmarAbono; }

    public JTextField getTxtMontoRetiro() { return txtMontoRetiro; }
    public JButton getBtnConfirmarRetiro() { return btnConfirmarRetiro; }

    public JTextArea getTxtAreaConsulta() { return txtAreaConsulta; }
}