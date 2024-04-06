var i = 0;
var numGlobal = 0;
function generarNumero() {
    var numeroAleatorio = Math.floor(Math.random() * 100) + 1;
    numGlobal = numeroAleatorio
    document.getElementById("numeroAleatorio").innerText = "Número Aleatorio Generado ";
    document.querySelector("button").style.display = "none";
}
val = false;
let menores = ["Error!!! es un numero mayor", "No!! Es un número más grande"];
let mayores = ["Error!!! es un numero menor", "No!! Es un número más pequeño"];
function numeroad() {
    console.log("num global: " + numGlobal);
    var numero = document.getElementById("num").value;
    nume = parseInt(numero);
    console.log("Número ingresado:", numero);
    if (nume < numGlobal) {
        if (documento == menores[0]) {
            documento = menores[1];
        } else {
            documento = menores[0];
        }
        console.log("numero menor");
        i = i + 1;
    } else if (nume > numGlobal) {
        if (documento == mayores[0]) {
            documento = mayores[1];
        } else {
            documento = mayores[0];
        }
        console.log("numero mayor");
        i = i + 1;
    } else if (nume == numGlobal) {
        documento = "haz adivinado!!";
        console.log("haz adivinado");
        val = true;
    }
    document.getElementById("i").innerText = 10 - i;
    document.getElementById("documento").innerText = documento;
    if (val) {
        alert("haz ganado. Respuesta correcta: "+ numGlobal);
        window.location.reload();
    } else if (i == 10) {
        alert("haz perdido. El resultado era: "+ numGlobal);
        window.location.reload();
    }
}
