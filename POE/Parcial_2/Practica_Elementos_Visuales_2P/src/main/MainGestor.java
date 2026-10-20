package main;

import modelo.Administrador;
import modelo.Clinica;
import vista.VistaLogin;

public class MainGestor {
    public static void main(String[] args){
        Administrador adminBase = new Administrador("Mario Ponce", 22, 3323380639L, "", "Latuza 159", 15000, "MBPB", "12345");
        Clinica.usuarios.add(adminBase);

        VistaLogin login = new VistaLogin();
        login.mostrarVentana();
    }
}
