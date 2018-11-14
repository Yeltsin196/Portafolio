#include <iostream>
#include <fstream>
#include <string>
#include "Arbol.h"
#include "string.h"
#include <stdlib.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	fstream archivotexto;
	char cadena1[1000],	cadena2[30];
	int numero;
	
		
	vector <Arbol<int>* > arboles;
	
	archivotexto.open("Claves.txt", ios::in);
	if(!archivotexto.fail()){
		
		while(true){
		
		
			if(!archivotexto.eof()){
				Arbol<int> *arbol= new Arbol<int>(false);
				archivotexto.getline(cadena1,1000);
				char * pch;
				pch = strtok (cadena1,",");
				  while (pch != NULL)
				  {
			//	   cout<<"pch "<<pch<<endl;
					strcpy(cadena2, pch);
					numero= atoi(cadena2); 
					int *p;
					p= new int();
					*p= numero;
					arbol->agregar(p);
					
				    pch = strtok (NULL, ",");
				  }
				  //arbol->anchura(arbol->getRaiz());
				
				arbol->imprimir( arbol->getRaiz(), Arbol<int>:: PREORDEN);
				int *cont=new int();
				*cont=0;
				if(arbol->FEnodo(arbol->getRaiz(), *cont)!=0){
					cout<<"No es AVL"<<endl;
				}
				arboles.push_back(arbol);
			}else{
				break;
			}
		}
		archivotexto.close();
	}else{
		cout<<"eror"<<endl;
	}
	bool iguales1=false;
	bool iguales2=false;
	bool iguales3=false;
	Arbol<int> *arbol1;
	Arbol<int> *arbol2;
	for(int i =0;i<arboles.size();i++){
		arbol1=arboles[i];	
		arbol1->der=false;
			arbol1->izq=false;
		for(int j=i+1;j<arboles.size();j++){
			iguales1=false;
			iguales2=false;
			iguales3=false;
			 arbol2=arboles[j];
		// funcion
			arbol2->der=false;
			arbol2->izq=false;
			arbol1->rotaciones(arbol1->getRaiz());
				arbol2->rotaciones(arbol2->getRaiz());
			while(true){
				if(arbol1->izq && arbol2->izq){
					arbol1->rotaciones(arbol1->get_sigi());
					arbol2->rotaciones(arbol2->get_sigi());
				}else	if(!arbol1->izq && arbol2->izq){
				//	cout<<"no son "<<endl;
					break;
				}else if(arbol1->izq && !arbol2->izq){
				//	cout<<"no son "<<endl;
					break;
				}else if(!arbol1->izq && !arbol2->izq ){
				//	cout<<"Lo son por izquierda"<<endl;
						iguales1=true;
					break;
					
				}
			arbol1->rotaciones(arbol1->getRaiz());
				arbol2->rotaciones(arbol2->getRaiz());
				while(true){
				if(arbol1->der && arbol2->der){
					arbol1->rotaciones(arbol1->get_dere());
					arbol2->rotaciones(arbol2->get_dere());
				}else if(!arbol1->der && arbol2->der){
				//	cout<<"no son "<<endl;
					break;
				}else if(arbol1->der && !arbol2->der){
				//	cout<<"no son "<<endl;
					break;
				}else if(!arbol1->der && !arbol2->der ){
				//	cout<<"Lo son por derecha"<<endl;
					break;
					iguales2=true;
					
				}
				
				}
				if(iguales1== iguales2){
					cout<<endl<<endl<<"Son iguales "<<"Arbol n# "<<i+1<<" Y Arbol n# "<<j+1<<endl;
				}	
			}
		}
		
	}
	cout<<endl<<endl<<"Altura entre los arboles"<<endl;
	for(int i=0;i<arboles.size();i++){
		arbol1=arboles[i];
		cout<<"Arbol "<<i+1<<"  Altura: "<<arbol1->getAltura()<<endl;	
	}
	int numero2;
	string cadena;
	cout<<endl<<endl<<"Ingresar nivel a imprimir"<<endl;
	getline(cin, cadena);
	numero2= atoi(cadena.c_str());
	cout<<endl<<endl;
	for(int i=0;i<arboles.size();i++){
		arbol1=arboles[i];
		cout<<"Arbol "<<i+1<<endl;
		cout<<"Numero: ";
		arbol1->imprimir(arbol1->getRaiz(), numero2);
		cout<<endl;
	}
	
	for(int i=0;i<arboles.size();i++){
		
		arbol1=arboles[i];
		arbol1->dere=arbol1->getRaiz();
		arbol1->sigi=arbol1->getRaiz();
	
		arbol1->comparandod(arbol1->getRaiz());
			
		arbol1->comparandoi(arbol1->getRaiz());
		while(true){
			if(!arbol1->der && !arbol1->izq){
				cout<<"Es simetrico el arbol n# "<<i+1<<endl;
				break;
			}else if((!arbol1->der && arbol1->izq) || (arbol1->der && !arbol1->izq)){
				cout<<"No es simetrico el arbol n# "<<i+1<<endl;
				break;
			}else{
				arbol1->comparandod(arbol1->dere);
			
				arbol1->comparandoi(arbol1->sigi);
			}		
		}
	
	
	}
	
	
	
	
	return 0;
	
}
