/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Interface;

import com.PFM.miapp.Model.Habilidad;
import java.util.List;

/**
 *
 * @author Usuario
 */
public interface IHabilidadService {
    public List<Habilidad> getHabilidades();
    
    public void saveHabilidad(Habilidad habilidad);
    
    public void deleteHabilidad(Long id);
    
    public Habilidad findHabilidad(Long id);
    
    public List<Habilidad> findByPersonaId(Long personaId);
    public Habilidad getOne(long id);
    public boolean existsById(Long id);
}
