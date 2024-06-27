use zapcompra;
SET SQL_SAFE_UPDATES=1;
-- se desea ajustar el ancho del campo Descrip50 de la tabla articulos a un maximo de 60 caracteres. Sentencia SQL
ALTER TABLE `zapcompra`.`articulos` CHANGE COLUMN `Descrip50` `Descrip50` VARCHAR(60) NULL DEFAULT NULL;

ALTER TABLE `zapcompra`.`articulos` CHANGE COLUMN `Descrip50` `Descrip60` VARCHAR(60) NULL DEFAULT NULL; -- codigo arreglado

-- ¿CUAL ES LA SENTENCIA SQL QUE PERMITE INSERTAR UN NUEVO ARTICULO EN LA TABLA ARTICULOS?
-- si la ejecuto dos veces no debe desencadenar error
select * from articulos;
select * from artgrupos;
select distinctrow * from articulos;
INSERT ignore INTO `articulos` 
(`Activo`,`Codigo`,`Descrip60`,`Descrip20`,`Cantidad`,`Unidad`,`Grupo`,
`PrecioC`,`PrecioV`,`PrecioOferta`,`AlicIva`,`ImpInt`,`ExistMinima`,`Observ`,`Usuario`,`FechaUM`) VALUES 
(1,'TopNeg431600','Zapatillas Topper 43','Zapatillas',1,2,52,'28.0000','30.0700','30.0700',0.21,0,0,'',4,'2024-06-27 10:42:46')
;

-- cual es la sentencia sql que permite determinar el monto discriminado por año y mes destinado
-- a la compra de articulos pertenecientes a la categoria o grupo saldanlia dama
SELECT * FROM articulos where Grupo=9;
select year(FechaUM) as anio, month(FechaUM) as mes, sum(PrecioC) as monto from articulos where Grupo=9 GROUP by anio,mes order by anio,mes;
select year(FechaUM) as anio, month(FechaUM) as mes, PrecioC as monto from articulos where Grupo=9 order by anio, mes;
select * from movcomdet;
select year(FechaUM) AS anio, month(FechaUM) as mes, sum(movcomdet.Subtotal) as monto from movcomdet
inner join articulos on movcomdet.Articulo=articulos.id where articulos.Grupo=9
group by anio, mes order by anio, mes;
SELECT * from movcomdet inner join articulos on movcomdet.Articulo=articulos.id where articulos.Grupo=9 order by articulo;
select year(movcomcab.Fecha) as anio, month(movcomcab.Fecha)as mes, sum(Subtotal) from movcomcab inner join movcomdet on movcomcab.id=movcomdet.idCab inner join articulos on movcomdet.Articulo=articulos.id
where articulos.Grupo=9 GROUP BY anio, mes;-- solucion correcta
SELECT year(FechaUM) as anio, month(FechaUM)as mes, sum(Subtotal) as monto
 from movcomdet inner join articulos on movcomdet.Articulo=articulos.id
 where articulos.Grupo=9 group by anio,mes order by anio,mes;

-- sentencia sql que pemite aumentar %6.45 el precio de venta de articulos de sandalia niño
-- redondeados en multiplos de 10 pesos.
select * from articulos where id not in(select Articulo from movcomdet);
select * from movcomdet where Articulo not in(select id from articulos);
SELECT * from movcomdet group by Articulo;

select * from articulos;

SET SQL_SAFE_UPDATES=0;
select id, truncate(PrecioV,0) from articulos;
update articulos set PrecioV=PrecioV*1.0645-(PrecioV*1.0645%10) where PrecioV!=0 and articulos.Grupo=9;
select * from articulos where Grupo=9;

-- creamos tabla temp para verificar cambios
CREATE TABLE `zapcompra`.`temp` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `ide` INT(10) NULL,
  `PrecioAnterior` DECIMAL(19,4) NULL,
  PRIMARY KEY (`id`));
 delete from temp;
Insert into `temp`(`ide`,`PrecioAnterior`) SELECT id, PrecioV from articulos where articulos.Grupo=9; 

Alter table `temp` add Column `PrecioNoRedondeado` decimal(19,4);
select * from temp;
-- respuesta correcta 3 sentencias
update articulos set PrecioV=PrecioV*1.0645 where PrecioV !=0 AND articulos.Grupo=9;
UPDATE articulos set PrecioV=Preciov-PrecioV%10 where PrecioV!=0 and PrecioV%10<5;
Update articulos set PrecioV=PrecioV+10-PrecioV%10 where PrecioV!=0 and PrecioV%10>=5;
-- verifica resultados en tabla temp
Update temp inner join articulos on temp.ide=articulos.id set PrecioNoRedondeado=PrecioV*1.0645;
Update temp inner join articulos on temp.ide=articulos.id set PrecioAnterior=articulos.PrecioV;
UPDATE articulos
SET PrecioV = 
  CASE
    WHEN PrecioV*1.0645 % 10 < 5 THEN PrecioV*1.0645 - PrecioV*1.0645 % 10 
    WHEN PrecioV*1.0645 % 10 >= 5 THEN PrecioV*1.0645 + 10 - PrecioV*1.0645 % 10 
  END
WHERE PrecioV != 0 and articulos.Grupo=9; -- respuesta correcta