<?php session_start();
	 $filas = 6;
	$columnas= 6;

	global $filas, $columnas;

	 ?>

<!DOCTYPE html>
<html>
<head>
	<title>Bubble Breaker</title>
</head>
<body>
	<div class="division" align="center">
		
		<?php 
		$_SESSION["filas"]=$filas;
		$_SESSION["columnas"]=$columnas;
		$_SESSION["matriz"]=array();

		for ($i=0; $i < $filas; $i++) { 
			# code...
				for ($j=0; $j < $columnas ; $j++) { 
					# code...	
						$_SESSION["matriz"][$i][$j]=rand(1,5);
					

						        //    echo $_SESSION["matriz"][$i][$j]. " " ; 
						         //     echo "<td height='0' width='0'> <a onclick='cargar(".$i.",".$j.");'> <img src=".$_SESSION["matriz"][$i][$j].".jpg /></img></td>"; 
					            }
					           // echo "<br>";
					        
		}

	//	$_SESSION["matriz"][1][0]=2;
		$_SESSION["matriz"][1][1]=2;
		header("location:juego.php");
		 ?>

	</div>
</body>
</html>