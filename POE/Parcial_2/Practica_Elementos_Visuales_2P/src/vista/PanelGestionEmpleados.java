package vista;

import modelo.Usuario;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.Objects;

public class PanelGestionEmpleados extends JPanel implements FormatoVista {
    private Usuario usuarioActual;

    private JMenuBar menuBarra;
    private JMenu menuOpciones;
    private JMenuItem itemConsultar;
    private JMenuItem itemAgregar;
    private JMenuItem itemEliminar;
    private JMenuItem itemModificar;
    private JMenuItem itemCerrarSesion;
    private JSplitPane splitPane;
    private JPanel panelIzquierdoPerfil;
    private JPanel panelDerechoLista;

    private ImageIcon imgFotoPerfil;
    private JLabel lblFotoPerfil;
    private JLabel lblNombreAdmin;
    private JLabel lblRolAdmin;

    private JLabel lblUsuarioVal;
    private JLabel lblEdadVal;
    private JLabel lblTelefonoVal;
    private JLabel lblTurnoVal;
    private JLabel lblSalarioVal;
    private JLabel lblDomicilioVal;

    private JPanel panelFiltros;
    private JLabel lblBuscarNombre;
    private JTextField txtBuscarNombre;
    private JLabel lblFiltroTipo;
    private JComboBox<String> cmbFiltroTipo;
    private JButton btnBuscar;

    private JTable tablaEmpleados;
    private DefaultTableModel modeloTabla;
    private JScrollPane scrollTabla;

    private final Color COLOR_FONDO_GENERAL = new Color(15, 23, 42);
    private final Color COLOR_PANEL_SECUNDARIO = new Color(30, 41, 59);
    private final Color COLOR_TARJETA_DATOS = new Color(51, 65, 85);
    private final Color COLOR_TEXTO_MAIN = new Color(248, 250, 252);
    private final Color COLOR_TEXTO_MUTED = new Color(148, 163, 184);
    private final Color COLOR_AZUL_ACCENT = new Color(59, 130, 246);
    private final Color COLOR_BORDER = new Color(71, 85, 105);

    public PanelGestionEmpleados(Usuario usuarioActual) {
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
        menuOpciones = new JMenu("Opciones de Gestión");
        itemConsultar = new JMenuItem("1 - Consultar Empleados");
        itemAgregar = new JMenuItem("2 - Agregar Empleado");
        itemEliminar = new JMenuItem("3 - Eliminar Empleados");
        itemModificar = new JMenuItem("4 - Modificar Empleado");
        itemCerrarSesion = new JMenuItem("5 - Cerrar Sesión");

        menuOpciones.add(itemConsultar);
        menuOpciones.add(itemAgregar);
        menuOpciones.add(itemEliminar);
        menuOpciones.add(itemModificar);
        menuOpciones.addSeparator();
        menuOpciones.add(itemCerrarSesion);
        menuBarra.add(menuOpciones);

        panelIzquierdoPerfil = new JPanel();
        panelDerechoLista = new JPanel();

        lblFotoPerfil = new JLabel();
        lblNombreAdmin = new JLabel(usuarioActual.getNombre(), SwingConstants.CENTER);
        lblRolAdmin = new JLabel(usuarioActual.getRol(), SwingConstants.CENTER);

        lblUsuarioVal = new JLabel(usuarioActual.getUsuario());
        lblEdadVal = new JLabel(usuarioActual.getEdad() + " años");
        lblTelefonoVal = new JLabel(String.valueOf(usuarioActual.getTelefono()));
        lblTurnoVal = new JLabel(usuarioActual.getTurno() != null ? usuarioActual.getTurno() : "N/A");
        lblSalarioVal = new JLabel("$" + usuarioActual.getSalarioBase());
        lblDomicilioVal = new JLabel("<html>" + usuarioActual.getDomicilio() + "</html>");

        panelFiltros = new JPanel();
        lblBuscarNombre = new JLabel("Buscar por Nombre:");
        txtBuscarNombre = new JTextField(12);
        lblFiltroTipo = new JLabel("Tipo de Empleado:");

        String[] tipos = {"Todos", "Administrador", "Recepcionista", "Doctor"};
        cmbFiltroTipo = new JComboBox<>(tipos);
        btnBuscar = new JButton("Buscar");

        String[] columnas = {
                "Nombre", "Edad", "Teléfono", "Rol/Tipo", "Turno",
                "Salario Base", "Título/Cédula", "Especialidad"
        };
        modeloTabla = new DefaultTableModel(columnas, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        tablaEmpleados = new JTable(modeloTabla);
        scrollTabla = new JScrollPane(tablaEmpleados);

        splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, panelIzquierdoPerfil, panelDerechoLista);
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
        panelIzquierdoPerfil.setLayout(new BoxLayout(panelIzquierdoPerfil, BoxLayout.Y_AXIS));
        panelDerechoLista.setLayout(new BorderLayout(10, 10));
        panelFiltros.setLayout(new FlowLayout(FlowLayout.LEFT, 12, 10));
    }

    @Override
    public void configurarComponenetes() {
        setBackground(COLOR_FONDO_GENERAL);

        menuBarra.setBackground(COLOR_PANEL_SECUNDARIO);
        menuBarra.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, COLOR_BORDER));
        menuOpciones.setForeground(COLOR_TEXTO_MAIN);
        menuOpciones.setFont(new Font("Segoe UI", Font.BOLD, 13));

        panelIzquierdoPerfil.setBackground(COLOR_PANEL_SECUNDARIO);
        panelIzquierdoPerfil.setBorder(new EmptyBorder(20, 20, 20, 20));
        panelIzquierdoPerfil.setPreferredSize(new Dimension(320, 0));

        lblFotoPerfil.setPreferredSize(new Dimension(110, 110));
        lblFotoPerfil.setMaximumSize(new Dimension(110, 110));
        lblFotoPerfil.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblNombreAdmin.setFont(new Font("Segoe UI", Font.BOLD, 18));
        lblNombreAdmin.setForeground(COLOR_TEXTO_MAIN);
        lblNombreAdmin.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblRolAdmin.setFont(new Font("Segoe UI", Font.BOLD, 12));
        lblRolAdmin.setForeground(COLOR_AZUL_ACCENT);
        lblRolAdmin.setAlignmentX(Component.CENTER_ALIGNMENT);

        panelDerechoLista.setBackground(COLOR_FONDO_GENERAL);
        panelDerechoLista.setBorder(new EmptyBorder(15, 15, 15, 15));

        panelFiltros.setBackground(COLOR_PANEL_SECUNDARIO);
        panelFiltros.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(COLOR_BORDER, 1, true),
                new EmptyBorder(5, 10, 5, 10)
        ));

        lblBuscarNombre.setFont(new Font("Segoe UI", Font.BOLD, 12));
        lblBuscarNombre.setForeground(COLOR_TEXTO_MUTED);

        txtBuscarNombre.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        txtBuscarNombre.setForeground(COLOR_TEXTO_MAIN);
        txtBuscarNombre.setBackground(COLOR_FONDO_GENERAL);
        txtBuscarNombre.setCaretColor(COLOR_TEXTO_MAIN);
        txtBuscarNombre.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(COLOR_BORDER, 1, true),
                BorderFactory.createEmptyBorder(5, 8, 5, 8)
        ));

        lblFiltroTipo.setFont(new Font("Segoe UI", Font.BOLD, 12));
        lblFiltroTipo.setForeground(COLOR_TEXTO_MUTED);

        cmbFiltroTipo.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        cmbFiltroTipo.setForeground(COLOR_TEXTO_MAIN);
        cmbFiltroTipo.setBackground(COLOR_FONDO_GENERAL);

        btnBuscar.setFont(new Font("Segoe UI", Font.BOLD, 13));
        btnBuscar.setForeground(Color.WHITE);
        btnBuscar.setBackground(COLOR_AZUL_ACCENT);
        btnBuscar.setFocusPainted(false);
        btnBuscar.setCursor(new Cursor(Cursor.HAND_CURSOR));

        tablaEmpleados.setBackground(COLOR_PANEL_SECUNDARIO);
        tablaEmpleados.setForeground(COLOR_TEXTO_MAIN);
        tablaEmpleados.setGridColor(COLOR_BORDER);
        tablaEmpleados.setRowHeight(32);
        tablaEmpleados.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        tablaEmpleados.setSelectionBackground(COLOR_AZUL_ACCENT);
        tablaEmpleados.setSelectionForeground(Color.WHITE);

        tablaEmpleados.getTableHeader().setBackground(COLOR_TARJETA_DATOS);
        tablaEmpleados.getTableHeader().setForeground(COLOR_TEXTO_MAIN);
        tablaEmpleados.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 13));
        tablaEmpleados.getTableHeader().setPreferredSize(new Dimension(0, 35));

        scrollTabla.getViewport().setBackground(COLOR_FONDO_GENERAL);
        scrollTabla.setBorder(BorderFactory.createLineBorder(COLOR_BORDER, 1));

        splitPane.setBackground(COLOR_FONDO_GENERAL);
        splitPane.setDividerLocation(320);
        splitPane.setDividerSize(6);
        splitPane.setContinuousLayout(true);
        splitPane.setBorder(null);
    }

    @Override
    public void configurarImagenes() {
        if (imgFotoPerfil != null) {
            Image img = imgFotoPerfil.getImage().getScaledInstance(110, 110, Image.SCALE_SMOOTH);
            lblFotoPerfil.setIcon(new ImageIcon(img));
        }
    }

    @Override
    public void agregarComponentes() {
        add(menuBarra, BorderLayout.NORTH);

        panelIzquierdoPerfil.add(lblFotoPerfil);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 12)));
        panelIzquierdoPerfil.add(lblNombreAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 4)));
        panelIzquierdoPerfil.add(lblRolAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 15)));

        JSeparator sep = new JSeparator(JSeparator.HORIZONTAL);
        sep.setForeground(COLOR_BORDER);
        sep.setMaximumSize(new Dimension(280, 2));
        panelIzquierdoPerfil.add(sep);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 15)));

        JPanel panelGridDatos = new JPanel(new GridLayout(6, 1, 0, 10));
        panelGridDatos.setOpaque(false);

        panelGridDatos.add(crearBloqueDato("NOMBRE DE USUARIO", lblUsuarioVal));
        panelGridDatos.add(crearBloqueDato("EDAD", lblEdadVal));
        panelGridDatos.add(crearBloqueDato("TELÉFONO DE CONTACTO", lblTelefonoVal));
        panelGridDatos.add(crearBloqueDato("TURNO ASIGNADO", lblTurnoVal));
        panelGridDatos.add(crearBloqueDato("SALARIO BASE", lblSalarioVal));
        panelGridDatos.add(crearBloqueDato("DOMICILIO", lblDomicilioVal));

        panelIzquierdoPerfil.add(panelGridDatos);

        panelIzquierdoPerfil.add(Box.createVerticalGlue());

        panelFiltros.add(lblBuscarNombre);
        panelFiltros.add(txtBuscarNombre);
        panelFiltros.add(lblFiltroTipo);
        panelFiltros.add(cmbFiltroTipo);
        panelFiltros.add(btnBuscar);

        panelDerechoLista.add(panelFiltros, BorderLayout.NORTH);
        panelDerechoLista.add(scrollTabla, BorderLayout.CENTER);

        add(splitPane, BorderLayout.CENTER);
    }

    /**
     * Genera un bloque estructurado con título tenue superior y valor resaltado inferior
     */
    private JPanel crearBloqueDato(String etiqueta, JLabel lblValor) {
        JPanel bloque = new JPanel();
        bloque.setLayout(new BoxLayout(bloque, BoxLayout.Y_AXIS));
        bloque.setBackground(COLOR_TARJETA_DATOS);
        bloque.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(COLOR_BORDER, 1, true),
                new EmptyBorder(6, 10, 6, 10)
        ));

        JLabel lblTitulo = new JLabel(etiqueta);
        lblTitulo.setFont(new Font("Segoe UI", Font.BOLD, 10));
        lblTitulo.setForeground(COLOR_TEXTO_MUTED);

        lblValor.setFont(new Font("Segoe UI", Font.BOLD, 13));
        lblValor.setForeground(COLOR_TEXTO_MAIN);

        bloque.add(lblTitulo);
        bloque.add(Box.createRigidArea(new Dimension(0, 2)));
        bloque.add(lblValor);

        return bloque;
    }

    public JButton getBtnBuscar() { return btnBuscar; }
    public JTextField getTxtBuscarNombre() { return txtBuscarNombre; }
    public JComboBox<String> getCmbFiltroTipo() { return cmbFiltroTipo; }
    public DefaultTableModel getModeloTabla() { return modeloTabla; }
    public JMenuBar getMenuBarra() { return menuBarra; }
    public JMenuItem getItemCerrarSesion() { return itemCerrarSesion; }
    public JMenuItem getItemAgregar() { return itemAgregar; }
}