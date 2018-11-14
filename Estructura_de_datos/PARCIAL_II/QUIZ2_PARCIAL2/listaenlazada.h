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
	int tam;
	public: 
		lista_enlazada(){
			cab=NULL;
			 tam=0;
		}	
	int agregar(T ele);
	int eliminar(T &eli);
	void imprimir();
	int getTam();
	vector<T >  retorno();
};

template <class T>
void lista_enlazada<T>::imprimir(){
	nodo<T > *p= cab;
	while(p!=NULL){
		cout<<p->get_inf()<<endl;
		p=p->get_sig();
	}

}
template <class T>
int lista_enlazada<T>:: getTam(){
	return tam;
}
template<class T>
vector <T > lista_enlazada<T>::retorno(){
	nodo<T> *p=cab;
	vector<T> v;
	T e;
	while(p!=NULL){
	
		e=p->get_inf();
		p=p->get_sig();
		v.push_back(e);
	}
	return v;
}



template<class T>
int lista_enlazada<T>::agregar(T ele){
	nodo<T> *nue, *p, *ant;
	tam++;
	nue= new nodo<T>(ele);
	if(nue== NULL) return 0;
	p= cab;
	ant=NULL;
	//sin ordenar
	if(p==cab)// caso 1: insercion en cabezera
	{
		nue->set_sig(cab);
		cab=nue;
	}else{	//caso 2:insercion en lugar !=cab
		nue->set_sig(p);
		ant->set_sig(nue);
	}
	return 1;

	
	
}
