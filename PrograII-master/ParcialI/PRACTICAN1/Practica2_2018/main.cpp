#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	 int nivel;
	 cout<<"Ingrese nivel deseado para construir el triangulo de pascal: ";
	cin>>nivel;

	vector<vector<int> > vector_piramide;
	int start_level=1;
	for(int i=0;i<nivel;i++){
		vector<int > numeros;
			vector<int > vector_ant;
			if(i>0)	vector_ant=	vector_piramide[i-1];
			for(int x=0;x<nivel-i;x++){
				cout<<"  ";
			}
		for(int j=0;j<i+1;j++){
			
		if(j==0 || j==i){
		cout<<start_level<<"  ";	
		numeros.push_back(start_level);
		}else{
		
		
					cout<<vector_ant[j]+vector_ant[j-1]<<"  ";
			numeros.push_back(vector_ant[j]+vector_ant[j-1]);
	
		}
	
		}	
		vector_piramide.push_back(numeros);	 
		cout<<endl;
	}
	cout<<endl<<"Hecho por : Luis Eduardo Guerrero Y Yeltsin Ruben Ramirez"<<endl;
	return 0;
}
