package controlador;

import modelo.Clinica;
import modelo.Usuario;
import vista.VentanaLogin;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlLogin implements ActionListener {
    private VentanaLogin vista;

    public ControlLogin(VentanaLogin vista) {
        this.vista = vista;

        vista.getBtnIngresar().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vista.getBtnIngresar()){
            String usuario = vista.getTxtUsuario().getText();
            String contrasena = vista.getTxtContrasena().getText();

            boolean credencialesValidas = false;

            for (Usuario u : Clinica.usuarios) {
                if (u.getUsuario().equals(usuario) && u.getContrasena().equals(contrasena)) {
                    credencialesValidas = true;
                    System.out.println("BIENVENIDO");

                    break;
                }
            }

            if(!credencialesValidas) {
                System.out.println("Usuario incorrecto");
            }
        }
    }
}
