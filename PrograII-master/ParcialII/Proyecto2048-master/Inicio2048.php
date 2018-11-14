<?php 
	session_start();
	$filas=4;
	$columnas=4;
	global $filas, $columnas;
 ?>


<!DOCTYPE html>
<html>
<head lang="es">
	<title>Inicio</title>
	<style type="text/css">
		table{
			background-color: grey;
		}
	</style>
</head>
<body>
	<?php 
		$_SESSION["matriz"]=array();
		$_SESSION["filas"]=$filas;
		$_SESSION["columnas"]=$columnas;
		$_SESSION["act"]=-1;
		for ($i=0; $i < $filas; $i++) { 
			# code...
			for ($j=0; $j <$columnas ; $j++) { 
				# code...

				$_SESSION["matriz"][$i][$j]=0;

			}
		}
			$cont=0;
			do{

				$auxfilas=rand(1,$filas-1);
				$auxcolumnas=rand(1,$filas-1);
	
				if($_SESSION["matriz"][$auxfilas][$auxcolumnas]==0){
					
					$_SESSION["matriz"][$auxfilas][$auxcolumnas]=2;
					$cont++;
					
				}
			}while($cont<2);	
	//	$_SESSION["matriz"][0][0]=8;
	//	$_SESSION["matriz"][1][0]=4;
		//$_SESSION["matriz"][0][2]=2;
			//	$_SESSION["matriz"][0][1]=2;	

			
	header("location:Juego2048.php");
		 ?>

</body>	
</html>