package controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import modelo.Alumno;
import modelo.Docente;
import vistas.VtnAlumno;
import vistas.VtnDocente;
import vistas.VtnMenuPrincipal;


public class ControladorMenuPrincipal implements ActionListener{

    private VtnMenuPrincipal vtn;
    private VtnAlumno vtnAl = null;
    private VtnDocente vtnDoc = null;
    
    private Alumno objAl = null;
    private Docente objDoc = null; 
    
    private ControladorVtnAlumno controlAl = null;
    private ControladorVtnDocente controlDoc = null;
    
    public ControladorMenuPrincipal(VtnMenuPrincipal vtn) {
        this.vtn = vtn;
        objAl = new Alumno();
        objDoc = new Docente();
        this.vtn.getBtnAlumno().addActionListener(this);
        this.vtn.getBtnDocente().addActionListener(this); 
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtn.getBtnAlumno()){
            if(vtnAl == null){      
                vtnAl = new VtnAlumno();
                vtnAl.dibujarVentana();
                controlAl =  new ControladorVtnAlumno(this, objAl);
            }
            vtnAl.getVtn().setVisible(true);
            vtn.getVtn().setVisible(false);
        }
        
        if(e.getSource() == vtn.getBtnDocente()){
            if(vtnDoc == null){
                vtnDoc = new VtnDocente();
                vtnDoc.dibujarVentana();
                controlDoc =  new ControladorVtnDocente(this, objAl, objDoc);
            }
            vtnDoc.getVtn().setVisible(true);
            vtn.getVtn().setVisible(false);     
        }
    }

    public VtnMenuPrincipal getVtn() {
        return vtn;
    }

    public VtnAlumno getVtnAl() {
        return vtnAl;
    }

    public VtnDocente getVtnDoc() {
        return vtnDoc;
    }   
}
