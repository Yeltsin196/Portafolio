#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
class edificio
{	
			
			vector<int> numeros;
	public:
		edificio();
		edificio(vector <int > _numeros){
			numeros=_numeros;
		}
		
		void setNumero(int i, int _numero){
			this->numeros[i]= _numero;
			//cout<<"numero   "<<i<<endl;
		}
		int getTamano(){
			return numeros.size();
		}
		int getNumero(int i){
			return numeros[i];
		}
			void colores(int c){

				HANDLE consol;
				consol = GetStdHandle
					(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute
					(consol, c);
			}
		void imprimirmatriz(int tam1,int x, int posicion){
	/*
					if(j%tam1==0) cout<<endl;
										if(j==posicion){
										colores(x);
									//	cout<<"º";
										printf("%c", 197);
									}	
										colores(15);
										cout<<numeros[j]<<" ";
									*/
	
			for(int j=0;j<numeros.size();j++){
									if(j%tam1==0) cout<<endl;
										if(j==posicion){
										colores(x);
									//	cout<<"º";
										printf("%c", 197);
									}	
										colores(15);
								if(numeros[j]>0)		cout<<numeros[j]<<" ";
								else if(numeros[j]==0)		printf("%c ", 158);
								
								}
			
		}
		~edificio();
	protected:
};

#endif
