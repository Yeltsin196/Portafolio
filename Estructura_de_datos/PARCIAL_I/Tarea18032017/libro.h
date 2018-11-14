#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#define tam 30
#include <string.h>
#include <stdlib.h>
using namespace std;
class libro
{
	char nom[tam*tam], autor[tam];
	int codigo;
	
	public :
		libro();
		libro(char * , int );
		void setNom(char *c){
			strcpy(nom,c);
			
		}
		void setCodigo(char *c){
			codigo=atoi(c);
		}
		void setAutor(char *c){
			strcpy(autor, c);
		}
	void imprimir(){
		cout<<"codigo:  "<<codigo<<"       nombre libro: "<<nom<< "  Autor: "<<autor<<endl;
	}
	char *getNom(){
		return nom;
	}
	int getCodigo(){
		return codigo;
	}
};

#endif
