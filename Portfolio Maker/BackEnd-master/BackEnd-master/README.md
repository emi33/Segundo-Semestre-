# BackEnd
Portfolio Backend
2023
# Descripción del Proyecto
Este proyecto es una aplicación CRUD (Crear, Leer, Actualizar, Eliminar) construida con Spring Boot, que 
se conecta a una base de datos relacional y utiliza una arquitectura many-to-one para relacionar 
cinco entidades habilidad, experiencia, educacion, proyectos y contactos, con una entidad persona. De esa forma,
podremos crear varias tablas de personas 

# Como usar el proyecto
La aplicación expone cuatro endpoints para interactuar con las entidades.

PERSONAS
GET personas/: Retorna una lista de todas las personas registradas en la base de datos, junto con sus detalles 
de sus cinco entidades relacionadas.
GET /personas/{id}: Retorna la persona con el ID especificado, junto con los detalles de sus cinco entidades relacionadas.
POST/: Crea una nueva persona en la base de datos
PUT /personas/{id}: Actualiza la persona con el ID especificado en la base de datos.
DELETE /personas/{id}: Elimina la persona con el ID especificado de la base de datos, junto con sus cinco entidades relacionadas.

TABLAS MANY TO ONE (Habilidad, Experiencia, Educacion, Contacto, Proyecto)
LAS PETICIONES SON IGUALES PARA LAS 5 ENTIDADES MANY-TO-ONE
Estas tablas cuentan con una clave foranea llamada "personaid" que las relaciona con la tabla persona.
GET: retorna una lista de todas las tablas de la entidad especificada.
GET /persona/{id}: retorna una lista de todas las tablas de la entidad especificada relacionadas con la persona especificada en el id.
GET /obtener/{id}: retorna la tabla de la entidad especificada con el id especificado.
POST /crear: crea una nueva tabla de la entidad especificada en la base de datos.
PUT /editar/persona/{id}/<ENTIDAD>/{Id}: Actualiza la la entidad con el personaid y el id especificado.
DELETE /<ENTIDAD>/{id}: Elimina la tabla con el ID especificado y la entidad especificada.
