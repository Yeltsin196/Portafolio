#include <iostream>
#include <string.h>
#include <fstream>
#include "Arbol.h"
#include <vector>
#include "lista_nominal.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


// enunciado en Claves.txt




int main(int argc, char** argv) {
	
	fstream archivo;
	char a[100], cadena[10000];
	vector <int > vectores;
	lista_enlazada< string > *l2= new lista_enlazada< string >();
	lista_enlazada<int > *lista2= new lista_enlazada<int>();
	vector<lista_enlazada <string >* > listas;
	Arbol<int > *arbol= new Arbol<int>(false);
	archivo.open("Claves.txt", ios::in);
		if(!archivo.fail()){
				
			while(true){
				
				if(!archivo.eof()){
					
				lista_enlazada< string > *l1= new lista_enlazada< string >();
				archivo.getline(cadena, 10000);
				char cadena2[1000], *pch;
				strcpy(cadena2, cadena);
				pch = strtok (cadena2," ,.-");
				  while (pch != NULL)
				  {
				  	int cont=0;
				    cout<<pch<<endl;
				    string cadeaux;
					cadeaux= pch;
					  int ascii2=0;
					  string cadeaux2="";
					  char a2;
					  for(int i=0;i<cadeaux.size();i++){
					  	cadeaux2=cadeaux[i];
					  	a2=cadeaux[i];
					  	 ascii2+=a2;
					 
					  	// cout<<int(a2);
					  
					  }
				 	 cout<<"ascii	"<<ascii2<<endl;
				bool band=false;
				
					for(int i=0;i<listas.size();i++){
						if(listas[i]->get_codigo()==ascii2){
							band=true;
							listas[i]->agregar(cadeaux);
						}
					}
					if(!band){
					 	l1->set_codigo(ascii2);
					 	l1->agregar(cadeaux);
						listas.push_back(l1);
					vectores.push_back(l1->get_codigo());
						
							
					}
					
				    
				    
				    
				    
				    
				    
				    pch = strtok (NULL, " ,.-:%""");
				  }
			
				
					}else{
					
						for(int i=0;i<vectores.size();i++){
							lista_enlazada< string > *l1= new lista_enlazada <string >();	
							l1=listas[i];
							int *p;
							p= new int();
							*p=vectores[i];
								arbol->agregar(p);
						 //	cout<<"" <<l1->get_tam();	
						}
						arbol->imprimir(arbol->getRaiz(),  Arbol<int>:: PREORDEN);
					break;
				}
			}
		}else{
			
		}
	return 0;
}
