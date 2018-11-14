#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
		//prototipos
		void membrete();
		int numero(int n);
		int numero1(int n1);
		void calculos2(int e , int f, int g, int h, int n1, int band1);
		void calculos3(int v1[], int v2[], int a , int b, int c, int d, int e, int f, int g, int h, int n, int n1,  int matriz[][4]);
		void calculos4(int matriz[][4], int n, int n1, int aux[]);
		void color(int c);
		void creditos();
int main(){
	int n, n1,a ,b ,c, d ,e, f,g, h; // la d
	int v1[4], v2[4], matriz[4][4], aux[8];
	char resp;

	do{
		
	system("CLS");
	membrete();
	n=numero(n);
	n1=numero1(n1);
	
	b=(n%1000)/100;
	c=(n%100)/10;
	d=((n%1000)%10)%10;
	if(n>=1000){	
		a=n/1000; 
	}

	f=(n1%1000)/100;
	g=(n1%100)/10;
	h=((n1%1000)%10)%10;
	if(n1>1000){	
		e=n1/1000;
	}

	calculos3(v1, v2, a,b, c,d,e,f,g,h, n, n1, matriz);
	calculos4(matriz, n,n1, aux);
	printf("\n");
	color(12);
	printf("\nDesea volver a intentarlo? <S/N>:  ");
	scanf(" %c", &resp);
	resp=tolower(resp);
	
	}while(resp=='s');
	creditos();
	getch();
	return 0;
}

void membrete(){
	color(31); 
	int i;
	printf("                              Multiplicaci%cn Arabe                              ", 162);	
	for(i=0;i<80;i++){
		printf("%c", 205);	
	}
	printf("\n");
}

int numero(int n){
	int c1=0;
	do{
		if(c1>0)
		{
			color(12);
			printf("\nIntroduzca un numero de 3 o 4 cifras\n");
		}
		color(15);
		printf("Numero a ingresar:  ");
		scanf("%d", &n);
	c1++;
	}while(n<100 || n>9999);
	return n;
}
 int numero1(int n1){
 	int c1=0;
 	do{
 		if(c1>0){
 			color(12);
 			printf("\nIntroduzca un numero de 3 o 4 cifras");
		 }
 		color(15);
 		printf("\nNumero que desea multiplicar:  ");
 		scanf("%d", &n1);
 		c1++;
	 }while(n1<100 || n1>9999);
	 return n1;
 }


void calculos3(int v1[], int v2[], int a , int b, int c, int d, int e, int f, int g, int h, int n, int n1, int matriz[][4]){
	
	int i , j , x, y;
	if(n>=1000){
		v1[0]=d;
		v1[1]=c;
		v1[2]=b;
		v1[3]=a;
		x=4;	
	}else{
		v1[0]=d;
		v1[1]=c;
		v1[2]=b;
		x=3;
	}
	
	if(n1>=1000){
		v2[0]=e;
		v2[1]=f;
		v2[2]=g;
		v2[3]=h;
			y=4;
	}else{
		v2[0]=f;
		v2[1]=g;
		v2[2]=h;
		y=3;
	}
	printf("\n");
		for(i=0;i<y;i++){
			color(30);
			printf("\t\t%d  %c", v2[i], 179);
		}
		printf("\n%c", 218);
		for(i=0;i<66;i++){
			if(i==18 || i==34 || i==50){
				printf("%c", 194);
			}else{
					printf("%c", 196);
			}
		}
		printf("%c", 191);
	for(i=0;i<x;i++){
		printf("\n");
			
		for(j=0;j<y;j++){
			if(j==0){
			
				printf("%c %d %c", 179, v1[i], 179);
			}
			matriz[i][j]=v1[i]*v2[j];		//calculo multiplicacion
			color(30);
			printf("\t    [ %d\\%d ]%c", matriz[i][j]/10, matriz[i][j]%10, 179);// observar
				
		}
	}
color(30);
printf("\n%c", 192);
	for(i=0;i<66;i++){
			printf("%c", 196);
		}
		printf("%c", 217);
}

void calculos4(int matriz[][4], int n, int n1, int aux[]){
	int cont,x, y, i, j, modulo=0, modulo1=0, cont1=0, z=7, cont2=0, m, aux1=0;
	if(n>=1000 && n1>=1000){
		x=4,	y=3; //cambio en y
			j=1;	
			color(14);
			printf("\n");
		do{
			i=0,cont=0, cont1=0,	m=y;
			printf("\nSuma # %d   ", cont2+1);
			do{
				cont1++;
				if(cont1%2!=0)
				{	
	
				if(cont1>2){
					i++;
				}
						modulo+=matriz[i][m]%10;
					printf("%d+", matriz[i][m]%10);
					
				}else if(cont1%2==0){		
				m++;
					modulo1+=matriz[i][m]/10;
					printf("%d+", matriz[i][m]/10);
				}
				
				cont++;
			}while(cont<j);
			aux[z]=modulo+modulo1+aux1;	
			printf(" (%d) ", aux1);	
			printf("= %d", aux[z]);
				color(14);
				if(aux[z]>=10){
				
				aux1=aux[z]/10;
				aux[z]=aux[z]%10;
			
				}else{ //printf(" (%d) ", aux1);
					aux[z]=aux[z]%10;
					aux1=0;

				}
			y--,j+=2 , z--, cont2++, modulo=0,	modulo1=0;
		}while(x>cont2);
		y=0, cont1=0, j=7,  i=0,  cont2=0, modulo=0, modulo1=0;
		do{
			cont=0, m=0, y=i, cont1=0;
			printf("\nSuma # %d   ", cont2+5);
			do{
				cont1++;
				if(cont1%2!=0)
				{

								if(cont1>2){
										m++;
								}
							modulo1+=matriz[y][m]/10;
								printf("%d+", matriz[y][m]/10);
						
				}else if(cont1%2==0){
					y++;
					modulo+=matriz[y][m]%10;
						printf("%d+", matriz[y][m]%10);
				}	
				cont++;	
					
			}while(cont<j);
			aux[z]=modulo+modulo1+aux1;
					printf(" (%d) ", aux1);
					printf(" = %d", aux[z]);
				if(aux[z]>=10){	
				aux1=aux[z]/10;
				aux[z]=aux[z]%10;

				}else{ 
					aux[z]=aux[z]%10;
					aux1=0;
				}
			
			j-=2,	i++,	cont2++,		z--,	modulo=0,	modulo1=0;
		}while(x>cont2);
		printf("\n\nResultado es:  ");
		for(i=0;i<8;i++){
			printf("\t%d", aux[i]);
		}
	}
	
	if((n>=100 && n<=999) && (n1>=100 && n1<=999)){
		x=3,	y=3,	j=1,	z=6;
		do{	
			cont=0,	y--,m=y,i=0;
			color(14);
				printf("\n\nSuma#%d= ", cont2+1);
			do{	
				cont++;
				if(cont%2==0){
						m++;
						modulo+=matriz[i][m]/10;
						printf("%d+", matriz[i][m]/10);
				}else if(cont!=0){
					if(cont>2){
						i++;
					}
					modulo1+=matriz[i][m]%10;
					printf("%d+", matriz[i][m]%10);
				}

			}while(cont<j);
					aux[z]=modulo+modulo1+aux1;
				if(aux[z]>=10){	printf(" (%d) ", aux1);
						printf("= %d", aux[z]);
					aux1=aux[z]/10;
					aux[z]=aux[z]%10;
					}else{	printf(" (%d) ", aux1);
						printf("= %d", aux[z]);
						aux[z]=aux[z]%10;	
						aux1=0;
					}
				
			j+=2,	z--,cont2++,	modulo=0,modulo1=0;
			
		}while(x>cont2);
		j=5, i=0,	cont2=0,	modulo=0,	modulo1=0;
		do{
			m=0,cont=0,	y=i;
				printf("\n\nSuma#%d= ", cont2+4);
			do{
				cont++;
				if(cont%2==0){
					if(cont!=1){
						y++;	
					}		
					modulo1+=matriz[y][m]%10;
						printf("%d+", matriz[y][m]%10);
				}else if(cont!=0){	
					if(cont>2){
							m++;
					}
					modulo+=matriz[y][m]/10;
							printf("%d+", matriz[y][m]/10);
				}
			}while(cont<j);
	
			aux[z]=modulo+modulo1+aux1;
				if(aux[z]>=10){	printf(" (%d) ", aux1);
						printf("= %d", aux[z]);
					aux1=aux[z]/10;
					aux[z]=aux[z]%10;

				
					}else{  printf(" (%d) ", aux1);
						printf("= %d", aux[z]);
						aux[z]=aux[z]%10;
						aux1=0;
					}

				j-=2,	z--,	i++, modulo=0, modulo1=0,	cont2++;
		}while(x>cont2);
		printf("\n\n\nResultado es:  ");
		for(i=0;i<7;i++){
			if(i!=0){
			printf("\t%d", aux[i]);
			}
		}
		printf("\n");
	}
		
	if((n>=100 && n<=999) && (n1>=1000 && n1<10000)){
		x=4,	y=4, j=1,	 cont=0,  z=7;                                                                  
		do{
			y--,	m=y, 	i=0,	cont=0, modulo1=0, modulo=0;
			color(14);
				printf("\n\nSuma#%d= ", cont2+1);
			do{
				cont++;
				if(cont%2==0){
					
					m++;
						modulo+=matriz[i][m]/10;
						printf("%d+", matriz[i][m]/10);
				}else if(cont%2!=0){
					if(cont>2){
						i++;
					}
					if(i>2){
						break;
					}
						modulo1+=matriz[i][m]%10;
						printf("%d+", matriz[i][m]%10);
				}

			}while(cont<j);

					aux[z]=modulo+modulo1+aux1;
				if(aux[z]>=10){	printf(" (%d) ", aux1);
				printf("= %d", aux[z]);
					aux1=aux[z]/10;
					aux[z]=aux[z]%10;

					}else{  printf(" (%d) ", aux1);
					printf("= %d", aux[z]);
						aux[z]=aux[z]%10;
						aux1=0;
					}
						printf("= %d", aux[z]);
			cont2++, j+=2, modulo=0, modulo1=0,	z--;
		}while(x>cont2);
		j=5,cont=0, cont2=1,	y=0	,i=0,	m=0,modulo1=0,modulo=0;
		
		do{	
			printf("\n\nSuma#%d= ", cont2+4);
			cont=0,y=i;
			do{
				cont++;
				if(cont%2==0){

						modulo1+=matriz[y][m]%10;
						printf("%d+", matriz[y][m]%10);
					m++;

				}else if(cont%2!=0){
					
					//impresion 
					modulo+=matriz[y][m]/10;
					printf("%d+", matriz[y][m]/10);
					y++;
				}

			}while(cont<j);
				
				aux[z]=modulo+modulo1+aux1;
				if(aux[z]>=10){	printf(" (%d) ", aux1);
				printf("= %d", aux[z]);
					aux1=aux[z]/10;
					aux[z]=aux[z]%10;

					}else{  printf(" (%d) ", aux1);
					printf("= %d", aux[z]);
						aux[z]=aux[z]%10;
						aux1=0;
					}
			cont2++,	m=0,	j-=2, i++, modulo=0, modulo1=0, z--;
		}while(x>cont2);
		printf("\n\n\nResultado es:  ");
		for(i=0;i<8;i++){
			if(i!=0){
					printf("\t%d", aux[i]);	
			}
		}
		printf("\n");
	}
	
	if((n>=1000 && n<10000) && (n1>=100 && n1<=999)){
		x=3,cont2=0, y=2, m, cont=0, aux1=0, j=1, modulo=0, modulo1=0, z=6;
		do{
			color(14);
			printf("\n\nSuma#%d= ", cont2+1);
			i=0, m=y, cont=0;
			do{
				cont++;	
				if(cont%2==0){
			
				m++;
				modulo+=matriz[i][m]/10;
				printf("%d+", matriz[i][m]/10);
				}else if(cont%2!=0){
						if(cont>2){
						i++;
					}
					modulo1+=matriz[i][m]%10;
						printf("%d+", matriz[i][m]%10);
				}
			
			}while(cont<j);
					aux[z]=modulo+modulo1+aux1;			
				if(aux[z]>=10){		printf(" (%d) ", aux1);
					aux1=aux[z]/10;
					aux[z]=aux[z]%10;

			
					}else{
						aux[z]=aux[z]%10;
						aux1=0;
							printf(" (%d) ", aux1);	
					}
					printf("= %d", aux[z]);
				
			 y--, z--,cont2++,  modulo=0, modulo1=0,j+=2;
		}while(x>cont2);
		x=4, j=6,modulo=0, modulo1=0, cont=0, cont2=0, y=0, m=0, i=0;
		do{
			y=i, m=0,cont=0;
				printf("\n\nSuma#%d= ", cont2+4);
			do{
				cont++;
				if(cont%2==0){
					y++;
						modulo1+=matriz[y][m]%10;
							printf("%d+", matriz[y][m]%10);
				}else if(cont%2!=0){
					if(cont!=1){
						m++;
					}
					modulo+=matriz[y][m]/10;
						printf("%d+", matriz[y][m]/10);
				}
			}while(cont<j);
				i++;
						aux[z]=modulo+modulo1+aux1;	
						printf(" (%d) ", aux1);	
				if(aux[z]>=10){	
					printf("= %d", aux[z]);
					aux1=aux[z]/10;
					aux[z]=aux[z]%10;
					}else{ 
						printf("= %d", aux[z]);
						aux[z]=aux[z]%10;
						aux1=0;
					}	
				cont2++, z--, modulo=0, modulo1=0; 
				if(cont2==1){
					j=5;
				}else{
					j-=2;	
				}		
		}while(x>cont2);
	printf("\n\nResultado es:  ");
		for(i=0;i<7;i++){
			printf("\t%d", aux[i]);
		}
		printf("\n");
	}
}
void creditos(){
	color(15);
	printf("\n\n            Hecho por Yeltsin Ruben Ramirez Carlosama");
	printf("\n             CIV 25496541  Seccion  Computacion I");
	
}

void color(int c){
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}	
