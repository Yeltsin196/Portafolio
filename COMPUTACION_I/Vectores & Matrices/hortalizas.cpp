#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
void color(int c){
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}	


int main(){
	
	int	i, j, y=0;
	float kg[30][30], precio, total[30], acum, total1=0, porc[100]; 
	char hortalizas[100][30];
	color(10);
	printf("\t**************Hortalizas***********");
	printf("\nPrecio por kg:  ");
	scanf("%f", &precio);
	
		for(i=0;i<3;i++){
			color(15);
			printf("\n\nNombre de la hortaliza:  ");
			fflush(stdin);
			scanf("%99[^\n]", hortalizas[i]);
			acum=0;
			for(j=0;j<3;j++){
				
			printf("\nKg consumidos dia %d: ", j+1);
			scanf("%f", &kg[i][j]);
			acum+=kg[i][j];
			
		
			}
			acum*=precio;
			total[y]=acum;
			color(12);
			printf("\n\nCosto total de %s: %.2f BSF", hortalizas[i], acum);
			y++;
		}
	
		for(i=0;i<3;i++){
			total1+=total[i];
			
		}
		for(i=0;i<3;i++){
			porc[i]=total[i]*100/total1;
			
		}
		printf("\n\n");
		for(i=0;i<3;i++){
			printf("%15.50s", hortalizas[i]);
		}
		
		for(i=0;i<3;i++){
			
			printf("\nDia %d", i+1);
			for(j=0;j<3;j++){
				printf("%10.1f kg", kg[j][i]);
			}
			
		}
		printf("\n\n");
		for(i=0;i<3;i++){
			printf("%15.2f%%", porc[i]);
		}
		
		printf("\n\nPrecio total de las hortalizas: %.2f BSF", total1);
	
	getch();
	return 0;
}
