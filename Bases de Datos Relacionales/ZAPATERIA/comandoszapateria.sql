use magescom;
select * from tbusuarios;
show tables;
-- mostrar primera fecha de movimientos comerciales cabecera
select fecha from movcomcab order by fecha limit 1; -- primera fecha movimiento
-- ver ultima fecha de movimientos comerciales cabecera
select fecha from movcomcab order by fecha desc limit 1; -- ultima fecha movimiento
-- ver ultima fecha de movimientos comerciales cabecera
select min(fecha), max(fecha) from movcomcab; -- primera y ultima fecha de movimientos comerciales
-- para calcular el promedio de un mes, debemos ver el primer mes que puede afectar el promedio general
-- ver y eliminar movimiento cabecera con fecha '2016-08-31'
select * from movcomcab where fecha='2016-08-31';
-- delete from movcomcab where fecha='2016-08-31';
select * from movcomcab;
use magescom;
-- VER registros huerfanos de movimiento detalle (usamos idcab)
select * from movcomdet as mcd where mcd.idCab not in (select id from movcomcab);
select * from movcomdet inner join movcomcab on !(movcomdet.idCab=movcomdet.id);
-- delete from movcomdet where movcomdet.idCab=3 and movcomdet.id=12389; -- tabla limpia
-- tabla de estados ordenado por id
select * from estados order by id;
-- contar los tipos de movimiento y la cantidad
SELECT TipoMov, COUNT(TipoMov) FROM movcomcab GROUP BY TipoMov;
-- VER DESCRIPCION DE TIPO DE MOVIMIENTOS Y LA CANTIDAD DE CADA TIPO(Inner join con tabla estados)
select e.descrip as Tipo, mcc.TipoMov, count(mcc.TipoMov) as Veces
from movcomcab mcc left join estados e on mcc.TipoMov=e.id
group by mcc.TipoMov order by Veces desc;
select idCab, Count(idCab) as sum from movcomdet group by idCab order by sum;
select * from movcomdet;
select * from movcomcab;
SELECT md.Cantidad AS 'Cantidad de Pares Comprados',COUNT(*) AS 'Cantidad de Veces'
FROM movcomdet md INNER JOIN movcomcab mc ON md.idCab = mc.id
-- Reemplaza ID_DEL_ARTÍCULO_DE_LOS_ZAPATOS con el ID del artículo de los zapatos que te interesa
GROUP BY md.Cantidad
ORDER BY md.Cantidad;
select * from movcomdet inner join movcomcab on movcomcab=202 group by movcomdet.idCab;
-- buscar los 3 productos mas caros de la zapateria
select Descrip50 AS Articulo, PrecioV AS Precio from articulos order by PrecioV desc LIMIT 3;
-- de las ventas, cuantos productos se venden por venta
select * from movcomcab where movcomcab.TipoMov=202;
select * from movcomdet where movcomdet.idCab=9;
select * from articulos where articulos.id=60170;
SELECT *
FROM movcomcab
INNER JOIN movcomdet ON movcomcab.id = movcomdet.idCab
WHERE movcomcab.TipoMov = 202;
SELECT movcomcab.id, SUM(-movcomdet.Cantidad) AS total_cantidad, articulos.Descrip50 
FROM movcomcab
INNER JOIN movcomdet ON movcomcab.id = movcomdet.idCab
inner join articulos on movcomdet.Articulo=articulos.id
WHERE movcomcab.TipoMov = 202
GROUP BY movcomcab.id ORder by total_cantidad desc, movcomcab.id;
-- cuantas veces vendieron x cantidad de productos
Select total_cantidad, COUNT(total_cantidad) from (SELECT movcomcab.id as Venta, SUM(-movcomdet.Cantidad) AS total_cantidad
FROM movcomcab
INNER JOIN movcomdet ON movcomcab.id = movcomdet.idCab
WHERE movcomcab.TipoMov = 202
GROUP BY movcomcab.id ORder by movcomcab.id) as subconsulta
GROUP BY total_cantidad
ORDER BY total_cantidad asc;
SELECT id, Descrip50
FROM articulos
INNER JOIN movcomdet ON articulos.id = movcomdet.idCab
WHERE movcomdet.id = 23557
GROUP BY articulos.id ORder by articulos.id;
-- pendiente: nombre del articulo que se vendio una vez y fue el mas vendido 33 se vendio 1 vez
select max(total_cantidad), id, descrip from(SELECT movcomcab.id as id, SUM(-movcomdet.Cantidad) AS total_cantidad, articulos.Descrip50 as descrip
FROM movcomcab
INNER JOIN movcomdet ON movcomcab.id = movcomdet.idCab
inner join articulos on movcomdet.Articulo=articulos.id
WHERE movcomcab.TipoMov = 202
GROUP BY movcomcab.id ORder by total_cantidad desc, movcomcab.id) as subconsulta;
-- de que colores hace la marca npo
select ID, Descrip50, substr(codigo,4,3) as color from articulos where codigo like 'Npo%'
group by color order by id,color;
select * from articulos where codigo like 'Npo%' order by id;
select * from artgrupos;
select * from articulos;
-- ver los grupo de articulos(tabla artgrupos) y contar la cantidad de articulos que tiene cada grupo
select artgrupos.id, artgrupos.nombre as ide, count(articulos.Grupo) as grupo from artgrupos 
inner join articulos on artgrupos.id=articulos.Grupo group by grupo order by grupo;
select * from articulos where Grupo = 29;
-- ver producto con menor desvio estandar
select D.Articulo as producto, year(C.FechaUM)*12 + month(C.FechaUM) - 24200 as x, sum(-D.Cantidad) as Cantidad 
from movcomcab C inner join movcomdet D on C.id=D.idCab
where C.tipomov=202
group by Producto, X;
-- GUARDAR TABLA PRODUCTO CON MENOR DESVIO ESTANDAR
CREATE table tmp
select D.Articulo as producto, year(C.FechaUM)*12 + month(C.FechaUM) - 24200 as x, sum(-D.Cantidad) as Cantidad 
from movcomcab C inner join movcomdet D on C.id=D.idCab
where C.tipomov=202
group by Producto, X;
select * from tmp;
-- ver productos con desvio estandar, si desvio estandar es 0, se vendio una vez o se vendio igual todos los meses
select producto, stddev(Cantidad) as desvio from tmp group by producto order by desvio;
select * from articulos where articulos.id=172103;
-- producto mas atemporal
select producto, stddev(Cantidad) as desvio, count(x) as meses from tmp group by producto order by meses desc, desvio asc;
select * from articulos where articulos.id=26403;
select * from articulos where articulos.id=9789;
-- eliminar tabla temporal
drop table tmp;
-- mejor opcion para uso de tablas temporales
select D.Articulo as producto, year(C.FechaUM)*12 + month(C.FechaUM) - 24200 as x, sum(-D.Cantidad) as Cantidad 
from movcomcab C inner join movcomdet D on C.id=D.idCab
where C.tipomov=202
group by Producto, X;
-- ver variacion de precio de articulo 9789
select movcomdet.PrecioUnit, movcomcab.Fecha as fecha 
from movcomdet inner join movcomcab on movcomdet.idCab=movcomcab.id where articulo=9789 
order by Fecha;
-- ver precio articulo, ya esta ordenado por fecha, ya que se utiliza la fecha del servidor
SELECT precioUnit FROM movcomdet WHERE articulo=9789 order by id desc;
select * from movcomdet 
inner join articulos on movcomdet.Articulo=articulos.id
inner join artgrupos on articulos.Grupo=artgrupos.id where artgrupos.Nombre LIKE 'ALPARGATA%' order by idCab;
-- precio promedio mensual historico de venta de las alpargatas
select year(movcomcab.fechaUM) AS AÑO, month(movcomcab.fechaUM) as MES, AVG(movcomdet.PrecioUnit) as precio, SUM(articulos.Cantidad) as Compra, 
articulos.Grupo as NumGrupo, artgrupos.Nombre as grupo
from movcomcab 
inner join movcomdet on movcomcab.id=movcomdet.idCab 
inner join articulos on movcomdet.Articulo=articulos.id
inner join artgrupos on articulos.Grupo=artgrupos.id where artgrupos.Nombre LIKE 'ALPARGATA%' AND movcomcab.TipoMov=202
group by AÑO,MES order by AÑO,MES;

-- ver detalles del promedio

select * from movcomdet 
inner join articulos on movcomdet.Articulo=articulos.id
inner join artgrupos on articulos.Grupo=artgrupos.id where artgrupos.Nombre LIKE 'ALPARGATA%' order by abs(movcomdet.Cantidad);
-- borrar registros donde la cantidad sea menor a uno de todos los registros
select * from movcomdet D where abs(Cantidad)<1;
-- borrar registros donde la cantidad sea menor a uno
select * from movcomdet 
inner join articulos on movcomdet.Articulo=articulos.id
inner join artgrupos on articulos.Grupo=artgrupos.id where artgrupos.Nombre LIKE 'ALPARGATA%' and (abs(movcomdet.Cantidad))<1;
select movcomdet.Articulo, articulos.Descrip20 from movcomdet inner join articulos on movcomdet.Articulo = articulos.id group by Descrip20;
-- desactivar modo seguro
SET SQL_SAFE_UPDATES=0;
-- borrar cantidades 23556
delete from movcomdet where abs(Cantidad)<1;
-- activar modo seguro
set sql_safe_updates=0;
SELECT movcomcab.id as id, Count(-movcomdet.idCab) AS cabeceras
FROM movcomcab
left JOIN movcomdet ON movcomcab.id = movcomdet.idCab
GROUP BY movcomcab.id ORder by movcomcab.id;

select * from(SELECT movcomcab.id as Venta, Count(-movcomdet.idCab) AS cabeceras
FROM movcomcab
left JOIN movcomdet ON movcomcab.id = movcomdet.idCab
GROUP BY movcomcab.id ORder by movcomcab.id) as subconsulta where cabeceras=0;

SELECT movcomcab.id as Venta, Count(-movcomdet.idCab) AS cabeceras
FROM movcomcab
left JOIN movcomdet ON movcomcab.id = movcomdet.idCab
GROUP BY movcomcab.id ORder by movcomcab.id;

-- delete registro
select * from movcomcab where id not in(select distinctrow idCab from movcomdet);
delete from movcomcab where id not in(select distinctrow idCab from movcomdet);


SELECT NULL FROM movcomdet AS parent join movcomcab WHERE parent.idCad = movcomcab.id;