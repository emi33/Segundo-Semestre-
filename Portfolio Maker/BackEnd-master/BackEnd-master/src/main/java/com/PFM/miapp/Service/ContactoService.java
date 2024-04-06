/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Service;

import com.PFM.miapp.Interface.IContactoService;
import com.PFM.miapp.Model.Contacto;
import com.PFM.miapp.Repository.ContactoRepository;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 *
 * @author Usuario
 */
@Service
public class ContactoService implements IContactoService{

    @Autowired
    private ContactoRepository contactoRepository;
    
    @Override
    public List<Contacto> getContactos() {
        List<Contacto> listaContacto = contactoRepository.findAll();
        return listaContacto;
    }

    @Override
    public void saveContacto(Contacto contacto) {
          contactoRepository.save(contacto);
    }

    @Override
    public void deleteContacto(Long id) {
        contactoRepository.deleteById(id);
    }

    @Override
    public Contacto findContacto(Long id) {
Contacto contacto = contactoRepository.findById(id).orElse(null);
        return contacto;
    }

    @Override
    public List<Contacto> findByPersonaId(Long personaId) {
      return contactoRepository.findByPersonaId(personaId);
    }

    @Override
    public Contacto getOne(long id) {
 Contacto contacto = contactoRepository.findById(id).orElse(null);
        return contacto;
    }

    @Override
    public boolean existsById(Long id) {
return contactoRepository.existsById(id);
    }
}
