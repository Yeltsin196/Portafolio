#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main (){
	
	 int i;
	 char nombremes[12][20]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
		char cara;
do{
	
 
	 do{
	 	printf("\nEscriba un numero del 1 al 12:  ");
	 	scanf("%d", &i);
	 }while(i<1 || i>12);
	 
	 printf("\nEl Numero %d corresponde al mes de %s", i , nombremes[i-1]);
	printf("\nDesea otro intento:  ");
	scanf("%c", &cara);
	cara=tolower(cara);
	}while(resp=='s');	 
	getch();
	return 0;
}
