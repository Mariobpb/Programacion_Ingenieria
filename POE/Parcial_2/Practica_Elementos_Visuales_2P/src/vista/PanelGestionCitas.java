package vista;

import modelo.Usuario;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.Objects;

public class PanelGestionCitas extends JPanel implements FormatoVista {
    private Usuario usuarioActual;

    private JMenuBar menuBarra;
    private JMenu menuOpciones;
    private JMenuItem itemCerrarSesion;

    private JTabbedPane tabbedPane;

    private JPanel panelCitasProgramadas;
    private JPanel panelFiltrosCitas;
    private JTextField txtBuscarPaciente;
    private JButton btnBuscarCitas;
    private JTable tablaCitas;
    private DefaultTableModel modeloTablaCitas;
    private JScrollPane scrollTablaCitas;

    private JPanel panelAgregarPaciente;
    private JLabel lblTituloAgregarPaciente;
    private JTextField txtNombrePaciente;
    private JSpinner spnEdadPaciente;
    private JTextField txtTelefonoPaciente;
    private JTextArea txtRestriccionesPaciente;
    private JScrollPane scrollRestriccionesPaciente;
    private JButton btnGuardarPaciente;
    private JButton btnLimpiarPaciente;

    private JPanel panelAgendarCita;
    private JLabel lblTituloAgendar;

    private DefaultListModel<String> modeloListaPacientes;
    private JList<String> lstPacientes;
    private JScrollPane scrollPacientes;

    private DefaultListModel<String> modeloListaDoctores;
    private JList<String> lstDoctores;
    private JScrollPane scrollDoctores;

    private JSpinner spnDia;
    private JSpinner spnMes;
    private JSpinner spnAno;
    private JSpinner spnHora;

    private JComboBox<String> cmbTipoCita;
    private JTextArea txtSintomas;
    private JScrollPane scrollSintomas;
    private JCheckBox chkFactura;
    private JSpinner spnCosto;

    private JButton btnAgendar;
    private JButton btnLimpiarFormulario;

    private ImageIcon imgFotoPerfil;
    private JLabel lblFotoPerfil;
    private JLabel lblNombreUsuario;

    public PanelGestionCitas(Usuario usuarioActual) {
        this.usuarioActual = usuarioActual;
    }

    @Override
    public void mostrarVentana() {
        instanciarComponentes();
        cargarImagenes();
        definirLayout();
        configurarComponenetes();
        configurarImagenes();
        agregarComponentes();
    }

    @Override
    public void instanciarComponentes() {
        menuBarra = new JMenuBar();
        menuOpciones = new JMenu("Opciones de Recepción");
        itemCerrarSesion = new JMenuItem("Cerrar Sesión");
        menuOpciones.add(itemCerrarSesion);
        menuBarra.add(menuOpciones);

        tabbedPane = new JTabbedPane();

        lblFotoPerfil = new JLabel();
        lblNombreUsuario = new JLabel("Atendiendo: " + usuarioActual.getNombre() + " (" + usuarioActual.getRol() + ")");

        panelCitasProgramadas = new JPanel(new BorderLayout(10, 10));
        panelFiltrosCitas = new JPanel(new FlowLayout(FlowLayout.LEFT, 15, 10));

        txtBuscarPaciente = new JTextField(15);
        btnBuscarCitas = new JButton("Buscar");

        String[] columnasCitas = {"Paciente", "Doctor", "Fecha / Hora", "Tipo Cita", "Síntomas", "Costo", "Factura"};
        modeloTablaCitas = new DefaultTableModel(columnasCitas, 0);
        tablaCitas = new JTable(modeloTablaCitas);
        scrollTablaCitas = new JScrollPane(tablaCitas);

        panelAgregarPaciente = new JPanel();
        lblTituloAgregarPaciente = new JLabel("REGISTRO DE NUEVO PACIENTE", SwingConstants.CENTER);

        txtNombrePaciente = new JTextField(20);
        spnEdadPaciente = new JSpinner(new SpinnerNumberModel(18, 0, 120, 1));
        txtTelefonoPaciente = new JTextField(20);

        txtRestriccionesPaciente = new JTextArea(3, 20);
        txtRestriccionesPaciente.setLineWrap(true);
        txtRestriccionesPaciente.setWrapStyleWord(true);
        scrollRestriccionesPaciente = new JScrollPane(txtRestriccionesPaciente);

        btnGuardarPaciente = new JButton("Registrar Paciente");
        btnLimpiarPaciente = new JButton("Limpiar Campos");

        panelAgendarCita = new JPanel();
        lblTituloAgendar = new JLabel("AGENDAR NUEVA CITA MÉDICA", SwingConstants.CENTER);

        modeloListaPacientes = new DefaultListModel<>();
        lstPacientes = new JList<>(modeloListaPacientes);
        lstPacientes.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        scrollPacientes = new JScrollPane(lstPacientes);
        scrollPacientes.setPreferredSize(new Dimension(250, 65));

        modeloListaDoctores = new DefaultListModel<>();
        lstDoctores = new JList<>(modeloListaDoctores);
        lstDoctores.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        scrollDoctores = new JScrollPane(lstDoctores);
        scrollDoctores.setPreferredSize(new Dimension(250, 65));

        spnDia = new JSpinner(new SpinnerNumberModel(20, 1, 31, 1));

        String[] meses = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
        spnMes = new JSpinner(new SpinnerListModel(meses));
        spnMes.setValue("Octubre");

        spnAno = new JSpinner(new SpinnerNumberModel(2026, 2026, 2030, 1));

        String[] horasPermitidas = {
                "08:00 AM", "09:00 AM", "10:00 AM", "11:00 AM", "12:00 PM",
                "01:00 PM", "02:00 PM", "03:00 PM", "04:00 PM", "05:00 PM",
                "06:00 PM", "07:00 PM"
        };
        spnHora = new JSpinner(new SpinnerListModel(horasPermitidas));

        String[] tiposCita = {"Consulta General", "Especialidad", "Urgencia", "Revisión / Rutina"};
        cmbTipoCita = new JComboBox<>(tiposCita);

        txtSintomas = new JTextArea(2, 20);
        txtSintomas.setLineWrap(true);
        txtSintomas.setWrapStyleWord(true);
        scrollSintomas = new JScrollPane(txtSintomas);

        chkFactura = new JCheckBox("¿El paciente requiere factura?");
        spnCosto = new JSpinner(new SpinnerNumberModel(500, 0, 20000, 50));

        btnAgendar = new JButton("Agendar Cita");
        btnLimpiarFormulario = new JButton("Limpiar Campos");
    }

    @Override
    public void cargarImagenes() {
        try {
            imgFotoPerfil = new ImageIcon(Objects.requireNonNull(getClass().getResource(usuarioActual.getUrlFoto())));
        } catch (Exception e) {
            imgFotoPerfil = null;
        }
    }

    @Override
    public void definirLayout() {
        setLayout(new BorderLayout());
        panelAgregarPaciente.setLayout(new BoxLayout(panelAgregarPaciente, BoxLayout.Y_AXIS));
        panelAgendarCita.setLayout(new BoxLayout(panelAgendarCita, BoxLayout.Y_AXIS));
    }

    @Override
    public void configurarComponenetes() {
        Font fuenteTitulos = new Font("Segoe UI", Font.BOLD, 16);
        Font fuenteTexto = new Font("Segoe UI", Font.PLAIN, 14);

        lblNombreUsuario.setFont(new Font("Segoe UI", Font.BOLD, 14));
        lblNombreUsuario.setForeground(new Color(30, 41, 59));

        panelCitasProgramadas.setBorder(new EmptyBorder(10, 10, 10, 10));
        tablaCitas.setFont(fuenteTexto);
        tablaCitas.setRowHeight(25);
        tablaCitas.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnBuscarCitas.setFont(new Font("Segoe UI", Font.BOLD, 13));

        panelAgregarPaciente.setBorder(new EmptyBorder(15, 30, 15, 30));
        panelAgregarPaciente.setBackground(Color.WHITE);
        lblTituloAgregarPaciente.setFont(fuenteTitulos);
        lblTituloAgregarPaciente.setAlignmentX(Component.CENTER_ALIGNMENT);

        btnGuardarPaciente.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnGuardarPaciente.setBackground(new Color(37, 99, 235));
        btnGuardarPaciente.setForeground(Color.WHITE);
        btnGuardarPaciente.setFocusPainted(false);
        btnGuardarPaciente.setCursor(new Cursor(Cursor.HAND_CURSOR));

        btnLimpiarPaciente.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnLimpiarPaciente.setBackground(Color.GRAY);
        btnLimpiarPaciente.setForeground(Color.WHITE);
        btnLimpiarPaciente.setFocusPainted(false);
        btnLimpiarPaciente.setCursor(new Cursor(Cursor.HAND_CURSOR));

        panelAgendarCita.setBorder(new EmptyBorder(15, 30, 15, 30));
        panelAgendarCita.setBackground(Color.WHITE);
        lblTituloAgendar.setFont(fuenteTitulos);
        lblTituloAgendar.setAlignmentX(Component.CENTER_ALIGNMENT);

        btnAgendar.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnAgendar.setBackground(new Color(37, 99, 235));
        btnAgendar.setForeground(Color.WHITE);
        btnAgendar.setFocusPainted(false);
        btnAgendar.setCursor(new Cursor(Cursor.HAND_CURSOR));

        btnLimpiarFormulario.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnLimpiarFormulario.setBackground(Color.GRAY);
        btnLimpiarFormulario.setForeground(Color.WHITE);
        btnLimpiarFormulario.setFocusPainted(false);
        btnLimpiarFormulario.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }

    @Override
    public void configurarImagenes() {
        if (imgFotoPerfil != null) {
            Image img = imgFotoPerfil.getImage().getScaledInstance(35, 35, Image.SCALE_SMOOTH);
            lblFotoPerfil.setIcon(new ImageIcon(img));
        }
    }

    @Override
    public void agregarComponentes() {
        JPanel panelHeader = new JPanel(new FlowLayout(FlowLayout.RIGHT, 15, 5));
        panelHeader.setBackground(new Color(241, 245, 249));
        panelHeader.add(lblFotoPerfil);
        panelHeader.add(lblNombreUsuario);

        panelFiltrosCitas.add(new JLabel("Buscar Paciente:"));
        panelFiltrosCitas.add(txtBuscarPaciente);
        panelFiltrosCitas.add(btnBuscarCitas);

        panelCitasProgramadas.add(panelFiltrosCitas, BorderLayout.NORTH);
        panelCitasProgramadas.add(scrollTablaCitas, BorderLayout.CENTER);

        Dimension dimEtiqueta = new Dimension(160, 25);

        panelAgregarPaciente.add(lblTituloAgregarPaciente);
        panelAgregarPaciente.add(Box.createRigidArea(new Dimension(0, 15)));
        panelAgregarPaciente.add(crearFila(new JLabel("Nombre Completo (*):"), txtNombrePaciente, dimEtiqueta));
        panelAgregarPaciente.add(crearFila(new JLabel("Edad (*):"), spnEdadPaciente, dimEtiqueta));
        panelAgregarPaciente.add(crearFila(new JLabel("Teléfono (Opcional):"), txtTelefonoPaciente, dimEtiqueta));
        panelAgregarPaciente.add(crearFila(new JLabel("Restricciones / Notas:"), scrollRestriccionesPaciente, dimEtiqueta));

        JPanel panelBotonesPaciente = new JPanel(new FlowLayout(FlowLayout.RIGHT, 10, 10));
        panelBotonesPaciente.setOpaque(false);
        panelBotonesPaciente.add(btnLimpiarPaciente);
        panelBotonesPaciente.add(btnGuardarPaciente);
        panelAgregarPaciente.add(panelBotonesPaciente);

        panelAgendarCita.add(lblTituloAgendar);
        panelAgendarCita.add(Box.createRigidArea(new Dimension(0, 10)));
        panelAgendarCita.add(crearFila(new JLabel("Paciente (JList):"), scrollPacientes, dimEtiqueta));
        panelAgendarCita.add(crearFila(new JLabel("Doctor (JList):"), scrollDoctores, dimEtiqueta));

        JPanel panelFechaHora = new JPanel(new FlowLayout(FlowLayout.LEFT, 5, 0));
        panelFechaHora.setOpaque(false);
        panelFechaHora.add(new JLabel("Día:"));
        panelFechaHora.add(spnDia);
        panelFechaHora.add(new JLabel(" Mes:"));
        panelFechaHora.add(spnMes);
        panelFechaHora.add(new JLabel(" Año:"));
        panelFechaHora.add(spnAno);
        panelFechaHora.add(new JLabel(" Hora:"));
        panelFechaHora.add(spnHora);

        panelAgendarCita.add(crearFila(new JLabel("Fecha y Hora:"), panelFechaHora, dimEtiqueta));
        panelAgendarCita.add(crearFila(new JLabel("Tipo de Cita:"), cmbTipoCita, dimEtiqueta));
        panelAgendarCita.add(crearFila(new JLabel("Síntomas:"), scrollSintomas, dimEtiqueta));
        panelAgendarCita.add(crearFila(new JLabel("Costo ($):"), spnCosto, dimEtiqueta));

        JPanel panelFactura = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 2));
        panelFactura.setOpaque(false);
        panelFactura.add(chkFactura);
        panelAgendarCita.add(panelFactura);

        JPanel panelBotonesAgendar = new JPanel(new FlowLayout(FlowLayout.RIGHT, 10, 10));
        panelBotonesAgendar.setOpaque(false);
        panelBotonesAgendar.add(btnLimpiarFormulario);
        panelBotonesAgendar.add(btnAgendar);
        panelAgendarCita.add(panelBotonesAgendar);

        tabbedPane.addTab("Citas Programadas", panelCitasProgramadas);
        tabbedPane.addTab("Agregar Paciente", panelAgregarPaciente);
        tabbedPane.addTab("Agendar Cita", panelAgendarCita);

        JPanel panelNorte = new JPanel(new BorderLayout());
        panelNorte.add(menuBarra, BorderLayout.NORTH);
        panelNorte.add(panelHeader, BorderLayout.SOUTH);

        add(panelNorte, BorderLayout.NORTH);
        add(tabbedPane, BorderLayout.CENTER);
    }

    private JPanel crearFila(JLabel etiqueta, JComponent campo, Dimension dimEtiqueta) {
        JPanel fila = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 3));
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

    public JMenuItem getItemCerrarSesion() { return itemCerrarSesion; }
    public JTabbedPane getTabbedPane() { return tabbedPane; }

    public JTextField getTxtBuscarPaciente() { return txtBuscarPaciente; }
    public JButton getBtnBuscarCitas() { return btnBuscarCitas; }
    public DefaultTableModel getModeloTablaCitas() { return modeloTablaCitas; }

    public JTextField getTxtNombrePaciente() { return txtNombrePaciente; }
    public JSpinner getSpnEdadPaciente() { return spnEdadPaciente; }
    public JTextField getTxtTelefonoPaciente() { return txtTelefonoPaciente; }
    public JTextArea getTxtRestriccionesPaciente() { return txtRestriccionesPaciente; }
    public JButton getBtnGuardarPaciente() { return btnGuardarPaciente; }
    public JButton getBtnLimpiarPaciente() { return btnLimpiarPaciente; }

    public DefaultListModel<String> getModeloListaPacientes() { return modeloListaPacientes; }
    public JList<String> getLstPacientes() { return lstPacientes; }

    public DefaultListModel<String> getModeloListaDoctores() { return modeloListaDoctores; }
    public JList<String> getLstDoctores() { return lstDoctores; }

    public JSpinner getSpnDia() { return spnDia; }
    public JSpinner getSpnMes() { return spnMes; }
    public JSpinner getSpnAno() { return spnAno; }
    public JSpinner getSpnHora() { return spnHora; }

    public JComboBox<String> getCmbTipoCita() { return cmbTipoCita; }
    public JTextArea getTxtSintomas() { return txtSintomas; }
    public JCheckBox getChkFactura() { return chkFactura; }
    public JSpinner getSpnCosto() { return spnCosto; }
    public JButton getBtnAgendar() { return btnAgendar; }
    public JButton getBtnLimpiarFormulario() { return btnLimpiarFormulario; }
}