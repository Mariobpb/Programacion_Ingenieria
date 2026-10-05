package com.metodos.modelo;

import net.objecthunter.exp4j.Expression;
import net.objecthunter.exp4j.ExpressionBuilder;
import net.objecthunter.exp4j.ValidationResult;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class Funcion {
    private String funcionTexto;
    private Expression expresion;

    public Funcion(String funcionTexto) throws IllegalArgumentException {
        if (funcionTexto == null || funcionTexto.trim().isEmpty()) {
            throw new IllegalArgumentException("ERROR: La función no puede estar vacía.");
        }
        this.funcionTexto = funcionTexto.trim();
        try {
            this.expresion = new ExpressionBuilder(this.funcionTexto)
                    .variable("x")
                    .build();
        } catch (Exception e) {
            throw new IllegalArgumentException("ERROR: " + e.getMessage());
        }
    }

    public double evaluar(double x) {
        double valorEvaluado = expresion.setVariable("x", x).evaluate();
        return valorEvaluado;
    }

    public double evaluarDerivada(double x) {
        double h = 1e-6;
        double valorDerivada = (evaluar(x + h) - evaluar(x - h)) / (2 * h);
        return valorDerivada;
    }

    public String getFuncionTexto() {
        return funcionTexto;
    }
}