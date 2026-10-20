package controlador;

import modelo.Clinica;
import modelo.Usuario;
import vista.VistaLogin;
import vista.VistaPrincipal;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlLogin implements ActionListener {
    private VistaLogin ventanaLogin = null;

    public ControlLogin(VistaLogin ventanaLogin) {
        this.ventanaLogin = ventanaLogin;
        ventanaLogin.getBtnIngresar().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ventanaLogin.getBtnIngresar()) {
            String usuario = ventanaLogin.getTxtUsuario().getText();
            String contrasena = ventanaLogin.getTxtContrasena().getText();

            boolean credencialesValidas = false;

            for (Usuario u : Clinica.usuarios) {
                if (u.getUsuario().equals(usuario) && u.getContrasena().equals(contrasena)) {
                    credencialesValidas = true;
                    ventanaLogin.getLblMensaje().setText("");

                    VistaPrincipal ventanaPrincipal = new VistaPrincipal(ventanaLogin, u);
                    ventanaPrincipal.mostrarVentana();

                    ventanaLogin.setVisible(false);
                    break;
                }
            }

            if (!credencialesValidas) {
                ventanaLogin.getLblMensaje().setText("Credenciales Incorrectas");
            }
        }
    }
}