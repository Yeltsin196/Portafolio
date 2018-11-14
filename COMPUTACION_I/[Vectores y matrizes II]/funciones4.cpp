#include <stdio.h>
#include <conio.h>

void imprimir1 (int v[]);
void imprimir2 (int []);

int main(){
	
	int edad[]={20,18,25,27,30};
	imprimir1(edad);
	printf("\n\n");

	
	return 0;
	getch();
}

void imprimir1(int v[]){
	int i;
	for(i=0;i<5;i++){
	printf("%d", v[i]);
	}	
}
