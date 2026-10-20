package vista;

import controlador.ControlLogin;

import javax.swing.*;
import java.awt.*;

public class VistaLogin extends JFrame implements FormatoVista {
    private ControlLogin controlLogin = null;

    private JPanel panelPrincipal = null;

    private JLabel lblTitulo = null;
    private JLabel lblUsuario = null;
    private JTextField txtUsuario = null;
    private JLabel lblContrasena = null;
    private JPasswordField txtContrasena = null;
    private JButton btnIngresar = null;
    private JLabel lblMensaje = null;

    private Font fuenteTitulo = null;
    private Font fuenteSubtitulo = null;
    private Font fuenteMensaje = null;

    public VistaLogin() {
        setTitle("LogIn");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(900, 600);
        setLocationRelativeTo(null);
        setResizable(false);
    }

    @Override
    public void mostrarVentana() {
        instanciarComponentes();
        definirLayout();
        configurarListeners();
        configurarComponenetes();
        agregarComponentes();


        add(panelPrincipal);

        controlLogin = new ControlLogin(this);
        setVisible(true);
    }

    @Override
    public void instanciarComponentes(){
        panelPrincipal = new JPanel();

        lblTitulo = new JLabel("INGRESO AL SISTEMA DE GESTIÓN");

        lblUsuario = new JLabel("Usuario:");
        txtUsuario = new JTextField();

        lblContrasena = new JLabel("Contraseña:");
        txtContrasena = new JPasswordField();

        btnIngresar = new JButton("Ingresar");

        lblMensaje = new JLabel();

        fuenteTitulo = new Font("Arial", Font.BOLD, 30);
        fuenteSubtitulo = new Font("Arial", Font.BOLD, 20);
        fuenteMensaje = new Font("Arial", Font.BOLD, 18);
    }

    @Override
    public void definirLayout() {
        panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
    }

    @Override
    public void configurarListeners() {
        btnIngresar.addActionListener(controlLogin);
    }

    @Override
    public void cargarImagenes() {

    }

    @Override
    public void configurarComponenetes() {
        panelPrincipal.setBorder(BorderFactory.createEmptyBorder(20, 50, 20, 50));
        lblTitulo.setFont(fuenteTitulo);
        lblUsuario.setFont(fuenteSubtitulo);
        txtUsuario.setMaximumSize(new Dimension(Integer.MAX_VALUE, 30));
        lblContrasena.setFont(fuenteSubtitulo);
        txtContrasena.setMaximumSize(new Dimension(Integer.MAX_VALUE, 30));
        btnIngresar.setAlignmentX(Component.CENTER_ALIGNMENT);
        lblMensaje.setForeground(Color.RED);
    }

    @Override
    public void configurarImagenes() {

    }

    @Override
    public void agregarComponentes() {
        panelPrincipal.add(lblTitulo);
        panelPrincipal.add(lblUsuario);
        panelPrincipal.add(txtUsuario);
        panelPrincipal.add(lblContrasena);
        panelPrincipal.add(txtContrasena);
        panelPrincipal.add(btnIngresar);
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
