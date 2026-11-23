package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConexionBD {
    private static final String URL =
            "jdbc:mysql://localhost:3306/escuela3n?serverTimezone=America/Mexico_City";
    private static final String USUARIO = "root";
    private static final String PASSWORD = "";

    public static Connection obtenerConexion() {
        Connection conexion = null;
        try {
            conexion = DriverManager.getConnection(URL, USUARIO, PASSWORD);
        } catch (SQLException e) {
            System.out.println("Error al Conectar a la Base de Datos");
            System.out.println(e.getMessage());
        }
        return conexion;
    }
}
