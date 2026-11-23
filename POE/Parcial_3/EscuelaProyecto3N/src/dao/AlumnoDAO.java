package dao;

import modelo.Alumno;

import java.util.List;

public interface AlumnoDAO {
    void insertar(Alumno alumno);
    void actualizar(Alumno alumno);
    void eliminar(Alumno alumno);
    Alumno buscarPorCodigo(String codigo);
    List<Alumno> listarTodos();
}
