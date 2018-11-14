#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
int main(){
	
	char ciudad[TAM][50], ciudad1[TAM][50];
	int distan[28], i, mayor=-999, x=0, j, y;
	float precio[28], precio1[28], porc;
	 
	 for(i=0;i<2;i++){
	 	
	 	printf("\n\nCiudad: ");
		fflush(stdin);
	 	scanf("%18[^\n]", ciudad[i]);
	 
	 	
	 	printf("\nDistancia: ");
	 	scanf("%d", &distan[i]);
	 	if(strcmpi(ciudad[i], "San Cristobal")!=0){
	 		
		 
	 		printf("\nValor: ");
	 		scanf("%f", &precio[i]);
	 	}
	 	
	 	if(distan[i]>=mayor && strcmpi(ciudad[i],"Pregonero")!=0){
	 		mayor=distan[i];
	 		strcpy(ciudad1[0], ciudad[i]); 
	 		
			 if(distan[i]==mayor){
			 x++;
			 strcpy(ciudad[x], ciudad[i]);
				
			}
		}
		 
	 	if(strcmpi(ciudad[i], "San Cristobal")==0){
	 		printf("\nValor: ");
	 		scanf("%f", &precio[i]);
		 }
		 if(distan[i]>30){
		 	porc=precio[i]*15/100;
		 	precio1[y]=precio[i]+porc;
		 	y++;
		 }else{
		 	porc=precio[i]*7.5/100;
		 	precio1[y]=precio[i]+porc;
		 	y++;
		 }
		
		 
	 	
	 }
	 	for(j=0;j<x;j++){
	 		
		 
	 		printf("\n%s", ciudad1[j]);
	 	}
	 	
	 	printf("\n");
	 	for(j=0;j<2;j++){
	 		printf("\n %s %.2f", ciudad[j], precio1[j]);
		 }
		
	getch();
	return 0;
}
