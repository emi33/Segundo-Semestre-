USE fincas;
select pa.vepFinca, f.fcaNombre, p.prcRef, pa.vepProdEstim FROM fincas f
INNER JOIN parcelas p ON f.fcaID = p.prcFinca
INNER JOIN parcelavariedad pa ON p.prcFinca = pa.vepFinca AND p.prcUMI = pa.vepUMI
INNER JOIN variedades v ON pa.vepVariedad = v.vrdID
where v.vrdEspecie=6 and v.vrdVariedad='Black Amber';
select sum(vepProdEstim) from parcelaVariedad where vepVariedad=18;
select fcaNombre, p.prcFinca from fincas f
inner join parcelas p on p.prcFinca = f.fcaID
inner join parcelavariedad pa on pa.vepFinca = p.prcFinca AND pa.vepUMI = p.prcUMI
INNER JOIN variedades v on v.vrdID = pa.vepVariedad
where vrdEspecie=6 and vrdVariedad='Black Amber';

