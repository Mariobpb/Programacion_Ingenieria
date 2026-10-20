package main;

import modelo.*;
import vista.VistaLogin;
import java.util.Date;

public class MainGestor {
    public static void main(String[] args){
        agregarDatosEstaticos();

        VistaLogin login = new VistaLogin();
        login.mostrarVentana();
    }

    private static void agregarDatosEstaticos(){
        Clinica.usuarios.add(new Administrador("Mario Ponce", 22, 3323380639L, "Latuza 159", 15000.0, "Matutino", "MBPB", "12345"));
        Clinica.usuarios.add(new Administrador("Carlos Ruiz", 38, 3311223344L, "Av. Hidalgo 450", 22000.0, "Vespertino", "CRuiz", "admin123"));

        Clinica.usuarios.add(new Recepcionista("Mariana Torres", 23, 3324380132L, "Lomas 821", 18000.0, "Matutino", "MI", "12345"));
        Clinica.usuarios.add(new Recepcionista("Fernanda Delgado", 26, 3355667788L, "Calle Independencia 102", 14000.0, "Vespertino", "FDelgado", "rec123"));
        Clinica.usuarios.add(new Recepcionista("Andrea Morales", 24, 3366778899L, "Av. México 550", 13500.0, "Matutino", "AMorales", "rec456"));
        Clinica.usuarios.add(new Recepcionista("Valeria Ortega", 28, 3377889900L, "Calle Morelos 980", 14500.0, "Vespertino", "VOrtega", "rec789"));
        Clinica.usuarios.add(new Recepcionista("Daniela Rios", 22, 3388990011L, "Av. Americas 140", 13000.0, "Matutino", "DRios", "rec321"));
        Clinica.usuarios.add(new Recepcionista("Lucia Navarro", 25, 3399001122L, "Calle Juarez 715", 14000.0, "Vespertino", "LNavarro", "rec654"));
        Clinica.usuarios.add(new Recepcionista("Sofia Castro", 29, 3344556677L, "Calle Chapultepec 310", 15000.0, "Matutino", "SCastro", "rec987"));
        Clinica.usuarios.add(new Recepcionista("Gabriela Gomez", 27, 3311998877L, "Av. La Paz 404", 14200.0, "Vespertino", "GGomez", "rec111"));

        Clinica.doctores.add(new Doctor("Alejandro Perez", 43, 3313626100L, "Colinas 141", 28500.0, "Matutino", true, "Cirujano General"));
        Clinica.doctores.add(new Doctor("Javier Hernandez", 50, 3310102030L, "Av. Patria 220", 30000.0, "Vespertino", true, "Pediatra"));
        Clinica.doctores.add(new Doctor("Gabriela Silva", 39, 3320203040L, "Calle Zaragoza 605", 28000.0, "Matutino", true, "Cardióloga"));
        Clinica.doctores.add(new Doctor("Ricardo Vargas", 47, 3330304050L, "Av. Guadalupe 890", 32000.0, "Vespertino", true, "Dermatólogo"));
        Clinica.doctores.add(new Doctor("Patricia Aguilar", 36, 3340405060L, "Calle Libertad 330", 27000.0, "Matutino", true, "Ginecóloga"));
        Clinica.doctores.add(new Doctor("Fernando Ramos", 55, 3350506070L, "Av. Union 105", 35000.0, "Vespertino", true, "Traumatólogo"));
        Clinica.doctores.add(new Doctor("Elena Mendoza", 41, 3360607080L, "Calle Prisciliano Sanchez 420", 29000.0, "Matutino", true, "Oftalmóloga"));
        Clinica.doctores.add(new Doctor("Hugo Gutierrez", 33, 3370708090L, "Av. Niño Obrero 750", 26000.0, "Vespertino", false, "Neurólogo"));
        Clinica.doctores.add(new Doctor("Monique Castillo", 37, 3380809000L, "Calle Terranova 112", 28500.0, "Matutino", true, "Psiquiatra"));
        Clinica.doctores.add(new Doctor("Rodrigo Alvarez", 48, 3390900011L, "Av. Mexico 1010", 31000.0, "Vespertino", true, "Otorrinolaringólogo"));


        Clinica.pacientes.add(new Paciente("Juan Escutia", 20, 3311112222L, "Alergia a la Penicilina"));
        Clinica.pacientes.add(new Paciente("Maria Felix", 65, 3322223333L, "Hipertensa"));
        Clinica.pacientes.add(new Paciente("Pedro Infante", 45, 3333334444L, "Diabético Tipo 2"));
        Clinica.pacientes.add(new Paciente("Luis Miguel", 30, 3344445555L, "Ninguna"));
        Clinica.pacientes.add(new Paciente("Consuelo Velazquez", 28, 3355556666L, "Intolerante a la Lactosa"));
    }
}