/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Interface;

import com.PFM.miapp.Model.Proyecto;
import java.util.List;

/**
 *
 * @author Usuario
 */
public interface IProyectoService {
    
    public List<Proyecto> getProyectos();
    
    public void saveProyecto(Proyecto proyecto);
    
    public void deleteProyecto(Long id);
    
    public Proyecto findProyecto(Long id);
    
    public List<Proyecto> findByPersonaId(Long personaId);
    
    public Proyecto getOne(long id);
    
    public boolean existsById(Long id);
}
