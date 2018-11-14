#include <iostream>
#include <vector>
#include <fstream>
#define tam 30
#include <stdlib.h>
#include <string.h>
#include "libro.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class editorial{
	char nom[30];
	int codigo;
	
	public :
	
		
	void	setNom(char *c){
			strcpy(nom,c);
	}
	void setCodigo(char *c){
		codigo=atoi(c);
	}
	void imprimir(){
		cout<<"codigo:  "<<codigo<<"nombre editorial: "<<nom<<endl;
	}
};



int main(int argc, char** argv) {
	vector <libro>vlibros;
	
	char cad[tam*tam];
	int cad1;
	editorial BUF;
	libro BUF1("hola",1), auxlibro();
//	vector <editorial*> editoriales;
	fstream arctxt, arcbin;
		
	arctxt.open("editorial.txt", ios::in);
	arcbin.open(("datos.dat"), ios::out | ios::binary);

	
	
	if(arctxt.fail() || arcbin.fail()){
		cout<<"error \n";
		
	}else{
		while(true){
		
	
			arctxt.getline(cad,30, ',');
			if(!arctxt.eof()){
			//	cout<<cad<<endl;
				BUF.setCodigo(cad);
				arctxt.getline(cad, 30);
			//	cout<<cad<<endl;
				BUF.setNom(cad);
				
				arcbin.write((char *) &BUF, sizeof(editorial));
			}else {
				break;
			}
				}
	//		cout<<"fue creado datos.dat"<<endl;
			arcbin.close();
			arctxt.close();
	}
	
	
	arctxt.open("libro.txt", ios::in);
											
	if(arctxt.fail() || arcbin.fail()){
		cout<<"error \n";
		
	}else{
		while(true){
		
	
			arctxt.getline(cad,30, ',');
			if(!arctxt.eof()){
	
				BUF1.setCodigo(cad);
				arctxt.getline(cad, tam*tam,',');
		
				BUF1.setNom(cad);
					arctxt.getline(cad, tam);
					BUF1.setAutor(cad);
				vlibros.push_back(BUF1);	//utilizo bf1 como auxiliar para llenar el vector de objetos libros
		
			}else {
				break;
			}
				}
		
			arctxt.close();
	}
	// burbuja clasica para ordenar los nombres 
	char aux1[90],aux2[90];
	string str(aux1);
	libro auxlibro1;//= new libro();
	for(int i=0;i<vlibros.size();i++){
	
		for(int j=i+1;j<vlibros.size();j++){
			strcpy(aux1, vlibros[i].getNom());
			strcpy(aux2, vlibros[j].getNom());
			//cout<<"aux1"<<aux1[0]<<endl;
			if(aux1[0]>aux2[0]){
				auxlibro1= vlibros[j];
				vlibros[j]=vlibros[i];
				vlibros[i]=auxlibro1;
			
			}
				
		}
	}
	char aux[tam*tam];
	arcbin.open(("datoslibros.dat"), ios::out | ios::binary);
	if(!arcbin.fail()){
		for(int i=0;i<vlibros.size();i++){
				arcbin.write((char *) &vlibros[i], sizeof(vlibros[i]));
			
			}
			arcbin.close();
	}	
	
	
	
	arcbin.open("datoslibros.dat", ios::in |ios::binary);
	if(arcbin.fail()){
		cout<<"error"<<endl;
	}else{
		
				while(true){
			arcbin.read((char *)&BUF1, sizeof(BUF1));
			if(arcbin.eof())	break;
		
		}
		arcbin.close();
	}
	
	arcbin.open("datos.dat", ios::in |ios::binary);
	if(arcbin.fail()){
		cout<<"error"<<endl;
	}else{
		
				while(true){
			arcbin.read((char *)&BUF, sizeof(BUF));
			if(arcbin.eof())	break;
	
		}
		arcbin.close();
	}
	// busco en los archivos de texto un nombre sin que tenga una letra mayor a L
	char nombrebuscar[tam*tam];
	
	cout<<"ingrese Nombre a buscar"<<endl;
	cin.sync();
		cin.getline(nombrebuscar,tam*tam);
		
		if(nombrebuscar[0]<'L'){
			for(int i=0;i<vlibros.size();i++){
				if(strcmp(nombrebuscar,vlibros[i].getNom() )==0){
					cout<<"se encontro"<<endl;
					vlibros[i].imprimir();
				}
			}
		}else{
			for(int i=vlibros.size();i>0;i--){
				if(strcmp(nombrebuscar,vlibros[i].getNom() )==0){
					cout<<"se encontro"<<endl;
					vlibros[i].imprimir();
				}
			}
		}
		
	
	
	system("PAUSE");
	
	return 0;
}
