use subase;
select year(Fecha) as año, month(Fecha) as mes, day(Fecha) as dia, count(boleto) as cantidad_pagos from pagos
group by year(Fecha), month(Fecha), day(Fecha);
SELECT * from pagos;
select year(Fecha) as año, month(Fecha) as mes, count(boleto) as cantidad_pagos from pagos
group by año, mes;
select DAY(Fecha) as Dia, count(boleto) as cantidad_pagos from pagos
group by Dia;
use subase;
select avg(importe) from pagos where Fecha>='2024-03-01' and Fecha<='2024-03-31';
select CAST(importe AS INTEGER) AS import from pagos where Fecha>='2024-03-01' and Fecha<='2024-03-31'; -- TABLA IMPORTES SIN DECIMALES
