/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Interface;

import com.PFM.miapp.Model.Contacto;
import java.util.List;

/**
 *
 * @author Usuario
 */
public interface IContactoService {
    
      public List<Contacto> getContactos();
    
    public void saveContacto(Contacto contacto);
    
    public void deleteContacto(Long id);
    
    public Contacto findContacto(Long id);
    
    public List<Contacto> findByPersonaId(Long personaId);
    
    public Contacto getOne(long id);
    
    public boolean existsById(Long id);
}
