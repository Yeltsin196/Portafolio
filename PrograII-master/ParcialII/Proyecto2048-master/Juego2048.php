<?php session_start();
	$fil=$_SESSION["filas"];
	$col=$_SESSION["columnas"];
	$act = $_SESSION["act"];
	global $fil, $col, $act;
	
 ?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Juego</title>
	<link rel="stylesheet" type="text/css" href="estilos.css">
</head>
<body>
	<h1>2048</h1>
	<?php 


		 ?>
		<script src="Jquery/jquery-3.2.1.min.js"></script><!--  Necesario para detectar teclado -->
				<script language="JavaScript" type="text/javascript">
				$(document).ready(function(){
				    //$("#target").
				  $(document).keypress(function(e) {
				  console.log( "Handler for .keypress() called." );
				// alert("Pulsaste la tecla con código: "+e.which);
 
 		if(e.which==97){ // a izquierda

 		  document.location="Juego2048.php?act="+'0';


 		}  else if(e.which==100){ // D derecha
 			  document.location="Juego2048.php?act="+'1';
 		} else if(e.which==119){ // W arriba
 			  document.location="Juego2048.php?act="+'2';
 		} else if(e.which==115){ // s abajo
 			  document.location="Juego2048.php?act="+'3';
 		}
      
      
      
});
    
    /*para evitar que php siga leyendo movimientos del get*/
    $(document).keyup(function(e){ //cuando se deja de presionar una tecla
        
        
       //  document.matriz.action= 'Juego2048.php?act'+'0';
     //  document.location="Juego2048.php?act="+'0';
        
    });
        
        
        
    
    
})
</script>
        
        
    <?php 
    		function change_rigth($x, $y){ //derecha
    		if($y+1<$_SESSION["filas"]){
    			if($_SESSION["matriz"][$x][$y+1]==0){
 					$_SESSION["matriz"][$x][$y+1]= $_SESSION["matriz"][$x][$y];
			
    				 $_SESSION["matriz"][$x][$y]=0;
    				 change_rigth($x,$y+1);
    				

	    	 	}else {
    					
    					if($_SESSION["matriz"][$x][$y+1]==$_SESSION["matriz"][$x][$y]){

						
    						  change_rigth($x,$y+1);
    							 $_SESSION["matriz"][$x][$y+1]+=$_SESSION["matriz"][$x][$y];
    							$_SESSION["matriz"][$x][$y]=0;

    					}			

    				}
    			}
    		}

    		function change_left($x, $y){ //izquierda
    		if($y-1>=0){
    			if($_SESSION["matriz"][$x][$y-1]==0){
 					$_SESSION["matriz"][$x][$y-1]= $_SESSION["matriz"][$x][$y];
			
    				 $_SESSION["matriz"][$x][$y]=0;
    				 change_left($x,$y-1);
    				

	    	 	}else {
    					
    					if($_SESSION["matriz"][$x][$y-1]==$_SESSION["matriz"][$x][$y]){

						
    						 change_left($x,$y-1);
    							 $_SESSION["matriz"][$x][$y-1]+=$_SESSION["matriz"][$x][$y];
    							$_SESSION["matriz"][$x][$y]=0;

    					}			

    				}
    			}
    		}

    		function change_up($x, $y){ // arriba
    		if($x-1>=0){
    			if($_SESSION["matriz"][$x-1][$y]==0){
 					$_SESSION["matriz"][$x-1][$y]= $_SESSION["matriz"][$x][$y];
			
    				 $_SESSION["matriz"][$x][$y]=0;
    				 change_up($x-1,$y);
    				

	    	 	}else {
    					
    					if($_SESSION["matriz"][$x-1][$y]==$_SESSION["matriz"][$x][$y]){

						
    							 change_up($x-1,$y);
    							 $_SESSION["matriz"][$x-1][$y]+=$_SESSION["matriz"][$x][$y];
    							$_SESSION["matriz"][$x][$y]=0;

    					}			

    				}
    			}
    		}

    		function change_down($x, $y){
    		if($x+1<$_SESSION["columnas"]){
    			if($_SESSION["matriz"][$x+1][$y]==0){
 					$_SESSION["matriz"][$x+1][$y]= $_SESSION["matriz"][$x][$y];
			
    				 $_SESSION["matriz"][$x][$y]=0;
    				 change_down($x+1,$y);
    				

	    	 	}else {
    					
    					if($_SESSION["matriz"][$x+1][$y]==$_SESSION["matriz"][$x][$y]){

						
    							 change_down($x+1,$y);
    							 $_SESSION["matriz"][$x+1][$y]+=$_SESSION["matriz"][$x][$y];
    							$_SESSION["matriz"][$x][$y]=0;

    					}			

    				}
    			}
    		}

    	 if(isset($_GET["act"])){
    	 		if($_GET["act"]==0 || $_GET["act"]==1 ||$_GET["act"]==2 ||$_GET["act"]==3 ){
    	 			

    	 			changes($_GET["act"]);
    	 			//go_rigth($x,$y);

    	 		}
    	 }


    	 function changes($tipo){
    	 	
    	 


    	 		if($tipo==1){ // cuando sea presionado para subir
						for ($i=0; $i <$_SESSION["filas"]; $i++) { 
		    	 				# code...
		    	 				for ($j=$_SESSION["columnas"]-1; $j>=0; $j--) { 
		    	 					if($_SESSION["matriz"][$i][$j]!=0){
		    	 					
		    	 						change_rigth($i,$j);

		    	 					}
		    	 				}

		    	 			}
	    	 	}

	    	 	if($tipo==0){ // cuando sea presionado para subir
						for ($i=0; $i <$_SESSION["filas"]; $i++) { 
		    	 				# code...
		    	 				for ($j=$_SESSION["columnas"]-1; $j>=0; $j--) { 
		    	 					if($_SESSION["matriz"][$i][$j]!=0){
		    	 					
		    	 						change_left($i,$j);

		    	 					}
		    	 				}

		    	 			}
	    	 	}



	    	 	if($tipo==3){ // cuando sea presionado la tecla de movimiento hacia abajo caso especial
	    	 		
		    	 		for ($i=$_SESSION["columnas"]-1; $i >=0; $i--) { 
		    	 				# code...
		    	 				for ($j=0; $j <$_SESSION["columnas"]; $j++) { 
		    	 					if($_SESSION["matriz"][$i][$j]!=0){
		    	 					
		    	 						change_down($i,$j);

		    	 					}
		    	 				}

		    	 			}

	    	 	}		
	    	 	if($tipo==2){ // cuando sea presionado para subir
						for ($i=0; $i <$_SESSION["columnas"]; $i++) { 
		    	 				# code...
		    	 				for ($j=0; $j <$_SESSION["columnas"]; $j++) { 
		    	 					if($_SESSION["matriz"][$i][$j]!=0){
		    	 					
		    	 						change_up($i,$j);

		    	 					}
		    	 				}

		    	 			}
	    	 	}




    	}

    	


?>	
	<table align="center">
		
				<?php 
				    	 for ($i=0; $i <$fil ; $i++) { 
							# code...
							for ($j=0; $j < $col; $j++) { 
								# code...
								//echo $_SESSION["matriz"][$i][$j] ." ";
								 echo "<td height='89' width='91'> <img src=".$_SESSION["matriz"][$i][$j].".jpg /></img></td>"; 
							}
							echo "</tr>"; 
							//echo "<br>";
						} 

					
						 $cont=0;
							do{

								$auxfilas=rand(1,$fil-1);
								$auxcolumnas=rand(1,$fil-1);
					
								if($_SESSION["matriz"][$auxfilas][$auxcolumnas]==0){
									
									$_SESSION["matriz"][$auxfilas][$auxcolumnas]=2;
									$cont++;
									
								}
							}while($cont<1);
				     ?>

	</table>
	
    	<center><button type="button" class="boton"><a href="reiniciar2.php">Reiniciar Juego</a></button></center>


</body>
</html>