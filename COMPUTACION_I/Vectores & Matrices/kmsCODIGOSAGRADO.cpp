#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int i, j, x=0, y=0, ve_km[5];
	char nombre[5][50];
	float km[5][5], acum, v_acum[5];
	
	for(i=0;i<5;i++){
		printf("\nNombre del ciclista:  ");
		fflush(stdin);
		scanf("%49[^\n]", nombre[i]);
		acum=0;
		for(j=0; j<5;j++){
			printf("\nKM Dia %d: ", j+1);
			scanf("%f", &km[i][j]);
		 acum+=km[i][j];
		 	
		}
		v_acum[x]=acum;
		x++;
	}
	
	for(i=0;i<2;i++){
		printf("\n %s  %.1f", nombre[i], v_acum[i]);
	}
	x=0;
	y=0;
	for(j=0;j<5;j++){
		x=0;
		for(i=0;i<5;i++){
			if(km[i][j]>0){
				x++;
			}else if(km[i][j]==0){
				x--;
			}
			
		}
		//	printf("\n%d", x);
		if(x==5){	
		ve_km[y]=j;
		y++;
		}
	}
	
	for(i=0;i<y;i++){
		printf("\nDia que corrieron todos: %d", ve_km[i]+1);
	}
	
	/* impresion de matriz 
	for(i=0;i<5;i++){
		printf("\n");
		for(j=0;j<5;j++){
			printf("\t%.1f", km[i][j]);
		}
	}*/
	
	getch();
	return 0;
}
