#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "_conio.h"
#include <time.h>
#define T 10

void color(int c){
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}



void marco();	
void cargar(int matriz[][T], int *t1);
void buscar(int matriz[][T], int *t1);
void trans(int matriz[][T], char tecla, int *p, int *t1);
int key_g();
void flechas();
void recur(int i,int j, int matriz[][T], int ll, int l, int *t3);
void comprobar(int matriz[][T], int cont1, int l, int *p, int *t1);
void submenu();
void pantallasalida();

void menu(int *p){
	
	gotoxy(40, 17);
	printf("1. Jugar" );
	gotoxy(40, 18);
	printf("2. Ayuda ");
	gotoxy(40,19);
	printf("3. Creditos ");
	gotoxy(40,20);
	printf("4. Salir ");
	gotoxy(40,21);
	printf("Opcion Seleccionada <1/2/3>");
	scanf("%d", &*p);

	
}

void dificultad(int *t1){
	char op;
	do{
	
	system("CLS");
	 marco();
	gotoxy(25,7);
	color(10);
	for(int i=0;i<10;i++){
		printf("%c", 219);
	}
	printf("%cDIFICULTAD DEL JUEGO%c", 16, 17);
	for(int i=0;i<8;i++){
		printf("%c", 219);
	}
	gotoxy(40,9);
	printf("1. Facil ");
	gotoxy(40,10);
	printf("2. Medio ");
	gotoxy(40,11);
	printf("3. Dificil ");
	gotoxy(40,12);
	printf("Opcion: ");
	op=key_g();
	if(op==49){
		*t1=6;
	}else if(op==50){
	*t1=8;	
	} else if(op==51){
		*t1=10; 
	} 
	}while(op!=49 && op!=50 && op!=51);

//	scanf("%d", &*t1);

	
}

int main(){
	
		system("MODE CON COLS=100 LINES=40");
	
	int matriz[T][T], p=0, cont1, l, resp, cont, t1;
	unsigned char tecla;

	 
	 
	do{
	submenu();				
	marco();
	
	menu(&p);	
	 
	
	 system("CLS");
	
	 if(p==1 || p==7)	dificultad(&t1);
	 	
	 while(p==1){
	  												
		p=0;
		cargar(matriz, &t1);	
		if(t1==6) cont=14;
		else if(t1==8) cont=18;
		else if(t1==10) cont=24;
			do{
				system("CLS");
			buscar(matriz, &t1);	
			gotoxy(3,10);
			color(12);
			printf("N# de intentos ");
			gotoxy(3,11);
			printf("restantes:%d", cont);
			tecla=key_g();
			trans(matriz, tecla, &p, &t1);
			if(p==5 && cont>0){
				system("CLS");
				buscar(matriz, &t1);
				color(14);
				printf("\n\n\n\t\t\t\t\t¡Ha ganado felicitaciones!");
				Sleep(3000);
				p=7;
				system("CLS");
				break;	
			}	

			cont--;
		
		
			}while(tecla!=27 && p!=1 && p!=2 && p!=3 && p!=5 && p!=4 && p!=6 && cont>0);
			if(cont==0){
				system("CLS");
				buscar(matriz, &t1);
				color(11);
				gotoxy(24,24);
				printf("Ha perdido llore :c");
				Sleep(3000);
				p=7;
				system("CLS");	
			} 
	 }
		system("CLS");
		if(p==2){ //ayuda
		color(14);
			printf("\t\t\t\t\t\tCOMO JUGAR");
			color(15);
			printf("\n\n\n\n\n\t\t1.- Cada vez que seleccione un color de la parte"
				"inferior de la pantalla\n\t\t las casillas empezando"
				"por la superior izquierda cambiaran a ese color.\n\n");
			printf("\t\t2.- Todas las casillas contiguas con el mismo color "
					"tambien cambiaran.\n\n");
			printf("\t\t3.- En los movimientos disponibles indicados sobre el "
					"tablero, deberas \n\t\tseleccionar los colores hasta que todo "
					"quede relleno con un unico color");
					gotoxy(50,20);
					color(12);
					printf("Presione R para regresar al menu principal");			
			tecla=key_g();
		}		 
	
		if(p==3){ // creditos
			marco();
			color(15);
			gotoxy(20,15);
			printf("Nombre y apellidos: Yeltsin Ruben Ramirez C. Computacion I Seccion 17");
			color(12);
			gotoxy(30,25);
			printf("Presione R para regresar al menu principal");	
			tecla=key_g();
		}
			if(tecla==82) system("CLS"), p=6;
		if(p==4){
		pantallasalida();
		
		}		
	}while(p==6 || p==7);
	
	getch();
	return 0;
}

void pantallasalida(){
	marco();
	int mapa2[6][30]={{0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0},
	           		  {0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0},
				      {0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,0},
				      {0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,1,0,0},
			          {0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0},
			          {1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0}};
	for(int i=0;i<6;i++){
		for(int j=0;j<30;j++){
			if(mapa2[i][j]==1){
				color(i+9);
				gotoxy(j+35,i+12);
			printf("%c", 219);	
			}
		
		}
	}
}

 void marco(){  //Es solo para la presentacion 
							
	for(int i=0;i<35;i++){
		for(int j=0;j<100;j++){
			if(i==0){
					
					if(j<50){
					gotoxy(j,0);
					color(10);
					printf("%c", 219);		
					}else if(j>=50 && j<100){
					gotoxy(j,0);
					color(12);
					printf("%c", 219);		
					}
			}else{
				if(i<33){
				gotoxy(0,i);
				color(13);
				printf("%c", 219);
				gotoxy(99, i);
				color(14);
				printf("%c", 219);	
				}
				if(i==33){
				
						gotoxy(j,33);
						color(15);
						printf("%c", 219);
				}
					
			}

		}
		
	}

 	
 }
 void submenu(){
 	
 	int  colorflood[7][56]={{0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1}, //1,1,1,1,1,1,1,1,1,1
 							{0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1},
 							{0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1},
 							{0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1},
 							{0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1},
 							{0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1},
 							{0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1},
	 						};
							
	 	for(int i=0;i<7;i++){
	 		for(int j=0;j<56;j++){
	 			if(colorflood[i][j]==0){
	 				color(9+i);
	 				gotoxy(j+25,i+4);
	 				printf("%c", 219);
				 }
			 }
		 }					
 	
 }
 
void cargar(int matriz[][T], int *t1){ // Genera la matriz random
	
	srand(time(NULL));
	
	for(int i=0;i<*t1;i++){
		for(int j=0;j<*t1;j++){
		matriz[i][j]=rand()%6+1;
		}
	}

}

void flechas(){  //intrucciones en base a teclas 
	
	gotoxy(18,29);
	color(160);
	printf("A: Azul   S: Rojo   D: Amarillo   F: Blanco   G: Morado   H: Verde ");
	gotoxy(34,31);
	color(76);
		printf("Z: Salir a menu  R: Reiniciar Juego");
	color(0);
}
void buscar(int matriz[][T], int *t1){ // identifica los numeros enteros para colorearlos
	submenu();
	int aux;
	aux=*t1;
	printf("\n\n");
		for(int i=0;i<*t1;i++){
	
		printf("\n\t\t\t");

		for(int j=0;j<*t1;j++){
			
			switch (matriz[i][j]){
				
				case 1: textbgcolor(RED,LIGHT_RED);
						printf("       ", matriz[i][j]);
						textbgcolor(BLACK,BLACK);
						break;
				case 2: textbgcolor(BLUE,LIGHT_BLUE);
						printf("       ",  matriz[i][j]);
						textbgcolor(BLACK,BLACK);
						
						break;
				case 3: textbgcolor(YELLOW, LIGHT_YELLOW);
						printf("       ",  matriz[i][j]);
						textbgcolor(BLACK,BLACK);
						break;
				case 4: textbgcolor(WHITE,LIGHT_WHITE);
						printf("       ",  matriz[i][j]);
						textbgcolor(BLACK,BLACK);
						break;
				case 5: textbgcolor(PURPLE,LIGHT_PURPLE);
						printf("       ",  matriz[i][j]);
						textbgcolor(BLACK,BLACK);
						break;
				case 6: textbgcolor(GREEN, LIGHT_GREEN);
						printf("       ",  matriz[i][j]);
						textbgcolor(BLACK,BLACK);
						break;
						
			}
			
		}
	}
	flechas();	
}

void trans(int matriz[][T], char tecla, int *p, int *t1){  // casos para cada tecla 
	
	int i=0, ll, j=0, l, cont1;
			switch (tecla){
				
				case 83: // s rojo 1
						l=1;
			 			ll=matriz[0][0];
						recur(0,0, matriz, ll, l, t1);
						matriz[0][0]=1;		
							comprobar(matriz, cont1, l, p, t1);
						
					break;				
				case 65: // a 2 azul
						l=2;
				 		ll=matriz[0][0];
						recur(0,0, matriz, ll, l, t1);
						matriz[0][0]=2;	
							comprobar(matriz, cont1, l, p, t1);			

					break;
				case 68: // d 3 amarillo
							
						l=3;
				 		ll=matriz[0][0];
						recur(0,0, matriz, ll, l, t1);
						matriz[0][0]=3;	
							comprobar(matriz, cont1, l, p, t1);
						break;
				case 70: // F 4 blanco
						l=4;
				 		ll=matriz[0][0];
						recur(0,0, matriz, ll, l, t1);
						matriz[0][0]=4;
							comprobar(matriz, cont1, l, p, t1);	
						break;
				case 71: // G 5 morado
						l=5;
				 		ll=matriz[0][0];
						recur(0,0, matriz, ll, l, t1);
						matriz[0][0]=5;
							comprobar(matriz, cont1, l, p, t1);	
						break;
				break;
				case 72: // H 6 verde 
						l=6;
				 		ll=matriz[0][0];
						recur(0,0, matriz, ll, l, t1);
						matriz[0][0]=6;
							comprobar(matriz, cont1, l, p, t1);
									
					break;	
					
				case 82: *p=1;
						 break;
				case 90: *p=6;
						break;		 	
			}
		}
		
void comprobar(int matriz[][T], int cont1, int l, int *p, int *t1){
	cont1=0;
	for(int i=0;i<*t1;i++){
		for(int j=0;j<*t1;j++){
			if(matriz[i][j]==l){
				cont1++;
			}
		}
	}
	
	if(cont1==(*t1)*(*t1))	*p=5;
 
}		

int key_g(){ // para transformar las teclas
	int key;
	
	key=toupper(getch());
	
	if(key==224)  key=toupper(getch());
	return key;
}


void recur(int i,int j, int matriz[][T], int ll, int l, int *t3){ // algoritmo de busqueda "la loquera"
	int t2;
	if(j+1<=10){
		if(matriz[i][j+1]==ll){
			matriz[i][j]=l;
			recur(i,j+1,matriz, ll, l, &t2);
		}else{
			matriz[i][j]=l;
		
		}
	}
	if(j-1>=0 && matriz[i][j-1]!=l){
		if(matriz[i][j-1]==ll){
			matriz[i][j]=l;
			recur(i,j-1,matriz, ll, l, &t2);
		}else{
			matriz[i][j]=l;
		
		}
	}
	if(i-1>=0 && matriz[i-1][j]!=l){
		if(matriz[i-1][j]==ll){
			matriz[i][j]=l;
			recur(i-1,j,matriz, ll, l, &t2);
		}else{
			matriz[i][j]=l;
		
		}
	}
	if(i+1<10){
		if(matriz[i+1][j]==ll){
			matriz[i][j]=l;
			recur(i+1,j,matriz, ll, l, &t2);
		}else{
			matriz[i][j]=l;
		
		}
	}	
}


