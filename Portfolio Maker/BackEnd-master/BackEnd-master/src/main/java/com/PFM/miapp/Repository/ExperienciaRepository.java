/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Repository;

import com.PFM.miapp.Model.Experiencia;
import jakarta.transaction.Transactional;
import java.util.List;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 *
 * @author Usuario
 */
@Repository
public interface ExperienciaRepository extends JpaRepository <Experiencia, Long>{
     List<Experiencia> findByPersonaId(Long personaId);
     
     //elimina todas las experiencias de una persona
     @Transactional
     void deleteByPersonaId(long personaId);
}
