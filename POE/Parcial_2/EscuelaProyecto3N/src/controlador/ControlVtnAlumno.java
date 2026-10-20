package controlador;

import modelo.Alumno;
import vista.VtnAlumno;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class ControlVtnAlumno implements ActionListener, WindowListener {
    private VtnAlumno vtnAlumno = null;
    private Alumno alumno = null;

    public ControlVtnAlumno(VtnAlumno vtnAlumno) {
        this.vtnAlumno = vtnAlumno;

        this.vtnAlumno.getBtnRegresar().addActionListener(this);
        this.vtnAlumno.getBtnBuscar().addActionListener(this);
        this.vtnAlumno.getBtnGuardar().addActionListener(this);
        this.vtnAlumno.getVtn().addWindowListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vtnAlumno.getBtnRegresar()) {
            vtnAlumno.getVtn().setVisible(false);
            vtnAlumno.getVtnMenuPrincipal().getVtn().setVisible(true);
        } else if (e.getSource() == vtnAlumno.getBtnGuardar()){
            String nombre = vtnAlumno.getTxtNombre().getText();
            int edad = Integer.parseInt(vtnAlumno.getTxtEdad().getText());
            String email = vtnAlumno.getTxtEmail().getText();
            String codigo = vtnAlumno.getTxtCodigo().getText();
            String carrera = vtnAlumno.getTxtCarrera().getText();

            alumno = new Alumno(nombre, edad, email, codigo, carrera);

        } else if (e.getSource() == vtnAlumno.getBtnBuscar()) {
            System.out.println("Codigo: "+vtnAlumno.getTxtBuscar().getText());

            if (alumno != null && vtnAlumno.getTxtBuscar().getText().equals(alumno.getCodigo())) {
                vtnAlumno.getTxtResultado().setText(alumno.mostrarInfo());
            } else {
                vtnAlumno.getTxtResultado().setText("Alumno no encontrado");
            }
        }
    }

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        vtnAlumno.getVtnMenuPrincipal().getVtn().setVisible(true);
    }

    @Override
    public void windowClosed(WindowEvent e) {

    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }
}
