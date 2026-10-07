package controlador;

import vista.VistaMenu;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControladorMenu implements ActionListener {
    private VistaMenu vtn = null;

    public ControladorMenu(VistaMenu vtn) {
        this.vtn = vtn;

        this.vtn.getMnAbrir().addActionListener(this);
        this.vtn.getMnSalir().addActionListener(this);
        this.vtn.getMnPdf().addActionListener(this);
        this.vtn.getMnDoc().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtn.getMnAbrir()) {
            System.out.println("Opcion Abrir");
        } else if(e.getSource() == vtn.getMnSalir()) {
            System.out.println("Opcion Salir");
            System.exit(0);
        } else if(e.getSource() == vtn.getMnPdf()) {
            System.out.println("Opcion PDF");
        } else if(e.getSource() == vtn.getMnDoc()) {
            System.out.println("Opcion DOC");
        }
    }
}
