
$(document).ready(function(){
    
    /*FORMULARIO*/
    
    /*bajar el formulario*/
    $('#panel').click(function(){
    $('#sec_formulario form, section h1').slideDown();
        
       
       /*Cambiar el boton a ser el boton panel-abierto, oculta
       a panel*/
       $(this).slideUp();
       $('#panel-abierto').slideDown();
        
   });

     /*Subir el formulario*/
    $('#panel-abierto').click(function(){
        
       $('#sec_formulario form, section h1').slideUp();
        
       /*Cambiar el boton a ser el boton panel*/
       $(this).slideUp();
       $('#panel').slideDown();
        
    });
    

    
    /*CRÉDITOS*/
    
    
    $('#creditos').click(function(){
    $('.creditos-nombres, .creditos-nombres resultados #titulo').slideDown();
        
       
       /*Cambiar el boton a ser el boton creditos-abierto, oculta
       a creditos*/
       $(this).slideUp();
       $('#creditos-abierto').slideDown();
        
   });

     /*Subir creditos*/
    $('#creditos-abierto').click(function(){
        
       $('.creditos-nombres, .creditos-nombres resultados #titulo').slideUp();
        
       /*Cambiar el boton a ser el boton creditos*/
       $(this).slideUp();
       $('#creditos').slideDown();
        
    });
    
    
    
    
    
    
    
    
    
    
    
});