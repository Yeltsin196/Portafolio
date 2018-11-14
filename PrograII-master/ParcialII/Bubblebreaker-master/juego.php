<?php 
session_start();
	
	$fil=$_SESSION["filas"];
	$col=$_SESSION["columnas"];
	
	global $fil, $col, $vacio;
 ?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Juego Bubble Breaker</title>
	<style type="text/css">
		

						.boton{
											margin-top: 10px;
										   	
										    background-color: #ED9CE0;
										   
										    display: inline-block;
										    font-weight: 400;
										    line-height: 1.25;
										    text-align: center;
										    vertical-align: middle;
										    user-select: none;
										   
										  /*  padding: .5rem 1rem;*/
										    font-size: 1rem;
										    border-radius: .25rem;
										    display:block;

										  
										  	border: 4px solid #ED9CE0;
										  	padding: 10px 20px 10px 20px;
										  	border-radius: 5px;

										  	
										
						}
							a{
    
							    text-decoration: none;
							  	 color:#111464;
							  	 font:bold 20px verdana;
							}

					button:hover{
					    
					    cursor: pointer;
					}

					body{
						background-color:  #EAF1EF;
					}

	</style>
</head>
<body>

	<div class="division" align="center">
		
		<?php 
			if(isset($_GET["fil"]) && isset($_GET["col"])){
			


				function b_up($i, $j, $vacio){

						if($i-1>=0){
							if($_SESSION["matriz"][$i-1][$j]!=$vacio){
								$_SESSION["matriz"][$i][$j]=$_SESSION["matriz"][$i-1][$j];
								$_SESSION["matriz"][$i-1][$j]=$vacio;
								b_up($i-1,$j,$vacio);
							}
										
						}
				}
				

				function b_reemplazarencaida($vacio){

			
						for ($i=0; $i <$_SESSION["columnas"] ; $i++) { 
							# code...
							for ($j=0; $j <$_SESSION["filas"] ; $j++) { 
								# code...
								if ($_SESSION["matriz"][$i][$j]==$vacio) { // verificar que despues encima de ese 0 haya un numero
									# code...
									b_up($i, $j, $vacio);
									
								}
							}
						}
							

					

				}


				$vacio=6;
				$x=$_GET["fil"];
				$y=$_GET["col"];
		

				function changes_cs($x,$y, $sentinela, $cambio){
					if($y+1<$_SESSION["filas"]){

								if ($_SESSION["matriz"][$x][$y+1]==$sentinela) {

									
									$_SESSION["matriz"][$x][$y+1]=$cambio;
									changes_cs($x,$y+1,$sentinela, $cambio);
								}

					}
					if($y-1>=0){

								if ($_SESSION["matriz"][$x][$y-1]==$sentinela) {

									
									$_SESSION["matriz"][$x][$y-1]=$cambio;
									changes_cs($x,$y-1,$sentinela, $cambio);
								}
					}

					if($x-1>=0){

								if ($_SESSION["matriz"][$x-1][$y]==$sentinela) {

									
									$_SESSION["matriz"][$x-1][$y]=$cambio;
									changes_cs($x-1,$y,$sentinela, $cambio);
								}
					}
					if($x+1<$_SESSION["columnas"]){

								if ($_SESSION["matriz"][$x+1][$y]==$sentinela) {

									
									$_SESSION["matriz"][$x+1][$y]=$cambio;
									changes_cs($x+1,$y,$sentinela, $cambio);
								}
					}
				}

				$cambio=$vacio;
				changes_cs($x,$y,$_SESSION["matriz"][$x][$y], $cambio);
				$_SESSION["matriz"][$x][$y]=$vacio;
				b_reemplazarencaida($vacio);
				
			
			}
		 ?>

		<form action="" method="post" name="matriz">
		
		<table>  


			 <!-- funcion cargar las imagenes  -->

						<?php 	
							for($i=0;$i<$_SESSION["columnas"];$i++){
					                for($j=0;$j<$_SESSION["filas"];$j++){

					           

						           echo "<td height='72' width='68'> <b onclick='cargar(".$i.",".$j.");'> <img src=".$_SESSION["matriz"][$i][$j].".jpg /></img></td>"; 

						            //echo $_SESSION["matriz"][$i][$j]. " " ; 
					                }
					                 echo "</tr>"; 
					              // echo "<br>";
					        }
			                for($i=0;$i<$fil;$i++){
					                for($j=0;$j<$col;$j++){

					           

						                //  echo "<td height='0' width='0'> <a onclick='cargar(".$i.",".$j.");'> <img src=".$_SESSION["matriz"][$i][$j].".jpg /></img></td>"; 

						         //   echo $_SESSION["matriz"][$i][$j]. " " ; 
					                }
					                // echo "</tr>"; 
					              // echo "<br>";
					        }

			             ?>	 	
			  

			
		</table>
	 
		</form>
				<script type="text/javascript">
					function cargar(fila,col){
				//	alert("fil="+fila+" col:"+col);
					document.location="juego.php?fil="+fila+"&col="+col;
				}
				</script>
	<!-- 	<button type="button" class="boton-azul"><b href="index.php">Reiniciar Juego</b></button>	 -->	


	</div>
	<center><button type="button" class="boton"><a href="reiniciar.php">Reiniciar Juego</a></button></center>
</body>
</html>