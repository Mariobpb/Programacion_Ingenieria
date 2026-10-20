package vista;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ItemEvent;

public class VistaAgregarEmpleado extends JDialog implements FormatoVista {
    private JPanel panelPrincipal;
    private JPanel panelFormulario;

    private JLabel lblTituloModal;

    private JTextField txtNombre;
    private JSpinner spnEdad;
    private JTextField txtTelefono;
    private JTextArea txtDomicilio;
    private JScrollPane scrollDomicilio;
    private JTextField txtSalario;
    private JLabel lblEspecialidad;
    private JTextField txtEspecialidad;

    private JComboBox<String> cmbRol;

    private JRadioButton rbtMatutino;
    private JRadioButton rbtVespertino;
    private ButtonGroup grupoTurno;
    private JPanel panelTurno;

    private JCheckBox chkCedula;

    private JTextField txtUsuario;
    private JPasswordField txtPassword;
    private JLabel lblUsuario;
    private JLabel lblPassword;

    private JButton btnGuardar;
    private JButton btnCancelar;

    public VistaAgregarEmpleado(Frame padre) {
        super(padre, "Agregar Nuevo Empleado", true);
        setSize(520, 720);
        setLocationRelativeTo(padre);
        setResizable(false);

        prepararVista();
    }

    public void prepararVista() {
        instanciarComponentes();
        definirLayout();
        configurarComponenetes();
        configurarListeners();
        agregarComponentes();
        actualizarEstadoCampos();
    }

    @Override
    public void mostrarVentana() {
        setVisible(true);
    }

    @Override
    public void instanciarComponentes() {
        panelPrincipal = new JPanel();
        panelFormulario = new JPanel();

        lblTituloModal = new JLabel("REGISTRO DE NUEVO EMPLEADO", SwingConstants.CENTER);

        txtNombre = new JTextField(20);
        spnEdad = new JSpinner(new SpinnerNumberModel(25, 18, 80, 1));
        txtTelefono = new JTextField(20);

        txtDomicilio = new JTextArea(3, 20);
        txtDomicilio.setLineWrap(true);
        scrollDomicilio = new JScrollPane(txtDomicilio);

        txtSalario = new JTextField(20);
        lblEspecialidad = new JLabel("Especialidad:");
        txtEspecialidad = new JTextField(20);

        String[] roles = {"DOCTOR", "RECEPCIONISTA", "ADMINISTRADOR"};
        cmbRol = new JComboBox<>(roles);

        rbtMatutino = new JRadioButton("Matutino", true);
        rbtVespertino = new JRadioButton("Vespertino");
        grupoTurno = new ButtonGroup();
        grupoTurno.add(rbtMatutino);
        grupoTurno.add(rbtVespertino);
        panelTurno = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 0));
        panelTurno.setOpaque(false);
        panelTurno.add(rbtMatutino);
        panelTurno.add(rbtVespertino);

        chkCedula = new JCheckBox("¿Cuenta con título/cédula profesional activa?");

        lblUsuario = new JLabel("Nombre de Usuario:");
        txtUsuario = new JTextField(20);
        lblPassword = new JLabel("Contraseña:");
        txtPassword = new JPasswordField(20);

        btnGuardar = new JButton("Guardar Empleado");
        btnCancelar = new JButton("Cancelar");
    }

    public void configurarListeners() {
        cmbRol.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                actualizarEstadoCampos();
            }
        });
    }

    public void actualizarEstadoCampos() {
        String rolSeleccionado = (String) cmbRol.getSelectedItem();
        boolean esDoctor = "DOCTOR".equalsIgnoreCase(rolSeleccionado);

        txtUsuario.setEnabled(!esDoctor);
        txtPassword.setEnabled(!esDoctor);
        lblUsuario.setEnabled(!esDoctor);
        lblPassword.setEnabled(!esDoctor);

        if (esDoctor) {
            txtUsuario.setText("");
            txtPassword.setText("");
        }

        txtEspecialidad.setEnabled(esDoctor);
        lblEspecialidad.setEnabled(esDoctor);
        chkCedula.setEnabled(esDoctor);

        if (!esDoctor) {
            txtEspecialidad.setText("");
            chkCedula.setSelected(false);
        }
    }

    @Override
    public void definirLayout() {
        panelPrincipal.setLayout(new BorderLayout(10, 15));
        panelFormulario.setLayout(new BoxLayout(panelFormulario, BoxLayout.Y_AXIS));
        panelFormulario.setOpaque(false);
    }

    @Override
    public void cargarImagenes() { }

    @Override
    public void configurarComponenetes() {
        panelPrincipal.setBorder(new EmptyBorder(20, 20, 20, 20));
        panelPrincipal.setBackground(Color.WHITE);

        lblTituloModal.setFont(new Font("Segoe UI", Font.BOLD, 18));
        lblTituloModal.setForeground(new Color(30, 41, 59));

        btnGuardar.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnGuardar.setBackground(new Color(37, 99, 235));
        btnGuardar.setForeground(Color.WHITE);
        btnGuardar.setFocusPainted(false);
        btnGuardar.setCursor(new Cursor(Cursor.HAND_CURSOR));

        btnCancelar.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnCancelar.setBackground(new Color(225, 29, 72));
        btnCancelar.setForeground(Color.WHITE);
        btnCancelar.setFocusPainted(false);
        btnCancelar.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }

    @Override
    public void configurarImagenes() { }

    @Override
    public void agregarComponentes() {
        Dimension dimEtiqueta = new Dimension(140, 25);

        panelFormulario.add(crearFilaFormulario(new JLabel("Tipo de Empleado:"), cmbRol, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(new JLabel("Nombre Completo:"), txtNombre, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(new JLabel("Edad:"), spnEdad, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(new JLabel("Teléfono:"), txtTelefono, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(new JLabel("Domicilio:"), scrollDomicilio, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(new JLabel("Salario Base:"), txtSalario, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(new JLabel("Turno Asignado:"), panelTurno, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(lblEspecialidad, txtEspecialidad, dimEtiqueta));

        JPanel panelChk = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 2));
        panelChk.setOpaque(false);
        panelChk.add(chkCedula);
        panelFormulario.add(panelChk);

        panelFormulario.add(crearFilaFormulario(lblUsuario, txtUsuario, dimEtiqueta));
        panelFormulario.add(crearFilaFormulario(lblPassword, txtPassword, dimEtiqueta));

        JPanel panelBotones = new JPanel(new FlowLayout(FlowLayout.RIGHT, 10, 5));
        panelBotones.setOpaque(false);
        panelBotones.add(btnCancelar);
        panelBotones.add(btnGuardar);

        panelPrincipal.add(lblTituloModal, BorderLayout.NORTH);
        panelPrincipal.add(panelFormulario, BorderLayout.CENTER);
        panelPrincipal.add(panelBotones, BorderLayout.SOUTH);

        add(panelPrincipal);
    }

    private JPanel crearFilaFormulario(JLabel etiqueta, JComponent campo, Dimension dimEtiqueta) {
        JPanel fila = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 2));
        fila.setOpaque(false);

        if (etiqueta != null) {
            etiqueta.setPreferredSize(dimEtiqueta);
            fila.add(etiqueta);
        }
        if (campo != null) {
            fila.add(campo);
        }
        return fila;
    }

    public JLabel getLblTituloModal() { return lblTituloModal; }
    public JTextField getTxtNombre() { return txtNombre; }
    public JSpinner getSpnEdad() { return spnEdad; }
    public JTextField getTxtTelefono() { return txtTelefono; }
    public JTextArea getTxtDomicilio() { return txtDomicilio; }
    public JTextField getTxtSalario() { return txtSalario; }
    public JComboBox<String> getCmbRol() { return cmbRol; }
    public JRadioButton getRbtMatutino() { return rbtMatutino; }
    public JCheckBox getChkCedula() { return chkCedula; }
    public JTextField getTxtUsuario() { return txtUsuario; }
    public JPasswordField getTxtPassword() { return txtPassword; }
    public JButton getBtnGuardar() { return btnGuardar; }
    public JButton getBtnCancelar() { return btnCancelar; }
    public JTextField getTxtEspecialidad() { return txtEspecialidad; }
}