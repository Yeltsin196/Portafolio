/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica1_2018;
import java.io.*;
import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) throws IOException {
        
         
        
         Principal p=  new Principal();
         String [] correccion = null ;
         
          String [] corregir;
            BufferedReader archivo_texto = new BufferedReader(new FileReader("archivo.txt"));
             String palabra_linea="";
       for(int i=0;i<p.leer_cantlineas();i++){
           // p.leer_archivo(i);
           
             if(i>0){
               if(i%2!=0){
                   
                    palabra_linea = archivo_texto.readLine();
                    if(palabra_linea!=null){
                     correccion= palabra_linea.split(" "); 
                     
                    }else{
                    }
                  
                

                }else{
                 //vector de palabras para arreglar
                   palabra_linea = archivo_texto.readLine();
                      corregir=palabra_linea.split(" ");
                  
                      if(correccion!=null){
                          int y;
                      for(y=0;y<correccion.length;y++) {
                           String palabra1= correccion[y];
                       
                           for(int j=0;j<corregir.length;j++){
                            String p_corregir= corregir[j];
                           if(palabra1.charAt(0)== p_corregir.charAt(0)){
                 
                               if(palabra1.charAt(palabra1.length()-1) == p_corregir.charAt(p_corregir.length()-1)){
                                
                                   char cadena=0;
                                    int cont_correccion=0, cont_corregir=0;
                                   for(int w=0;w<palabra1.length()-1;w++){
                                      cont_correccion+=palabra1.charAt(w);
                                   }
                                  for(int w=0;w<p_corregir.length()-1;w++){
                                       cont_corregir+=p_corregir.charAt(w);
                                   }
                                   if(cont_correccion==cont_corregir){
                                       corregir[j]=correccion[y];
                                   }
                               }
                             }   
                           }
                           
                       }
                       
                      
                    }
                      for(int w=0;w<correccion.length;w++){
                          String aux=corregir[w];
                          System.out.println(aux);
                        }
               } 
                    
                   }else{
               if(palabra_linea!=null)  palabra_linea = archivo_texto.readLine();
                 
             }
            
       }
   
        
         
      archivo_texto.close();    
    } 
        
         
         
    
    public int leer_cantlineas() throws IOException{
        
        int contador_lineas=0;
        BufferedReader archivo_texto = new BufferedReader(new FileReader("archivo.txt"));
                String palabra_linea = archivo_texto.readLine(); 
                //System.out.println(palabra_linea);
               
             contador_lineas=    Integer.parseInt(palabra_linea)*2;
                archivo_texto.close();
                
                
              return contador_lineas;  
    }
    
}
    

