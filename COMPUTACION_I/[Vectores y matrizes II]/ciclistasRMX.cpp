#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	int n, nro[100], i, j;
	char resp, nombres[50][100], pais[50][100];
	float	etapas[100][100];
	int x=0, cont=0;
	do{
	
	printf("Numero de etapas:  ");
	scanf("%d", &n);
	}while(n<2);
	do{
		
	
		printf("\nNombre del ciclista:  ");
		fflush(stdin);
		gets(nombres[x]);
		
		printf("\nPais:  ");
		fflush(stdin);
		gets(pais[x]);
		
		printf("\nNumero de ciclista:  ");
		scanf("%d", &nro[x]);
		
		for(j=0;j<n;j++){	
		printf("\nEtapa n#%d:  ", j+1);
		scanf("%f", &etapas[x][j]);
		}
		
		x++;
	
			
		if(cont>=1){
		
		printf("\n\nHay algun otro ciclista dentro de la competencia <S/N>:  ");
		scanf(" %c", &resp);
		
	
		resp==tolower(resp);
		}
		cont++;
	}while(resp=='s'|| cont<2);
	
	// ganador de la etapa
	
	float menor=99, aux[100];
	int y=0, band1;
	for(i=0;i<x;i++){
		//auxiliar poderoso
		band1=0;
		for(j=0;j<n;j++){
			
					
			if(etapas[i][j]==0){
				band1=1;
				aux[i]+=100;
			}
			if(etapas[i][j]!=0){
				aux[i]+=etapas[i][j];
			
			}
			
	
		}//fin del for
		if(aux[i]<menor){
			menor=aux[i];
			y=i;
		}
	}
	printf("\nGanador es: %s  de %s nro %d en un tiempo de %.1f", nombres[y], pais[y], nro[y], aux[y]);
	
	// listado de ciclistas que se han retirado en la 5ta etapa
	
	int band;
	printf("\n\n");
	for(i=0;i<x;i++){
		band=0;
		for(j=2;j<n;j++){	
	//	printf("\n%f", etapas[i][j]);	//5ta etapa no 2da
			if(etapas[i][j]==0){
				band=1;
				break;
			}
		}
		if(band==1){
		
		printf("\nciclista retirados: ");
		printf("%s", nombres[i]);
		}
	}
	//calcular porcentaje de venezolanos expetuando a los colombianos
	int p, vzl=0;
	p=x;
	float porc;
	for(i=0;i<x;i++){
		
			if(strcmpi(pais[i], "Colombia")==0){
				p--;
			//	printf("\nContador%d", p);
			}
			if(strcmpi(pais[i], "Venezuela")==0){
				vzl++;
			//	printf("\nContador%d", vzl);
			}
			
	}
	porc=(vzl*100)/p;
	printf("\nPorcentaje de Venezolanos en la competencia:  %.2f%%", porc);
	getch();
	return 0;
}
