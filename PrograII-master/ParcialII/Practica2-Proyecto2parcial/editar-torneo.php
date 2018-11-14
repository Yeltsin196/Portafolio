<?php
$torneo_edit=$_GET['nombre'];
$_SESSION['torneo']=null;
$connection = mysqli_connect('localhost', 'root', '');
if(!$connection){
die('No hay conexion a la BD');
}
mysqli_select_db($connection,'basetorneo');
$sql = sprintf("SELECT * FROM torneo_registro WHERE nombre_torneo='$torneo_edit'");
$res= mysqli_query($connection, $sql);
$row = mysqli_fetch_assoc($res);
$_SESSION['torneo']=$row;
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title>Editar Torneo</title>
</head>
<body>
    <div>
       <form method="post" action="">        
        <fieldset id=PInicio>
             <h1 >Datos del torneo</h1>
                <div>
                   <label id= "LJ" for="torneo">Nombre del Torneo</label><br>
                    <input value="<?php echo $_SESSION['torneo']['nombre_torneo']?>"name="torneo" id="torneo" type="text" required placeholder="Torneo...">
                </div>
                 <div>
                   <br><label id= "LJ" for="fecha">Fecha de Realizacion</label><br>
                    <input value="<?php echo $_SESSION['torneo']['fecha_realizacion']?>" name="fecha" id="fecha" type="date" required>
                </div>
                <br><br><input class="boton-verde" type="submit" value="Guardar" id="Guardar" name= "Guardar">
        </fieldset>
        <a href=""></a>
        </form>

    </div>
    <?php
        if(isset($_POST['Guardar'])){
            $nombre_torneo =filter_input(INPUT_POST, 'torneo', FILTER_SANITIZE_STRING);
            $fecha = filter_input( INPUT_POST, 'fecha', FILTER_SANITIZE_STRING);        
            
            $connection = mysqli_connect('localhost', 'root', '');
                if(!$connection){
                    die('No hay conexion a la BD');
                }
            //SELECCION DE LA BASE DE DATOS
                mysqli_select_db($connection,'basetorneo');                
                $sql= sprintf("UPDATE torneo_registro SET nombre_torneo='$nombre_torneo',fecha_realizacion='$fecha' WHERE nombre_torneo='$torneo_edit'" );
                $res = mysqli_query($connection, $sql);
                
                $sql = sprintf("UPDATE torneo_usuario SET nombre_torneo='$nombre_torneo' WHERE nombre_torneo='$torneo_edit'");
                $res= mysqli_query($connection, $sql);
        
                if($res){
                    echo "<script>";
                    echo "alert('Edicion exitosa')";
                    echo "</script>";
                    header("refresh:0;url=editar-torneo.php?nombre=$nombre_torneo");
                }
            
        }
    
    ?>
    <form >
    <br>    <a class="boton-azul" href="admin.php">Volver</a>
    </form>
    
</body>
</html>