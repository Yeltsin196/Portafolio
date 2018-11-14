#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#define tam 10

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ordenacionShell(long long int a[], int n)
{
long long int i, j, inc, temp;
  
  for(inc = 1 ; inc<n;inc=inc*3+1);
   
      while (inc > 0)
      {
          for (i=inc; i < n; i++)
          {
                j = i;
                temp = a[i];
                while ((j >= inc) && (a[j-inc] > temp))
                {
                    a[j] = a[j - inc];
                    j = j - inc;
                }
       
                a[j] = temp;
          }
         
          inc/= 2;
      }
   
}

 string indirecta(string v, int n){
 int i, j;
 string aux=" ", aux2=" ";
 for (i = 0; i < n; i++){
 /* indice j es para explorar la sublista a[i-1]..a[0] buscando la posicion
correcta del elemento destino */
 	j = i;
 	aux = v[i];
 // se localiza el punto de inserción explorando hacia abajo
 		while (j > 0 && toupper(aux[0]) < toupper(v[j-1])){
		 // desplazar elementos hacia arriba para hacer espacio
		 v[j] = v[j-1];
 		j--;
 		}
		 v[j] = aux[0];
 	}
 		aux2=v;
 		return aux2; 
	}

int menu(){
	int op;
	cout<<"1.- Cargar data"<<endl;
	cout<<"2.- Busqueda"<<endl;
	
	cin>>op;
	return op;
	
}
int busquedaBinaria( string arreglo[], int tamano, string clave)
{
	 //tolower(clave);
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}





int main(int argc, char** argv) {
	int op=menu();
	char resp;
	string *vectorc= new string[tam];
		long long int *vectori= new long long int[tam];
		bool bandera= false;
	while(op==1 ){
	if(bandera){
		system("CLS");
		 op=menu();
	}	
	if( !bandera ){
 	bandera= true;
		string vector[10]={"F135a69z190L58W", "D3z198p60S200R6",
		"Q121a80E115r128S", "e120g71h210I89m","J95a67N212m96q1", 
		"D112e70U200s67P", "E35a200C15h90S80", "65D100o16g200f85R", 
		"N95e70B118d149W", "97E32n150L62a78D1"};

	string *vectorc= new string[tam];

//	char vectorc1[10][20];
	long long int *vectori= new long long int[tam];
	int tam1=tam;
		long	long int numeroaux;
	string aux, aux1;
		for(int i=0;i<10;i++){

	vectori[i]=0;
	 aux="";
	 aux1="";
	 numeroaux=0;
			for(int j=0;j<vector[i].size();j++){
				
			
				
				if((vector[i][j]>='A' && vector[i][j]<='Z') || (vector[i][j]>='a' && vector[i][j]<='z')){
					cout<<vector[i][j]; // separando las letras 
					aux+=vector[i][j];
						numeroaux+=atoll(aux1.c_str());
					aux1="";
				//	vector
				}else {
				//	cout<<vector[i][j];
				
					aux1+=vector[i][j];
				//	cout<<""<<aux1<<" ";
				
					
				}
			}
		
			vectorc[i]=aux;
			cout<<aux1;

			vectori[i]=numeroaux;
			cout<<"   "<<vectorc[i];
	//		strcpy(vectorc1[i], aux.c_str());
				cout<<"   "<<vector[i];
		
				cout<<endl;
		}
		
		ordenacionShell(vectori,tam );
			//	ordenacionShell1(vectorc,tam );
		cout<<endl<<"\tclave numerica";
		cout<<endl;
				for(int i=0;i<tam;i++){
				
					cout<<vectori[i]<<endl;
				}
		cout<<"\tvector alfabetico";
		cout<<endl;
		
				for(int i=0;i<tam;i++){
				cout<<indirecta(vectorc[i], vectorc[i].size());
				cout<<endl;
				
				}
				
				cout<<"desea volver al menu ? si: s  no: n"<<endl;
				cin>>resp;
				if(resp=='s') op=1;
				else op=0;
	}
	}
	if	( op==2 && bandera==false){
		cout<<"no se ha cargado nada :c"<<endl;
	}else if(op==2 && bandera==true){
		string codigo;
		cout<<"ingrese codigo a buscar"<<endl;
		cin>>codigo;
	//	cout<<busquedaBinaria(vectorc, tam, codigo);
		if(busquedaBinaria(vectorc, tam, codigo)==-1){
			cout<<"no se encontro"<<endl;
		}else{
			cout<<"si se encuentra"<<endl;
		}
	}
	
	
		return 0;
	system("PAUSE");
}
