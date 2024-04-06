/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Interface;

import com.PFM.miapp.Model.Experiencia;
import java.util.List;

/**
 *
 * @author Usuario
 */
public interface IExperienciaService {
    
    public List<Experiencia> getExperiencias();
    
    public void saveExperiencia(Experiencia experiencia);
    
    public void deleteExperiencia(Long id);
    
    public Experiencia findExperiencia(Long id);
    
    public List<Experiencia> findByPersonaId(Long personaId);
    public Experiencia getOne(long id);
  
}

