use zapcompra;
select count(id) from movcomdet;
SELECT * FROM movcomdet ORDER by idCab;
select * from estados;
select * from tbusuarios;
select * from movcomcab inner join movcomdet on movcomcab.id=movcomdet.idCab group by movcomcab.id;
select * from articulos;
select * from movcomcab inner join movcomdet on movcomcab.id=movcomdet.idCab group by movcomcab.id;
select * from movcomdet;
select * from movcomcab order by ImpTotal desc;
select codigo, substr(codigo,1,3)as marca from articulos group by marca;

-- ¿Cuántas compras hay registradas en la base de datos?
select count(*) as total_compras from zapcompra.movcomcab;


select * from movcomdet inner join movcomcab on movcomdet.idCab=movcomcab.id 
where TipoMov=201;
use zapcompra;
-- ¿En qué fecha se registró la primera compra?
-- Escriba la respuesta en formato ISO: aaaa-mm-mm
SELECT min(Fecha) from movcomcab order by movcomcab.Fecha;

-- ¿En qué fecha se registró la última compra?
-- Escriba la respuesta en formato ISO: aaaa-mm-mm
SELECT max(Fecha) from movcomcab order by movcomcab.Fecha;
SELECT * from movcomcab order by movcomcab.Fecha desc;

-- ¿A cuántos proveedores se compró en más de 200 oportunidades?
select count(contador) from (select idPers, count(idPers) as contador from movcomcab group by idPers having contador>200)as sub2;
select idPers, count(idPers) as contador from movcomcab group by idPers having contador>200;
SELECT idPers, COUNT(id) as veces from movcomcab where TipoMov=201 group by idPers order by veces DESC;

-- Borrar movcomcab id=7090
select * from movcomcab where idPers=7090;
select * from movcomdet inner join movcomcab on movcomdet.idCab=movcomcab.id where idPers=7090;
select * from movcomdet where idCab not in(select distinctrow id from movcomcab);
select * from movcomdet where idCab=8555;
DELETE FROM movcomdmovcomcabet D inner join movcomcab D ON C.id=D.idCab where idCab=7090;
delete from movcomdet where idCab NOT 21921 in(select id from movcomcab);
delete from movcomcab where idCab=7090;
select * from movcomcab inner join movcomdet on movcomcab.id=movcomdet.idCab where idPers=7090;

-- ¿Cuál es el ID (idPers) del proveedor al que se le compró más veces?
select idPers, count(idPers) as contador from movcomcab group by idPers order by contador desc limit 1;

-- Se ha detectado que un proveedor fue cargado dos veces, en la primera oportunidad le tocó el idPers=7000 y luego el idPers=7040.
-- Desea ejecutarse una actualización (UPDATE) de la tabla movcomcab de forma tal que todos los registros que tienen idPers=7040 
-- sean cambiados a idPers=7000.
-- ¿Cuántos registros afectó su sentencia UPDATE?
select * from movcomcab where idPers=7040;
select * from articulos;
SET SQL_SAFE_UPDATES=0;
update movcomcab set idPers=7000 where idPers=7040;
SET SQL_SAFE_UPDATES=1;
SELECT ROW_COUNT() AS registros_afectados;

-- Nota: La marca está abreviada y corresponde a los 3 primeros caracteres del código de articulo.
-- ¿Cuántas marcas distintas se han codificado en la tabla de artículos?
select codigo, substr(codigo,1,3) as marca from articulos group by marca;
select count(distinct substr(codigo,1,3)) as marca from articulos;
SELECT COUNT(DISTINCT LEFT(Codigo, 3)) AS total_marcas
FROM articulos;

-- ¿Cuántas líneas de detalle tiene la compra con mayor cantidad de líneas?
-- Nota: en cada compra se inserta un registro en movcomcab y tantos registros en movcomdet como líneas de detalle contenga la factura.
SELECT movcomcab.id as id, Count(movcomdet.idCab) AS cabeceras
FROM movcomcab
left JOIN movcomdet ON movcomcab.id = movcomdet.idCab
GROUP BY movcomcab.id ORder by cabeceras desc;

SELECT COUNT(*) AS Total_Lineas_Detalle
FROM movcomdet
WHERE idCab = (
    SELECT id
    FROM movcomcab
    ORDER BY COUNT(*) DESC
    LIMIT 1
);

-- ¿Cuántos artículos incluía la mayor compra?
select idCab, max(cantidades) from (SELECT idCab, SUM(Cantidad) as cantidades from movcomdet
GROUP BY idCab) as sub;-- solucion correcta
    
select sum(movcomdet.Cantidad) as mayor_compra from movcomdet where idCab=481219;
select sum(movcomdet.Cantidad) as mayor_compra from movcomdet where idCab=411673;
SELECT SUM(Cantidad) AS cantidad_total_articulos
FROM movcomdet
WHERE idCab = (
    SELECT idCab
    FROM movcomdet
    GROUP BY idCab
    ORDER BY COUNT(*) DESC
    LIMIT 1
);

select movcomdet.Articulo, articulos.Descrip50, articulos.codigo from movcomdet 
inner join articulos on movcomdet.Articulo=articulos.id where idCab=411673;
select movcomdet.Articulo, articulos.Descrip50 from movcomdet inner join articulos on movcomdet.Articulo=articulos.id where idCab=481219;
select sum(Cantidad) from movcomdet where idCab=411673;
SELECT COUNT(DISTINCT Articulo) AS Total_Articulos
FROM movcomdet
WHERE idCab = (
    SELECT id
    FROM movcomcab
    ORDER BY COUNT(*) DESC
    LIMIT 1
);
SELECT COUNT(Articulo) AS Total_Articulos
FROM movcomdet
WHERE idCab = (
    SELECT id
    FROM movcomcab
    ORDER BY COUNT(*) DESC
    LIMIT 1
);
SELECT *
    FROM movcomcab
    ORDER BY COUNT(*) DESC;
-- ¿Cuántos registros existen en movcomcab sin tener registros correspondientes en la tabla movcomdet?
select count(*) as suma_registros from movcomcab where id not in(select distinctrow idCab from movcomdet);
SELECT COUNT(*) AS TotalRecordsWithoutDetails
FROM movcomcab
LEFT JOIN movcomdet ON movcomcab.id = movcomdet.idCab
WHERE movcomdet.id IS NULL;

-- En promedio ¿cuántas líneas de detalle se incluyen en cada compra?
-- Indique al menos 2 decimales utilizando el punto como separador decimal.
select ROUND(avg(cabeceras), 2) as promedio from (SELECT movcomcab.id as id,movcomdet.idCab, Count(movcomdet.idCab) AS cabeceras
FROM movcomcab
inner JOIN movcomdet ON movcomcab.id = movcomdet.idCab
GROUP BY movcomcab.id Order by cabeceras asc) as subconsulta;

SELECT ROUND(AVG(detail_count), 2) AS AverageDetailLines
FROM (
    SELECT COUNT(*) AS detail_count
    FROM movcomdet
    GROUP BY idCab
) AS detail_counts;

SELECT movcomcab.id as id, Count(movcomdet.idCab) AS cabeceras
FROM movcomcab
left JOIN movcomdet ON movcomcab.id = movcomdet.idCab
GROUP BY movcomcab.id ORder by cabeceras asc;

SELECT round(AVG(total_lineas),2) AS promedio_lineas_por_compra
FROM (
    SELECT idCab, COUNT(idCab) AS total_lineas
    FROM movcomdet
    GROUP BY idCab
) AS total;
-- En promedio ¿cuántos artículos se incluyen en cada compra?
-- Redondee la respuesta de forma tal que su respuesta sea un número entero.
select round(avg(art),0) AS promedio from (select movcomdet.id, sum(movcomdet.Cantidad) as art from movcomdet group by idCab) as sub;
select movcomdet.id, Articulo, sum(movcomdet.Cantidad) as art from movcomdet INNER JOIN
articulos on movcomdet.Articulo=articulos.id group by idCab;
select avg(Cantidad) from movcomdet;
select * from movcomdet;
select sum(Cantidad) from movcomdet;

-- Nota: La marca está abreviada y corresponde a los 3 primeros caracteres del código de articulo.
-- Escriba una consulta que entregue por resultado la cantidad de marcas distintas compradas.
-- Si su consulta es correcta debería mostrar: 135
select count(distinct substr(codigo,1,3)) as total from movcomdet inner join articulos
on movcomdet.Articulo=articulos.id;
select count(distinct substr(codigo,1,3)) as total from movcomdet inner join movcomcab on movcomdet.idCab=movcomcab.id inner join articulos
on movcomdet.Articulo=articulos.id and movcomcab.TipoMov=201;

SELECT COUNT(DISTINCT LEFT(articulos.Codigo, 3)) AS CantidadMarcas
FROM movcomdet
JOIN articulos ON movcomdet.Articulo = articulos.id;


SELECT movcomcab.id, ImpNetoGrav as suma
FROM movcomcab order by suma desc limit 1;
select round(sum(Cantidad),0) as cantidad from movcomdet where idCab = 
(select id from movcomcab where ImpNetoGrav = (select max(ImpNetoGrav) from movcomcab));
select sum(movcomdet.Cantidad) from movcomcab inner join movcomdet on movcomcab.id=movcomdet.idCab
where ImpNetoGrav = (select max(ImpNetoGrav) from movcomcab);

select id from movcomcab where ImpNetoGrav = (select max(ImpNetoGrav) from movcomcab);
select max(ImpNetoGrav) from movcomcab;
SELECT SUM(movcomdet.Cantidad)
FROM movcomcab
INNER JOIN movcomdet ON movcomcab.id = movcomdet.idCab
INNER JOIN (
    SELECT MAX(ImpNetoGrav) AS maxImpNetoGrav
    FROM movcomcab
) AS maxTable ON movcomcab.ImpNetoGrav = maxTable.maxImpNetoGrav;
select avg(CantLin) as PromLin
from(
    select idCab, COUNT(*) AS CantLin
    from movcomdet
    group by idCab
) as promedio;

SELECT COUNT(*) AS total_compras
FROM movcomcab;
SELECT MAX(Fecha) AS ultima_compra
FROM movcomcab;
SELECT COUNT(*)
FROM (
    SELECT idPers, COUNT(*) AS contador
    FROM movcomcab
    GROUP BY idPers
    HAVING COUNT(*) > 200
) AS subquery;
SELECT *
FROM movcomcab
GROUP BY idPers
ORDER BY COUNT(*) DESC
LIMIT 1;