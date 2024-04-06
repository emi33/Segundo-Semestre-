/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Service;

import com.PFM.miapp.Interface.IProyectoService;
import com.PFM.miapp.Model.Proyecto;
import com.PFM.miapp.Repository.ProyectoRepository;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;

import org.springframework.stereotype.Service;

/**
 *
 * @author Usuario
 */
@Service
public class ProyectoService implements IProyectoService {

    @Autowired
    private ProyectoRepository proyectoRepository;

    @Override
    public List<Proyecto> getProyectos() {
        List<Proyecto> listaProyecto = proyectoRepository.findAll();
        return listaProyecto;
    }

    @Override
    public void saveProyecto(Proyecto proyecto) {
        proyectoRepository.save(proyecto);
    }

    @Override
    public void deleteProyecto(Long id) {
        proyectoRepository.deleteById(id);
    }

    @Override
    public Proyecto findProyecto(Long id) {
        Proyecto proyecto = proyectoRepository.findById(id).orElse(null);
        return proyecto;
    }

    @Override
    public List<Proyecto> findByPersonaId(Long personaId) {
        return proyectoRepository.findByPersonaId(personaId);
    }

    @Override
    public Proyecto getOne(long id) {
        Proyecto proyecto = proyectoRepository.findById(id).orElse(null);
        return proyecto;
    }

    @Override
    public boolean existsById(Long id) {
        return proyectoRepository.existsById(id);
    }

}
