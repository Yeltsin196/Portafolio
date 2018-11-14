<?php
session_start();

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title></title>
</head>
<body>
    <h1 id=PInicio>
    <?php
    echo "User: ". $_SESSION['user']['usuario'];    
    ?></h1>
    <div>
        <fieldset  >
            <h1 style="color:white;">OPCIONES ESPECIALES DE SU CUENTA ADMIN</h1>
            <form action="ver_torneos.php" method="post">
                <br><input class="boton-verde" type="submit" value="Ver Torneos">
            </form>
            <form action="ver-registros.php" method="post">
                <br><input class="boton-verde" type="submit" value="Ver Equipos Inscritos">
            </form>
            
            <form action="registrar_torneo.php">
                <br><input class="boton-verde" type="submit" value="Registrar Torneo">
            </form>
           
            <a class="boton-verde"href="cerrar_sesion.php">Cerrar Sesion</a>   
       
        </fieldset>
        
        
        
    </div>
</body>
</html>