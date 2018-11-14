<?php
session_start();
$_SESSION["ntorneos"]=null;
$_SESSION["ftorneos"]=null;
$_SESSION['torneoYa']=null;
?>


<!DOCTYPE html>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Styles/style.css">
    <title> Inscripcion de Torneo</title>
</head>
<body>
    <h1>Bienvenido<?php echo" ".$_SESSION['user']['usuario'] ?></h1>
    <section id="PInicio">
    <h1 style="color:white;">Inscribirse en un torneo</h1>
    <?php 
    
    
	 	
    $connection = mysqli_connect('localhost', 'root', '');
 	if(!$connection){
 		die('No hay conexion a la BD');
 	}
 	
 	mysqli_select_db($connection,'basetorneo'); // entro a la base de datos
 	
    $tam=0;
    $res = mysqli_query($connection, "SELECT * FROM torneo_usuario");	
    while ($consulta=mysqli_fetch_array($res)) { // consulta almacena torneo almacenado
 	//	echo $consulta['Torneosname'];
 		if($consulta['id_user']==$_SESSION['user']['id']){
            $_SESSION['torneoYa'][$tam]=$consulta['nombre_torneo'];
            $tam++;
        }
 	}   
  
        
    $torneos='torneo_registro';   
    $res = mysqli_query($connection, "SELECT * FROM $torneos");	// leo la tabla de torneos completa...
	$i=$j=0;
    
 	while ($consulta=mysqli_fetch_array($res)) { // consulta almacena torneo almacenado
 	//	echo $consulta['Torneosname'];
        $agg=true;
        for($i=0;$i<$tam;$i++){
            if($consulta['nombre_torneo']==$_SESSION['torneoYa'][$i]){
                $agg=false;
                break;
            }
        }
        if($agg){
        $_SESSION["ntorneos"][$j]=$consulta["nombre_torneo"];
        $_SESSION["ftorneos"][$j]=$consulta["fecha_realizacion"]; 
        $j++;
        }
         
     // con la i determino el tamaño del array mas tarde
 	}	

        
        
    ?>
    <form  method='post'>

	 		<select name="Torneos">
					
			 		<optgroup label='Selecciona torneo disponible'>
					<?php 
					for ($i=0; $i < count($_SESSION["ntorneos"]); $i++) { 
                        $torneo=$_SESSION['ntorneos'][$i];
						echo "<option value='$torneo'>$torneo</option>";
					}
					 
					 	
					  ?>
					</optgroup>	

				</select>

	 		
			
	 		<input name="Cantidad" type="text" required maxlength="2" placeholder="Cantidad de participantes..">  
	 		<select name="Opcion">
	 		<optgroup label="Seleccionar Nivel del Torneo">
	 			
	 				<option value="Principiante" >Principiante</option>
					<option value="Aficionados">Aficionados</option>
					<option value="Profesionales">Profesionales</option>
					</optgroup>

	 			</select>
					

					<br><br><input class='boton-verde' value='Inscribir' type='submit' id='inscribir' name='inscribir'> 
			</form>  
	   
        
        
        
        
    </section>
    
    <?php
        if(isset($_POST['inscribir']) && isset($_POST['Torneos'])){
            $connection = mysqli_connect('localhost', 'root', '');
            if(!$connection){
            die('No hay conexion a la BD');
            }

         mysqli_select_db($connection,'basetorneo');
        $idd=$_SESSION['user']['id']; 
        $fecha_torneo=null;
        for($k=0;$k<count($_SESSION['ntorneos']);$k++){
            if($_POST['Torneos']==$_SESSION['ntorneos'][$k]){
                $fecha_torneo=$_SESSION['ftorneos'][$k];
            }
        }
        
        if($fecha_torneo!=null){
             $sql= sprintf("INSERT INTO torneo_usuario  (id_user, nombre_torneo, fecha,participantes,nivel) VALUES ('%u','%s','%s', '%u','%s')",$idd,$_POST['Torneos'],$fecha_torneo,$_POST['Cantidad'],$_POST['Opcion']);
            $res = mysqli_query($connection, $sql);
        }    
       

       

            
        mysqli_select_db($connection,'basetorneo'); 
        $res = mysqli_query($connection, "SELECT * FROM torneo_usuario");	
        echo "<h1 id=".'PInicio'.">Torneos para ".$_SESSION['user']['usuario']." </h1><br>";
        while ($consulta=mysqli_fetch_array($res)) { 

            if($_SESSION['user']['id']==$consulta['id_user']){
                $tor=$consulta['nombre_torneo'];
                $ftor=$consulta['fecha'];
                echo "<h1 >Torneo: $tor Fecha : $ftor </h1> "; 
            }





            }
           
        }
    
     
    
    ?>
    <section>
       <form >
        <a class="boton-verde"href="cerrar_sesion.php">Cerrar Sesion</a>   
       </form>
        
    </section>
    
</body>
</html>