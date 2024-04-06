<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Salud Programada</title>
    <!-- CSS -->
    <link rel="stylesheet" href="css/index/estilos.css">
    <link rel="stylesheet" href="css/index/navs.css">
    <link rel="stylesheet" href="css/index/precios.css">
    <link rel="stylesheet" href="css/index/contacto.css">
    <!-- Favicon -->
    <link rel="shortcut icon" href="Imagenes/SP.ico" type="image/x-icon">
    <!-- Fuentes de Google -->
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Salsa&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=League+Spartan:wght@500;600;700&family=Philosopher:ital,wght@0,400;0,700;1,400&display=swap" rel="stylesheet">
    <!-- Iconos -->
    <script src="https://kit.fontawesome.com/6d55038673.js" crossorigin="anonymous"></script>
</head>
<body>

    <header class="header">
        
        <a href="index.php" class="header__logo"  title="Inicio">
            <img src="Imagenes/logo.png" alt="Logo" class="header__img">
            <p class="header__paragraph">Fulbo</p>
        </a>

        <nav class="nav">
            <ul class="nav__ul">
                <li class="nav__li">
                    <a href="#" class="nav__links">Iniciar Sesión <i class="fa-solid fa-arrow-down"></i></a>
                    <ul class="dropdown">
                        <li><a href="sesion_paciente.php" class="nav__links nav__links--item">Paciente</a></li>
                        <li><a href="#" class="nav__links nav__links--item">Doctor</a></li>
                        <li><a href="#" class="nav__links nav__links--item">Administrador</a></li>
                    </ul>
                </li>
                <li class="nav__li"><a href="#" class="nav__links hero__cta">Registro</a></li>
                <li class="nav__li"><a href="#nosotros" class="nav__links">Nosotros</a></li>
                <li class="nav__li"><a href="#precios" class="nav__links">Precios</a></li>
                <li class="nav__li"><a href="#contacto" class="nav__links">Contacto</a></li>
            </ul>
        </nav>
        
    </header>

    <!-- Registro -->
    <section class="modal">
        <div class="modal__container">
            <a href="#" class="modal__close">X</a>
            <section class="form-register">
                <h4>Formulario Registro</h4>
                <form action="">
                    <label for="cuil">Cuil
                        <div class="controls">
                            <i class="fa-solid fa-pen-to-square"></i>
                            <input class="placeholder" type="text" name="cuil" id="cuil" placeholder="Ingrese su Cuil (Sin guion y sin espacio)">
                        </div>
                    </label>
                    <label for="nombres">Nombre
                        <div class="controls">
                            <i class="fa-solid fa-person"></i>
                            <input class="placeholder" type="text" name="nombres" id="nombres" placeholder="Ingrese su Nombre/s">
                        </div>
                    </label>
                    <label for="apellidos">Apellido
                        <div class="controls">
                            <i class="fa-solid fa-person"></i>
                            <input class="placeholder" type="text" name="apellidos" id="apellidos" placeholder="Ingrese su Apellido/s">
                        </div>
                        
                    </label>
                    <label for="correo">Correo
                        <div class="controls">
                            <i class="fa-solid fa-envelope"></i>
                            <input class="placeholder" type="email" name="correo" id="correo" placeholder="Ingrese su Correo">
                        </div>
                        
                    </label>
                    <label for="fechanacimiento">Fecha Nacimiento
                        <div class="controls">
                            <i class="fa-solid fa-calendar-days"></i>
                            <input class="placeholder" type="date" name="fechanacimiento" id="fechanacimiento" placeholder="Ingrese su fecha de nacimiento">
                        </div>
                        
                    </label>
                    <label for="contrasena">Contraseña
                        <div class="controls">
                            <i class="fa-solid fa-lock"></i>
                            <input class="placeholder" type="password" name="contrasena" id="contrasena" placeholder="Ingrese su Contraseña">
                        </div>
                        
                    </label>
                    <input type="checkbox" name="terminos" id="terminos" required><p>Estoy de acuerdo con <a href="#">Terminos y Condiciones</a></p>
                    <input class="botons" type="submit" value="Registrar">
                </form>
              </section>
        </div>
    </section>

    <!-- Principal -->
    <section class="section">

        <div class="section__texto">
            <p class="section__paragraph1">Nunca fue tan fácil pedir un turno</p>
            <h1 class="section__title"><em>Salud Programada</em></h1>
            <p class="section__paragraph2">"Tu Bienestar, Nuestra Prioridad"</p>
        </div>
        
        <img src="Imagenes/img3.avif" alt="logo principal" class="section__img">

    </section>

    <!-- Nosotros -->
    <section class="seccionNosotros" id="nosotros">

        <h1 class="titulo">Nosotros</h1>

        <div class="contenedornosotros">
            <div class="contenedornosotros__texto">
                <h2>Bienvenido a nuestro servicio de turnos online</h2>
                <p>Somos SaludProgramada, y estamos comprometidos a facilitar el proceso de programar turnos a través de nuestra plataforma en línea. Con 1 año de experiencia, hemos trabajado para hacer que la gestión de turnos sea simple y eficiente para nuestros usuarios.</p>
                <p>En SaludProgramada, comprendemos la importancia de su tiempo y queremos ofrecerle una solución conveniente para programar sus turnos de manera fácil y rápida. Nuestra plataforma segura y fácil de usar le permite reservar turnos desde la comodidad de su hogar o cualquier lugar con acceso a Internet.</p>
                <p>¡Gracias por elegirnos para sus necesidades de turnos online! Si tiene alguna pregunta o comentario, no dude en ponerse en contacto con nuestro equipo de soporte.</p>
            </div>
            <div class="contenedornosotros__video">
                <iframe src="https://drive.google.com/file/d/122wfLdJmASALwY_eZnwHQrdpbX1dmda4/preview" width="640" height="480" allow="autoplay"></iframe>
            </div>
        </div>

        <div class="contenedornosotros__informacion">
            <div class="contenedornosotros__info">
                <h1>Datos de la empresa</h1>
                <p>SaludProgramada</p>
                <p>20-42712790-8</p>
                <p>Domicilio: Avenida Siempreviva al 123</p>
             </div>
            <div class="contenedornosotros__info">
                <h1>Protección de datos personales</h1>
                <p>Política de Privacidad de SaludProgramada</p>
                <a href="Privacy.pdf" target="_blanck"><button class="botonnosotros">Política de Privacidad</button></a>
             </div>
            <div class="contenedornosotros__info">
                <h1>Actualizaciones de términos y condiciones</h1>
                <p>Política de Privacidad de SaludProgramada</p>
                <p>Cualquier cambio en los Términos y Condiciones será notificado con 30 días de antelación</p>
                <a href="TermsNCond.pdf" target="_blank"><button class="botonnosotros">Términos y Condiciones</button></a>
            </div>
        </div>
    </section>

    <!-- Precios -->
    <section class="seccionPrecios" id="precios">
        
        <h1 class="titulo">Planes para clientes y empresas</h1>

        <div class="contenedor">
            <div class="contenedor__cliente">
                <div class="cliente__plan">
                    <h2 class="cliente__titulo">Plan Gratuito</h2>
                    <p class="cliente_parrafo1">(con anuncios)</p>
                    <p class="cliente__parrado2">AR $0 / mes</p>
                </div>

                <div class="cliente__plan">
                    <h2 class="cliente__titulo">Plan Premium</h2>
                    <p class="cliente_parrafo1">(con anuncios)</p>
                    <p class="cliente__parrado2">AR $1500 / mes</p>
                </div>

                <button class="boton">Contratar</button>
            </div>

            <div class="contenedor__empresa">

                <div class="cliente__plan plan__empresa1">
                    <h2 class="cliente__titulo">Empresarial 1</h2>
                    <p class="cliente_parrafo1">(Capacidad 1 Gb hosting)</p>
                    <p class="cliente__parrado2">AR $5500 / mes</p>
                </div>

                <div class="cliente__plan plan__empresa2">
                    <h2 class="cliente__titulo">Empresarial 2</h2>
                    <p class="cliente_parrafo1">(Capacidad 5 Gb hosting)</p>
                    <p class="cliente__parrado2">AR $8999 / mes</p>
                </div>

                <div class="cliente__plan plan__empresa3">
                    <h2 class="cliente__titulo">Empresarial 3</h2>
                    <p class="cliente_parrafo1">(Capacidad 15 Gb hosting)</p>
                    <p class="cliente__parrado2">AR $11999 / mes</p>
                </div>

                <div class="cliente__plan plan__empresa4">
                    <h2 class="cliente__titulo">Empresarial 1</h2>
                    <p class="cliente_parrafo1">(Capacidad 50 Gb hosting)</p>
                    <p class="cliente__parrado2">AR $14999 / mes</p>
                </div>

                <button class="boton boton--empresa">Contactenos</button>
            </div>
        </div>

    </section>

    <!-- Contacto -->
    <section class="seccionContacto" id="contacto">

        <div class="contacto1">
            <div class="contacto1__info">
                <div>
                    <h1 class="contacto1__titulo1">Contáctenos</h1>
                    <p class="contacto1__parrafo">Para iniciar un ticket de reclamo contactar a <br> soporte@saludprogramada.com en horario de atención</p>
                </div>
                <div>
                    <h2 class="contacto1__titulo2">Ubicación</h2>
                    <p class="contacto1__parrafo">Defensa 200-2, San Martin, Mendoza</p>
                    <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d1987.5467144694592!2d-68.48011499871909!3d-33.092206736039245!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x967e42e18d0efccb%3A0x802cefb5e43893f2!2sCentro%20Universitario%20del%20Este!5e0!3m2!1ses!2sar!4v1704668168197!5m2!1ses!2sar" allowfullscreen="" loading="lazy" referrerpolicy="no-referrer-when-downgrade" class="iframe"></iframe>
                </div>
            </div>
            <div class="contacto1__foto">
                <img src="Imagenes/img1.jpg" alt="Imagen Médico" class="contacto1__img">
            </div>
        </div>
        
        <div class="contacto2">
            <div class="contacto2__items">
                <h2 class="contacto2__titulo">Llámenos</h2>
                
                <p class="contacto2__parrafo">WhatsApp: 2615975657</p>
            </div>
            <div class="contacto2__items">
                <h2 class="contacto2__titulo">Email</h2>
                <p class="contacto2__parrafo">contacto@saludprogramada.com</p>
            </div>
            <div class="contacto2__items">
                <h2 class="contacto2__titulo">Horario de atención</h2>
                <p class="contacto2__parrafo">lunes-viernes: 8:00hs-22:00hs <br>
                sabado-domingo: 8:00hs-19:00hs
                </p>
            </div>
        </div>
    </section>
    
    <!-- Footer -->
    <footer class="footer">

        <section class="footer__social">
            <a href="#" class="footer__link"><img src="Imagenes/facebook.svg" alt="facebook" class="footer__link"></a>
            <a href="#" class="footer__link"><img src="Imagenes/twitter.svg" alt="twitter"></a>
            <a href="#" class="footer__link"><img src="Imagenes/instagram.svg" alt="instagram"></a>
            <a href="#" class="footer__link"><img src="Imagenes/linkedin.svg" alt="linkedin"></a>
            <a href="https://github.com/emi33" target="_blank" class="footer__link"><img src="Imagenes/github.svg" alt="github"></a>
        </section>

        <p class="footer__paragraph">Derechos de autor © 2023. SaludProgramada.</p>

    </footer>

    <script src="js/main.js"></script>
</body>
</html>