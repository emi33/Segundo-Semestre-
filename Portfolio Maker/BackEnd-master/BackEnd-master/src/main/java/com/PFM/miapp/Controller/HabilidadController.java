/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Controller;

import com.PFM.miapp.Interface.IHabilidadService;
import com.PFM.miapp.Model.Habilidad;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 *
 * @author Usuario
 */
@RestController
@CrossOrigin(origins="https://portfolio-maker-98538.web.app")
@RequestMapping("/habilidad")
public class HabilidadController {
    
    @Autowired
    private IHabilidadService iHabilidad;

    @GetMapping("/persona/{id}")
    public ResponseEntity<List<Habilidad>> getAllHabilidadesByPersonaId(@PathVariable Long id) {
        List<Habilidad> habilidades = iHabilidad.findByPersonaId(id);
        return new ResponseEntity<>(habilidades, HttpStatus.OK);
    }
    @GetMapping("/obtener/{id}")
    public ResponseEntity<Habilidad> getHabilidadById(@PathVariable Long id) {
        Habilidad habilidades = iHabilidad.findHabilidad(id);
        return new ResponseEntity<>(habilidades, HttpStatus.OK);
    }

    @GetMapping("/traer")
    public List<Habilidad> getHabilidades() {
        return iHabilidad.getHabilidades();
    }

    @PostMapping("/crear")
    public ResponseEntity<HttpStatus> createHabilidad(@RequestBody Habilidad habilidad) {
        if(iHabilidad.findByPersonaId(habilidad.getPersonaid())!=null){
            iHabilidad.saveHabilidad(habilidad);
        }else{
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @PutMapping("/editar/persona/{id}/habilidad/{Id}")
    public ResponseEntity<Habilidad> updateHabilidad(@PathVariable long id, @PathVariable long Id, @RequestBody Habilidad habilidad) {
        List<Habilidad> habilidades = iHabilidad.findByPersonaId(id);
        if (habilidades != null && iHabilidad.existsById(Id)) {
            Habilidad skill = iHabilidad.findHabilidad(Id);
            skill.setHabilidad(habilidad.getHabilidad());     
            
            skill.setPorcentaje(habilidad.getPorcentaje());
            skill.setSemana(habilidad.getSemana());
            skill.setMensual(habilidad.getMensual());
            iHabilidad.saveHabilidad(skill);
            habilidad = skill;
        }
        return new ResponseEntity<>(habilidad, HttpStatus.OK);
    }

    @DeleteMapping("/borrar/{id}")
    public ResponseEntity<HttpStatus> deleteEducacion(@PathVariable Long id) {
        iHabilidad.deleteHabilidad(id);
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }

}

