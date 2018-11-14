#include <stdio.h>
#include <conio.h>
#include <string.h>


int main(){
	int n, a[100], x=0, i, y=0, menor=999, aux, j;
	float porc;

	
	printf("\nIngrese numero de posiciones del vector: ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		printf("\nIngrese numero %d: ", i+1);
		scanf("%d", &a[i]);
		
		
	}
	
	for(i=0;i<n;i++){
			if(a[i]%2!=0){
				x++;
			}
			if(a[i]%7==0){
				y++;
			}
			if(a[i]%2==0){
				if(a[i]<menor){
					menor=a[i];
				}
			}
	}
	
	printf("\n\nCantidad de numeros impares %d", x);
	porc=y*100/n;
	printf("\nPorcentaje de multiplos de 7%.2f%%", porc);
	//d) Crear un nuevo arreglo que contenga el sucesor, si el entero es negativo, o el predecesor si el entero es positivo.
	//mayor a menor
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[j]>a[i]){
				aux=a[j];
				a[j]=a[i];
				a[i]=aux;
			}
		}
		
	} 
	for(i=0;i<n;i++){
		printf("\n%d", a[i]);
	}
	
	getch();
	return 0;
}

