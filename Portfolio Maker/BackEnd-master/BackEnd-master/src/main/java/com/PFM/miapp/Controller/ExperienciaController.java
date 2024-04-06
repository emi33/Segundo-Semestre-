package com.PFM.miapp.Controller;

import com.PFM.miapp.Interface.IExperienciaService;
import com.PFM.miapp.Model.Experiencia;
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
@RequestMapping("/experiencias")
public class ExperienciaController {

    @Autowired
    private IExperienciaService iExperiencia;

    @GetMapping("/persona/{id}")
    public ResponseEntity<List<Experiencia>> getAllExperienciasByPersonaId(@PathVariable Long id) {

        List<Experiencia> experiencias = iExperiencia.findByPersonaId(id);
        return new ResponseEntity<>(experiencias, HttpStatus.OK);
    }
    @GetMapping("/experiencia/{id}")
    public ResponseEntity<Experiencia> getExperienciaById(@PathVariable Long id) {

        Experiencia experiencias = iExperiencia.findExperiencia(id);
        return new ResponseEntity<>(experiencias, HttpStatus.OK);
    }

    @GetMapping("/traer")
    public List<Experiencia> getExperiencias() {
        return iExperiencia.getExperiencias();
    }

    @PostMapping("/crear")
    public ResponseEntity<HttpStatus> createExperiencia(@RequestBody Experiencia experiencia) {
        if(experiencia.getPersonaid()!= null){
            iExperiencia.saveExperiencia(experiencia);
           return new ResponseEntity<>(HttpStatus.OK);
        }else{
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }  
    }

    @PutMapping("/editar/persona/{id}/experiencia/{Id}")
    public ResponseEntity<Experiencia> updateExperiencia(@PathVariable long id, @PathVariable long Id, @RequestBody Experiencia expRequest) {
        List<Experiencia> experiencias = iExperiencia.findByPersonaId(id);
        Experiencia experiencia = iExperiencia.findExperiencia(Id);
        if (experiencias != null && experiencia != null) {
            Experiencia expe = iExperiencia.findExperiencia(Id);
            expe.setCargo(expRequest.getCargo());
            expe.setDescripcion(expRequest.getDescripcion());
            expe.setEmpresa(expRequest.getEmpresa());
            expe.setFecha(expRequest.getFecha());
            expe.setFechafin(expRequest.getFechafin());
            iExperiencia.saveExperiencia(expe);
            expRequest = expe;
        }
        return new ResponseEntity<>(expRequest, HttpStatus.OK);
    }

    @DeleteMapping("/borrar/{id}")
    public ResponseEntity<HttpStatus> deleteExperiencia(@PathVariable Long id) {
        iExperiencia.deleteExperiencia(id);
        return new ResponseEntity<>(HttpStatus.NO_CONTENT);
    }

   

}
