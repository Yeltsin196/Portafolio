<?php
session_start();
$_SESSION['usuario']=null;

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="Styles/style.css">
    <title>Inicio Sesion</title>
</head>
<body>

    <h1>Iniciar Sesion
    <?php
    if($_SESSION['admin']==1)
    echo "(MODO ADMINISTRADOR)";
    ?>
    
    </h1>
    <fieldset id="PInicio">
        <form  method="post" action="">
            <div>
                <label id= "LJ" for="nombre">Usuario: </label><br>
                <input name="nombre"type="text" required >
            </div>

            <div>
                <label id= "LJ" for="contra">Contraseña: </label><br>
                <input name="contra" type="password" required >
            </div>
            <input class="boton-verde" value="Entrar" type="submit" id="Entrar" name="Entrar">
        </form>
    </fieldset>
    
    <?php
    if(isset($_POST['Entrar'])){

        $validacion_nombre=$_POST['nombre'];
        $validacion_contra=$_POST['contra'];
        $connection = mysqli_connect('localhost', 'root', '');
        if(!$connection){
            die('No hay conexion a la BD');
        }
        mysqli_select_db($connection,'basetorneo');
        $sql = sprintf("SELECT * FROM usuario WHERE usuario='$validacion_nombre' LIMIT 1");
        $res= mysqli_query($connection, $sql);

        if (mysqli_num_rows($res) > 0) {
        $row= mysqli_fetch_assoc($res);

            if($row['contra']==$validacion_contra){
                $_SESSION['user']=array();
                $_SESSION['user']=$row;
                
                if($_SESSION['admin']==1){
                    if($row['admin']==1)
                        header("location:admin.php");
                    else
                      echo "<h1>Lo sentimos no eres administrador.</h1>";  
                }else{
                    if($row['admin']==1){
                         echo "<h1>Iniciaste sesion con una cuenta admin, te enviaremos a la seccion admin en un momento.</h1>"; 
                        header("Refresh:4;url=admin.php");
                    }else{
                        header("location:inscripcion_torneo.php");
                    }
                   
                }
                
            }
            else{
               echo "<h1>Contraseña invalida.</h1>"; 
            }
            
        } else {
            echo "<h1>Usuario o contraseña invalida</h1>";
        }
        
        


    }
    

    ?>

    <fieldset id="PInicio">
        <a style="color:white;" href="registro.php">No tienes cuenta? Registrate ahora</a><br><br>
        <a style="color:white;" href="index.php">INICIO</a>
    </fieldset>



</body>
</html>