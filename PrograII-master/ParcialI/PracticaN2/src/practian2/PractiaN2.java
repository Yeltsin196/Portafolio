/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practian2;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author Yeltsin
 */
public class PractiaN2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
       
         BufferedReader archivo_texto = new BufferedReader(new FileReader("Archivo.txt"));
         String linea_texto= archivo_texto.readLine();
         while(linea_texto!=null){
             
             System.out.println(linea_texto);
            
             String[] seccionar=linea_texto.split(",");
             //  ArrayList<String> cadenas = new ArrayList<>();
             //  ArrayList<Integer> numeros = new ArrayList<>();
               
               ArrayList<String > cadenas= new ArrayList<>();
                 ArrayList<Integer> numeros= new ArrayList<>();
               
             if(seccionar.length>1){
               
                 for(int i=0;i<seccionar.length;i++){
                     int y=0;
                     char a=' ', b='.';
                     if(seccionar[i].charAt(0)==a){
                         y+=1;
                     }
                     //System.out.println(seccionar[i]);
                      if((seccionar[i].charAt(y)>=65 ||seccionar[i].charAt(y)>=97)  && (seccionar[i].charAt(y)<=90 || seccionar[i].charAt(y)<=122) ){
                            char aux2;
                              String quitarspace="";
                          if(seccionar[i].charAt(0)==' '){
                          
                              for(int x=0;x<seccionar[i].length();x++){
                                  if(x!=0){
                                      aux2=seccionar[i].charAt(x);
                                     quitarspace+=aux2;
                                  }
                                  
                              
                              } 
                              seccionar[i]=quitarspace;
                              quitarspace="";
                          }
                       //   System.out.println(seccionar[i].charAt(seccionar[i].length()));
                          if(seccionar[i].charAt(seccionar[i].length()-1)=='.'){
                              for(int x=0;x<seccionar[i].length();x++){
                                  if(x<seccionar[i].length()-1){
                                      aux2=seccionar[i].charAt(x);
                                     quitarspace+=aux2;
                                  }
                                 
                              }
                              seccionar[i]=quitarspace;
                          } 
                      
                          cadenas.add(seccionar[i]);
                           
                          
                      }else if(seccionar[i].charAt(y)>=48 || seccionar[i].charAt(y)<=57){
                         
                           String[] auxsplit;
                            int convertir=0;
                        if(seccionar[i].charAt(0)==' '){
                           
                                 String [] auxsplit2= seccionar[i].split(" ");
                                  char aux2;
                                 String quitarspace="";
                                 for(int x=0;x<seccionar[i].length();x++){
                                     if(x!=0){
                                         aux2= seccionar[i].charAt(x);
                                         quitarspace+=aux2;
                                     }
                                 }
                               seccionar[i]=quitarspace; 
                              //  System.out.println(quitarspace);
                              
                            y--;
                          }
                          
                          
                          if(seccionar[i].charAt(seccionar[i].length()-1)=='.'){
                               char aux2;
                                 String quitarpunto="";
                                 for(int x=0;x<seccionar[i].length();x++){
                                     if(x!=seccionar[i].length()-1){
                                         aux2= seccionar[i].charAt(x);
                                         quitarpunto+=aux2;
                                     }
                                 }
                              //   System.out.println(quitarpunto);
                                 seccionar[i]=quitarpunto;
                          }
                          if(seccionar[i].charAt(y)=='-' ){
                               auxsplit= seccionar[i].split("-");
                          //    System.out.println(auxsplit[1]);
                              seccionar[i]=auxsplit[1];
                           //   System.out.println(Integer.parseInt(seccionar[i])*-1);
                            numeros.add(Integer.parseInt(seccionar[i])*-1);
                             
                          }else if(seccionar[i].charAt(0)>=48 || seccionar[i].charAt(seccionar[i].length())<=57){
                         //   System.out.println(seccionar[i]);
                           numeros.add(Integer.parseInt(seccionar[i]));   
                          }
                          
                      }
                      
                      
                      
                 }
                        int [] numeros1= new int[numeros.size()];
                        String [] cadenas1= new String[cadenas.size()];
                        
                            for(int x = 0; x< numeros.size(); x++) {
                                numeros1[x]= numeros.get(x);
                             }
                            
                        for(int x = 0; x < numeros1.length - 1; x++)  {
                            for(int y = 0; y < numeros1.length - 1; y++) {

                               if (numeros1[y] > numeros1[y + 1]){

                                   int tmp = numeros1[y+1];

                                   numeros1[y+1] = numeros1[y];

                                   numeros1[y] = tmp;
                                }
                            }
                        }   
                        ArrayList<Integer> numeros2= new ArrayList<>();
                        for(int x=0;x<numeros1.length;x++){
                        numeros2.add(numeros1[x]);
                            System.out.println(numeros2.get(x));
                        }
                        numeros=numeros2;
                        
                        
                        for(int x=0;x<cadenas.size();x++){
                            cadenas1[x]= cadenas.get(x);
                           //  System.out.println(cadenas.get(x));
                        }
                        
                       for(int x = 0; x < cadenas1.length - 1; x++)  {
                            for(int y = 0; y < cadenas1.length - 1; y++) {
                                
                               if (Character.toLowerCase(cadenas1[y].charAt(0)) > Character.toLowerCase(cadenas1[y+1].charAt(0))){

                                   String tmp = cadenas1[y+1];

                                   cadenas1[y+1] = cadenas1[y];

                                  cadenas1[y] = tmp;
                                }
                            }
                        } 
                       ArrayList<String> cadenas2= new ArrayList<>();
                        for(int x=0;x<cadenas1.length;x++){
                        cadenas2.add(cadenas1[x]);
                            System.out.println(cadenas2.get(x));
                        }
                       
                        
           }
             linea_texto= archivo_texto.readLine();
         }
         archivo_texto.close();
     
           
        
    }
}
    


