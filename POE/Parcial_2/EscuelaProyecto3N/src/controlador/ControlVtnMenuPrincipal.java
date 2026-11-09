package controlador;

import vista.VtnAlumno;
import vista.VtnDocente;
import vista.VtnMenuPrincipal;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlVtnMenuPrincipal implements ActionListener {
    private VtnMenuPrincipal vtnMenuPrincipal = null;

    private VtnAlumno vtnAlumno = null;
    private VtnDocente vtnDocente = null;

    public ControlVtnMenuPrincipal(VtnMenuPrincipal vtnMenuPrincipal) {
        this.vtnMenuPrincipal = vtnMenuPrincipal;

        vtnMenuPrincipal.getBtnAlumno().addActionListener(this);
        vtnMenuPrincipal.getBtnDocente().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vtnMenuPrincipal.getBtnAlumno()){
            if (vtnAlumno == null){
                vtnAlumno = new VtnAlumno(vtnMenuPrincipal);
                vtnAlumno.dibujarVentana();
            }
            vtnAlumno.getVtn().setVisible(true);
            vtnMenuPrincipal.getVtn().setVisible(false);
        } else if (e.getSource() == vtnMenuPrincipal.getBtnDocente()){
            if (vtnDocente == null){
                vtnDocente = new VtnDocente(vtnMenuPrincipal);
                vtnDocente.dibujarVentana();
            }
            vtnDocente.getVtn().setVisible(true);
            vtnMenuPrincipal.getVtn().setVisible(false);
        }
    }
}
