#include <iostream>
using namespace std;
template <class T>
class pila_array{
	public:
	int tope, tam;
	T *v;
	public:
		pila_array(){
			
		}
		pila_array(int size);
		int agregar(T ele);
		int eliminar (T eli);
		void imprimir();
		T retorno(int i);
		int getTam(){
			return tam;
		}
};

template <class T>
 pila_array<T>::pila_array(int size){
	
	tope=-1;
	tam=size;
	v= new T[size];
	if(!v);
	
	
}

template <class T>
int pila_array<T>::agregar(T ele){
	
	if(tope<tam-1){
		tope++;
		v[tope]=ele;
		return 1;
	}else{
		return 0;
		
	}
	
}
template <class T>
int pila_array<T>::eliminar(T eli){
	
	if(tope==-1){
		return 0;
	}
	eli= v[tope];
	cout<<"eliminado"<<eli<<endl;
	tope--;
	return 1;
}

template <class T>
void pila_array<T>::imprimir(){
	for(int i=0;i<tam;i++){
		cout<<v[i]<<endl;
	}
	
}
template <class T>
T pila_array<T>::retorno(int i){
	return v[i];
}
