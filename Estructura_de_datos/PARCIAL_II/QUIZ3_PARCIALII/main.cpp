#include <iostream>
#include <fstream>
#include "edificio.h"
#include <vector>
#include <stdlib.h>
#include "Jugador.h"
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void color(int c){

	HANDLE consol;
	consol = GetStdHandle
		(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
		(consol, c);
}

bool validacion(vector<Jugador*> jugadores, int posicion){
	int x=0;

	for(int i=0;i<jugadores.size();i++){
		
		if(jugadores[i]->getPosicion()<posicion){
		
			x++;
		}
		
	}
	if(x==jugadores.size()){
		return true;
	}else{
		return false;
	}
}


vector <Jugador*>  quicksort(int limiteinicial, int der , vector<Jugador*> jugadores)
{ 
int i, j, pivote; 
i = limiteinicial; 
j = der; 
Jugador *auxjugador= new Jugador();
	
pivote = jugadores[ (limiteinicial+ der) /2 ]->getDadonumero(); 


    do{ 
        while( (jugadores[i]->getDadonumero() < pivote) && (j <= der) )
        { 
            i++;
        } 
 
        while( (pivote < jugadores[j]->getDadonumero()) && (j > limiteinicial) )
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            auxjugador = jugadores[i]; 
			 jugadores[i] =  jugadores[j];
		 jugadores[j] =  auxjugador; 
            i++;  
			j--; 
        }
         
    }while( i <= j ); 
 
    if( limiteinicial < j ) {
    	quicksort( limiteinicial, j , jugadores); 
	}
        
    if( i < der ){
    	  quicksort( i, der , jugadores); 
	} 
      return jugadores;
        	
}
vector <Jugador*>  quicksort2(int limiteinicial, int der , vector<Jugador*> jugadores)
{ 
int i, j, pivote; 
i = limiteinicial; 
j = der; 
Jugador *auxjugador= new Jugador();
	
pivote = jugadores[ (limiteinicial+ der) /2 ]->sumapuntos(); 


    do{ 
        while( (jugadores[i]->sumapuntos() < pivote) && (j <= der) )
        { 
            i++;
        } 
 
        while( (pivote < jugadores[j]->sumapuntos()) && (j > limiteinicial) )
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            auxjugador = jugadores[i]; 
			 jugadores[i] =  jugadores[j];
		 jugadores[j] =  auxjugador; 
            i++;  
			j--; 
        }
         
    }while( i <= j ); 
 
    if( limiteinicial < j ) {
    	quicksort( limiteinicial, j , jugadores); 
	}
        
    if( i < der ){
    	  quicksort( i, der , jugadores); 
	} 
      return jugadores;
        	
}

int main(int argc, char** argv) {
	
			fstream arctxt ;
			edificio *Edf;
			char aux[4];
		vector <int> c;
	
	//	prueba();
		
		int filas, co, i=0;
		srand(time(NULL));
		arctxt.open("Edificio.txt", ios::in);	
			int tam, tam1;
		if(!arctxt.fail()){
			
			
			
			while(true){
							arctxt.getline(aux,4, ' ');
					
					if(!arctxt.eof()){
					if(i==0){
					//	cout<<aux<<"aux";
				
					tam=atoi(aux);
						arctxt.getline(aux,4);
					//	cout<<"  "<<aux<<endl;
						tam1=atoi(aux);
						
					}else{
					//	cout<<aux<<" ";
						c.push_back(atoi(aux));
						for(int j=0;j<tam1-2;j++){
							arctxt.getline(aux,4, ' ');
							c.push_back(atoi(aux));	
						}
						
						
				//			cout<<aux<<" ";
						arctxt.getline(aux,4);
							c.push_back(atoi(aux));
					//		cout<<aux<<endl;
					if(i==5){
						for(int j=0;j<c.size();j++){
							if(j%tam1==0) cout<<endl;
							//	cout<<c[j]<<" ";
						}
						//	getch();
						}	
					}

							i++;

					
					}else{
						break;
					} 
					
				
			}
				Edf= new edificio(c);
				
				
				
				arctxt.close();	
				
		}else{
		cout<<"error"<<endl;
			
		}
		color(14);
		//JUEGO
		int auxpts;
		vector<Jugador*> jugadores;
		char aux1[30], aux2;
		
		while(true){
			cout<<endl<<"Nombre del jugador:  ";
			cin.sync();
			cin.getline(aux1,30);
			jugadores.push_back(new Jugador(aux1,Edf->getTamano(),0));
			
			cout<<"Desea introducir otro jugador: <s/n> "<<endl;
			cin.sync();
			cin>>aux2;
	
		//	if(aux2=='n') break;
		int n= tolower(aux2);
			if(n==110){
				if(jugadores.size()>1)	break;
				else cout<<endl<<"HACEN FALTA JUGADORES";
				
				
			}
		}
		int nrandom;
		for(int x=0;x<jugadores.size();x++){
			nrandom= rand()%6+1;
			jugadores[x]->setNumerodado(nrandom);
			//	cout<<jugadores[x]->getDadonumero()<<endl;
		}
		 
		 system("CLS");
	//	cout<<nrandom<<endl;
		jugadores=quicksort(0,jugadores.size()-1,jugadores);
		//cout<<endl;
		int turno=0;
		while(true){
			if(turno==jugadores.size()){
				turno=0;
			}
			nrandom= rand()%6+1;
			auxpts=0;
			if(jugadores[turno]->getPosicion()>(tam1-1)){
	
					jugadores[turno]->setPosicion(nrandom);
					if(jugadores[turno]->getPosicion()<0){
						
						jugadores[turno]->setPosicion2(0);
					}
					jugadores[turno]->setNumerodado(nrandom);
					color(10+turno);
					cout<<"Nombre: "<<jugadores[turno]->getNombre()<<"	Se movio: "<<jugadores[turno]->getDadonumero()<<" casillas"<<endl;	
				//		cout<<"Posicion(): "<<jugadores[turno]->getPosicion()<<endl;
					//	system("PAUSE");
					
					if(Edf->getNumero(	jugadores[turno]->getPosicion()) >0){
						jugadores[turno]->addsetpuntaje(Edf->getNumero(	jugadores[turno]->getPosicion()));
							Edf->setNumero(jugadores[turno]->getPosicion(),0);
					
						jugadores[turno]->imprimirpuntajes();
						if(jugadores[turno]->sumapuntos()>400){
							do{
							
					
							auxpts+=jugadores[turno]->deletesetpuntaje();
					cout<<"se ha eliminado de la cola: "<<auxpts<<" pts"<<endl;
								}	while(jugadores[turno]->sumapuntos()>400);	
							
								Edf->setNumero(jugadores[turno]->getPosicion(),auxpts);
						}
						
						
					
						}
					cout<<endl<<endl;
						color(15);
						Edf->imprimirmatriz(tam1, 10+turno,  jugadores[turno]->getPosicion());
						color(14);
						cout<<endl<<endl;
							getch();
			}
		
			turno++;
			if(validacion(jugadores,tam1)){
				break;
			} 
		}
	
		jugadores=quicksort2(0,jugadores.size()-1,jugadores);
		
		for(int x=jugadores.size()-1;x>=0;x--){
			if(x==jugadores.size()-1){
				color(12);
				cout<<"	GANADOR-> ";
				color(15);
				cout<<jugadores[x]->getNombre()<<" Con "<<jugadores[x]->sumapuntos()<<" PTS"<<endl;
			}
			
		}
	
	system("PAUSE");
	return 0;
}
