package dao;

import modelo.Alumno;

import javax.xml.transform.Result;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

public class AlumnoDAOImp implements AlumnoDAO{
    private String stInsertar = "INSERT INTO Alumno VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
    private String stConsultar = "SELECT * FROM Alumno WHERE codigo=?";
    private String stActualizar = "UPDATE Alumno SET calMate=?, calFisica=?, calProgra=?, promedio=? WHERE codigo = ?";
    private String stEliminar = "DELETE FROM Alumno WHERE codigo=?";

    @Override
    public void insertar(Alumno alumno) {
        try (Connection conexion = ConexionBD.obtenerConexion();
             PreparedStatement ps = conexion.prepareStatement(stInsertar)) {
            ps.setString(1, alumno.getCodigo());
            ps.setString(2, alumno.getNombre());
            ps.setInt(3, alumno.getEdad());
            ps.setString(4, alumno.getEmail());
            ps.setString(5, alumno.getCarrera());
            ps.setDouble(6, alumno.getCalMate());
            ps.setDouble(7, alumno.getCalFisica());
            ps.setDouble(8, alumno.getCalProgra());
            ps.setDouble(9, alumno.getPromedio());

            ps.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Error al registrar un Alumno");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void actualizar(Alumno alumno) {
        try (Connection conexion = ConexionBD.obtenerConexion();
             PreparedStatement ps = conexion.prepareStatement(stActualizar)){
            ps.setDouble(1, alumno.getCalMate());
            ps.setDouble(2, alumno.getCalFisica());
            ps.setDouble(3, alumno.getCalProgra());
            ps.setDouble(4, alumno.getPromedio());
            ps.setString(5, alumno.getCodigo());

            ps.executeUpdate();

        } catch (SQLException e){
            System.out.println("Error al actualizar Alumno");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void eliminar(Alumno alumno) {
        try (Connection conexion = ConexionBD.obtenerConexion();
             PreparedStatement ps = conexion.prepareStatement(stEliminar)){
            ps.setString(1, alumno.getCodigo());

            ps.executeUpdate();
        } catch (SQLException e){
            System.out.println("Error al eliminar Alumno");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public Alumno buscarPorCodigo(String codigo) {
        try (Connection conexion = ConexionBD.obtenerConexion();
              PreparedStatement ps = conexion.prepareStatement(stConsultar)){

            ps.setString(1, codigo);
            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                return construirAlumno(rs);
            }
        } catch (SQLException e) {
            System.out.println("Error al Buscar un Alumno por código");
            System.out.println(e.getMessage());
        }
        return null;
    }

    private Alumno construirAlumno(ResultSet rs) {
        Alumno alumno = null;
        try {
            alumno = new Alumno();
            alumno.setCodigo(rs.getString("codigo"));
            alumno.setNombre(rs.getString("nombre"));
            alumno.setEdad(rs.getInt("edad"));
            alumno.setEmail(rs.getString("email"));
            alumno.setCarrera(rs.getString("carrera"));
            alumno.setCalMate(rs.getDouble("calMate"));
            alumno.setCalFisica(rs.getDouble("calFisica"));
            alumno.setCalProgra(rs.getDouble("calProgra"));
            alumno.setPromedio(rs.getDouble("promedio"));
        } catch (SQLException e){
            System.out.println("Error al construir el Alumno");
            System.out.println(e.getMessage());
        }
        return alumno;
    }

    @Override
    public List<Alumno> listarTodos() {
        return List.of();
    }

}
