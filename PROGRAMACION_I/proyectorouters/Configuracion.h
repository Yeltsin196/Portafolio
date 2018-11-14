#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#include <vector>
#include <iostream>
using namespace std;
class Configuracion {
    vector <string> routers;
    vector <string> rutas;
    vector <string> comunicacion;
    
    public:
        Configuracion(){
            routers.push_back("routerA");
            routers.push_back("routerB");
            routers.push_back("routerC");  
            //---------------------------
            rutas.push_back("routerA 40448 Fa0");
            rutas.push_back("routerA 33024 S0");
            rutas.push_back("routerB 33792 S0");
            rutas.push_back("routerB 33024 S1");
            rutas.push_back("routerB 55552 Fa0");
            rutas.push_back("routerC 60672 Fa0");
            rutas.push_back("routerC 33792 S0"); 
            //----------------------------------
            comunicacion.push_back("55592 60926 prueba");
            comunicacion.push_back("60926 55592 prueba recibida satisfactoriamente");
            comunicacion.push_back("40652 55799 Envio de nomina de pago");
            comunicacion.push_back("55720 60887 email de afiliados");
            comunicacion.push_back("60887 40695 Cronograma de actividades");
                                 
        } 
        
        char * getRouter(int n){
            return (char *)routers[n].c_str();
        } 
        char * getRuta(int n){
            return (char *)rutas[n].c_str();
        } 
        char * getComunicaciones(int n){
            return (char *)comunicacion[n].c_str();
        } 
        
        int getCanComunicaciones(){ return comunicacion.size();}
        int getCanRouters(){ return routers.size();}
        int getCanRutas(){ return rutas.size();}
    
      
};


#endif
