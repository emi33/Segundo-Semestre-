/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Interface;

import com.PFM.miapp.Model.Educacion;
import java.util.List;

/**
 *
 * @author Usuario
 */
public interface IEducacionService {
    public List<Educacion> getEstudios();
    
    public void saveEducacion(Educacion educacion);
    
    public void deleteEducacion(Long id);
    
    public Educacion findEducacion(Long id);
    
    public List<Educacion> findByPersonaId(Long personaId);
    public Educacion getOne(long id);
       public boolean existsById(Long id);
      
}
