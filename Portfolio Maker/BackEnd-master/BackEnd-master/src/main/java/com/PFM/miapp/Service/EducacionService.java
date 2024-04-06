/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Service;

import com.PFM.miapp.Interface.IEducacionService;
import com.PFM.miapp.Model.Educacion;
import com.PFM.miapp.Repository.EducacionRepository;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 *
 * @author Usuario
 */
@Service
public class EducacionService implements IEducacionService{
    
    @Autowired
    private EducacionRepository educacionRepository;

    @Override
    public List<Educacion> getEstudios() {
         List<Educacion> listaEducacion = educacionRepository.findAll();
        return listaEducacion;
    }

    @Override
    public void saveEducacion(Educacion educacion) {
         educacionRepository.save(educacion);
    }

    @Override
    public void deleteEducacion(Long id) {
        educacionRepository.deleteById(id);
    }

    @Override
    public Educacion findEducacion(Long id) {
        Educacion educacion = educacionRepository.findById(id).orElse(null);
        return educacion;
    }

    @Override
    public List<Educacion> findByPersonaId(Long personaId) {
        return educacionRepository.findByPersonaId(personaId);
    }
   

    @Override
    public Educacion getOne(long id) {
         Educacion edu = educacionRepository.findById(id).orElse(null);
        return edu;
    }

    @Override
    public boolean existsById(Long id) {
        return educacionRepository.existsById(id);
    }

 
   
    
   
}
