package controlador;

import vista.VtnAlumno;
import vista.VtnMenuPrincipal;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlVtnMenuPrincipal implements ActionListener {
    private VtnMenuPrincipal vtnMenuPrincipal = null;
    private VtnAlumno vtnAlumno = null;

    public ControlVtnMenuPrincipal(VtnMenuPrincipal vtnMenuPrincipal) {
        this.vtnMenuPrincipal = vtnMenuPrincipal;

        vtnMenuPrincipal.getBtnAlumno().addActionListener(this);
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
        }

    }
}
