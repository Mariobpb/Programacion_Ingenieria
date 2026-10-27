package vistas;
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

public class VtnDocente {

    // Ventana principal: la clase NO hereda de JFrame
    private JFrame vtn;

    // Componentes generales
    private JPanel panelPrincipal;
    private JLabel lblTitulo;
    private JTabbedPane pestanas;

    // Componentes del tab Registrar
    private JLabel lblNombre;
    private JLabel lblEdad;
    private JLabel lblEmail;
    private JLabel lblCodigo;
    private JLabel lblHorasTrabajadas;
    private JLabel lblPagoHora;

    private JTextField txtNombre;
    private JTextField txtEdad;
    private JTextField txtEmail;
    private JTextField txtCodigo;
    private JTextField txtHorasTrabajadas;
    private JTextField txtPagoHora;

    private JButton btnGuardar;

    // Componentes del tab Buscar
    private JTextField txtBuscar;
    private JButton btnBuscar;
    private JTextArea txtResultado;

    // Componentes del tab Evaluar
    private JLabel lblCodigoAlumno;
    private JTextField txtCodigoAlumno;
    private JButton btnBuscarAlumno;

    private JLabel lblMatematicas;
    private JLabel lblFisica;
    private JLabel lblProgramacion;

    private JTextField txtMatematicas;
    private JTextField txtFisica;
    private JTextField txtProgramacion;

    private JButton btnEvaluarAlumno;

    // Botón inferior
    private JButton btnRegresar;

    public VtnDocente() {

        // Crear el JFrame
        vtn = new JFrame();

        // Configurar la vtn
        vtn.setTitle("Docentes");
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtn.setSize(600, 500);
        vtn.setResizable(false);
        vtn.setLocationRelativeTo(null);
    }

    public void dibujarVentana() {

        // Panel principal
        panelPrincipal = new JPanel(new BorderLayout(10, 10));

        panelPrincipal.setBorder(
            BorderFactory.createEmptyBorder(15, 20, 15, 20)
        );

        // Título superior
        lblTitulo = new JLabel("Docente",SwingConstants.CENTER);

        lblTitulo.setFont(new Font("Arial", Font.BOLD, 26));

        panelPrincipal.add(lblTitulo, BorderLayout.NORTH);

        // Crear las pestañas
        pestanas = new JTabbedPane();

        pestanas.addTab("Registrar", crearTabRegistrar());
        pestanas.addTab("Buscar", crearTabBuscar());
        pestanas.addTab("Evaluar", crearTabEvaluar());

        panelPrincipal.add(pestanas, BorderLayout.CENTER);

        // Botón inferior
        btnRegresar = new JButton("Regresar a Principal");
        btnRegresar.setFont(new Font("Arial", Font.PLAIN, 14));

        JPanel panelInferior = new JPanel();
        panelInferior.add(btnRegresar);

        panelPrincipal.add(panelInferior, BorderLayout.SOUTH);

        // Agregar el panel al JFrame
        vtn.setContentPane(panelPrincipal);
        vtn.setVisible(true);
    }

    // =====================================================
    // TAB REGISTRAR
    // =====================================================

    private JPanel crearTabRegistrar() {

        JPanel panel = new JPanel(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 8, 5, 8);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        // Etiquetas
        lblNombre = new JLabel("Nombre:");
        lblEdad = new JLabel("Edad:");
        lblEmail = new JLabel("Email:");
        lblCodigo = new JLabel("Código:");
        lblHorasTrabajadas = new JLabel("Horas Trabajadas:");
        lblPagoHora = new JLabel("Pago x Hora:");

        // Campos de texto
        txtNombre = new JTextField(18);
        txtEdad = new JTextField(18);
        txtEmail = new JTextField(18);
        txtCodigo = new JTextField(18);
        txtHorasTrabajadas = new JTextField(18);
        txtPagoHora = new JTextField(18);

        // Agregar los campos
        agregarCampo(panel, gbc, 0, lblNombre, txtNombre);
        agregarCampo(panel, gbc, 1, lblEdad, txtEdad);
        agregarCampo(panel, gbc, 2, lblEmail, txtEmail);
        agregarCampo(panel, gbc, 3, lblCodigo, txtCodigo);
        agregarCampo(panel, gbc, 4, lblHorasTrabajadas, txtHorasTrabajadas);
        agregarCampo(panel, gbc, 5, lblPagoHora, txtPagoHora);

        // Botón Guardar
        btnGuardar = new JButton("Guardar");

        gbc.gridx = 0;
        gbc.gridy = 6;
        gbc.gridwidth = 2;
        gbc.weightx = 0;
        gbc.fill = GridBagConstraints.NONE;
        gbc.anchor = GridBagConstraints.CENTER;
        panel.add(btnGuardar, gbc);

        return panel;
    }

    // =====================================================
    // TAB BUSCAR
    // =====================================================

    private JPanel crearTabBuscar() {

        JPanel panel = new JPanel(new BorderLayout(10, 10));

        panel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        // Zona de búsqueda
        JPanel panelBusqueda = new JPanel(new BorderLayout(10, 0));

        txtBuscar = new JTextField();
        btnBuscar = new JButton("Buscar");

        panelBusqueda.add(txtBuscar, BorderLayout.CENTER);
        panelBusqueda.add(btnBuscar, BorderLayout.EAST);

        panel.add(panelBusqueda, BorderLayout.NORTH);

        // Área para mostrar la información
        txtResultado = new JTextArea();
        txtResultado.setEditable(false);
        txtResultado.setFont(
            new Font("Monospaced", Font.PLAIN, 13)
        );
        txtResultado.setLineWrap(true);
        txtResultado.setWrapStyleWord(true);

        JScrollPane scroll = new JScrollPane(txtResultado);

        panel.add(scroll, BorderLayout.CENTER);

        return panel;
    }

    // =====================================================
    // TAB EVALUAR
    // =====================================================

    private JPanel crearTabEvaluar() {

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(6, 6, 6, 6);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        // Código del alumno
        lblCodigoAlumno = new JLabel("Codigo del Alumno a Evaluar:");
        txtCodigoAlumno = new JTextField(12);
        btnBuscarAlumno = new JButton("Buscar");

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.weightx = 0;

        panel.add(lblCodigoAlumno, gbc);

        gbc.gridx = 1;
        gbc.weightx = 1;

        panel.add(txtCodigoAlumno, gbc);

        gbc.gridx = 2;
        gbc.weightx = 0;

        panel.add(btnBuscarAlumno, gbc);

        // Calificación de Matemáticas
        lblMatematicas = new JLabel("Matematicas:");
        txtMatematicas = new JTextField(12);

        agregarCampo(panel, gbc, 1, lblMatematicas, txtMatematicas);

        // Calificación de Física
        lblFisica = new JLabel("Fisica:");
        txtFisica = new JTextField(12);

        agregarCampo(panel, gbc, 2, lblFisica, txtFisica);

        // Calificación de Programación
        lblProgramacion = new JLabel("Programación:");
        txtProgramacion = new JTextField(12);

        agregarCampo(panel, gbc, 3, lblProgramacion, txtProgramacion);

        // Botón Evaluar Alumno
        btnEvaluarAlumno = new JButton("Evaluar Alumno");

        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        gbc.weightx = 0;
        gbc.fill = GridBagConstraints.NONE;
        gbc.anchor = GridBagConstraints.CENTER;

        panel.add(btnEvaluarAlumno, gbc);

        return panel;
    }

    // =====================================================
    // MÉTODO AUXILIAR PARA AGREGAR ETIQUETAS Y CAMPOS
    // =====================================================

    private void agregarCampo(JPanel panel,GridBagConstraints gbc, int fila,JLabel etiqueta, JTextField campo) {

        gbc.gridwidth = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.weightx = 0;

        gbc.gridx = 0;
        gbc.gridy = fila;

        panel.add(etiqueta, gbc);

        gbc.gridx = 1;
        gbc.weightx = 1;

        panel.add(campo, gbc);
    }

}

