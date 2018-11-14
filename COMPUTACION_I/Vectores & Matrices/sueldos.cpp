#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TAM 8

int main(){
	
	int i, x=0, y=0;
	float sueldo[TAM], sueldo1[TAM];
	for(i=0;i<TAM;i++){
		printf("\nIngrese el sueldo: ");
		scanf("%f", &sueldo[i]);
		
	}
	
	if(sueldo[0]<sueldo[TAM]){
		printf("\nEs inferior");
	}	

	for(i=5;i<TAM;i++){
		printf("\n%.1f", sueldo[i]);
	}
	
	for(i=0;i<TAM;i++){
	
		if(sueldo[i]>150000){
			x++;
		}
	}
		if(x>0){
			printf("\nHay un sueldo mayor");
		}else{
			printf("\nNo hay ningun sueldo mayor");
		}
// error en esta parte
	for(i=0;i<TAM;i++){
		if(sueldo[i]<350000){
			sueldo1[y]=sueldo[i]*12/100;
			
			sueldo[i]=sueldo[i]+sueldo1[y];
			y++;
		}else if(sueldo[i]>350000 && sueldo[i]<676000){
			sueldo1[y]=sueldo[i]*7/100;
			
			sueldo[i]=sueldo[i]+sueldo1[y];
			y++;
		}
		
	}	
	printf("\n\n");
	for(i=0;i<TAM;i++){
		printf("\nSueldo N %d %.1f", i+1, sueldo[i]);
	}
	
	getch();
	return 0;
}
