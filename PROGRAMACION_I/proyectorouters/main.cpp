#include <iostream>
#include "Configuracion.h"	
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

int getsubred( int n);
bool busqueda( string,  string, vector<vector<string> >, vector<vector<string> >, vector<string>);
string host(int);


void color(int c){  // colores 
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}

int main(){
	
	Configuracion c;
	
	vector<vector<string> > direcc;			//rutas vector anidado listas de rutas de cada direccion ip
	vector<vector<string> > tppuerto;		//los puertos dentro de cada lista de las direcciones ip	
	vector<string> tprouters;				//vector de routers tipo de routers
	
	for(int i=0;i<c.getCanRouters();i++){
		
		tprouters.push_back(c.getRouter(i));		// push_bach utilizado para cosas que desconozco como el tp de red
		vector<string> dir;			// direccion de subred = ruta que puede seguir el mensaje 	AUXILIAR	
		vector<string> tp;				// vector de tipos de puerto		AUXILIAR
		
		for(int j=0;j<c.getCanRutas();j++){
			
			string aux = c.getRuta(j); //copia toda la cadena de los routers existentes
			string aux3,pconexion,ip;
			
			istringstream aux2(aux);  	// se parte la informacion de los routeres
			getline(aux2, aux3, ' ');
			getline(aux2, ip, ' ');
			getline(aux2, pconexion);
			if (tprouters[i] == aux3){		//valida que tipo de router sea igual . Si es igual pasa y guarda los demas datos
				dir.push_back(ip);
				tp.push_back(pconexion);
			}
		}
		direcc.push_back(dir);		// guarda en el vector de direcciones la direccion asignada en esa posicion
		tppuerto.push_back(tp);		//guarda en el vector de tipo de puertos el puerto correspondiente
	}
	
// 1.- imprime-arma tabla de enrutamiento para cada router
	cout << "\tTabla de enrutamiento (direcciones/routers activos)"  <<endl;
	for(int i=0;i<c.getCanRouters();i++){
		cout << "\n\tRouter: " <<tprouters[i]<<endl;

		cout << "\tRed/Subred   -   Puerto"<< endl;
		// direcc[i].size devulve el tamaño del vector por cada tipo de router
		for(int j=0;j<direcc[i].size();j++){
			cout<<"\t"<<direcc[i][j]<<"\t\t"<<tppuerto[i][j]<<endl;
		}
	}
		getch();
		system("CLS");
		
//2.- agarra mensaje , parte receptor emisor y el mensaje que se debe llevar
	for (int i=0;i<c.getCanComunicaciones();i++){
		
		string cadenaaux(c.getComunicaciones(i));
		istringstream b(cadenaaux);
		
		string emisor, receptor, msm;
			getline(b, emisor,  ' ');
			getline(b, receptor, ' ');
			getline(b, msm);
			
			
			// 3.- entra a funcion para determinar la ruta que sigue el mensaje-> busqueda
			bool op=busqueda(emisor, receptor,direcc,tppuerto,tprouters);
			
			if(!op){ // en caso de que la direccion no este registrada.
				color(12);
				cout<<"ERROR"<<endl<<"La direccion IP no ha podido ser encontrada en la comunicacion n# :"<<i+1<<endl;
			}else{
				Sleep(500);
				color(15);
				cout<<"\n\n\tMensaje n#: " <<i+1<<" es: "<<msm<<"\n\n\n";
			}
	}
	
	//4 clase de red y cantidad de mensajes por cada host 
	getch();
	system("CLS");
	vector<int> hoste; //host emisores
		vector<int> hostr;	//host receptores
		// dividi en 2 vectores 
	int danbera=0;

		cout<<"\tIP host  -   Clase de red\n"<<endl;
		//se almacenan los emisores
	for(int i=0;i<c.getCanComunicaciones();i++){
		string base(c.getComunicaciones(i));
		istringstream b(base);
		string auxn;
		
			getline(b, auxn, ' ');
			hoste.push_back(atoi(auxn.c_str()));
		//	cout<<auxn<<"  Tipo  "<<tipohost(atoi(auxn.c_str()))<<endl;		
		
	}
	//se almacenan los receptores
	for(int i=0;i<c.getCanComunicaciones();i++){
		string base(c.getComunicaciones(i));
		istringstream b(base);
		string auxn;
		getline(b, auxn, ' ');
			getline(b, auxn, ' ');
			hostr.push_back(atoi(auxn.c_str()));
		//	cout<<auxn<<"  Tipo  "<<tipohost(atoi(auxn.c_str()))<<endl;	
	}
	int cont;
	for(int i=0;i<c.getCanComunicaciones();i++){
		cont=0;
			for(int j=0;j<c.getCanComunicaciones();j++){
				if(hostr[i]==hostr[j]){
					cont++;
				}
			}
			cout<<"\t"<<hostr[i]<<"  total mensajes: "<<cont<<endl<<"\tTipo  "<<host(hostr[i])<<endl<<endl;;	
	}

	for(int i=0;i<c.getCanComunicaciones();i++){
		cont=0;
		bool resp=false;
		for(int j=0;j<c.getCanComunicaciones();j++){
			if(hoste[i]==hostr[j]){
				resp=true;
				break;
			}
			
		
		}
		if(!resp)	cout<<"\t"<<hoste[i]<<"  total mensajes: "<<cont<<endl<<"\tTipo  "<<host(hoste[i])<<endl<<endl;
	}
	getch();
    return 0;
}

int getsubred( int n){ // determina la subred
	int b = n >> 8;
	return b << 8;
}


bool busqueda( string emite,  string recibe, vector<vector<string> > direcc, vector<vector<string> > tppuerto, vector<string> tprouters){
	
	bool aux=false,aux2=false;  //banderas auxuliares
	
									//varoablestring.c_str()  transforma todo a una cadena 
	int emisor= getsubred(atoi(emite.c_str()));  //subred emisor
	int receptor= getsubred(atoi(recibe.c_str()));	//subred receptor 
	
	int xi, yi, xf, yf;		// auxiliares xinical xfinal yfinal yinicial

	for (int i=0;i<tprouters.size();i++){ // valida que las direcciones existan del emisor y del receptor que pertenezcan al menos a alguna red
		for (int j = 0; j < direcc[i].size(); j++){
			if(emisor == atoi(direcc[i][j].c_str())) {
				
				xi=i, yi=j;
				aux= true;
				
			}
			if(receptor == atoi(direcc[i][j].c_str())) {
				aux2= true;
				xf=i, yf=j;
			}
		}
	}
	if(!(aux && aux2)){  // al negar esto si al menos una direccion ip no existe no sigue ejecuando el mensaje dado. 
		return  false;
	}
	// Validacion para coincidir cada uno de las ip . Si no existe ninguna de las 2 se retonara falso, y se indicara que no existe. 


	int  tf = -1;
	
	Sleep(800);
	color(12);
	cout <<"IP host emisor: "<<emite;
	color(15);
	cout<<"  Mensaje pasa por " <<endl;
	cout<<emisor<< "-" <<tppuerto[xi][yi]<<  "-" <<tprouters[xi]<<"-->"<<endl;
	while (xi != xf){ //para que se sepa que no es el mismo router jugando a dañar el algoritmo
		bool  bandera = false;
		
		for (int i=0;i<direcc[xi].size();i++){
			for (int j=0;j<direcc[xf].size(); j++){
				if (direcc[xi][i]==direcc[xf][j]){ // certifica que esa misma direccion ip tambien la pueda tener el otro router en su tabla de enrutamiento
					
				//	cout<<"r: "<<rutas[xi][i]<<"   "<<rutas[xf][j]<<endl;
					tf = j;
					xi = xf;
						Sleep(700);
					cout<<" "<<tppuerto[xi][tf]<< "-" <<tprouters[xi]<<"-";
					bandera= true;
				}
				if (bandera)break;
			}
			if (bandera)break;
		}
		bandera= false;
		if (tf==-1){ // en caso de que sea del mismo router
			for (int k=0;k<tprouters.size();k++){
				if (k!=xi){
					for (int i=0;i<direcc[xi].size(); i++){
						for (int j=0;j<direcc[k].size();j++) {
							if (direcc[xi][i]==direcc[k][j]){
								yi = tf = j;
								xi=k;
									Sleep(800);
								cout<<"-"<<tppuerto[xi][tf]<<"-"<<tprouters[xi]<<endl;
								bandera= true;
							}
							if (bandera)break;
						}
						if (bandera)break;
					}
				}
				if (bandera)break;
			}

		}

	}
		Sleep(700);
	cout<< "-" <<tppuerto[xi][yf]<<endl<<"->  subred destinada: "<<receptor;
	color(12);
	cout<<" ->IP de Destino->"<<recibe<<endl;
	color(15);
	
	
	return true;
}

string host(int ruta){
	string aux;
	int b=ruta>>13;  //corro los bits 13 posiciones para evaluar las 3 restantes
	bool band=false;
	
	if(b==6){
		band=true;
		return aux="Red Clase C";
	}
	if(b==4){
		band=true;
		return aux="Red Clase B";
	}
	if(b<=3){  // en caso de que sea 011 o 010 o 001
		band=true;
		return aux="Red Clase A";
	}
	if(!band){
		return aux= "No se ha encontrado clase para la direccion IP dada";
	}
}
