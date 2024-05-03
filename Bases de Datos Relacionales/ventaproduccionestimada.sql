USE fincas;
SELECT
    f.fcaNombre AS Finca,
    pa.prcRef AS Parcela,
    pv.vepProdEstim AS Produccion_Estimada
FROM
    fincas f, 
INNER JOIN
    parcelas pa ON f.fcaID = pa.prcFinca
INNER JOIN
    parcelavariedad pv ON pa.prcFinca = pv.vepFinca AND pa.prcUMI = pv.vepUMI
INNER JOIN
    variedades v ON pv.vepVariedad = v.vrdID
WHERE
    v.vrdVariedad = 'Black Amber'
    AND v.vrdEspecie = 6;
select * FROM parcelavariedad where vepVariedad=18;
select sum(vepProdEstim) from parcelaVariedad where vepVariedad=18;