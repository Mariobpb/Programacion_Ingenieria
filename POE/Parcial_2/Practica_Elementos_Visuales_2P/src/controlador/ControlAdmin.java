package controlador;

import modelo.*;
import vista.PanelGestionEmpleados;
import vista.VistaAgregarEmpleado;
import vista.VistaPrincipal;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class ControlAdmin implements ActionListener {
    private VistaPrincipal vistaPrincipal;
    private VistaAgregarEmpleado ventanaAgregar;

    public ControlAdmin(VistaPrincipal vistaPrincipal) {
        this.vistaPrincipal = vistaPrincipal;

        PanelGestionEmpleados panel = this.vistaPrincipal.getPanelEmpleados();
        panel.getBtnBuscar().addActionListener(this);
        panel.getCmbFiltroTipo().addActionListener(this);
        panel.getItemCerrarSesion().addActionListener(this);
        panel.getItemAgregar().addActionListener(this);

        cargarTablaEmpleados("", "Todos");
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        PanelGestionEmpleados panel = vistaPrincipal.getPanelEmpleados();

        if (e.getSource() == panel.getItemAgregar()) {
            abrirFormularioAgregar();
            return;
        }

        if (e.getSource() == panel.getItemCerrarSesion()) {
            cerrarSesion();
            return;
        }

        if (e.getSource() == panel.getBtnBuscar() || e.getSource() == panel.getCmbFiltroTipo()) {
            String textoNombre = panel.getTxtBuscarNombre().getText().trim().toLowerCase();
            String filtroTipo = (String) panel.getCmbFiltroTipo().getSelectedItem();
            cargarTablaEmpleados(textoNombre, filtroTipo);
            return;
        }

        if (ventanaAgregar != null && e.getSource() == ventanaAgregar.getBtnGuardar()) {
            guardarNuevoEmpleado();
        } else if (ventanaAgregar != null && e.getSource() == ventanaAgregar.getBtnCancelar()) {
            ventanaAgregar.dispose();
        }
    }

    private void abrirFormularioAgregar() {
        ventanaAgregar = new VistaAgregarEmpleado(vistaPrincipal);
        ventanaAgregar.getBtnGuardar().addActionListener(this);
        ventanaAgregar.getBtnCancelar().addActionListener(this);
        ventanaAgregar.mostrarVentana();
    }

    private void guardarNuevoEmpleado() {
        try {
            String rol = (String) ventanaAgregar.getCmbRol().getSelectedItem();
            String nombre = ventanaAgregar.getTxtNombre().getText().trim();
            int edad = (int) ventanaAgregar.getSpnEdad().getValue();
            long telefono = Long.parseLong(ventanaAgregar.getTxtTelefono().getText().trim());
            String domicilio = ventanaAgregar.getTxtDomicilio().getText().trim();
            double salario = Double.parseDouble(ventanaAgregar.getTxtSalario().getText().trim());
            String fotoDefault = "/imagenes/default_foto.png";

            String turno = ventanaAgregar.getRbtMatutino().isSelected() ? "Matutino" : "Vespertino";

            if (nombre.isEmpty()) {
                JOptionPane.showMessageDialog(ventanaAgregar, "El nombre es obligatorio.", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            if ("DOCTOR".equalsIgnoreCase(rol)) {
                boolean tieneTitulo = ventanaAgregar.getChkCedula().isSelected();
                String especialidad = ventanaAgregar.getTxtEspecialidad().getText().trim();

                if (especialidad.isEmpty()) {
                    JOptionPane.showMessageDialog(ventanaAgregar, "La especialidad es requerida para el Doctor.", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }

                Doctor nuevoDoc = new Doctor(nombre, edad, telefono, fotoDefault, domicilio, salario, turno, tieneTitulo, especialidad);
                Clinica.doctores.add(nuevoDoc);
            } else if ("RECEPCIONISTA".equalsIgnoreCase(rol)) {
                String user = ventanaAgregar.getTxtUsuario().getText().trim();
                String pass = new String(ventanaAgregar.getTxtPassword().getPassword());

                if (user.isEmpty() || pass.isEmpty()) {
                    JOptionPane.showMessageDialog(ventanaAgregar, "El usuario y la contraseña son obligatorios.", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }

                Recepcionista nuevaRec = new Recepcionista(nombre, edad, telefono, fotoDefault, domicilio, salario, turno, user, pass);
                Clinica.usuarios.add(nuevaRec);
            } else if ("ADMINISTRADOR".equalsIgnoreCase(rol)) {
                String user = ventanaAgregar.getTxtUsuario().getText().trim();
                String pass = new String(ventanaAgregar.getTxtPassword().getPassword());

                if (user.isEmpty() || pass.isEmpty()) {
                    JOptionPane.showMessageDialog(ventanaAgregar, "El usuario y la contraseña son obligatorios.", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }

                Administrador nuevoAdmin = new Administrador(nombre, edad, telefono, fotoDefault, domicilio, salario, turno, user, pass);
                Clinica.usuarios.add(nuevoAdmin);
            }

            JOptionPane.showMessageDialog(ventanaAgregar, "Empleado agregado exitosamente.", "Éxito", JOptionPane.INFORMATION_MESSAGE);
            ventanaAgregar.dispose();

            cargarTablaEmpleados("", "Todos");

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(ventanaAgregar, "Por favor verifica que teléfono y salario contengan valores numéricos válidos.", "Error de Formato", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void cargarTablaEmpleados(String filtroNombre, String filtroTipo) {
        DefaultTableModel modeloTabla = vistaPrincipal.getPanelEmpleados().getModeloTabla();
        modeloTabla.setRowCount(0);

        List<Empleado> listaGeneral = obtenerListaUnificada();

        for (Empleado emp : listaGeneral) {
            String rolOEmpleado = obtenerRolEmpleado(emp);

            boolean coincideTipo = filtroTipo.equalsIgnoreCase("Todos") || rolOEmpleado.equalsIgnoreCase(filtroTipo);
            boolean coincideNombre = filtroNombre.isEmpty() || emp.getNombre().toLowerCase().contains(filtroNombre);

            if (coincideTipo && coincideNombre) {
                String tieneTitulo = "N/A";
                String especialidad = "N/A";

                if (emp instanceof Doctor) {
                    Doctor doc = (Doctor) emp;
                    tieneTitulo = doc.isTitulo() ? "Sí" : "No";
                    especialidad = doc.getEspecialidad();
                }

                Object[] fila = new Object[]{
                        emp.getNombre(),
                        emp.getEdad(),
                        emp.getTelefono(),
                        rolOEmpleado,
                        emp.getTurno() != null ? emp.getTurno() : "N/A",
                        "$" + emp.getSalarioBase(),
                        tieneTitulo,
                        especialidad
                };
                modeloTabla.addRow(fila);
            }
        }
    }

    private List<Empleado> obtenerListaUnificada() {
        List<Empleado> todos = new ArrayList<>();
        if (Clinica.usuarios != null) todos.addAll(Clinica.usuarios);
        if (Clinica.doctores != null) {
            for (Doctor doc : Clinica.doctores) {
                if (!todos.contains(doc)) todos.add(doc);
            }
        }
        return todos;
    }

    private String obtenerRolEmpleado(Empleado emp) {
        if (emp instanceof Usuario) {
            return ((Usuario) emp).getRol();
        } else if (emp instanceof Doctor) {
            return "DOCTOR";
        }
        return "Empleado";
    }

    private void cerrarSesion() {
        if (vistaPrincipal.getPanelEmpleados() != null) {
            vistaPrincipal.getVtnLogin().getTxtUsuario().setText("");
            vistaPrincipal.getVtnLogin().getTxtContrasena().setText("");
            vistaPrincipal.getVtnLogin().getLblMensaje().setText("");
            vistaPrincipal.getVtnLogin().setVisible(true);
        }
        vistaPrincipal.dispose();
    }
}