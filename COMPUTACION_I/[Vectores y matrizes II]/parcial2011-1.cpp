#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 32
#define TAM1 3
/* prototipos*/ void cargardatos(int thrs[][TAM], char nombres[][TAM1], int semanas);
				void promedio(float prome[], int thrs[][TAM], int semanas);
				void consulta(char nombres[][TAM1], char nombre[], int semanas, int thrs[][TAM]);
int main(){
	 int semanas, thrs[TAM1][TAM];
		char nombres[TAM][TAM1], nombre[TAM];
		float prome[TAM];	
		
		do{
	
		printf("\nCantidad de semanas trabajadas:  ");
		scanf("%d", &semanas);
		}while(semanas>TAM);
		
		cargardatos(thrs, nombres, semanas);
		promedio(prome, thrs, semanas);
		consulta(nombres, nombre, semanas, thrs);
		
	getch();
	return 0;
}

	void cargardatos(int thrs[TAM1][TAM], char nombres[TAM][TAM1], int semanas){
	int  i , j;

	printf("\n");
	for(i=0;i<TAM1;i++){
		printf("\nIngrese nombre del trabajador:  ");
		fflush(stdin);
		gets(nombres[i]); 
		for(j=0;j<semanas;j++){
			printf("\nHrs trabajadas semana %d: ", j+1);
			scanf("%d", &thrs[i][j]);
		}
	}
	
}

	void promedio( float prome[TAM], int thrs[TAM1][TAM], int semanas){
		int i, j, cont1;
		 float aux=0;
		for(i=0;i<semanas;i++){
			aux=0;
			cont1=0;
			for(j=0;j<TAM1;j++){
				//  No tome en cuenta para el calculo del promedio cuando un trabajador dejo de laborar esa semana. 
				if(thrs[j][i]==0){
					cont1++;
				}
				aux+=thrs[j][i];
					
			}
			aux/=TAM1-cont1;
			prome[i]=aux;
			printf("\nPromedio de la semana %d %.2f Hrs", i+1, prome[i]);
		}
		
	}

		void consulta(char nombres[TAM][TAM1], char nombre[TAM], int semanas, int thrs[TAM1][TAM]){
		 char resp;
		do{
		system("CLS");
		
		printf("\nIngrese nombre a buscar:  ");
		fflush(stdin);
		gets(nombre);
		 int i, j=0;
			for(i=0;i<TAM1 && j==0;i++){ //revisar
				if(strcmpi(nombre, nombres[i])==0){
					for(j=0;j<semanas; j++){
						printf("\nHrs trabajadas : %d", thrs[i][j]);
					}
				}
			}
			printf("\nDesea Hacerlo otra vez?:  ");
			fflush(stdin);
			scanf("%c", &resp);
			resp=tolower(resp);
		}while(resp=='s');
	}
		  
