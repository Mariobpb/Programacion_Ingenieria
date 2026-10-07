package controlador;

import vista.VistaMenu;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControladorMenu implements ActionListener {
    private VistaMenu vista = new VistaMenu();

    public ControladorMenu(VistaMenu vista) {
        this.vista = vista;
        this.vista.getMnAbrir().addActionListener(this);
        this.vista.getMnPDF().addActionListener(this);
        this.vista.getMnDOC().addActionListener(this);
        this.vista.getMnSalir().addActionListener(this);
        this.vista.getMnCopiar().addActionListener(this);
        this.vista.getMnCortar().addActionListener(this);
        this.vista.getMnPegar().addActionListener(this);
        this.vista.getMnOscuro().addActionListener(this);
        this.vista.getMnClaro().addActionListener(this);
        this.vista.getMnConfiguracion().addActionListener(this);
        this.vista.getMnActualizar().addActionListener(this);
        this.vista.getMnRestaurar().addActionListener(this);
        this.vista.getMnModificar().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == this.vista.getMnAbrir()) {
            System.out.println("Abrir");
        } else  if (e.getSource() == this.vista.getMnPDF()) {
            System.out.println("PDF");
        } else  if (e.getSource() == this.vista.getMnDOC()) {
            System.out.println("DOC");
        } else  if (e.getSource() == this.vista.getMnSalir()) {
            System.out.println("Salir");
        } else  if (e.getSource() == this.vista.getMnCopiar()) {
            System.out.println("Copiar");
        } else  if (e.getSource() == this.vista.getMnCortar()) {
            System.out.println("Cortar");
        } else  if (e.getSource() == this.vista.getMnPegar()) {
            System.out.println("Pegar");
        } else  if (e.getSource() == this.vista.getMnOscuro()) {
            System.out.println("Modo Oscuro");
        } else  if (e.getSource() == this.vista.getMnClaro()) {
            System.out.println("Modo Claro");
        } else  if (e.getSource() == this.vista.getMnConfiguracion()) {
            System.out.println("Configuracion");
        } else  if (e.getSource() == this.vista.getMnActualizar()) {
            System.out.println("Actualizar");
        } else  if (e.getSource() == this.vista.getMnRestaurar()) {
            System.out.println("Restaurar");
        } else  if (e.getSource() == this.vista.getMnModificar()) {
            System.out.println("Modificar");
        }
    }
}
