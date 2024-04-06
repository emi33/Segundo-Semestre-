/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Repository;

import com.PFM.miapp.Model.Educacion;
import jakarta.transaction.Transactional;
import java.util.List;
import java.util.Optional;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 *
 * @author Usuario
 */
@Repository
public interface EducacionRepository extends JpaRepository<Educacion, Long>{
     List<Educacion> findByPersonaId(Long personaId);
    
     public boolean existsById(Long id);
     //elimina todas las educaciones de una persona
     @Transactional
     void deleteByPersonaId(long personaId);
}
