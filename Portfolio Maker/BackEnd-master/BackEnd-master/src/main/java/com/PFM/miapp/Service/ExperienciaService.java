/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Service;

import com.PFM.miapp.Interface.IExperienciaService;
import com.PFM.miapp.Model.Experiencia;
import com.PFM.miapp.Repository.ExperienciaRepository;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 *
 * @author Usuario
 */
@Service
public class ExperienciaService implements IExperienciaService {

    @Autowired
    private ExperienciaRepository experienciaRepository;

    @Override
    public List<Experiencia> getExperiencias() {
        List<Experiencia> listaExperiencia = experienciaRepository.findAll();
        return listaExperiencia;
    }

    @Override
    public void saveExperiencia(Experiencia experiencia) {
        experienciaRepository.save(experiencia);
    }

    @Override
    public void deleteExperiencia(Long id) {
        experienciaRepository.deleteById(id);
    }

    @Override
    public Experiencia findExperiencia(Long id) {
        Experiencia experiencia = experienciaRepository.findById(id).orElse(null);
        return experiencia;
    }

    public List<Experiencia> findByPersonaId(Long personaId) {
        return experienciaRepository.findByPersonaId(personaId);
    }

    public Experiencia getOne(long id) {
        Experiencia expe = experienciaRepository.findById(id).orElse(null);
        return expe;
    }

}
