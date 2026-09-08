package controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;
import modelo.CuentaBanco;
import vista.VentanaCuentaBanco;

public class ControladorCuentaBanco implements ActionListener {

    private CuentaBanco objCuentaBanco;
    private VentanaCuentaBanco vista;

    public ControladorCuentaBanco(CuentaBanco objCuentaBanco, VentanaCuentaBanco vista) {
        this.objCuentaBanco = objCuentaBanco;
        this.vista = vista;

        this.vista.getBtnMenuCrear().addActionListener(this);
        this.vista.getBtnMenuImprimir().addActionListener(this);
        this.vista.getBtnMenuAbonar().addActionListener(this);
        this.vista.getBtnMenuRetirar().addActionListener(this);
        this.vista.getBtnMenuSalir().addActionListener(this);
        this.vista.getBtnGuardarCuenta().addActionListener(this);
        this.vista.getBtnConfirmarAbono().addActionListener(this);
        this.vista.getBtnConfirmarRetiro().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vista.getBtnMenuCrear()) {
            vista.mostrarTarjeta("CARD_CREAR");
        } else if (e.getSource() == vista.getBtnMenuImprimir()) {
            vista.mostrarTarjeta("CARD_IMPRIMIR");
            vista.getTxtInfo().setText(objCuentaBanco.imprimirDatos());
        } else if (e.getSource() == vista.getBtnMenuAbonar()) {
            vista.mostrarTarjeta("CARD_ABONAR");
        } else if (e.getSource() == vista.getBtnMenuRetirar()) {
            vista.mostrarTarjeta("CARD_RETIRAR");
        } else if (e.getSource() == vista.getBtnMenuSalir()) {
            System.exit(0);
        } else if (e.getSource() == vista.getBtnGuardarCuenta()) {
            objCuentaBanco.setNombreC(vista.getTxtNombreC().getText());
            objCuentaBanco.setNumeroC(vista.getTxtNumeroC().getText());
            objCuentaBanco.setSaldoC(Double.parseDouble(vista.getTxtSaldoInicial().getText()));
            JOptionPane.showMessageDialog(null, "Cuenta creada");
        } else if (e.getSource() == vista.getBtnConfirmarAbono()) {
            double monto = Double.parseDouble(vista.getTxtAbonar().getText());
            objCuentaBanco.abonarCuenta(monto);
            JOptionPane.showMessageDialog(null, "Monto abonado\nSaldo actual: " + objCuentaBanco.getSaldoC() + "$");
        } else if (e.getSource() == vista.getBtnConfirmarRetiro()) {
            double monto = Double.parseDouble(vista.getTxtRetirar().getText());
            if (objCuentaBanco.retirarCuenta(monto)){
                JOptionPane.showMessageDialog(null, "Monto retirado\nSaldo actual: " + objCuentaBanco.getSaldoC() + "$");
            } else {
                JOptionPane.showMessageDialog(null, "Error:\nEl monto a retirar es insuficiente");
            }
        }
    }
}