#include <stdio.h> 
#include <cstdlib> 
#include <iostream> 
#include <windows.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
#include <conio.h> 
#define c 5 
#define g 5
int m[c][g], fil=0, col=0, n=0, j=0, vector[25],num,l=0, matrizrotada[c][g];
void matriz_aleatoria_sinrepetir(){

	
			do{ 
			printf("-Ingrese tamaño de matriz: "); 
			scanf("%d", &n); 
	 	
			}while(n<=0||n>5);

	j=n*n; 
	srand(time(NULL)); 
	int econ=0; 
	for(fil=0;fil<j;fil++){ 
	
		econ=0; 
	
		num=rand()%j+1; 
		for(col=0;col<fil;col++){ 
		if(vector[col]==num){
		 econ=1; 
		 break; 
	 		} 
	 
	 		} 
	 if(econ==1){ 
	 fil--; 
	 }else{ 
	 vector[fil]=num; 
	 
	 } 
	 
	 } 
	 for(fil=0;fil<n;fil++){ 
	 		for(col=0;col<n;col++){ 
			 	m[fil][col]=vector[l]; 
			 	l++;
			 
			  }
			  } 
			  
			 
			  for(fil=0;fil<n;fil++){ 
			  printf("\n"); 
			  for(col=0;col<n;col++){ 
		
			   printf(" %2d  ",m[fil][col]);
			  printf("\t"); 
			 
			  
			
               	
			  }
			  
			   	} 
printf("\n\n");
for(int fil=0;fil<n;fil++){
	printf("\n");
	for(int col=0;col<n;col++){
		
		printf("%d", m[col][fil]);
		printf("\t");
	}
}

	
}









int main(){
	
	matriz_aleatoria_sinrepetir();
	
	
return 0;

system("pause");
	
}

