#ifndef JUGADOR_H
#define JUGADOR_H
#include "coladinamica.h"
#include <string.h>
class Jugador
{		int posicion, puntaje;
		Cola<int > cola1;
		int numerodado;
		char nombre[30];
	
			public:
		Jugador();
		Jugador(char * nombre1, int _posicion, int _puntaje){
			strcpy(nombre,nombre1);
			this->posicion=_posicion;
			this->puntaje=_puntaje;
			
			
			
			
			
		} 
		char * getNombre(){
			return nombre;
		}
		void imprimirpuntajes(){
			cout<<"Puntos para "<<nombre<<" ";
			cola1.imprimir();
			cout<<"suma  "<<cola1.suma()<<endl;
		}
		int sumapuntos(){
			return cola1.suma();
		}
		void addsetpuntaje(int p){
			cola1.insertar(p);			
		}
		int deletesetpuntaje(){
			int ele,x;
			x=cola1.extraer();
			return x; 
		}
		int getPuntaje(){
			return puntaje;
		}
		void setPosicion(int _posicion){
			this->posicion-=_posicion;
		}
		void setPosicion2(int _posicion){
			this->posicion=_posicion;
		}
		int getPosicion(){
			return posicion;
		}
		void setNumerodado(int x){
			this->numerodado=x;
		}
		int getDadonumero(){
			return numerodado;
		}
		~Jugador();
	protected:
};

#endif
