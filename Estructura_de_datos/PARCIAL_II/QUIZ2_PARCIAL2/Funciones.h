#include <iostream>
#include <string.h>

using namespace std;

template <class T>
class funciones{
	public:
		void mezclar(vector<T> c, char tipo[30] );
		void convirtiendo1(pila_array<T> c, char tipo[30]);	
		void convirtiendo2(cola_circular<T> c, char tipo[30]);
		void convirtiendo3(lista_enlazada<T>c, char tipo[30]);
		void revirtiendo1(pila_array<T> c, char tipo[30]);
		void revirtiendo2(cola_circular<T> c, char tipo[30]);
		void revirtiendo3(lista_enlazada<T>c, char tipo[30]);
		void concatenando(vector<T> c , char tipo[30]);
		vector<T> insercionDirecta(vector <T>,	int n);
};
template <class T>

vector<T>  funciones<T>::insercionDirecta(vector <T> A,	int n)
{

      int i,j;
	  T v;

      for (i = 1; i < n; i++)
		{
			 v = A[i];
			 j = i - 1;
			 while (j >= 0 && A[j] > v)
			 {
				  A[j + 1] = A[j];
				  j--;
			 }
			
			 A[j + 1] = v;
	  }
	  return    A;
}
 
template <class T>

void funciones<T>::concatenando(vector<T> c, char tipo[30]){
	if(strcmp(tipo, "cola")==0){
		cola_circular<T> obj(c.size());
		for(int i=0;i<c.size();i++){
			obj.agregar(c[i]);
		}
			obj.imprimir();
	}else if(strcmp(tipo, "pila")==0){
		pila_array<T> obj(c.size());
		for(int i=0;i<c.size();i++){
			obj.agregar(c[i]);
		}
		obj.imprimir();
	}else{
		lista_enlazada<T> obj;
		for(int i=0;i<c.size();i++){
			obj.agregar(c[i]);
		}
		obj.imprimir();
	}
}
template <class T>
void funciones<T>::mezclar(vector	<T>	c, char tipo[30]){
	 
	 if(strcmp(tipo,"cola")==0){
	 	cola_circular<T> cola(c.size());
	 	for(int i=0;i<c.size();i++){
	 		
	 		cola.agregar(c[i]);
	 		
		 }
		 cola.imprimir();
	 }else if(strcmp(tipo, "pila")==0){
	 	pila_array<T> pila(c.size());
	 	for(int i=0;i<c.size();i++){
	 		
	 		pila.agregar(c[i]);
	 		
		 }
		 pila.imprimir();
	 }else if(strcmp(tipo, "lista")==0){
		lista_enlazada<T >lista;
		for(int i=0;i<c.size();i++){
	 		
	 	lista.agregar(c[i]);
	 		
		 }
		 lista.imprimir();
	 }
		
	
	
}
template <class T>
void	 funciones<T>::convirtiendo1(pila_array<T> c, char tipo[30]){
		cola_circular<T> cc1(c.getTam()); 
		lista_enlazada<T >lista;
		//lista enlazada falta
		T n;
			for(int w=0;w<cc1.tam;w++){
					n=	c.retorno(w);
					if(strcmp(tipo, "cola")==0)	{
							cc1.agregar(n);	  
					}else if(strcmp(tipo, "lista")==0){
						lista.agregar(n);
					}						    									
										    									    						
			}
		if (strcmp(tipo, "cola")==0){
				cc1.imprimir();	
		}							    									
		if (strcmp(tipo, "lista")==0){
			lista.imprimir();
		}
	
}
template <class T>
void funciones<T>::convirtiendo2(cola_circular<T>c, char tipo[30]){
	pila_array<T> pl(c.getTam());
	lista_enlazada<T >lista;
	
	//lista enlazada falta
		T n;
			for(int w=0;w<pl.tam;w++){
					n=	c.retorno(w);
					if(strcmp(tipo, "pila")==0)	{
							pl.agregar(n);	  
					}else if(strcmp(tipo, "lista")==0){
						lista.agregar(n);
					}						    									
										    									    						
			}
		if (strcmp(tipo, "pila")==0){
				pl.imprimir();	
		}							    									
		if (strcmp(tipo, "lista")==0){
			lista.imprimir();
		}
	
}
template <class T>
void funciones<T>::revirtiendo1(pila_array<T> c, char tipo[30]){
	cola_circular<T> cc1(c.getTam()); 
	lista_enlazada<T > lista;
		pila_array<T> pila;
		T n;
			for(int w=c.getTam()-1;w>=0;w--){
					n=	c.retorno(w);
				
				//	cout<<n<<endl;
				if(strcmp(tipo, "cola")==0)	{
								cc1.agregar(n);	
					
				}else if(strcmp(tipo, "lista")==0){
						lista.agregar(n);
				}else{ 
				pila.agregar(n);
				}
				
		
			}
			
		if (strcmp(tipo, "cola")==0){
			cc1.imprimir();		
		}							    									
		if (strcmp(tipo, "lista")==0){
			lista.imprimir();
		}
		if(strcmp(tipo, "pila")==0){
			pila.imprimir();
		}		
}
template <class T>
void funciones<T>::revirtiendo2(cola_circular<T> c, char tipo[30]){
	pila_array<T> pl(c.getTam()); 
	lista_enlazada<T > lista;
		cola_circular <T> cola(c.getTam());
		T n;
			for(int w=c.getTam()-1;w>=0;w--){
					n=	c.retorno(w);
				
				//	cout<<n<<endl;
				if(strcmp(tipo, "pila")==0)	{
								pl.agregar(n);	
					
				}else if(strcmp(tipo, "lista")==0){
					lista.agregar(n);
				}else {
					cola.agregar(n);
				}
		
			}
			
		if (strcmp(tipo, "pila")==0){
			pl.imprimir();		
		}							    									
		if (strcmp(tipo, "lista")==0){
			lista.imprimir();	
		}
		if(strcmp(tipo, "cola")==0){
			cola.imprimir();
		}		
}
template <class T>
void funciones<T>::revirtiendo3(lista_enlazada<T> c, char tipo[30]){
	pila_array<T> pl(c.getTam()); 
	cola_circular<T> cl(c.getTam());
	lista_enlazada<T > lista;
//	cout<<c.getTam()<<endl;
	
		//
		vector<T> n;
			n=	c.retorno();
			for(int w=0;w<n.size();w++){
			//	cout<<w<<"  "<<n[w]<<endl;
				
				//	cout<<n<<endl;
				if(strcmp(tipo, "pila")==0)	{
								pl.agregar(n[w]);	
					
				}else if(strcmp(tipo, "cola")==0){
					cl.agregar(n[w]);
				}else if(strcmp(tipo,"lista")==0){
					lista.agregar(n[w]);
				}
		
			}
			
		if (strcmp(tipo, "pila")==0){
			pl.imprimir();		
		}							    									
		if (strcmp(tipo, "cola")==0){
			cl.imprimir();
		}
		if(strcmp(tipo,"lista")==0){
			lista.imprimir();
		}		
}
template <class T>
void funciones<T>::convirtiendo3(lista_enlazada<T> c, char tipo[30]){
	pila_array<T> pl(c.getTam()); 
	cola_circular<T> cl(c.getTam());

		//lista enlazada falta
		//
		vector<T> n;
			n=	c.retorno();
			for(int w=n.size()-1;w>=0;w--){
			//	cout<<w<<"  "<<n[w]<<endl;
				
				//	cout<<n<<endl;
				if(strcmp(tipo, "pila")==0)	{
								pl.agregar(n[w]);	
					
				}else if(strcmp(tipo, "cola")==0){
					cl.agregar(n[w]);
				}
		
			}
			
		if (strcmp(tipo, "pila")==0){
			pl.imprimir();		
		}							    									
		if (strcmp(tipo, "cola")==0){
			cl.imprimir();
		}		
}
