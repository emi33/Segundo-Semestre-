/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Controller;

import com.PFM.miapp.Interface.IPersonaService;
import com.PFM.miapp.Model.Persona;

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

@RestController
@CrossOrigin(origins="https://portfolio-maker-98538.web.app")  
@RequestMapping("/personas")
public class PersonaController {
    
    @Autowired
    private IPersonaService iPersona;
    
    @GetMapping("/traer")
    public ResponseEntity<List<Persona>> getPersonas(){
        return new ResponseEntity<>(iPersona.getPersonas(), HttpStatus.OK);
    }
    
    @PostMapping("/crear")
    public  ResponseEntity<HttpStatus> savePersona(@RequestBody Persona persona){
        iPersona.savePersona(persona);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }
    
    @DeleteMapping("/borrar/{id}")
    public ResponseEntity<HttpStatus> deletePersona(@PathVariable Long id){
        iPersona.deletePersona(id);
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }
    
    @PutMapping("/editar/{id}")
    public ResponseEntity<HttpStatus> edit(@PathVariable("id") long id, @RequestBody Persona persona){
        if (iPersona.findPersona(id)!= null){
            iPersona.editPersona(persona);
            return new ResponseEntity<>(HttpStatus.OK);
        }else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
        
        
    }
    
    @GetMapping("/traer/{id}")
    public ResponseEntity<Persona> detail(@PathVariable("id") long id){
        return ResponseEntity.ok(iPersona.findPersona(id));
    }      
    
   
}

