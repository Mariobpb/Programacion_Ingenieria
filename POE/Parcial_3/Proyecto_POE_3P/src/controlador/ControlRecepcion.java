package controlador;

import modelo.Cita;
import modelo.Clinica;
import modelo.Doctor;
import modelo.Paciente;
import vista.PanelGestionCitas;
import vista.VistaPrincipal;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class ControlRecepcion implements ActionListener {
    private VistaPrincipal vistaPrincipal;
    private PanelGestionCitas vistaCitas;

    public ControlRecepcion(VistaPrincipal vistaPrincipal) {
        this.vistaPrincipal = vistaPrincipal;
        this.vistaCitas = vistaPrincipal.getPanelCitas();

        this.vistaCitas.getItemCerrarSesion().addActionListener(this);
        this.vistaCitas.getBtnGuardarPaciente().addActionListener(this);
        this.vistaCitas.getBtnLimpiarPaciente().addActionListener(this);
        this.vistaCitas.getBtnAgendar().addActionListener(this);
        this.vistaCitas.getBtnLimpiarFormulario().addActionListener(this);
        this.vistaCitas.getBtnBuscarCitas().addActionListener(this);

        inicializarDatos();
    }

    private void inicializarDatos() {
        actualizarCombosYListas();
        cargarTablaCitas("");
    }

    private void actualizarCombosYListas() {
        DefaultListModel<String> modelPacientes = vistaCitas.getModeloListaPacientes();
        modelPacientes.clear();
        if (Clinica.pacientes != null) {
            for (Paciente p : Clinica.pacientes) {
                modelPacientes.addElement(p.getNombre());
            }
        }

        DefaultListModel<String> modelDoctores = vistaCitas.getModeloListaDoctores();
        modelDoctores.clear();
        if (Clinica.doctores != null) {
            for (Doctor d : Clinica.doctores) {
                modelDoctores.addElement(d.getNombre() + " (" + d.getEspecialidad() + ")");
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vistaCitas.getItemCerrarSesion()) {
            cerrarSesion();
            return;
        }

        if (e.getSource() == vistaCitas.getBtnGuardarPaciente()) {
            guardarPaciente();
            return;
        }

        if (e.getSource() == vistaCitas.getBtnLimpiarPaciente()) {
            limpiarCamposPaciente();
            return;
        }

        if (e.getSource() == vistaCitas.getBtnAgendar()) {
            agendarCita();
            return;
        }

        if (e.getSource() == vistaCitas.getBtnLimpiarFormulario()) {
            limpiarCamposCita();
            return;
        }

        if (e.getSource() == vistaCitas.getBtnBuscarCitas()) {
            String filtro = vistaCitas.getTxtBuscarPaciente().getText().trim().toLowerCase();
            cargarTablaCitas(filtro);
        }
    }

    private void guardarPaciente() {
        String nombre = vistaCitas.getTxtNombrePaciente().getText().trim();
        int edad = (int) vistaCitas.getSpnEdadPaciente().getValue();
        String telText = vistaCitas.getTxtTelefonoPaciente().getText().trim();
        String restricciones = vistaCitas.getTxtRestriccionesPaciente().getText().trim();

        if (nombre.isEmpty()) {
            JOptionPane.showMessageDialog(vistaCitas, "El nombre del paciente es obligatorio.", "Atención", JOptionPane.WARNING_MESSAGE);
            return;
        }

        long telefono = -1;
        if (!telText.isEmpty()) {
            try {
                telefono = Long.parseLong(telText);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(vistaCitas, "Formato de teléfono no válido.", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
        }

        Paciente nuevoPaciente = new Paciente(nombre, edad, telefono, restricciones);
        Clinica.pacientes.add(nuevoPaciente);

        JOptionPane.showMessageDialog(vistaCitas, "Paciente registrado correctamente.", "Éxito", JOptionPane.INFORMATION_MESSAGE);
        limpiarCamposPaciente();
        actualizarCombosYListas();
    }

    private void agendarCita() {
        if (Clinica.pacientes == null || Clinica.pacientes.isEmpty()) {
            JOptionPane.showMessageDialog(vistaCitas, "No hay pacientes registrados. Registre uno primero.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        int idxPaciente = vistaCitas.getLstPacientes().getSelectedIndex();
        int idxDoctor = vistaCitas.getLstDoctores().getSelectedIndex();

        if (idxPaciente < 0) {
            JOptionPane.showMessageDialog(vistaCitas, "Debes seleccionar un paciente de la lista (JList).", "Atención", JOptionPane.WARNING_MESSAGE);
            return;
        }

        if (idxDoctor < 0) {
            JOptionPane.showMessageDialog(vistaCitas, "Debes seleccionar un doctor de la lista (JList).", "Atención", JOptionPane.WARNING_MESSAGE);
            return;
        }

        Paciente paciente = Clinica.pacientes.get(idxPaciente);
        Doctor doctor = Clinica.doctores.get(idxDoctor);

        int dia = (int) vistaCitas.getSpnDia().getValue();
        String mesNombre = (String) vistaCitas.getSpnMes().getValue();
        int ano = (int) vistaCitas.getSpnAno().getValue();
        String horaStr = (String) vistaCitas.getSpnHora().getValue();

        Date fechaCalculada = construirFecha(dia, mesNombre, ano, horaStr);

        String tipoCita = (String) vistaCitas.getCmbTipoCita().getSelectedItem();
        String sintomas = vistaCitas.getTxtSintomas().getText().trim();
        boolean requiereFactura = vistaCitas.getChkFactura().isSelected();
        int costo = (int) vistaCitas.getSpnCosto().getValue();

        Cita nuevaCita = new Cita(doctor, paciente, fechaCalculada, tipoCita);
        if (!sintomas.isEmpty()) {
            nuevaCita.setSintomas(sintomas);
        }
        nuevaCita.setRequiereFactura(requiereFactura);
        nuevaCita.setCosto(costo);

        Clinica.citas.add(nuevaCita);

        JOptionPane.showMessageDialog(vistaCitas, "Cita agendada correctamente.", "Éxito", JOptionPane.INFORMATION_MESSAGE);
        limpiarCamposCita();
        cargarTablaCitas("");

        vistaCitas.getTabbedPane().setSelectedIndex(0);
    }

    private Date construirFecha(int dia, String mesNombre, int ano, String horaStr) {
        int mesNum = 0;
        String[] meses = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
        for (int i = 0; i < meses.length; i++) {
            if (meses[i].equalsIgnoreCase(mesNombre)) {
                mesNum = i;
                break;
            }
        }

        int horaNum = 8;
        if (horaStr.contains("08:00 AM")) horaNum = 8;
        else if (horaStr.contains("09:00 AM")) horaNum = 9;
        else if (horaStr.contains("10:00 AM")) horaNum = 10;
        else if (horaStr.contains("11:00 AM")) horaNum = 11;
        else if (horaStr.contains("12:00 PM")) horaNum = 12;
        else if (horaStr.contains("01:00 PM")) horaNum = 13;
        else if (horaStr.contains("02:00 PM")) horaNum = 14;
        else if (horaStr.contains("03:00 PM")) horaNum = 15;
        else if (horaStr.contains("04:00 PM")) horaNum = 16;
        else if (horaStr.contains("05:00 PM")) horaNum = 17;
        else if (horaStr.contains("06:00 PM")) horaNum = 18;
        else if (horaStr.contains("07:00 PM")) horaNum = 19;

        Calendar cal = Calendar.getInstance();
        cal.set(Calendar.YEAR, ano);
        cal.set(Calendar.MONTH, mesNum);
        cal.set(Calendar.DAY_OF_MONTH, dia);
        cal.set(Calendar.HOUR_OF_DAY, horaNum);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);

        return cal.getTime();
    }

    private void cargarTablaCitas(String filtroPaciente) {
        DefaultTableModel modelo = vistaCitas.getModeloTablaCitas();
        modelo.setRowCount(0);

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy hh:mm a");

        if (Clinica.citas != null) {
            for (Cita c : Clinica.citas) {
                boolean coincide = filtroPaciente.isEmpty() || c.getPaciente().getNombre().toLowerCase().contains(filtroPaciente);
                if (coincide) {
                    Object[] fila = new Object[]{
                            c.getPaciente().getNombre(),
                            c.getDoctor().getNombre(),
                            c.getFecha() != null ? sdf.format(c.getFecha()) : "N/A",
                            c.getTipoCita(),
                            c.getSintomas(),
                            "$" + c.getCosto(),
                            c.isRequiereFactura() ? "Sí" : "No"
                    };
                    modelo.addRow(fila);
                }
            }
        }
    }

    private void limpiarCamposPaciente() {
        vistaCitas.getTxtNombrePaciente().setText("");
        vistaCitas.getSpnEdadPaciente().setValue(18);
        vistaCitas.getTxtTelefonoPaciente().setText("");
        vistaCitas.getTxtRestriccionesPaciente().setText("");
    }

    private void limpiarCamposCita() {
        vistaCitas.getSpnDia().setValue(20);
        vistaCitas.getSpnMes().setValue("Octubre");
        vistaCitas.getSpnAno().setValue(2026);
        vistaCitas.getSpnHora().setValue("08:00 AM");
        vistaCitas.getTxtSintomas().setText("");
        vistaCitas.getChkFactura().setSelected(false);
        vistaCitas.getSpnCosto().setValue(500);
        vistaCitas.getLstPacientes().clearSelection();
        vistaCitas.getLstDoctores().clearSelection();
    }

    private void cerrarSesion() {
        vistaPrincipal.getVtnLogin().getTxtUsuario().setText("");
        vistaPrincipal.getVtnLogin().getTxtContrasena().setText("");
        vistaPrincipal.getVtnLogin().getLblMensaje().setText("");
        vistaPrincipal.getVtnLogin().setVisible(true);
        vistaPrincipal.dispose();
    }
}