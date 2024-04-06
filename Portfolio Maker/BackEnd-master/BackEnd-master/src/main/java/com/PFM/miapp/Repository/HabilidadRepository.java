/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Repository;

import com.PFM.miapp.Model.Habilidad;
import jakarta.transaction.Transactional;
import java.util.List;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface HabilidadRepository extends JpaRepository <Habilidad, Long>{
     List<Habilidad> findByPersonaId(Long personaId);
     
     //elimina todas las experiencias de una persona
     @Transactional
     void deleteByPersonaId(long personaId);
}