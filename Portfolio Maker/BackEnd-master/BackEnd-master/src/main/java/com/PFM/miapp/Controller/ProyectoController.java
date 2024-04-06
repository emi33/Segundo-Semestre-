/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.PFM.miapp.Controller;

import com.PFM.miapp.Interface.IProyectoService;
import com.PFM.miapp.Model.Proyecto;
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
@CrossOrigin(origins = "https://portfolio-maker-98538.web.app")
@RequestMapping("/proyecto")
public class ProyectoController {

    @Autowired
    private IProyectoService iProyecto;

    @GetMapping("/persona/{id}")
    public ResponseEntity<List<Proyecto>> getAllProyectosByPersonaId(@PathVariable Long id) {
        List<Proyecto> proyectos = iProyecto.findByPersonaId(id);
        return new ResponseEntity<>(proyectos, HttpStatus.OK);
    }

    @GetMapping("/obtener/{id}")
    public ResponseEntity<Proyecto> getProyectoById(@PathVariable Long id) {
        Proyecto proyectos = iProyecto.findProyecto(id);
        return new ResponseEntity<>(proyectos, HttpStatus.OK);
    }

    @GetMapping("/traer")
    public List<Proyecto> getProyectos() {
        return iProyecto.getProyectos();
    }

    @PostMapping("/crear")
    public ResponseEntity<HttpStatus> createProyecto(@RequestBody Proyecto proyecto) {
        if (proyecto.getPersonaid() != null) {
            iProyecto.saveProyecto(proyecto);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @PutMapping("/editar/persona/{id}/proyecto/{Id}")
    public ResponseEntity<Proyecto> updateProyecto(@PathVariable long id, @PathVariable long Id, @RequestBody Proyecto proyectoRequest) {
        List<Proyecto> proyectos = iProyecto.findByPersonaId(id);
        if (proyectos != null && iProyecto.existsById(Id)) {
            Proyecto proyecto = iProyecto.findProyecto(Id);
            proyecto.setNombreProyecto(proyectoRequest.getNombreProyecto());
            proyecto.setDescripcion(proyectoRequest.getDescripcion());
            proyecto.setDesarrollo(proyectoRequest.getDesarrollo());
            proyecto.setLanzamiento(proyectoRequest.getLanzamiento());
            proyecto.setImg(proyectoRequest.getImg());
            proyecto.setLink(proyectoRequest.getLink());
            iProyecto.saveProyecto(proyecto);
        proyectoRequest = proyecto;
        }
        return new ResponseEntity<>(proyectoRequest, HttpStatus.OK);
    }

    @DeleteMapping("/borrar/{id}")
    public ResponseEntity<HttpStatus> deleteProyecto(@PathVariable Long id) {
        iProyecto.deleteProyecto(id);
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }

}
