#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main (){
	
	int matriz[10][10], nl, nc;
	
	printf("\nIngrese numero de filas:  ");
	scanf("%d", &nf);
	printf("\nIngrese numero de columnas:  ");
	scanf("%d", &nc);
	
	srand(time(NULL));
	printf("\n\Matriz original: ");
	
	for(i=0;i<nf;i++){
		for(j=0;j<nc;j++){
			matriz[i][j]=rand()%9+1;
			
			printf("\t%d", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz Transpuesta");
	for(j=0;j<nc;j++){
		for(i=0;i<nf;i++){
			printf("%d", matriz[i][j]);
		}
	}
	getch();
	return 0;
}
