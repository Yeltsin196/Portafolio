<?php
session_start();
$nombre = filter_input( INPUT_POST ,'nombre', FILTER_SANITIZE_STRING);
$nombre_corto =filter_input(INPUT_POST, 'nombre_corto', FILTER_SANITIZE_STRING);
$fecha = filter_input( INPUT_POST, 'fecha', FILTER_SANITIZE_STRING);
$direccion = filter_input( INPUT_POST, 'direccion', FILTER_SANITIZE_STRING);
$correo = filter_input( INPUT_POST, 'correo',  FILTER_SANITIZE_STRING);
$web = filter_input( INPUT_POST, 'web',  FILTER_SANITIZE_STRING);
$usuario = filter_input( INPUT_POST, 'usuario',  FILTER_SANITIZE_STRING);
$contra = filter_input( INPUT_POST, 'contra',  FILTER_SANITIZE_STRING);

$connection = mysqli_connect('localhost', 'root', '');
 	if(!$connection){
 		die('No hay conexion a la BD');
 	}
//SELECCION DE LA BASE DE DATOS
 	mysqli_select_db($connection,'basetorneo');

    $exito=false;
    $sql = sprintf("SELECT * FROM usuario WHERE usuario='$usuario' LIMIT 1");
    $res= mysqli_query($connection, $sql);
    if(mysqli_num_rows($res)>0){
        $exito=false;
    }else{
        $exito=true;
    }
    
    if($exito){
        $sql= sprintf("INSERT INTO usuario (usuario,contra,admin) VALUES ('%s','%s','%i')",$usuario,$contra,0);
        $res = mysqli_query($connection, $sql);


        //PREPARAR SENTENCIA SQL
        $sql = sprintf("SELECT * FROM usuario WHERE usuario='$usuario' LIMIT 1");
        $res= mysqli_query($connection, $sql);
    
    
        if(mysqli_num_rows($res)>0){
        $row= mysqli_fetch_assoc($res);
        $id_usuario=$row['id'];     
        $sql =sprintf("INSERT INTO equipo (nombre,nombre_corto,fecha,direccion,correo,web,id_usuario) VALUES ('%s','%s','%s','%s','%s','%s','%u')"
        ,$nombre,$nombre_corto,$fecha,$direccion,$correo,$web,$id_usuario);
        $res = mysqli_query($connection, $sql);
        $exito=true;
        }
        
    }
    
    

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="Styles/style.css">
    <title>Registro</title>
</head>
<body>
    <?php
    if($exito)
    echo " <h1>Registro Exitoso</h1>";
    else
    echo "<h1>Nombre de usuario ya registrado</h1>";
    ?>
    <fieldset id="PInicio">
        <form  action="index.php">
             <input class="boton-verde" type="submit"value="Volver al Menu">
        </form>
         <form  method="post"action="">
             <input class="boton-verde" type="submit"value="Iniciar Sesion">
             <input type="hidden" name="admin" value=0>
        </form>
    </fieldset>
    <?php
    if(isset($_POST['admin'])){
        if($_POST['admin']==1)
        $_SESSION['admin']=1;    
        else
        $_SESSION['admin']=0;
    header("location:sesion.php");
    }

    ?>
   
</body>
</html>