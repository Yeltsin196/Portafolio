#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TAM 4
#include <windows.h>
void color(int c){
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}	

int main(){
	
	char nomb1[16][25], nomb2[25];
	int i, j, dosis, cant=0, cont1=0;
	float temp[3][3], porc=0, prom, aux, mayor=-99; 
		do{
			printf("\nCantidad de dias que se tomo la temperatura :  ");
			scanf("%d", &cant);
			}while(cant<0);	
		do{
			printf("\nCantidad de dosis:  ");
			scanf("%d", &dosis);
		}while(dosis<0);
		
	for(i=0;i<TAM;i++){
		fflush(stdin);
		printf("\nNombre del chimpace:  ");
		
		gets(nomb1[i]);

		for(j=0;j<cant;j++){
			printf("\nTemperatura :  ");
			scanf("%f", &temp[i][j]);
			
		}	
	}
	
	for(i=0;i<TAM;i++){
		for(j=0;j<cant;j++){
			if(temp[i][j]>38.5){
				dosis-=1;
			}
		}
	}

	if(dosis<=0){
		printf("\nNo Alcanzaron las dosis");
	}else if(dosis>0){
		printf("\nAlcanzaron las dosis");
	}
		//parte c porcentaje de chimpances 
	for(i=0;i<TAM;i++){
		cont1=0;
		for(j=0;j<3;j++){
			if(temp[i][j]>37.5 && temp[i][j]<=38.5 && cont1==0){
				cont1=1;
				porc++;
			}
		}
	}
	porc=(porc*100)/TAM;
	
	printf("\nPorcentaje de chimpances:  %.2f%%", porc);
		 system("PAUSE");
	   system("CLS");
	  
	  //parte d temp promedio de un nombre pedido al usuario
	  int bandera=0;
	 printf("\n\n");
	 printf("\nIntroduzca el nombre del chimpace que desa buscar:  ");
	 fflush(stdin);
	 gets(nomb2); 
	for(i=0;i<TAM;i++){
		 if(strcmpi(nomb2, nomb1[i])==0){
	 		for(j=0;j<cant;j++){
	 			prom+=temp[i][j];
	 			bandera=1;

			 }
		 }else if(i==TAM-1 && bandera==0){
		 	printf("\nNo encontrado");
		 }

		
	}
		color(14);
	 	prom/=cant;
	 	if(prom>0){
	 			printf("\nTemperatura promedio: %.2f", prom);
				 	 }
	//parte e mostrar que chimpance tuvo mas fiebre el quinto dia exeptuando el primero y el ultimo
	char nomb3[25];
	for(i=0;i<TAM;i++){
		if(i>0 && i<TAM-1){
			if(temp[i][4]>mayor){
				mayor=temp[i][4];
				strcpy(nomb3, nomb1[i]);
			}
		}
	}
		printf("\n\nEl chimpance que presento mas fiebre el quinto dia fue %s", nomb3);
	
	getch();
	return 0;
}
