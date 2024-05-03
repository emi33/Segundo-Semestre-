-- CREATE StoredProcedure nombre(vrdVariedad); --crear procedimientos almacenados para guardar informacion
Create view algo as select * from fincas; -- crear vistas
-- select nombre,variedad from algo; -- leemos vista sin ver base de datos
-- select vrdVariedad from variedades;

-- select fincas.fcaNombre As Productor, vrdVariedad as Variedad -- DB.Tabla.campo
-- from fincas inner join variedades as 1==0, parcelas, parcelavariedad -- en join podemos colocar inner, left o right
use fincas;
Create view VariedadesUsuales as 
select espNombre as Especie, vrdVariedad as Variedad from especies inner join variedades on espID=vrdEspecie limit 10000;
select * from especies;
select vrdVariedad from variedades;

select * from Variedades;
select * from VariedadesUsuales order by especie, variedad; 
select * from algo;
-- insert into view
insert into VariedadesUsuales (Especie,Variedad) values('Ananá','Hawaiana'); -- no permite insertar tablas dentro de vistas
drop view algo;
-- coalesce
select espNombre as especie, coalesce(vrdVariedad, 'Desconocida') -- coalesce permite usar varias variables, no solo 2
as variedad  from especies left join Variedades on espID=vrdEspecie -- hay especies que no tienen variedades
order by variedad, especie;
-- ifnull
select espNombre as especie, ifnull(vrdVariedad, 'Desconocida') -- ifnull solo funciona en mariadb y mysqlserver, se puede usar coalesce
as variedad  from especies left join Variedades on espID=vrdEspecie -- hay especies que no tienen variedades
order by variedad, especie;
-- bucle where
select espNombre as especie, ifnull(vrdVariedad, 'Desconocida') 
as variedad from especies left join variedades on espID=vrdEspecie
where vrdVariedad like 'Desconocida' -- no existe ninguna tabla 'desconocida' ya que ejecuta el where antes de filtrar
order by especie,variedad;
-- funcion having
select espNombre as especie, ifnull(vrdVariedad, 'Desconocida') 
as variedad from especies left join variedades on espID=vrdEspecie
having Variedad like 'Desconocida' -- muestra variedad ya que ejecuta having despues de filtrar
order by especie,variedad;
-- BORRAR
delete from especies where espID in (10,12,15,16);
delete from ca where espID IN(select espID, espNombre as especie, ifnull(vrdVariedad, 'Desconocida') 
as variedad from especies left join variedades on espID=vrdEspecie
having Variedad like 'Desconocida') C1; -- ARREGLAR SINTAXIS
