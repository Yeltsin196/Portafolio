#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define filas 7
#define columnas 9

int main(){
	
	int matriz[filas][columnas], i, j, decimal[filas];
	int bit, potencia, menor=9999, mayor=-999, bits_cons, suma;
	
	//cargar matriz
	
	srand(time(NULL));
	
	for(i=0;i<filas;i++){
			
			bit=0; //contabiliza cuantos bit 1 hay en esa fila
				
		for(j=0; j<columnas-1;j++){ //para que solo cargue las primera 8 columnas, la 9 es la paridad (par)
			
			matriz[i][j] = rand()%2;
			
			if(matriz[i][j]==1){
				
				bit++;
			}
			
		//	printf("%d ", matriz[i][j]);
		}
		
		//hallar bit de paridad
		
		matriz[i][columnas-1]=0; 
		
		if(bit%2!=0){
			
			matriz[i][columnas-1]=1;
		}
		
	//	printf("%d = %d \n", matriz[i][columnas-1], bit);
	}
	
	//buscar los bit de cada fila y multiplicar por la potencia 
	
	for(i=0;i<filas;i++){
		
		decimal[i]=0;
		
		for(j=columnas-1, potencia=0;j>=0;j--, potencia++){ //columnas disminuye y potencia aumenta
			
			decimal[i]+=matriz[i][j] * pow(2,potencia); //acumulador 
			
		}
		
		//para mostrarla en orden la matriz resultante
		
		for(j=0;j<columnas;j++){ 
			
			printf("%5d ", matriz[i][j]); 
		}
		
		printf("%10d \n", decimal[i]); //vector de decimales
		
		//mayor y menor
		if(decimal[i]>mayor){
		
			mayor=decimal[i];
		}
		
		if(decimal[i]<menor){
			
			menor=decimal[i];
		}
	}
	
	printf("\n\n El mayor valor es: %d", mayor);
	printf("\n Y se encuentra en la fila: ");
	
	//mostrar la fila con el mayor valor
	for(i=0;i<filas;i++){
		
		if(decimal[i]==mayor){
			printf("%1d", i+1);
		}
		
	}
	
	printf("\n");
	
	printf("\n\n El menor valor es: %d", menor);
	printf("\n Y se encuentra en la fila: ");
	
	//mostrar la fila con el mayor valor
	for(i=0;i<filas;i++){
		
		if(decimal[i]==menor){
			printf("%1d", i+1);
		}
		
	}
		
		//3 bit consecutivos
		
		printf("\n");
		
		printf("\n\n Columnas con mas de 2 bit consecutiva: ");
		
	/*	for(j=0;j<columnas;j++){
		
			bits_cons=0;
		
			for(i=0;i<filas;i++){
			
				suma=matriz[i][j];
			
				if(i+1<filas){
				
					suma+=matriz[i+1][j];
				}
			
				if(i+2<filas){
				
					suma+=matriz[i+2][j];
				}
			
				if(suma==3){
					
					bits_cons=1;
					break;
				}
			
			}
		
			if(bits_cons==1){
			
			printf("%3d ", j+1);
	   	 }	
	
		}*/
		
	//OTRO METODO PARA MOSTRAR LOS 3 BITS CONSECUTIVOS
	
	int sig; //para validar las posiciones
	
	for(j=0;j<columnas;j++){
		
		for(i=0;i<filas;i++){
			
			bits_cons=matriz[i][j];
			
			for(sig=i+1;sig<filas && sig<=i+2;sig++){
				
				bits_cons += matriz[sig][j];
			}
			
			 if(bits_cons>2){
				
				printf("%3d ", j+1);
				break;
			 }
		}
	}
		
	return 0;
}
