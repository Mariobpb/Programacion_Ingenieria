package controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JOptionPane;

import dao.AlumnoDAO;
import dao.AlumnoDAOImp;
import modelo.Alumno;
import vistas.VtnAlumno;

public class ControladorVtnAlumno implements ActionListener {
    private ControladorMenuPrincipal controlPrin = null;
    private VtnAlumno vtnAl = null;
    private Alumno objAl = null;
    private AlumnoDAO alumnoDAO;
    
    public ControladorVtnAlumno(ControladorMenuPrincipal controlPrin, Alumno objAl) {
        this.objAl = objAl;
        this.controlPrin = controlPrin;
        this.vtnAl = controlPrin.getVtnAl();
        this.alumnoDAO = new AlumnoDAOImp();

        this.vtnAl.getBtnRegresar().addActionListener(this);
        this.vtnAl.getBtnGuardar().addActionListener(this);
        this.vtnAl.getBtnBuscar().addActionListener(this);

        this.vtnAl.getVtn().addWindowListener(new WindowAdapter(){
            @Override
            public void windowClosing(WindowEvent e){
              controlPrin.getVtn().getVtn().setVisible(true);
            }
        });

    }

    
    
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtnAl.getBtnRegresar()){
            controlPrin.getVtn().getVtn().setVisible(true);
            vtnAl.getVtn().setVisible(false);
        }
        
        if(e.getSource() == vtnAl.getBtnGuardar()){
            almacenarAlumno();
        }
        
        if(e.getSource() == vtnAl.getBtnBuscar()){
            buscarAlumno();
        }
        
    }
    
    public void buscarAlumno(){
        String codigo = vtnAl.getTxtBuscar().getText().trim();

        objAl = alumnoDAO.buscarPorCodigo(codigo);

        if(objAl != null){
            vtnAl.getTxtResultado().setText(objAl.mostrarInfo());
        }else{
            JOptionPane.showMessageDialog(null, "Alumno no encontrado");
            borrarCajas();
        }
    }
    
    public void almacenarAlumno(){
        objAl.setNombre(vtnAl.getTxtNombre().getText());
        objAl.setEdad(Integer.parseInt(vtnAl.getTxtEdad().getText()));
        objAl.setEmail(vtnAl.getTxtEmail().getText());
        objAl.setCodigo(vtnAl.getTxtCodigo().getText());
        objAl.setCarrera(vtnAl.getTxtCarrera().getText());

        alumnoDAO.insertar(objAl);
        JOptionPane.showMessageDialog(null, "Alumno almacenado correctamente");
        borrarCajas();
        System.out.println(objAl.mostrarInfo());
    }
    public void borrarCajas(){
        vtnAl.getTxtNombre().setText("");
        vtnAl.getTxtEdad().setText("");
        vtnAl.getTxtEmail().setText("");
        vtnAl.getTxtCodigo().setText("");
        vtnAl.getTxtCarrera().setText("");
        vtnAl.getTxtResultado().setText("");
    }
}
