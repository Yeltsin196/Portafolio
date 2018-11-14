#include <iostream>
#include <vector>
using namespace std;


template <class T>
class nodo{

	T	inf;
	nodo<T> *sig;
	
	public:
		nodo(){
			sig=NULL;	
		}
		nodo(T dato){
			inf=dato; sig=NULL;
		}
		void set_inf(T e){
			inf=e;
		}
		void set_sig(nodo<T> *p){
			sig=p;
		}
		
		T get_inf(){
			return inf;
		}
		nodo<T> * get_sig(){
			return sig;
		}
	
};


template <class T>
class lista_enlazada{
	
	
	nodo<T> *cab;
	public: 
	 int tam;
	 int codigo;
	 int *devolver2(){
	 	return codigo;
	 }
	 		lista_enlazada(){
			cab=NULL;
			tam=0;
		}	
	void set_codigo(int _codigo){
		this->codigo=_codigo;
	}	
	int get_tam(){
		return tam;
	}
	int get_codigo();
	int agregar(T ele);
	int eliminar(T &eli);
	void imprimir();
	bool buscar   ( T &bus);
	vector<string> devolver();
};

template <class T>
void lista_enlazada<T>::imprimir(){
	nodo<T > *p= cab;
	while(p!=NULL){
		cout<<p->get_inf()<<endl;
		p=p->get_sig();
	}

}
template<class T>
vector<string> lista_enlazada<T>:: devolver(){
	vector <string> c;
	cout<<cab->get_inf();
	nodo<T > *p= cab;
	while(p!=NULL){
	c.push_back(p->get_inf());
		p=p->get_sig();
	}
		
	return c;
	
}
template<class T>
int lista_enlazada<T>::get_codigo(){
	return codigo;
}
template <class T>
bool lista_enlazada<T>::buscar( T &bus)
{
      nodo<T> *p;
      p=cab;
      while(p!=NULL){
	  //cout<<bus<<endl;
	 	//	cout<<p->get_inf()<<endl;
      	if ( bus==p->get_inf() )
          {
               
           //    bus= p->get_inf();
               return true;
           }
           if(p->get_sig()==NULL){
           	break;
		   }
        p=p->get_sig();
	  }
          
          
      return false;
}
template<class T>
int lista_enlazada<T>::agregar(T ele){

	
	nodo<T> *nue;
	nodo<T> *ant;
	nodo<T> *p;
	nue=new nodo<T>(ele);
	p=cab;
//	cout<<ele<<endl;
	if(buscar(ele)==false){ //falso, pq si no se encuentra se agrega 
//	if(p->get_inf()==NULL)	cout<<"ele"<<p->get_inf();
		while(p!=NULL){
			
			if(nue->get_inf() < p->get_inf()){ //si el nuevo valor es menor q donde apunta p
				
				break;		
			}else{
				ant=p; //toma la direccion anterior antes q cambie p
				p=p->get_sig(); //apunta al siguiente valor de la lista
			}
		}
		
		if(p==cab){ //caso 1: inserccion en cabezera 
			
			nue->set_sig(cab); 
			cab=nue; //cabezera es el inicio
			tam++;
		}else{ //caso 2: inserccion en lugar != cab
			
			nue->set_sig(p);
			ant->set_sig(nue);
			tam++;
		}	
	}else{
		return 0;
	}
	
	return 1;


}
