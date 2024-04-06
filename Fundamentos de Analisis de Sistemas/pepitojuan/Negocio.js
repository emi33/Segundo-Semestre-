let cantidad, precio, totalPagar, total, descuento;

cantidad = parseInt(prompt("Ingrese la cantidad del producto:"));
precio = parseInt(prompt("Ingrese el precio del producto:"));

totalPagar = cantidad * precio;

if (cantidad < 10) {
    total = totalPagar;
    descuento=false;
} else {
    if (cantidad <= 20) {
        total = totalPagar * 0.8;
        descuento=true;
        porce= 20;
    } else {
        total = totalPagar * 0.75;
        descuento=true;
        porce= 25;
    }
}

document.write("El total es: " + total);
if (descuento) {

    document.write(" descuento: " + porce + "%")
}