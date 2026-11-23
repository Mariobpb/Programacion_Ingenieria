package controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JOptionPane;

import dao.AlumnoDAO;
import dao.AlumnoDAOImp;
import modelo.Alumno;
import modelo.Docente;
import vistas.VtnDocente;

public class ControladorVtnDocente implements ActionListener{

    private VtnDocente vtnDoc = null;
    private ControladorMenuPrincipal controlPrin = null;
    private Alumno objAl = null;
    private Docente objDoc = null;
    private AlumnoDAO alumnoDAO;
    
    public ControladorVtnDocente(ControladorMenuPrincipal controlPrin, Alumno objAl, Docente objDoc) {
        this.controlPrin = controlPrin;
        this.objAl = objAl;
        this.objDoc =objDoc;
        this.vtnDoc = controlPrin.getVtnDoc();
        this.alumnoDAO = new AlumnoDAOImp();
              
        this.vtnDoc.getBtnRegresar().addActionListener(this);
        this.vtnDoc.getBtnGuardar().addActionListener(this);
        this.vtnDoc.getBtnBuscar().addActionListener(this);
        this.vtnDoc.getBtnBuscarAlumno().addActionListener(this);
        this.vtnDoc.getBtnEvaluarAlumno().addActionListener(this);
        this.vtnDoc.getBtnEliminarAlumno().addActionListener(this);
        
        
        this.vtnDoc.getVtn().addWindowListener(new WindowAdapter(){
            @Override
            public void windowClosing(WindowEvent e){
              controlPrin.getVtn().getVtn().setVisible(true);  
            }
        });
    }

    
    
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtnDoc.getBtnRegresar()){
            controlPrin.getVtn().getVtn().setVisible(true);
            vtnDoc.getVtn().setVisible(false);
        }
        
        if(e.getSource() == vtnDoc.getBtnGuardar()){
            almacenarDocente();
        }
        
        if(e.getSource() == vtnDoc.getBtnBuscar()){
            if(vtnDoc.getTxtBuscar().getText().equals(objDoc.getCodigo())){
               vtnDoc.getTxtResultado().setText(objDoc.mostrarInfo());
            }else{
              JOptionPane.showMessageDialog(null, "Docente no encontrado");
              borrarCajas();
            }
        }
        
        if(e.getSource() == vtnDoc.getBtnBuscarAlumno()){
            String codigo = vtnDoc.getTxtCodigoAlumno().getText().trim();
            objAl = alumnoDAO.buscarPorCodigo(codigo);

            if(objAl != null){
                JOptionPane.showMessageDialog(null, "Alumno encontrado, lo puedes evaluar");
                vtnDoc.habilitarEvaluacion();
            }else{
                JOptionPane.showMessageDialog(null, "Alumno no encontrado");
            }
        }
        
        if(e.getSource() == vtnDoc.getBtnEvaluarAlumno()){
            evaluarAlumno();
            borrarCajas();
            alumnoDAO.actualizar(objAl);
            JOptionPane.showMessageDialog(null, "Alumno " + objAl.getNombre() + " evaluado");
            vtnDoc.deshabilitarEvaluacion();
        }

        if(e.getSource() == vtnDoc.getBtnEliminarAlumno()) {
            eliminarAlumno();
        }
    }

    public void almacenarDocente(){
        objDoc.setNombre(vtnDoc.getTxtNombre().getText());
        objDoc.setEdad(Integer.parseInt(vtnDoc.getTxtEdad().getText()));
        objDoc.setEmail(vtnDoc.getTxtEmail().getText());
        objDoc.setCodigo(vtnDoc.getTxtCodigo().getText());
        objDoc.setCantHoras(Integer.parseInt(vtnDoc.getTxtHorasTrabajadas().getText()));
        objDoc.setPagoHora(Double.parseDouble(vtnDoc.getTxtPagoHora().getText()));
        objDoc.calcularSalario();
        JOptionPane.showMessageDialog(null, "Docente almacenado correctamente");
        borrarCajas();
        System.out.println(objDoc.mostrarInfo());
        
    }

    public void borrarCajas(){
        vtnDoc.getTxtNombre().setText("");
        vtnDoc.getTxtEdad().setText("");
        vtnDoc.getTxtEmail().setText("");
        vtnDoc.getTxtCodigo().setText("");
        vtnDoc.getTxtHorasTrabajadas().setText("");
        vtnDoc.getTxtPagoHora().setText("");
        vtnDoc.getTxtResultado().setText("");
        vtnDoc.getTxtMatematicas().setText("");
        vtnDoc.getTxtFisica().setText("");
        vtnDoc.getTxtProgramacion().setText("");
        vtnDoc.getTxtEliminarAlumno().setText("");
    }
    
    public void evaluarAlumno(){
        double calMate = Double.parseDouble(vtnDoc.getTxtMatematicas().getText());
        double calFisica = Double.parseDouble(vtnDoc.getTxtFisica().getText());
        double calProgra = Double.parseDouble(vtnDoc.getTxtProgramacion().getText());
        
        objDoc.evaluarAlumno(objAl, calMate, calFisica, calProgra);


        
    }

    private void eliminarAlumno() {
        String codigo = vtnDoc.getTxtEliminarAlumno().getText().trim();

        objAl = alumnoDAO.buscarPorCodigo(codigo);

        if (objAl != null) {
            int respuesta = JOptionPane.showConfirmDialog(
                    vtnDoc.getVtn(),
                    "¿Está seguro de eliminar al alumno: " + objAl.getNombre() + "?",
                    "Eliminar alumno",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.WARNING_MESSAGE
            );

            if (respuesta == JOptionPane.YES_OPTION) {
                alumnoDAO.eliminar(objAl);
                JOptionPane.showMessageDialog(vtnDoc.getVtn(), "Alumno " + objAl.getNombre() + " eliminado");
                borrarCajas();
            }
        } else {
            JOptionPane.showMessageDialog(vtnDoc.getVtn(), "Alumno no encontrado");
            borrarCajas();
        }
    }
}
