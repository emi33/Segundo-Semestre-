/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Service;

import com.PFM.miapp.Interface.IHabilidadService;
import com.PFM.miapp.Model.Habilidad;
import com.PFM.miapp.Repository.HabilidadRepository;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 *
 * @author Usuario
 */
@Service
public class HabilidadService implements IHabilidadService{
    
    @Autowired
    private HabilidadRepository habilidadRepository;

    @Override
    public List<Habilidad> getHabilidades() {
         List<Habilidad> listaHabilidad = habilidadRepository.findAll();
        return listaHabilidad;
    } 

    @Override
    public void saveHabilidad(Habilidad habilidad) {
         habilidadRepository.save(habilidad);
    }

    @Override
    public void deleteHabilidad(Long id) {
        habilidadRepository.deleteById(id);
    }

    @Override
    public Habilidad findHabilidad(Long id) {
        Habilidad habilidad = habilidadRepository.findById(id).orElse(null);
        return habilidad;
    }

    @Override
    public List<Habilidad> findByPersonaId(Long personaId) {
        return habilidadRepository.findByPersonaId(personaId);
    }
   

    @Override
    public Habilidad getOne(long id) {
         Habilidad habilidad = habilidadRepository.findById(id).orElse(null);
        return habilidad;
    }

    @Override
    public boolean existsById(Long id) {
        return habilidadRepository.existsById(id);
    }
    
   
}

