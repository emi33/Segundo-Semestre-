/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Service;

import com.PFM.miapp.Interface.IPersonaService;
import com.PFM.miapp.Model.Persona;
import com.PFM.miapp.Repository.PersonaRepository;
import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import jakarta.persistence.Query;
import java.math.BigDecimal;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 *
 * @author Usuario
 */
@Service
public class PersonaService implements IPersonaService {
    
    @PersistenceContext
    private EntityManager entityManager;

    @Autowired
    private PersonaRepository personaRepository;

    @Override
    public List<Persona> getPersonas() {
        List<Persona> listaPersonas = personaRepository.findAll();
        return listaPersonas;
    }

    @Override
    public void savePersona(Persona persona) {
        personaRepository.save(persona);
    }

    @Override
    public void deletePersona(Long id) {
        personaRepository.deleteById(id);
    }

    @Override
    public Persona findPersona(Long id) {
        Persona persona = personaRepository.findById(id).orElse(null);
        return persona;
    }

    @Override
    public void editPersona(Persona persona) {
        personaRepository.save(persona);
    }

    @Override
    public Long obtenerProximoId() {
        Query query = entityManager.createNativeQuery("SELECT PERSONA_GENERATOR.NEXTVAL FROM DUAL");
        return ((BigDecimal) query.getSingleResult()).longValue();
    }
    
    

}
