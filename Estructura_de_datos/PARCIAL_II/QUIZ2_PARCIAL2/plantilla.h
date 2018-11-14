#include <iostream>
using namespace std;
template <class T>
class cola_circular{
	public:
	T *v;
	cola_circular(){
	}
	int fre, fin, tam;
	cola_circular(int size);
	int agregar(T &ele);
	int eliminar(T  &eli);
	void imprimir();
	int getTam(){
		return tam;
	}
	T retorno(int i);
};




template<class T>
void cola_circular<T>::imprimir(){
	for(int i=0;i<tam;i++){
		cout<<v[i]<<endl;	
	}

}

template <class T>
cola_circular<T>::cola_circular(int size){
	tam = size;
	fre=fin=-1; // cola vacia
	v= new T[tam];
	if(!v) 	cout<<"agotada memory"<<endl;
	
	
	
}
template <class T>
T cola_circular<T>::retorno(int i){
	return v[i];
}

template <class T>
int cola_circular<T>::agregar(T &ele){
	

	if((fin+1)%tam == fre){
		return -1;
	}
		if(fre==-1){
		fre=0;
	}
	v[(fin+1)%tam]= ele;
	fin= (fin+1)%tam;
	return fin;
	
}

template <class T>
int cola_circular<T>::eliminar(T &eli){
	int aux;
	
	if(fre==-1 && fin==-1){
		return -1;
	}
	eli==v[fre];
	aux=fre;
	if(fre==fin)fre= fin=-1;
	else fre=(fre+1)%tam;
	return aux;
}
