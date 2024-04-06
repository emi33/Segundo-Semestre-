/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Repository;

import com.PFM.miapp.Model.Proyecto;
import jakarta.transaction.Transactional;
import java.util.List;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 *
 * @author Usuario
 */
@Repository
public interface ProyectoRepository extends JpaRepository <Proyecto, Long>{
     List<Proyecto> findByPersonaId(Long personaId);
     
     //elimina todos los proyectos de una persona
     @Transactional
     void deleteByPersonaId(long personaId);
}