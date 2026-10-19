package controlador;

import modelo.Clinica;
import modelo.Usuario;
import vista.VentanaLogin;
import vista.VentanaPrincipal;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlLogin implements ActionListener {
    private VentanaLogin ventanaLogin = null;
    private VentanaPrincipal ventanaPrincipal = null;

    public ControlLogin(VentanaLogin ventanaLogin) {
        this.ventanaLogin = ventanaLogin;

        ventanaLogin.getBtnIngresar().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ventanaLogin.getBtnIngresar()){
            String usuario = ventanaLogin.getTxtUsuario().getText();
            String contrasena = ventanaLogin.getTxtContrasena().getText();

            boolean credencialesValidas = false;

            for (Usuario u : Clinica.usuarios) {
                if (u.getUsuario().equals(usuario) && u.getContrasena().equals(contrasena)) {
                    credencialesValidas = true;
                    System.out.println("BIENVENIDO");

                    if (ventanaPrincipal == null) {
                        ventanaPrincipal = new VentanaPrincipal(ventanaLogin);
                        ventanaPrincipal.mostrarVentana();
                    }
                    ventanaPrincipal.getVtnPrincipal().setVisible(true);
                    ventanaLogin.getVtnLogin().setVisible(false);

                    break;
                }
            }

            if(!credencialesValidas) {
                System.out.println("Usuario incorrecto");
            }
        }
    }
}
