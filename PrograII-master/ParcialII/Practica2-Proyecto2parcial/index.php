<?php
session_start();
$_SESSION['admin']=null;
?>
<!DOCTYPE html>
<html >
<head>
	<title>Inicio</title>
    <link rel="stylesheet" href="Styles/style.css">
</head>
<body id="Ini" >
    <div >
        <h1 id="Tinicio">Federacion Olimpica Boletos en linea</h1>
        <form  action="registro.php">
             <input class="boton-azul" type="submit"value="REGISTRAR USUARIO">
        </form>
       <form  method="post" action="">
            <input class="boton-azul" type="submit"value="INICIAR SESION">
            <input type="hidden" name="admin" value=0>
       </form>
       <form method ="post" action="">
           <input class="boton-azul" type="submit"value="ADMINISTRADOR">
           <input type="hidden" name="admin" value=1>
       </form>
    </div>
    
    <?php
    if(isset($_POST['admin'])){
        if($_POST['admin']==1){
            $_SESSION['admin']=1;
            header("location:sesion.php");
        }else{
            $_SESSION['admin']=0;
            header("location:sesion.php");
        }
        
    }
    
    
    ?>
	 


</body>
</html>