<?php
$connection = mysqli_connect('localhost', 'root', '');
if(!$connection){
die('No hay conexion a la BD');
}
$id_registro=$_GET['idd'];
mysqli_select_db($connection,'basetorneo');
$sql = sprintf("SELECT * FROM usuario WHERE id='$id_registro'");
$res= mysqli_query($connection, $sql);
$row = mysqli_fetch_assoc($res);
$_SESSION['delete']=$row;

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title>Delete user</title>
</head>
<body>
    <div id=PInicio>
        <h1>USER <?php echo $_SESSION['delete']['usuario']?> DELETE</h1>
        <script>
        alert("Usuario Eliminado");
        </script>
        <?php
            $idd=$_GET['idd'];
            $connection = mysqli_connect('localhost', 'root', '');
            if(!$connection){
            die('No hay conexion a la BD');
            }
         
            mysqli_select_db($connection,'basetorneo');
            
            $sql = sprintf("DELETE FROM usuario WHERE id='$idd'");
            $res= mysqli_query($connection, $sql);
       
            
            $sql = sprintf("DELETE FROM equipo WHERE id_usuario='$idd'");
            $res= mysqli_query($connection, $sql);
            
            $sql = sprintf("DELETE FROM torneo_usuario WHERE id_user='$idd'");
            $res= mysqli_query($connection, $sql);                   
            
            var_dump($res);
          header("refresh:1;url=admin.php");
        ?>
        
    </div>
</body>
</html>