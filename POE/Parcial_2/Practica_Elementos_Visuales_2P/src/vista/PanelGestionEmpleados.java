package vista;

import modelo.Usuario;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
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
    private JLabel lblUsuarioAdmin;
    private JLabel lblEdadAdmin;
    private JLabel lblTelefonoAdmin;
    private JLabel lblTurnoAdmin;
    private JLabel lblSalarioAdmin;
    private JLabel lblDomicilioAdmin;

    private JPanel panelFiltros;
    private JLabel lblBuscarNombre;
    private JTextField txtBuscarNombre;
    private JLabel lblFiltroTipo;
    private JComboBox<String> cmbFiltroTipo;
    private JButton btnBuscar;

    private JTable tablaEmpleados;
    private DefaultTableModel modeloTabla;
    private JScrollPane scrollTabla;

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
        menuOpciones.add(itemCerrarSesion);
        menuBarra.add(menuOpciones);

        panelIzquierdoPerfil = new JPanel();
        panelDerechoLista = new JPanel();

        lblFotoPerfil = new JLabel();
        lblNombreAdmin = new JLabel(usuarioActual.getNombre());
        lblRolAdmin = new JLabel("Rol: " + usuarioActual.getRol());
        lblUsuarioAdmin = new JLabel("Usuario: " + usuarioActual.getUsuario());
        lblEdadAdmin = new JLabel("Edad: " + usuarioActual.getEdad() + " años");
        lblTelefonoAdmin = new JLabel("Teléfono: " + usuarioActual.getTelefono());
        lblTurnoAdmin = new JLabel("Turno: " + (usuarioActual.getTurno() != null ? usuarioActual.getTurno() : "N/A"));
        lblSalarioAdmin = new JLabel("Salario Base: $" + usuarioActual.getSalarioBase());
        lblDomicilioAdmin = new JLabel("Domicilio: " + usuarioActual.getDomicilio());

        panelFiltros = new JPanel();
        lblBuscarNombre = new JLabel("Buscar por Nombre:");
        txtBuscarNombre = new JTextField(15);
        lblFiltroTipo = new JLabel("Tipo de Empleado:");

        String[] tipos = {"Todos", "Administrador", "Recepcionista", "Doctor"};
        cmbFiltroTipo = new JComboBox<>(tipos);
        btnBuscar = new JButton("Buscar");

        String[] columnas = {
                "Nombre", "Edad", "Teléfono", "Rol/Tipo", "Turno",
                "Salario Base", "Título/Cédula", "Especialidad"
        };
        modeloTabla = new DefaultTableModel(columnas, 0);
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
        panelDerechoLista.setLayout(new BorderLayout());

        panelFiltros.setLayout(new FlowLayout(FlowLayout.LEFT, 15, 10));
    }

    @Override
    public void configurarComponenetes() {
        Font fuenteTitulos = new Font("Segoe UI", Font.BOLD, 17);
        Font fuenteTexto = new Font("Segoe UI", Font.PLAIN, 13);
        Font fuenteDestacado = new Font("Segoe UI", Font.BOLD, 13);

        panelIzquierdoPerfil.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.GRAY), "Mi Perfil", TitledBorder.CENTER, TitledBorder.TOP, new Font("Segoe UI", Font.BOLD, 14)),
                new EmptyBorder(15, 15, 15, 15)
        ));
        panelIzquierdoPerfil.setPreferredSize(new Dimension(290, 0));
        panelIzquierdoPerfil.setBackground(Color.WHITE);

        lblFotoPerfil.setPreferredSize(new Dimension(110, 110));
        lblFotoPerfil.setMaximumSize(new Dimension(110, 110));
        lblFotoPerfil.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblNombreAdmin.setFont(fuenteTitulos);
        lblNombreAdmin.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblRolAdmin.setFont(fuenteDestacado);
        lblRolAdmin.setForeground(new Color(37, 99, 235));
        lblRolAdmin.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblUsuarioAdmin.setFont(fuenteTexto);
        lblUsuarioAdmin.setAlignmentX(Component.LEFT_ALIGNMENT);

        lblEdadAdmin.setFont(fuenteTexto);
        lblEdadAdmin.setAlignmentX(Component.LEFT_ALIGNMENT);

        lblTelefonoAdmin.setFont(fuenteTexto);
        lblTelefonoAdmin.setAlignmentX(Component.LEFT_ALIGNMENT);

        lblTurnoAdmin.setFont(fuenteTexto);
        lblTurnoAdmin.setAlignmentX(Component.LEFT_ALIGNMENT);

        lblSalarioAdmin.setFont(fuenteTexto);
        lblSalarioAdmin.setAlignmentX(Component.LEFT_ALIGNMENT);

        lblDomicilioAdmin.setFont(fuenteTexto);
        lblDomicilioAdmin.setAlignmentX(Component.LEFT_ALIGNMENT);

        panelDerechoLista.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        lblBuscarNombre.setFont(fuenteTexto);
        txtBuscarNombre.setFont(fuenteTexto);
        lblFiltroTipo.setFont(fuenteTexto);
        cmbFiltroTipo.setFont(fuenteTexto);
        btnBuscar.setFont(new Font("Segoe UI", Font.BOLD, 14));

        tablaEmpleados.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        tablaEmpleados.setRowHeight(25);
        tablaEmpleados.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 14));

        splitPane.setDividerLocation(290);
        splitPane.setDividerSize(5);
        splitPane.setContinuousLayout(true);
    }

    @Override
    public void configurarImagenes() {
        if (imgFotoPerfil != null) {
            lblFotoPerfil.setIcon(imgFotoPerfil);
        }
    }

    @Override
    public void agregarComponentes() {
        add(menuBarra, BorderLayout.NORTH);

        panelIzquierdoPerfil.add(lblFotoPerfil);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 10)));
        panelIzquierdoPerfil.add(lblNombreAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 4)));
        panelIzquierdoPerfil.add(lblRolAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 15)));
        panelIzquierdoPerfil.add(new JSeparator(JSeparator.HORIZONTAL));
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 15)));

        panelIzquierdoPerfil.add(lblUsuarioAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 8)));
        panelIzquierdoPerfil.add(lblEdadAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 8)));
        panelIzquierdoPerfil.add(lblTelefonoAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 8)));
        panelIzquierdoPerfil.add(lblTurnoAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 8)));
        panelIzquierdoPerfil.add(lblSalarioAdmin);
        panelIzquierdoPerfil.add(Box.createRigidArea(new Dimension(0, 8)));
        panelIzquierdoPerfil.add(lblDomicilioAdmin);

        panelFiltros.add(lblBuscarNombre);
        panelFiltros.add(txtBuscarNombre);
        panelFiltros.add(lblFiltroTipo);
        panelFiltros.add(cmbFiltroTipo);
        panelFiltros.add(btnBuscar);

        panelDerechoLista.add(panelFiltros, BorderLayout.NORTH);
        panelDerechoLista.add(scrollTabla, BorderLayout.CENTER);

        add(splitPane, BorderLayout.CENTER);
    }

    public JButton getBtnBuscar() { return btnBuscar; }
    public JTextField getTxtBuscarNombre() { return txtBuscarNombre; }
    public JComboBox<String> getCmbFiltroTipo() { return cmbFiltroTipo; }
    public DefaultTableModel getModeloTabla() { return modeloTabla; }
    public JMenuBar getMenuBarra() { return menuBarra; }
    public JMenuItem getItemCerrarSesion() { return itemCerrarSesion; }
    public JMenuItem getItemAgregar() { return itemAgregar; }
}