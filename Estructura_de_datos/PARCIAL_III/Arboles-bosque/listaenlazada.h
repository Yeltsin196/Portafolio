#include <iostream>
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
		lista_enlazada(){
			cab=NULL;
		}	
	int agregar(T ele);
	int eliminar(T &eli);
	void imprimir();
	
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
int lista_enlazada<T>::agregar(T ele){
	nodo<T> *nue, *p, *ant;
	nue= new nodo<T>(ele);
	if(nue== NULL) return 0;
	p= cab;
	ant=NULL;
	while(p!=NULL){
		if(nue->get_inf()<p->get_inf()){
			break;
		}else{
			ant=p;
			p=p->get_sig();
		}
	}
	if(p==cab)// caso 1: insercion en cabezera
	{
		nue->set_sig(cab);
		cab=nue;
	}else{	//caso 2:insercion en lugar !=cab
		nue->set_sig(p);
		nue->set_sig(nue);
	}
	return 1;

	
	
}
