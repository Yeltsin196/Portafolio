#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 3

int main(){
	
	int dia[TAM], anio[TAM], i, anio1=2015, x=0, y=0, j=0;
	char nombre[3][100], deporte[3][100], sexo[TAM], mes[TAM][100], v_sexof[TAM][100], v_sexov[TAM][100], v_deportes[TAM][100];
	
	for(i=0;i<3;i++){
		printf("\n\nNombre:  ");
		fflush(stdin);
		scanf("%99[^\n]", nombre[i]);
		
		printf("\nSexo: ");
		scanf(" %c", &sexo[i]);
	
		sexo[i]=tolower(sexo[i]);
		if(sexo[i]=='v'){
			strcpy(v_sexov[x], nombre[i]);
			x++;
		}else{
			strcpy(v_sexof[y], nombre[i]);
			y++;
		}
		
		printf("\nFecha de nacimiento");
		printf("\nDia: ");
		scanf("%d", &dia[i]);
		printf("\nMes: ");
		fflush(stdin);
		scanf("%99[^\n]", mes[i]);
		
		printf("\nAnio: ");
		scanf("%d", &anio[i]);
		
		anio[i]=anio1-anio[i];	
		printf("\nDeporte Favorito:  ");
		fflush(stdin);
		scanf("%99[^\n]", deporte[i]);
	
		if(anio[i]>=16 && anio[i]<=18 && strcmpi(deporte[i], "natacion")==0 && sexo[i]=='f'){
			strcpy(v_deportes[j], nombre[i]);
			j++;
		}
		
	}
	system("PAUSE");
	system("CLS");
	printf("\n\nPosiciones:Varones");
	for(i=0;i<x;i++){
		
	
	printf("\n%s", v_sexov[i]);
	}
	printf("\n\nFeminas");
	for(i=0;i<y;i++){
		printf("\n\n%s", v_sexof[i]);
	}
	printf("\n\nMujeres con edad comprendida entre 16 y 18 anios en natacion");
	for(i=0;i<j;i++){
		printf("\n%s", v_deportes[i]);
	}
	
	getch();
	return 0;
}
