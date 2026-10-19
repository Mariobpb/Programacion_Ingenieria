package vista;

import controlador.ControlAdmin;
import controlador.ControlLogin;

import javax.swing.*;
import java.awt.*;

public class VentanaLogin {
    private ControlLogin controlLogin;
    private JFrame vtn = null;

    private JTextField txtUsuario;
    private JPasswordField txtContrasena;
    private JButton btnIngresar;

    public VentanaLogin() {
        vtn = new JFrame("LogIn");
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtn.setSize(500, 300);
        vtn.setResizable(false);
    }

    public void mostrarVentana() {
        JPanel panelPrincipal = new JPanel();
        panelPrincipal.setLayout(new BoxLayout(panelPrincipal, BoxLayout.Y_AXIS));
        panelPrincipal.setBorder(BorderFactory.createEmptyBorder(20, 50, 20, 50));

        // Inicialización de componentes visuales
        JLabel lblUsuario = new JLabel("Usuario:");
        txtUsuario = new JTextField();
        txtUsuario.setMaximumSize(new Dimension(Integer.MAX_VALUE, 30));

        JLabel lblContrasena = new JLabel("Contraseña:");
        txtContrasena = new JPasswordField(); // Instancia del Password Field
        txtContrasena.setMaximumSize(new Dimension(Integer.MAX_VALUE, 30));

        btnIngresar = new JButton("Ingresar");
        btnIngresar.setAlignmentX(Component.CENTER_ALIGNMENT); // Centrar el botón

        // Instanciar el controlador y pasarse a sí misma como referencia
        controlLogin = new ControlLogin(this);

        // Escuchar el evento principal del componente visual (Requisito del documento)
        btnIngresar.addActionListener(controlLogin);

        // Ensamblar la interfaz
        panelPrincipal.add(lblUsuario);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 5)));
        panelPrincipal.add(txtUsuario);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 15)));
        panelPrincipal.add(lblContrasena);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 5)));
        panelPrincipal.add(txtContrasena);
        panelPrincipal.add(Box.createRigidArea(new Dimension(0, 25)));
        panelPrincipal.add(btnIngresar);

        vtn.add(panelPrincipal);
        vtn.setVisible(true);
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
}
