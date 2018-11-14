<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title>ver Registros</title>
</head>
<body>
    <?php
        
            
        echo"<section>";
        $connection = mysqli_connect('localhost', 'root', '');
        if(!$connection){
            die('No hay conexion a la BD');
        }
        echo "<h1>Equipos Inscritos</h1>";
        echo "<form id='PInicio2'>";
        echo "<table border=1>";
        mysqli_select_db($connection,'basetorneo');
        $sql = sprintf("SELECT * FROM usuario");
        $res= mysqli_query($connection, $sql);
        echo "<tr>";
        echo "<td>NOMBRE DE USUARIO </td>";               
        echo "<td>CONTRASEÑA </td>";
        echo "<td>NOMBRE DE EQUIPO </td>";
        echo "<td>NOMBRE CORTO </td>";
        echo "<td>FECHA DE CREACION </td>";
        echo "<td>DIRECCION </td>";
        echo "<td>CORREO</td>";
        echo "<td>SITIO WEB</td>";
        echo"</tr>";
        if (mysqli_num_rows($res) > 0) {
            while($row = mysqli_fetch_assoc($res)) {
                echo "<tr>";
                echo "<td>" . $row["usuario"]."</td>";
                echo "<td>" . $row["contra"]. "</td>";
                
                $b=$row['id'];
                
                $sql2= sprintf("SELECT * FROM equipo WHERE id_usuario='$b'");
                $res2=mysqli_query($connection, $sql2);
                if(mysqli_num_rows($res2)>0){
                    while($row2=mysqli_fetch_assoc($res2)){
                         echo "<td>" . $row2["nombre"]."</td>";
                         echo "<td>" . $row2["nombre_corto"]."</td>";
                         echo "<td>" . $row2["fecha"]."</td>";
                         echo "<td>" . $row2["direccion"]."</td>";
                         echo "<td>" . $row2["correo"]."</td>";
                         echo "<td>" . $row2["web"]."</td>";
                         echo "<td>";
                         echo "<a style='background-color:green;color:white;border-radius:3px;font-size:1.5rem'href='editar-registro.php?idd=$b'>editar</a><br><a style='background-color:red;color:white;border-radius:3px;font-size:1.5rem'href='delete.php?idd=$b'>eliminar</a>";   
                        echo "</td>";
                        
                    }
                }
                echo"</tr>";
            }
        echo"</form>";    
        }else{
        echo "0 results";
        }
        
        echo "</table>";
        
        echo"</section>";
        
    
    ?>
    <form>
        <a class="boton-verde" href="admin.php">Volver</a>
    </form>
</body>
</html>