package modelo;

public class PrincipalEscuela {

    public static void main(String[] args) {
        Alumno objAl = new Alumno();
        Docente objDoc = new Docente();

        objAl.setNombre("Mario Ponce");
        objAl.setEdad(22);
        objAl.setEmail("mario@gmail.com");
        objAl.setCodigo("25310234");
        objAl.setCarrera("IDS");

        objDoc.setNombre("Pedro Lopez");
        objDoc.setEdad(35);
        objDoc.setEmail("pedro@gmail.com");
        objDoc.setCodigo("6789");
        objDoc.setCantHoras(20);
        objDoc.setPahoHora(200);

        System.out.println(objAl.mostrarInfo());
        System.out.println("-------------------------------");
        System.out.println(objDoc.mostrarInfo());

        objDoc.calcularSalario();
        objDoc.evaluarAlumno(objAl, 80, 100, 90);

        System.out.println(objAl.mostrarInfo());
        System.out.println("-------------------------------");
        System.out.println(objDoc.mostrarInfo());
    }
}
