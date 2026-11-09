package controlador;

import modelo.Docente;
import modelo.Escuela;
import vista.VtnDocente;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class ControlVtnDocente implements ActionListener, WindowListener {
    private VtnDocente vtnDocente = null;
    private boolean accesoEvaluar = false;

    public ControlVtnDocente(VtnDocente vtnDocente) {
        this.vtnDocente = vtnDocente;

        this.vtnDocente.getBtnRegresar().addActionListener(this);
        this.vtnDocente.getBtnGuardar().addActionListener(this);
        this.vtnDocente.getBtnBuscar().addActionListener(this);
        this.vtnDocente.getBtnBuscarAlumno().addActionListener(this);
        this.vtnDocente.getBtnEvaluarAlumno().addActionListener(this);
        this.vtnDocente.getVtn().addWindowListener(this);

        this.vtnDocente.getBtnEvaluarAlumno().setBackground(Color.RED);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vtnDocente.getBtnRegresar()) {
            vtnDocente.getVtn().setVisible(false);
            vtnDocente.getVtnMenuPrincipal().getVtn().setVisible(true);
        } else if (e.getSource() == vtnDocente.getBtnGuardar()) {
            String nombre = vtnDocente.getTxtNombre().getText();
            int edad = Integer.parseInt(vtnDocente.getTxtEdad().getText());
            String email = vtnDocente.getTxtEmail().getText();
            String codigo = vtnDocente.getTxtCodigo().getText();
            int cantHoras = Integer.parseInt(vtnDocente.getTxtHorasTrabajadas().getText());
            int pagoHoras = Integer.parseInt(vtnDocente.getTxtPagoHora().getText());

            Escuela.docente = new Docente(nombre, edad, email, codigo, cantHoras, pagoHoras);
            System.out.println("Docente registrado: "+ Escuela.docente.mostrarInfo());
        } else if (e.getSource() == vtnDocente.getBtnBuscar()) {
            System.out.println("Codigo: "+vtnDocente.getTxtBuscar().getText());

            if (Escuela.docente != null && vtnDocente.getTxtBuscar().getText().equals(Escuela.docente.getCodigo())) {
                vtnDocente.getTxtResultado().setText(Escuela.docente.mostrarInfo());
            } else {
                vtnDocente.getTxtResultado().setText("Docente no encontrado");
            }
        } else if (e.getSource() == vtnDocente.getBtnBuscarAlumno()) {
            System.out.println("Codigos: " + Escuela.alumno.getCodigo() + " | " + vtnDocente.getTxtCodigoAlumno().getText());
            if (vtnDocente.getTxtCodigoAlumno().getText().equals(Escuela.alumno.getCodigo())){
                this.vtnDocente.getBtnEvaluarAlumno().setBackground(Color.GREEN);
                this.vtnDocente.getTxtMatematicas().setText(String.valueOf(Escuela.alumno.getCalMate()));
                this.vtnDocente.getTxtFisica().setText(String.valueOf(Escuela.alumno.getCalFisica()));
                this.vtnDocente.getTxtProgramacion().setText(String.valueOf(Escuela.alumno.getCalProgra()));
                accesoEvaluar = true;
            } else {
                this.vtnDocente.getTxtMatematicas().setText("");
                this.vtnDocente.getTxtFisica().setText("");
                this.vtnDocente.getTxtProgramacion().setText("");
                this.vtnDocente.getBtnEvaluarAlumno().setBackground(Color.RED);
                accesoEvaluar = false;
            }
        } else if (e.getSource() == vtnDocente.getBtnEvaluarAlumno()) {
            if (accesoEvaluar) {
                double calMate = Double.parseDouble(vtnDocente.getTxtMatematicas().getText());
                double calFisica = Double.parseDouble(vtnDocente.getTxtFisica().getText());
                double calProgra = Double.parseDouble(vtnDocente.getTxtProgramacion().getText());

                Escuela.docente.evaluarAlumno(Escuela.alumno, calMate, calFisica, calProgra);
            }
        }
    }

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        vtnDocente.getVtnMenuPrincipal().getVtn().setVisible(true);
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
