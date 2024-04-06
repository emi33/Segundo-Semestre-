/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Controller;

import com.PFM.miapp.Interface.IEducacionService;
import com.PFM.miapp.Model.Educacion;
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
@RequestMapping("/educacion")
public class EducacionController {
    
    @Autowired
    private IEducacionService iEducacion;

    @GetMapping("/persona/{id}")
    public ResponseEntity<List<Educacion>> getAllEstudiosByPersonaId(@PathVariable Long id) {

        List<Educacion> estudios = iEducacion.findByPersonaId(id);
        return new ResponseEntity<>(estudios, HttpStatus.OK);
    }
    @GetMapping("/obtener/{id}")
    public ResponseEntity<Educacion> getEducacionById(@PathVariable Long id) {

        Educacion estudios = iEducacion.findEducacion(id);
        return new ResponseEntity<>(estudios, HttpStatus.OK);
    }

    @GetMapping("/traer")
    public List<Educacion> getEstudios() {
        return iEducacion.getEstudios();
    }

    @PostMapping("/crear")
    public ResponseEntity<HttpStatus> createEducacion(@RequestBody Educacion educacion) {
        
        if(educacion.getPersonaid()!= null){
            iEducacion.saveEducacion(educacion);
           
        }else{
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
        
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @PutMapping("/editar/persona/{id}/educacion/{Id}")
    public ResponseEntity<Educacion> updateEducacion(@PathVariable long id, @PathVariable long Id, @RequestBody Educacion eduRequest) {
        List<Educacion> estudios = iEducacion.findByPersonaId(id);
        
        if (estudios != null && iEducacion.existsById(Id)) {
            Educacion edu = iEducacion.findEducacion(Id);
            edu.setInstitucion(eduRequest.getInstitucion());
            edu.setTitulo(eduRequest.getTitulo());
            edu.setFechainicio(eduRequest.getFechainicio());
            edu.setFechafin(eduRequest.getFechafin());
            iEducacion.saveEducacion(edu);
            eduRequest = edu;
        }
        return new ResponseEntity<>(eduRequest, HttpStatus.OK);
    }

    @DeleteMapping("/borrar/{id}")
    public ResponseEntity<HttpStatus> deleteEducacion(@PathVariable Long id) {
        iEducacion.deleteEducacion(id);
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }
    
  
}
