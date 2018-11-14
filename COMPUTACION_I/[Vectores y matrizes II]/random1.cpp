#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // bilbioteca para numeros pseudoaleatroios.
#include <time.h>  //biblioteca para numeros aleatorios

/* numero entre 0 y 6 
rand()%(n+1) siendo n el limite superior
rand()%(6+1)
rand()%7


rand()%(N-M+1)+1  N= limite inferior , M= limite superior 

rand()%(6+1-1)+1
rand()%6+1
rand()%7
rand() -> muestra numeros pseudoaletorios que si corre el programa mas de una vez muestra los mismos numeros.

srand()-> Son numeros aleatorios srand(time(null))
time(null) 

int aleatorio = min+rand()%(max-min+1);
*/
int main(){

	
	int n, i ;
	srand (time(NULL));
	for(i=0;i<=20;i++){
	
		printf("%7d", rand()%2); 
		printf("\n");
	}
	getch();
	return 0;
}


