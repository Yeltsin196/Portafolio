<?php
session_start();
$id_registro=$_GET['idd'];
$_SESSION['usuario']=null;
$_SESSION['equipo']=null;
$connection = mysqli_connect('localhost', 'root', '');
if(!$connection){
die('No hay conexion a la BD');
}
mysqli_select_db($connection,'basetorneo');
$sql = sprintf("SELECT * FROM equipo WHERE id_usuario='$id_registro'");
$res= mysqli_query($connection, $sql);
$row = mysqli_fetch_assoc($res);
$_SESSION['equipo']=$row;

$sql = sprintf("SELECT * FROM usuario WHERE id='$id_registro'");
$res= mysqli_query($connection, $sql);
$row2 =mysqli_fetch_assoc($res);
$_SESSION['usuario']=$row2;

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Editar</title>
    <link rel="stylesheet" href="Styles/style.css">
</head>
<body>
    <h1>Editar Equipo</h1>
    <div>
    <form action="" method="post">
           <section id="PInicio">
                
                <legend>Datos del Equipo</legend><br>
                <div>
                   <label id= "LJ" for="nombre">Nombre</label><br>
                    <input value="<?php echo $_SESSION['equipo']['nombre']?>"name="nombre" id="nombre" type="text" required placeholder="Ingrese nombre...">
                </div>
                <div>
                   <label id= "LJ" for="nombre_corto">Nombre Corto</label><br>
                    <input value="<?php echo $_SESSION['equipo']['nombre_corto']?>"name="nombre_corto" id="nombre_corto" type="text" required placeholder="Ingrese nombre corto...">
                </div>
                 <div>
                   <label id= "LJ" for="fecha">Fecha de Creacion</label><br>
                    <input value="<?php echo $_SESSION['equipo']['fecha']?>"name="fecha" id="fecha" type="date" required>
                </div>
                 <div>
                   <label id= "LJ" for="direccion">Direccion</label><br>
                    <input value="<?php echo $_SESSION['equipo']['direccion']?>" name="direccion" id="direccion" type="text" placeholder="Opcional">
                </div>
                 <div>
                   <label id= "LJ" for="correo">Correo</label><br>
                    <input value="<?php echo $_SESSION['equipo']['correo']?>" name="correo" id="correo" type="email" required placeholder="example@example.com">
                </div>
                 <div>
                   <label id= "LJ" for="web">Sitio Web</label><br>
                    <input value="<?php echo $_SESSION['equipo']['web']?>" name="web" id="web" type="text" required placeholder="example.com">
                </div>
                 <div>
                   <label id= "LJ" for="usuario">Usuario</label><br>
                    <input  value="<?php echo $_SESSION['usuario']['usuario']?>"name="usuario" Ud="usuario" Uype="text" required placeholder="Ingrese Usuario...">
                </div>
                 <div>
                   <label id= "LJ" for="contra">Contraseña</label><br>
                    <input name="contra" id="contra" type="password" required placeholder="Ingrese Contraseña...">
                </div>
                     <br><br><input class="boton-verde" value="Guardar" type="submit" id="Guardar" name="Guardar">
                     
                     
           </section>
    </form>
    <?php
    if(isset($_POST['Guardar'])){
        $connection = mysqli_connect('localhost', 'root', '');
        if(!$connection){
        die('No hay conexion a la BD');
        }
        mysqli_select_db($connection,'basetorneo');
        
        $update_nombre=$_POST['nombre'];
        $update_nc=$_POST['nombre_corto'];
        $update_fecha=$_POST['fecha'];
        $update_direccion=$_POST['direccion'];
        $update_correo=$_POST['correo'];
        $update_web=$_POST['web'];
        $update_usuario=$_POST['usuario'];
        $update_contra=$_POST['contra'];
        
        
        $sql= sprintf("UPDATE equipo SET  nombre='$update_nombre',
        nombre_corto='$update_nc',
        fecha ='$update_fecha',
        direccion='$update_direccion',
        correo='$update_correo',
        web='$update_web'
        WHERE id_usuario='$id_registro'");
        $res=mysqli_query($connection, $sql);
        
        $sql= sprintf("UPDATE usuario SET  usuario='$update_usuario',
        contra='$update_contra'
        WHERE id='$id_registro'");
        $res=mysqli_query($connection, $sql);
        
        echo "<script>";
        echo "alert('Edicion exitosa')";
        echo "</script>";
        header("refresh:0;url=editar-registro.php?idd=$id_registro");
    } 
    ?>


    </div>
    <form >
        <a class="boton-verde" href="admin.php">Volver</a>
    </form>
</body>
</html>