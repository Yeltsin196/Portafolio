<?php 


session_start();

/*borra todas las variables contenidas dentro del array $_SESSION*/
session_unset();

/*Destruye toda la informacion registrada de una sesion asociada al servidor*/
session_destroy();


/*Entonces lo mando al index para el loggeo*/
header("location:index.php");


?>