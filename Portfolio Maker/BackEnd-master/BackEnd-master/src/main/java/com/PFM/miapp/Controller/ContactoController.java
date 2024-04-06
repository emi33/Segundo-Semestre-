/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Controller;

import com.PFM.miapp.Interface.IContactoService;
import com.PFM.miapp.Model.Contacto;
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
@CrossOrigin(origins = "https://portfolio-maker-98538.web.app")
@RequestMapping("/contacto")
public class ContactoController {
    
    @Autowired
    private IContactoService iContacto;

    @GetMapping("/persona/{id}")
    public ResponseEntity<List<Contacto>> getAllContactosByPersonaId(@PathVariable Long id) {
        List<Contacto> contactos = iContacto.findByPersonaId(id);
        return new ResponseEntity<>(contactos, HttpStatus.OK);
    }
    
    @GetMapping("/obtener/{id}")
    public ResponseEntity<Contacto> getContactoById(@PathVariable Long id) {
        Contacto contacto = iContacto.findContacto(id);
        return new ResponseEntity<>(contacto, HttpStatus.OK);
    }
    
    @GetMapping("/traer")
    public List<Contacto> getContactos() {
        return iContacto.getContactos();
    }
    
    @PostMapping("/crear")
    public ResponseEntity<HttpStatus> createContacto(@RequestBody Contacto contacto) {
        if (contacto.getPersonaid() != null) {
            iContacto.saveContacto(contacto);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
        return new ResponseEntity<>(HttpStatus.OK);
    }
    
    @PutMapping("/editar/persona/{id}/contacto/{Id}")
    public ResponseEntity<Contacto> updateContacto(@PathVariable long id, @PathVariable long Id, @RequestBody Contacto contactoRequest) {
        List<Contacto> contactos = iContacto.findByPersonaId(id);
        if (contactos != null && iContacto.existsById(Id)) {
            Contacto contacto = iContacto.findContacto(Id);
            contacto.setSocial(contactoRequest.getSocial());
            contacto.setUser(contactoRequest.getUser());
            iContacto.saveContacto(contacto);
        contactoRequest = contacto;
        }
        return new ResponseEntity<>(contactoRequest, HttpStatus.OK);
    }
    
      @DeleteMapping("/borrar/{id}")
    public ResponseEntity<HttpStatus> deleteContacto(@PathVariable Long id) {
        iContacto.deleteContacto(id);
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }

}
