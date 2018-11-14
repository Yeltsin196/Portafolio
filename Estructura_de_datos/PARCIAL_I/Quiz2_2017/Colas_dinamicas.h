#include "NodoO.h"
#include <iostream>

using namespace std;
template<class T>
class Colas_dinamicas
{
	NodoO<T> *frente,*fin;
	public:
		Colas_dinamicas(){
			frente=NULL;
			fin=NULL;
		}
		
		int Agregar(T ele);
		int Eliminar(T &eli);
		void Imprimir();
		void buscar_posicion(int x);
		bool vacia(){
			
			
			return frente==NULL;
		}
	protected:
};

template <class T>
int Colas_dinamicas<T>::Agregar(T ele){
	
	NodoO<T> *nuevo;
	nuevo= new NodoO<T>();
	
	if(!nuevo){  //SI ES NULO CORTESE LOCA
		cout<<"-No hay memoria"<<endl;
		return 0;
	}
	
	//caso 1: frente vacio es cola vacia, se actualiza y tengo una nueva cola que es el nuevo
	
	nuevo->set_info(ele);
	if(!frente){
		frente=nuevo;
	
	
	}
	
	if(fin){
			fin->set_sig(nuevo);
    }	

fin=nuevo;	

	
	return 1;
	
}

template <class T>
int  Colas_dinamicas<T>:: Eliminar(T &eli){
		
	NodoO<T> *aux=frente;
	
	if(aux==NULL){
		
		cout<<endl<<"-Cola Vacia Papurris"<<endl;
		return 0;
	}
	eli=aux->get_info();
	frente = frente->get_sig();
	
	delete aux;

	return 1;
	
}

template <class T>
void Colas_dinamicas<T>::Imprimir(){
	
	NodoO<T> *p=frente;
	
	while(p){// SIGNIFICA QUE IMPRIME SOLO SI HAY VALOR AHI 
		
		cout<<"-Elemento:"<<p->get_info()<<endl;
		p=p->get_sig();
	}
}

template <class T>
void Colas_dinamicas<T>:: buscar_posicion(int x){
	
	NodoO<T> *moverse=frente;//para empezar por el principio
	
	for(int i=0;i<x&&moverse;i++){ // y el moverse no se desborde no sea null
		
		moverse= moverse->get_sig(); // ellos son cajitas interlazadas O--O--O--O me muevo de caja en caja dandole a siguiente hasta conseguir la caja(posicion) que quiero ver y me quedo con esa y la muestro
		
	}
	
	cout<<"\t-Lo que buscabas tiene: "<<moverse->get_info()<<endl;
}

