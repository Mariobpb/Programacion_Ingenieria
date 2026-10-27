package vista;

import controlador.ControlLogin;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class VistaLogin extends JFrame implements FormatoVista {
    private ControlLogin controlLogin = null;

    private JPanel panelPrincipal = null;
    private JPanel panelTarjeta = null;
    private JPanel panelUsuario = null;
    private JPanel panelContrasena = null;

    private JLabel lblSubtitulo = null;
    private JLabel lblTitulo = null;
    private JLabel lblUsuario = null;
    private JTextField txtUsuario = null;
    private JLabel lblContrasena = null;
    private JPasswordField txtContrasena = null;
    private JButton btnIngresar = null;
    private JLabel lblMensaje = null;

    private final Color COLOR_FONDO = new Color(15, 23, 42);
    private final Color COLOR_TARJETA = new Color(30, 41, 59);
    private final Color COLOR_INPUT_BG = new Color(15, 23, 42);
    private final Color COLOR_TEXTO_PRINCIPAL = new Color(248, 250, 252);
    private final Color COLOR_TEXTO_MUTED = new Color(148, 163, 184);
    private final Color COLOR_PRIMARIO = new Color(59, 130, 246);
    private final Color COLOR_BORDE = new Color(51, 65, 85);
    private final Color COLOR_ERROR = new Color(244, 63, 94);

    private Font fuenteTitulo = null;
    private Font fuenteSubtitulo = null;
    private Font fuenteEtiquetas = null;
    private Font fuenteIngresoDatos = null;

    public VistaLogin() {
        setTitle("Sistema de Gestión Médica - Inicio de Sesión");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
    }

    @Override
    public void mostrarVentana() {
        instanciarComponentes();
        definirLayout();
        configurarComponenetes();
        agregarComponentes();

        add(panelPrincipal);

        pack();
        setLocationRelativeTo(null);

        controlLogin = new ControlLogin(this);
        setVisible(true);
    }

    @Override
    public void instanciarComponentes() {
        panelPrincipal = new JPanel();
        panelTarjeta = new JPanel();
        panelUsuario = new JPanel();
        panelContrasena = new JPanel();

        lblSubtitulo = new JLabel("SISTEMA DE GESTIÓN MÉDICA");
        lblTitulo = new JLabel("Iniciar Sesión");

        lblUsuario = new JLabel("Usuario");
        txtUsuario = new JTextField(22);

        lblContrasena = new JLabel("Contraseña");
        txtContrasena = new JPasswordField(22);

        btnIngresar = new JButton("INGRESAR");

        lblMensaje = new JLabel(" ", SwingConstants.CENTER);

        fuenteTitulo = new Font("Segoe UI", Font.BOLD, 26);
        fuenteSubtitulo = new Font("Segoe UI", Font.BOLD, 11);
        fuenteEtiquetas = new Font("Segoe UI", Font.BOLD, 13);
        fuenteIngresoDatos = new Font("Segoe UI", Font.PLAIN, 14);
    }

    @Override
    public void cargarImagenes() { }

    @Override
    public void configurarImagenes() { }

    @Override
    public void definirLayout() {
        panelPrincipal.setLayout(new GridBagLayout());

        panelTarjeta.setLayout(new BoxLayout(panelTarjeta, BoxLayout.Y_AXIS));

        panelUsuario.setLayout(new BoxLayout(panelUsuario, BoxLayout.Y_AXIS));
        panelContrasena.setLayout(new BoxLayout(panelContrasena, BoxLayout.Y_AXIS));
    }

    @Override
    public void configurarComponenetes() {
        panelPrincipal.setBackground(COLOR_FONDO);
        panelPrincipal.setBorder(new EmptyBorder(35, 35, 35, 35));

        panelTarjeta.setBackground(COLOR_TARJETA);
        panelTarjeta.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(COLOR_BORDE, 1, true),
                new EmptyBorder(30, 45, 30, 45)
        ));
        panelTarjeta.setAlignmentX(Component.CENTER_ALIGNMENT);

        panelUsuario.setOpaque(false);
        panelUsuario.setAlignmentX(Component.CENTER_ALIGNMENT);

        panelContrasena.setOpaque(false);
        panelContrasena.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblSubtitulo.setFont(fuenteSubtitulo);
        lblSubtitulo.setForeground(COLOR_PRIMARIO);
        lblSubtitulo.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblTitulo.setFont(fuenteTitulo);
        lblTitulo.setForeground(COLOR_TEXTO_PRINCIPAL);
        lblTitulo.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblUsuario.setFont(fuenteEtiquetas);
        lblUsuario.setForeground(COLOR_TEXTO_MUTED);
        lblUsuario.setAlignmentX(Component.CENTER_ALIGNMENT);

        txtUsuario.setFont(fuenteIngresoDatos);
        txtUsuario.setForeground(COLOR_TEXTO_PRINCIPAL);
        txtUsuario.setBackground(COLOR_INPUT_BG);
        txtUsuario.setCaretColor(COLOR_TEXTO_PRINCIPAL);
        txtUsuario.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(COLOR_BORDE, 1, true),
                BorderFactory.createEmptyBorder(8, 12, 8, 12)
        ));
        txtUsuario.setAlignmentX(Component.CENTER_ALIGNMENT);
        txtUsuario.setMaximumSize(new Dimension(280, 38));

        lblContrasena.setFont(fuenteEtiquetas);
        lblContrasena.setForeground(COLOR_TEXTO_MUTED);
        lblContrasena.setAlignmentX(Component.CENTER_ALIGNMENT);

        txtContrasena.setFont(fuenteIngresoDatos);
        txtContrasena.setForeground(COLOR_TEXTO_PRINCIPAL);
        txtContrasena.setBackground(COLOR_INPUT_BG);
        txtContrasena.setCaretColor(COLOR_TEXTO_PRINCIPAL);
        txtContrasena.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(COLOR_BORDE, 1, true),
                BorderFactory.createEmptyBorder(8, 12, 8, 12)
        ));
        txtContrasena.setAlignmentX(Component.CENTER_ALIGNMENT);
        txtContrasena.setMaximumSize(new Dimension(280, 38));

        btnIngresar.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btnIngresar.setForeground(Color.WHITE);
        btnIngresar.setBackground(COLOR_PRIMARIO);
        btnIngresar.setFocusPainted(false);
        btnIngresar.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));
        btnIngresar.setAlignmentX(Component.CENTER_ALIGNMENT);
        btnIngresar.setMaximumSize(new Dimension(280, 42));

        lblMensaje.setFont(new Font("Segoe UI", Font.BOLD, 12));
        lblMensaje.setForeground(COLOR_ERROR);
        lblMensaje.setAlignmentX(Component.CENTER_ALIGNMENT);
    }

    @Override
    public void agregarComponentes() {
        panelUsuario.add(lblUsuario);
        panelUsuario.add(Box.createRigidArea(new Dimension(0, 6)));
        panelUsuario.add(txtUsuario);

        panelContrasena.add(lblContrasena);
        panelContrasena.add(Box.createRigidArea(new Dimension(0, 6)));
        panelContrasena.add(txtContrasena);

        panelTarjeta.add(lblSubtitulo);
        panelTarjeta.add(Box.createRigidArea(new Dimension(0, 4)));
        panelTarjeta.add(lblTitulo);
        panelTarjeta.add(Box.createRigidArea(new Dimension(0, 25)));

        panelTarjeta.add(panelUsuario);
        panelTarjeta.add(Box.createRigidArea(new Dimension(0, 15)));

        panelTarjeta.add(panelContrasena);
        panelTarjeta.add(Box.createRigidArea(new Dimension(0, 25)));

        panelTarjeta.add(btnIngresar);
        panelTarjeta.add(Box.createRigidArea(new Dimension(0, 12)));

        panelTarjeta.add(lblMensaje);

        panelPrincipal.add(panelTarjeta);
    }

    public JTextField getTxtUsuario() {
        return txtUsuario;
    }

    public JPasswordField getTxtContrasena() {
        return txtContrasena;
    }

    public JButton getBtnIngresar() {
        return btnIngresar;
    }

    public JLabel getLblMensaje() {
        return lblMensaje;
    }
}