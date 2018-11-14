#ifndef NODOO_H
#define NODOO_H

template <class T>
class NodoO
{
	public:
	T info;
	NodoO<T> *ant, *sig;
	public:
	NodoO(T val){
		info=val;
		ant=NULL;
		sig=NULL;
		}
	NodoO(){ 
	 ant=sig=NULL;	
	 }
	void set_info(T val){ 
			info=val;
	}
	void set_sig(NodoO<T> *p){
			sig=p;
	}
	void set_ant(NodoO<T> *p){
			ant=p;
	}
	
	T get_info(){
		return info;
	}
	NodoO<T> *get_sig(){
		return sig;
	}
	
	NodoO<T> *get_ant(){
		return ant;
	}
	
	protected:
};

#endif
