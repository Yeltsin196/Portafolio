#include <stdio.h>
#include <conio.h>
						//prototipo precio base
float calcular_precio(float base, float impuesto);

int main(){
	
	float importe=37.50; //precio base
	float tasa=0.12; // impuesto
	float precio;
	
	

	precio=calcular_precio(importe, tasa); //llamada a la funcion secundaria 
	
	printf("\nEl precio a pagar es:  %.2f Bsf", precio);
	
	
	
	return 0;
	getch();
}	
		float calcular_precio(float base, float impuesto){
		float calculo;
		calculo=base+(base*impuesto);
		return calculo;
	}
	
/*paso de argumentos
por valor (se pasa una copia del valor del argumento)
por reerencia( se pasa el argumento mismo de la funcion principal utilizando su direccion de memoria)

los vectores y matrices se pasan por referencia

