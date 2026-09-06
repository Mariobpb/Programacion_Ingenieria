package controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import modelo.Calculadora;
import ventana.VentanaPrincipal;

public class Control implements ActionListener {
    
    private VentanaPrincipal vtn = null;
    private Calculadora calc = null;
    
    public Control (VentanaPrincipal vtn){
        this.vtn = vtn;
        calc = new Calculadora();
        
        this.vtn.getBtnAceptar().addActionListener(this);
        this.vtn.getBtnCancelar().addActionListener(this);
        this.vtn.getBtnBuscar().addActionListener(this);
        this.vtn.getBtnEliminar().addActionListener(this);
        this.vtn.getBtnInsertar().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtn.getBtnAceptar()){
            calc.setNum1(Double.parseDouble(vtn.getTxtDato1().getText()));
            calc.setNum2(Double.parseDouble(vtn.getTxtDato2().getText()));
            calc.sumarNumeros();
            System.out.println(calc.getRes());
            vtn.getLblRes().setText(String.valueOf(calc.getRes()));
        }
        else if(e.getSource() == vtn.getBtnCancelar()){
            calc.setNum1(Double.parseDouble(vtn.getTxtDato1().getText()));
            calc.setNum2(Double.parseDouble(vtn.getTxtDato2().getText()));
            calc.restarNumeros();
            vtn.getLblRes().setText(String.valueOf(calc.getRes()));
        }
        else if(e.getSource() == vtn.getBtnBuscar()){
            calc.setNum1(Double.parseDouble(vtn.getTxtDato1().getText()));
            calc.setNum2(Double.parseDouble(vtn.getTxtDato2().getText()));
            calc.multiplicarNumeros();
            vtn.getLblRes().setText(String.valueOf(calc.getRes()));
        }
        else if(e.getSource() == vtn.getBtnEliminar()){
            calc.setNum1(Double.parseDouble(vtn.getTxtDato1().getText()));
            calc.setNum2(Double.parseDouble(vtn.getTxtDato2().getText()));
            calc.dividirNumeros();
            vtn.getLblRes().setText(String.valueOf(calc.getRes()));
        }
        else if(e.getSource() == vtn.getBtnInsertar()){
            System.out.println("Botón insertar presionado");
        }
    }
    
}
