<?php
$connection = mysqli_connect('localhost', 'root', '');
if(!$connection){
die('No hay conexion a la BD');
}
$nombre_torneo=$_GET['nombre'];
mysqli_select_db($connection,'basetorneo');
$sql = sprintf("SELECT * FROM torneo_registro WHERE nombre_torneo='$nombre_torneo'");
$res= mysqli_query($connection, $sql);
$row = mysqli_fetch_assoc($res);
$_SESSION['delete']=$row;

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title>Delete equipor</title>
</head>
<body>
    <div id=PInicio>
        <h1>Equipo <?php echo $_SESSION['delete']['nombre_torneo']?> Eliminado</h1>
        <?php
            $nombre_torneo=$_GET['nombre'];
            $connection = mysqli_connect('localhost', 'root', '');
            if(!$connection){
            die('No hay conexion a la BD');
            }
         
            mysqli_select_db($connection,'basetorneo');
            
            $sql = sprintf("DELETE FROM torneo_registro WHERE nombre_torneo='$nombre_torneo'");
            $res= mysqli_query($connection, $sql);
                   
            $sql = sprintf("DELETE FROM torneo_usuario WHERE nombre_torneo='$nombre_torneo'");
            $res= mysqli_query($connection, $sql);                   
            
         header("refresh:1;url=admin.php");
        ?>
         <script>
        alert("Usuario Eliminado");
        </script>
    </div>
</body>
</html>