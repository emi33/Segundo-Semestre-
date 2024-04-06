/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package com.PFM.miapp.Repository;

import com.PFM.miapp.Model.Contacto;
import jakarta.transaction.Transactional;
import java.util.List;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 *
 * @author Usuario
 */
@Repository
public interface ContactoRepository extends JpaRepository <Contacto, Long>{
    List<Contacto> findByPersonaId(Long personaId);
     
     //elimina todos los contactos de una persona
     @Transactional
     void deleteByPersonaId(long personaId);
}
