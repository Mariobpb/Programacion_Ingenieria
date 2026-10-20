package vista;

import controlador.ControlLogin;

import javax.swing.*;
import java.awt.*;

public class VistaLogin extends JFrame implements FormatoVista {
    private ControlLogin controlLogin = null;

    private JPanel panelPrincipal = null;
    private JPanel panelUsuario = null;
    private JPanel panelContrasena = null;

    private JLabel lblTitulo = null;
    private JLabel lblUsuario = null;
    private JTextField txtUsuario = null;
    private JLabel lblContrasena = null;
    private JPasswordField txtContrasena = null;
    private JButton btnIngresar = null;
    private JLabel lblMensaje = null;

    private Font fuenteTitulo = null;
    private Font fuenteSubtitulo = null;
    private Font fuenteIngresoDatos = null;

    public VistaLogin() {
        setTitle("LogIn");
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
    public void instanciarComponentes(){
        panelPrincipal = new JPanel();
        panelUsuario = new JPanel();
        panelContrasena = new JPanel();

        lblTitulo = new JLabel("SISTEMA DE GESTIÓN");

        lblUsuario = new JLabel("Usuario:");
        txtUsuario = new JTextField(20);

        lblContrasena = new JLabel("Contraseña:");
        txtContrasena = new JPasswordField(20);

        btnIngresar = new JButton("INGRESAR");

        lblMensaje = new JLabel("", SwingConstants.CENTER);

        fuenteTitulo = new Font("Segoe UI", Font.BOLD, 35);
        fuenteSubtitulo = new Font("Segoe UI", Font.BOLD, 20);
        fuenteIngresoDatos = new Font("Segoe UI", Font.BOLD, 16);
    }

    @Override
    public void configurarImagenes() {

    }

    @Override
    public void definirLayout() {
        panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
        panelUsuario.setLayout(new FlowLayout(FlowLayout.RIGHT, 30, 10));
        panelContrasena.setLayout(new FlowLayout(FlowLayout.RIGHT, 30, 10));
    }

    @Override
    public void cargarImagenes() {

    }

    @Override
    public void configurarComponenetes() {
        panelPrincipal.setBackground(Color.WHITE);
        panelPrincipal.setBorder(BorderFactory.createEmptyBorder(25, 40, 25, 40));

        panelUsuario.setOpaque(false);
        panelContrasena.setOpaque(false);

        lblTitulo.setFont(fuenteTitulo);
        lblTitulo.setForeground(Color.BLACK);
        lblTitulo.setAlignmentX(Component.CENTER_ALIGNMENT);

        panelUsuario.setAlignmentX(Component.CENTER_ALIGNMENT);
        panelContrasena.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblUsuario.setFont(fuenteSubtitulo);
        lblUsuario.setForeground(Color.BLACK);
        txtUsuario.setFont(fuenteIngresoDatos);

        lblContrasena.setFont(fuenteSubtitulo);
        lblContrasena.setForeground(Color.BLACK);
        txtContrasena.setFont(fuenteIngresoDatos);

        btnIngresar.setFont(new Font("Segoe UI", Font.BOLD, 15));
        btnIngresar.setForeground(Color.WHITE);
        btnIngresar.setBackground(Color.DARK_GRAY);
        btnIngresar.setFocusPainted(false);
        btnIngresar.setBorder(BorderFactory.createEmptyBorder(10, 30, 10, 30));
        btnIngresar.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btnIngresar.setAlignmentX(Component.CENTER_ALIGNMENT);

        lblMensaje.setFont(new Font("Segoe UI", Font.BOLD, 13));
        lblMensaje.setForeground(new Color(225, 29, 72));
        lblMensaje.setAlignmentX(Component.CENTER_ALIGNMENT);
    }


    @Override
    public void agregarComponentes() {
        panelUsuario.add(lblUsuario);
        panelUsuario.add(txtUsuario);

        panelContrasena.add(lblContrasena);
        panelContrasena.add(txtContrasena);

        panelPrincipal.add(lblTitulo);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 15)));
        panelPrincipal.add(panelUsuario);
        panelPrincipal.add(panelContrasena);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 15)));
        panelPrincipal.add(btnIngresar);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 10)));
        panelPrincipal.add(lblMensaje);
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
