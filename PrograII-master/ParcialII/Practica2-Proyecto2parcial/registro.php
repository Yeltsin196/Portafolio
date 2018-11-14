<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>INICIO</title>
    <link rel="stylesheet" href="Styles/style.css">
</head>
<body>
    <h1>Registro De Equipo</h1>
    <div>
    <form action="registro_base.php" method="post">
           <section id="PInicio">
                
                <legend>Datos del Equipo</legend><br>
                <div>
                   <label id= "LJ" for="nombre">Nombre</label><br>
                    <input name="nombre" id="nombre" type="text" required placeholder="Ingrese nombre...">
                </div>
                <div>
                   <label id= "LJ" for="nombre_corto">Nombre Corto</label><br>
                    <input name="nombre_corto" id="nombre_corto" type="text" required placeholder="Ingrese nombre corto...">
                </div>
                 <div>
                   <label id= "LJ" for="fecha">Fecha de Creacion</label><br>
                    <input name="fecha" id="fecha" type="date" required>
                </div>
                 <div>
                   <label id= "LJ" for="direccion">Direccion</label><br>
                    <input name="direccion" id="direccion" type="text" placeholder="Opcional">
                </div>
                 <div>
                   <label id= "LJ" for="correo">Correo</label><br>
                    <input name="correo" id="correo" type="email" required placeholder="example@example.com">
                </div>
                 <div>
                   <label id= "LJ" for="web">Pagina Web</label><br>
                    <input name="web" id="web" type="text" placeholder="Opcional.com">
                </div>
                 <div>
                   <label id= "LJ" for="usuario">Usuario</label><br>
                    <input name="usuario" Ud="usuario" Uype="text" required placeholder="Ingrese Usuario...">
                </div>
                 <div>
                   <label id= "LJ" for="contra">Contraseña</label><br>
                    <input name="contra" id="contra" type="password" required placeholder="Ingrese Contraseña...">
                </div>
                     <br><br><input class="boton-verde" value="Registrar" type="submit">
                     
           </section>
    </form>
    </div>
      <form >
        <a class="boton-azul" href="index.php">INICIO</a>
    </form>
</body>
</html>