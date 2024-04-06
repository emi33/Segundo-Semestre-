/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Model;

import com.fasterxml.jackson.annotation.JsonIgnore;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.Table;
import org.hibernate.annotations.OnDelete;
import org.hibernate.annotations.OnDeleteAction;

/**
 *
 * @author Usuario
 */
@Entity
@Table(name = "educacion")
public class Educacion {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "educacion_generator")
    private Long id;
    @Column(name = "institucion")
    private String institucion;
    @Column(name = "titulo")
    private String titulo;
    @Column(name = "fechainicio")
    private int fechainicio;
    @Column(name = "fechafin")
    private int fechafin;

    @ManyToOne(fetch = FetchType.LAZY, optional = false)
    @JoinColumn(name = "personaid", nullable = false, insertable=false, updatable=false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    @JsonIgnore
    private Persona persona;

    private Long personaid;
    
    public Educacion() {
    }

    public Educacion(String institucion, String titulo, int fechainicio, int fechafin, Persona persona) {
        this.institucion = institucion;
        this.titulo = titulo;
        this.fechainicio = fechainicio;
        this.fechafin = fechafin;
        this.persona = persona;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getInstitucion() {
        return institucion;
    }

    public void setInstitucion(String institucion) {
        this.institucion = institucion;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getFechainicio() {
        return fechainicio;
    }

    public void setFechainicio(int fechainicio) {
        this.fechainicio = fechainicio;
    }

    public int getFechafin() {
        return fechafin;
    }

    public void setFechafin(int fechafin) {
        this.fechafin = fechafin;
    }

    public Persona getPersona() {
        return persona;
    }

    public void setPersona(Persona persona) {
        this.persona = persona;
    }

    public Long getPersonaid() {
        return personaid;
    }

    public void setPersonaid(Long personaid) {
        this.personaid = personaid;
    }
    

   

    

    
    
    
}
