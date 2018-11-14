
/* Funciones en C
Una funcion es un ragmento de codigo que realiza una tarea bien definida 

estructura general

tipo_retorno(lista_parametros){
cuerpo de la funcion 

return expresion
}

*/

#include <stdio.h>
#include <conio.h>

void imprimir_mensaje(char frase[]){
	printf("\nLa frase es: %s ", frase);
	
}
int main(){
	
	char cadena[100]; 
	printf("\nIngrese Cadena:  ");
	fflush(stdin);
	gets(cadena); 
	
	imprimir_mensaje(cadena);

	return 0;
	getch();
}
