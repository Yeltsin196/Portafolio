<?php
session_start();

$connection = mysqli_connect('localhost', 'root', '');
if(!$connection){
die('No hay conexion a la BD');
}
mysqli_select_db($connection,'basetorneo');
$sql = sprintf("SELECT * FROM torneo_registro");
$res= mysqli_query($connection, $sql);




$_SESSION['torneos_consulta']=array();
$i=0;
if(mysqli_num_rows($res)>0){
    while($row = mysqli_fetch_assoc($res)) {
        $_SESSION['torneos_consulta'][$i++]=$row['nombre_torneo'];
    }
    
}



?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Ver Torneos</title>
    <link rel="stylesheet" href="Styles/style.css">
</head>
<body>
    <h1>Torneos</h1>
    <section id=PInicio>
                       
        <?php
        echo "<form action='' method='post'>";
        echo "<fieldset>";
             echo"  <label for='Torneos'>Torneos</label><br>";
            	echo "<select name='Torneos'>";	
			 		echo "<optgroup label='Selecciona torneo disponible'>";
                    
                    for($i=0;$i<count($_SESSION['torneos_consulta']);$i++){
                     $aux=$_SESSION['torneos_consulta'][$i];
                        echo "<option value='$aux'>$aux</option>";
                        
                    }
					echo "</optgroup>";	

				echo "</select>";
            
       echo " </fieldset>";
        echo "<input type='submit'' class='boton-verde' value='Consultar' name='Consultar' id='Consultar'>";
       echo "</form>";
        ?>
    </section>
    <?php
        if(isset($_POST['Consultar'])){
            echo "<h1>";
                echo $_POST["Torneos"];
            echo  "</h1>";
           $connection = mysqli_connect('localhost', 'root', '');
           if(!$connection){
           die('No hay conexion a la BD');
            }
            mysqli_select_db($connection,'basetorneo');
            $nombre_torneo_consulta=$_POST["Torneos"];
            $sql = sprintf("SELECT * FROM torneo_usuario WHERE nombre_torneo='$nombre_torneo_consulta'");
            $res= mysqli_query($connection, $sql);
          
            if(mysqli_num_rows($res)>0){
                
                      
                echo "<br><br><div id='PInicio2'>";
                echo "<table border=1>";
                echo "<tr>";
                echo "<td>TORNEO </td>";               
                echo "<td>CATEGORIA </td>";
                echo "<td>NOMBRE DE EQUIPO </td>";
                echo "<td>PARTICIPANTES </td>";
                echo "<td>ACCIONES</td>";
                echo"</tr>";
                while( $row = mysqli_fetch_assoc($res)){
                    echo "<tr>";
                    echo "<td>" . $row["nombre_torneo"]."</td>";
                    echo "<td>" . $row["nivel"]."</td>";
                    $idd=$row['id_user'];
                    $sql2 = sprintf("SELECT * FROM equipo WHERE id_usuario='$idd' LIMIT 1");
                    $res2= mysqli_query($connection, $sql2);
                    $rowx = mysqli_fetch_assoc($res2);
                    echo "<td>" . $rowx["nombre"]."</td>";
                    echo "<td>" . $row["participantes"]."</td>";
                    echo "<td>";
                    echo "<a style='background-color:green;color:white;border-radius:3px;font-size:1.5rem'href='editar-registro.php?idd=$idd'>editar</a><br><a style='background-color:red;color:white;border-radius:3px;font-size:1.5rem'href='delete.php?idd=$idd'>eliminar</a>";    
                    echo "</td>";
                    echo "</tr>";
                }
                
                
                echo "</table>"; 
                echo "</div>";
            }
              echo "<form>";
              echo "<br><a class='boton-verde' href='editar-torneo.php?nombre=$nombre_torneo_consulta'>Editar Torneo</a>";
              echo "<br><a class='boton-rojo' href='eliminar-torneo.php?nombre=$nombre_torneo_consulta'>Eliminar Torneo</a>";
            echo "</form>";
        }
    
    ?>
    
    <?php
        
    ?>
    
    <form >
        <a class="boton-azul" href="admin.php">Volver</a>
    </form>
    
</body>
</html>