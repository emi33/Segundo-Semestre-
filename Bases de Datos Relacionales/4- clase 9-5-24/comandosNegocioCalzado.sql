select * from ´magescom´,´articulos´ inner join ´magescom´.´unidades´ 
on articulos.grupo=unidades.id;
select unidades from ´magescom´,´articulos´ group by unidad;
select articulos.id,codigo,descrip50,nombre from ´magescom´,´articulos´ 
inner join ´magescom´.´unidades´ on articulos.grupo=unidades.id;
select count(*) from ´magescom´.´articulos´;
(select * from ´magescom´,´articulos´ order by nombre);
select nombre,id,activo from arti.grupos where nombre in(select nombre 
from artgrupos as tmp group by nombre having count(*)>1) 
order by nombre;
select nombre,id,activo from arti.grupos where nombre in(select nombre 
from artgrupos as tmp group by nombre having count(*)>1) 
order by nombre asc, activo desc;
select nombre as categoria from artgrupos as grupitos 
group by nombre having count(*)>1;
select nombre, count(*) as categoria from artgrupos as grupo group by nombre 
having count (*)>1;
select nombre, count(*) as categoria from artgrupos as grupo where activo=0 
group by categoria; 
select articulos.id,codigo,descrip50,artgrupo.nombre, unidades.nombre 
from ´magescom´,´articulos´ 
inner join ´magescom´.´unidades´ on articulos.grupo=unidades.id
inner join artgrupos on articulos.grupo=artgrupos.id;
select * from articulos left join artgrupos on 
articulos.grupo = artgrupos.id where artgrupo.id is null; -- consulta para encontrar no coincidentes o registros huerfanos
select articulos.id, codigo, descrip50 from ´magescom´, ´articulos´
where codigo like 'ViaNeg__3380%' or grupo=2024;
select articulos.id, codigo, descrip50 from ´magescom´, ´articulos´
where codigo like '%Neg__3380%' or grupo=2024; -- como funciona el porcentaje para buscar codigo
-- se puede colocar adelante, atras y guiones para que filtre cualquier cosa que este ahi
select substr(codigo,4,3) as color, count(id) -- buscamos calzado via por color
 from ´magescom´.´articulos´
 where activo=1
 group by color; -- mysql cuenta en base 1


