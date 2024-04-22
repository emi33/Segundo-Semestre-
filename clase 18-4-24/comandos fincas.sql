-- insert into fincas.variedades (vrdEspecie, vrdVariedad, vrdChgBy, vrdFechaUM)
-- values (14, 'Juniense', 15, now());
-- delete from variedades where vrdVariedad='Mendocina' and vrdEspecie =14 and vrdID=123;
use fincas;
-- select espNombre, vrdVariedad from variedades inner join especies on vrdEspecie= espID where vrdActiva =1  order by espNombre, vrdVariedad;
select espNombre, vrdVariedad from variedades inner join especies on vrdEspecie= espID where vrdActiva !=0  order by espNombre, vrdVariedad; -- forma de escribir vrdActiva mas segura
select vrdVariedad, vrdID from variedades inner join especies on vrdEspecie = espID where espNombre='Palta' order by vrdVariedad; -- cantidad paltas
select vrdVariedad, vrdID from variedades inner join especies on vrdEspecie = espID where espNombre='Peras' order by vrdVariedad; -- cantidad peras
select espNombre, count(vrdID) from variedades inner join especies on vrdEspecie = espID where vrdActiva !=0 group by vrdEspecie order by espNombre;
select * from variedades where vrdEspecie = 14 order by vrdVariedad;
