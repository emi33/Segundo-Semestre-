<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://kit.fontawesome.com/6d55038673.js" crossorigin="anonymous"></script>
    <title>Inicio Sesión | Paciente</title>
    <link rel="stylesheet" href="css/sesion/sesion.css">
</head>
<body>
    
    <section>
        <div class="contenedor">
            <form action="#" class="formulario">
                <h2>Iniciar Sesión</h2>
                <h3>Paciente</h3>

                <div class="input-contenedor">
                    <label for="correo">Email</label>
                    <i class="fa-solid fa-envelope"></i>
                    <input type="email" name="email" id="correo" required>
                </div>

                <div class="input-contenedor">
                    <label for="contraseña">Contraseña</label>
                    <i class="fa-solid fa-lock"></i>
                    <input type="password" name="contrasena" id="contraseña" required>
                </div>

                <div class="olvidar">
                    <label for="recordar">
                        <input type="checkbox" id="recordar"> Recordar |
                        <a href="#">Olvidé la contraseña</a>
                    </label>
                </div>

                <div>
                    <button>Acceder</button>

                    <div class="registrar">
                        <p>¿No tiene cuenta? <a href="#">Crear Una</a></p>
                    </div>
                </div>
            </form>
        </div>

    </section>
</body>
</html>