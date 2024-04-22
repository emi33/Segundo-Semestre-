SHOW GRANTS FOR root; 
SELECT * FROM estadistica.notas;
SELECT AVG(nota) AS media
FROM estadistica.notas;
SET @row_number := 0;


SELECT 
    @Median := AVG(1.0 * nota)
FROM (
    SELECT 
         nota,
        (@row_number := @row_number + 1) AS row_number,
        (SELECT COUNT(*) FROM estadistica.notas) AS total_rows
    FROM 
        estadistica.notas
    ORDER BY 
        nota
) AS ranked
WHERE 
    row_number IN (CEIL(total_rows / 2), FLOOR(total_rows / 2) + 1);

SELECT @Median AS Median;

SET @mode_count := 0;
SET @mode_value := NULL;

-- Calcula la moda
SELECT 
    nota AS moda,
    COUNT(*) AS frecuencia
FROM 
    estadistica.notas
GROUP BY 
    nota
ORDER BY 
    COUNT(*) DESC
LIMIT 1;
 -- varianza
 SELECT AVG(nota) INTO @media
FROM estadistica.notas;

-- Calcula la varianza
SELECT 
    SUM(POWER(nota - @media, 2)) / (COUNT(*) - 1) AS varianza
FROM 
    estadistica.notas;
SELECT SQRT(SUM(POWER(nota - (SELECT AVG(nota) FROM estadistica.notas), 2)) / (COUNT(*) - 1)) AS desviacion_estandar
FROM estadistica.notas;