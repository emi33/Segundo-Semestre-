/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Interface;

import com.PFM.miapp.Model.Persona;

import java.util.List;

/**
 *
 * @author Usuario
 */
public interface IPersonaService {
    
    public List<Persona> getPersonas();
    
    public void savePersona(Persona persona);
    
    public void deletePersona(Long id);
    
    public Persona findPersona(Long id);
    
    public void editPersona(Persona persona);
    

    
    public Long obtenerProximoId();
}
