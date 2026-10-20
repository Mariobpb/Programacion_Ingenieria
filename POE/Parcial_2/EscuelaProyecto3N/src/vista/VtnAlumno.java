package vista;

import controlador.ControlVtnAlumno;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.SwingConstants;

public class VtnAlumno {
    VtnMenuPrincipal vtnMenuPrincipal;
    ControlVtnAlumno control;

    private JFrame vtn;
    private JPanel panelPrincipal;
    private JLabel lblTitulo;
    private JTabbedPane pestanas;

    // Componentes del tab Registrar
    private JLabel lblNombre;
    private JLabel lblEdad;
    private JLabel lblEmail;
    private JLabel lblCodigo;
    private JLabel lblCarrera;

    private JTextField txtNombre;
    private JTextField txtEdad;
    private JTextField txtEmail;
    private JTextField txtCodigo;
    private JTextField txtCarrera;

    private JButton btnGuardar;
    // Componentes del tab Buscar
    private JTextField txtBuscar;
    private JButton btnBuscar;
    private JTextArea txtResultado;

    // Botón inferior
    private JButton btnRegresar;

    public VtnAlumno(VtnMenuPrincipal vtnMenuPrincipal) {
        vtn = new JFrame();
        vtn.setTitle("Alumnos");
        vtn.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        vtn.setSize(600, 500);
        vtn.setResizable(false);
        vtn.setLocationRelativeTo(null);
        this.vtnMenuPrincipal = vtnMenuPrincipal;
    }

    public void dibujarVentana() {

        // Panel principal
        panelPrincipal = new JPanel(new BorderLayout(10, 10));
        panelPrincipal.setBorder(BorderFactory.createEmptyBorder(15, 20, 15, 20));

        lblTitulo = new JLabel("Alumno",SwingConstants.CENTER);
        lblTitulo.setFont(new Font("Arial", Font.BOLD, 26));
        panelPrincipal.add(lblTitulo, BorderLayout.NORTH);

        pestanas = new JTabbedPane();
        pestanas.addTab("Registrar", crearTabRegistrar());
        pestanas.addTab("Buscar", crearTabBuscar());

        panelPrincipal.add(pestanas, BorderLayout.CENTER);

        btnRegresar = new JButton("Regresar a Principal");
        btnRegresar.setFont(new Font("Arial", Font.PLAIN, 14));

        JPanel panelInferior = new JPanel();
        panelInferior.add(btnRegresar);

        panelPrincipal.add(panelInferior, BorderLayout.SOUTH);

        vtn.add(panelPrincipal);

        control = new ControlVtnAlumno(this);
        vtn.setVisible(true);  
    }

    private JPanel crearTabRegistrar() {

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(8, 10, 8, 10);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        lblNombre = new JLabel("Nombre:");
        lblEdad = new JLabel("Edad:");
        lblEmail = new JLabel("Email:");
        lblCodigo = new JLabel("Código:");
        lblCarrera = new JLabel("Carrera:");

        txtNombre = new JTextField(20);
        txtEdad = new JTextField(20);
        txtEmail = new JTextField(20);
        txtCodigo = new JTextField(20);
        txtCarrera = new JTextField(20);

        // Fila 0: Nombre
        agregarCampo(panel, gbc, 0, lblNombre, txtNombre);
        // Fila 1: Edad
        agregarCampo(panel, gbc, 1, lblEdad, txtEdad);
        // Fila 2: Email
        agregarCampo(panel, gbc, 2, lblEmail, txtEmail);
        // Fila 3: Código
        agregarCampo(panel, gbc, 3, lblCodigo, txtCodigo);
        // Fila 4: Carrera
        agregarCampo(panel, gbc, 4, lblCarrera, txtCarrera);
        // Botón Guardar
        btnGuardar = new JButton("Guardar");

        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.fill = GridBagConstraints.NONE;

        panel.add(btnGuardar, gbc);

        return panel;
    }

    private JPanel crearTabBuscar() {

        JPanel panel = new JPanel(new BorderLayout(10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        JPanel panelBusqueda = new JPanel(new BorderLayout(10, 0));
        txtBuscar = new JTextField();
        btnBuscar = new JButton("Buscar");

        panelBusqueda.add(txtBuscar, BorderLayout.CENTER);
        panelBusqueda.add(btnBuscar, BorderLayout.EAST);
        panel.add(panelBusqueda, BorderLayout.NORTH);

        // Área para mostrar resultados
        txtResultado = new JTextArea();
        txtResultado.setEditable(false);
        txtResultado.setFont(new Font("Monospaced", Font.PLAIN, 13));
        txtResultado.setLineWrap(true);
        txtResultado.setWrapStyleWord(true);

        JScrollPane scroll = new JScrollPane(txtResultado);
        panel.add(scroll, BorderLayout.CENTER);
        return panel;
    }

    private void agregarCampo(JPanel panel,GridBagConstraints gbc,int fila,JLabel etiqueta,JTextField campo) {
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.weightx = 0;
        gbc.gridx = 0;
        gbc.gridy = fila;
        panel.add(etiqueta, gbc);
        gbc.gridx = 1;
        gbc.weightx = 1;
        panel.add(campo, gbc);
    }

    public JTextField getTxtNombre() {
        return txtNombre;
    }

    public JTextField getTxtEdad() {
        return txtEdad;
    }

    public JTextField getTxtEmail() {
        return txtEmail;
    }

    public JTextField getTxtCodigo() {
        return txtCodigo;
    }

    public JTextField getTxtCarrera() {
        return txtCarrera;
    }

    public JTextField getTxtBuscar() {
        return txtBuscar;
    }

    public JTextArea getTxtResultado() {
        return txtResultado;
    }



    public VtnMenuPrincipal getVtnMenuPrincipal() {
        return vtnMenuPrincipal;
    }

    public JFrame getVtn() {
        return vtn;
    }

    public JButton getBtnBuscar() {
        return btnBuscar;
    }

    public JButton getBtnGuardar() {
        return btnGuardar;
    }

    public JButton getBtnRegresar() {
        return btnRegresar;
    }
}

