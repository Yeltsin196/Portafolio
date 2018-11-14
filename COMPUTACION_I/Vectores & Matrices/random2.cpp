#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*
cargar el vector "a" con numeros 
aleatorios entre 100 y 999 
*/
int main (){
	
	int i, j, n, enc, a[30], b[30];
	srand (time(NULL));
	
	for(i=0;i<30;i++){
		do{
		n=rand()%35+1;
		enc=0;
			for(j=i-1;j>=0;j--){
				if(n==a[j]){
					enc=1;
					break;
				}
			}
		}while(enc==1);
		a[i]=n;
	}
	for(i=0;i<30;i++){
		printf("\n%d", a[i]);
	}

	getch();
	return 0;
}
