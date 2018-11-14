#include <stdio.h>
#include <conio.h>


int main(){
	char codigo[100][25], circuito[100];
	float voltaje[100], intensidad[100], potencia[100], factor;
	int num_mediciones, i;
	
	do{
		printf("Numero de mediciones: ");
		scanf("%d",  &num_mediciones);
	}while(num_mediciones<1 || num_mediciones>100);
	
	for(i=0;i<num_mediciones;i++){
		printf("\nIngrese codigo de la medicion:  ");
		fflush(stdin);
		scanf("%s", codigo[i]);
		printf("\nIngrese voltaje:  ");
		scanf("%f", &voltaje[i]);
		printf("\nIngrese intensidad:  ");
		scanf("%f", &intensidad[i]);
		
	} 
	//parte a 
	for(i=0;i<num_mediciones;i++){
		factor=voltaje[i]/intensidad[i];
		circuito[i]='\0';
		if(factor>0 && factor<0.5){
			circuito[i]='C';
		}else if(factor>=0.5 && factor<1){
			circuito[i]='I';
		}else if(factor==1){
			circuito[i]='R';
		}
		if(circuito!='\0'){
			printf("\nEl circuito de la medicion %s es %c", codigo[i], circuito[i]);
		}
	}
	
	getch();
	return 0;
}
