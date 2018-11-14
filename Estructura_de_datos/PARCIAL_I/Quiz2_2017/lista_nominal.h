#ifndef LISTA_NOMINAL_H
#define LISTA_NOMINAL_H
#include "listaenlazada.h"
class lista_nominal
{
		
	public:
		int codigo;
		lista_enlazada<string> *l1;
		
		lista_nominal();
		lista_nominal(int _codigo, lista_enlazada<string> *l2){
			this->l1=l2;
			this->codigo=_codigo;
		}
		bool operator==(lista_nominal n){
			return ( this->codigo == n.codigo);
		}
		bool operator<(lista_nominal n){
			return ( this->codigo < n.codigo);
		}	
		
		 friend ostream & operator<<(  ostream &os, lista_nominal c ) { 
		 	vector <string > vectores;
              vectores= c.l1->devolver();
               for(int i=0;i<vectores.size();i++){
               	os<<"N= "<<vectores[i]<<endl;
			   }
              return os;
       } 
		
	protected:
};

#endif
