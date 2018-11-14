<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title>Registrar Torneo</title>
</head>
<body>
    <div>
       <form method="post" action="">        
        <fieldset id=PInicio>
             <h1 >Datos del torneo</h1>
                <div>
                   <label id= "LJ" for="torneo">Nombre del Torneo</label><br>
                    <input name="torneo" id="torneo" type="text" required placeholder="Torneo...">
                </div>
                 <div>
                   <br><label id= "LJ" for="fecha">Fecha de Realizacion</label><br>
                    <input name="fecha" id="fecha" type="date" required>
                </div>
                <br><br><input class="boton-verde" type="submit" value="registrar" id="registrar" name= "registrar">
        </fieldset>
        <a href=""></a>
        </form>

    </div>
    <?php
        if(isset($_POST['registrar'])){
            $nombre_torneo =filter_input(INPUT_POST, 'torneo', FILTER_SANITIZE_STRING);
            $fecha = filter_input( INPUT_POST, 'fecha', FILTER_SANITIZE_STRING);        
            
            $connection = mysqli_connect('localhost', 'root', '');
                if(!$connection){
                    die('No hay conexion a la BD');
                }
            //SELECCION DE LA BASE DE DATOS
                mysqli_select_db($connection,'basetorneo');
                
            $exito=false;
            $sql=sprintf("SELECT * FROM torneo_registro WHERE nombre_torneo='$nombre_torneo' LIMIT 1");
            $res=mysqli_query($connection, $sql);
            if(mysqli_num_rows($res)>0){
                $exito=false;
                echo "<h1>Nombre de torneo ya registrado</h1>";
            }else{
                $exito=true;
            }
    
            
            if($exito){
                
                $sql= sprintf("INSERT INTO torneo_registro (nombre_torneo,fecha_realizacion) VALUES ('%s','%s')",$nombre_torneo,$fecha);
                $res = mysqli_query($connection, $sql);
                
                if($res){
                    echo" <h1>Registro Exitoso</h1>";
                }
            }
        }
    
    ?>
    <form >
        <a class="boton-azul" href="admin.php">Volver</a>
    </form>
    
</body>
</html>