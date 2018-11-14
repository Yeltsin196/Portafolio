#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
void color(int c){
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}	


int main (){
	
	char pelicula[50][50];
	int cantp, i, j, cpm[50], spm[50], npm[50], a1=0, a2=0,  a3=0, cant1[50], menor=99, c=0;
	float pro1[50];
	
	color(15);
	printf("\nCantidad de peliculas en cartelera:  ");
	scanf("%d", &cantp);
	printf("\n");
	for(i=0;i<cantp;i++){
		color(14);
		fflush(stdin);
		printf("\nNombre de la pelicula:  ");
		
		gets(pelicula[i]);
		color(7);
		printf("\nCantidad de asistencia a las 5pm:  ");
		scanf("%d", &cpm[i]);
		a1+=cpm[i];
		printf("\nCantidad de asistencia a las 7pm:  ");
		scanf("%d", &spm[i]);
		a2+=spm[i];
		printf("\nCantidad de asistencia a las 9pm:  ");
		scanf("%d", &npm[i]);
		a3+=npm[i];
		pro1[i]=cpm[i]+spm[i]+npm[i];
		pro1[i]/=3;
		
	}
	for(i=0;i<cantp;i++){
		printf("\n\nPromedio para pelicula %s %.2f", pelicula[i], pro1[i]);
	}
	
	color(12);
		printf("\n\n");
		if((a1>a2 && a1>a3) || (a1==a2 || a1==a3)){
			printf("\nLas personas prefieren el horario de las 5");
		}

		if((a2>a1 && a2>a3) || (a2==a1 || a2==a3)){
			printf("\nLas personas prefieren el horario de las 7");
		}
		if((a3>a1 && a3>a2) || (a3==a1 || a3==a2)){
			printf("\nLas personas prefieren el horairo de las 9");
		}
	
	for(i=0;i<cantp;i++){
		if(spm[i]<menor){
			menor=cpm[i];
			c=i;	
		}	
		if(i==cantp-1){
			printf("\n\nLa pelicula con menor asistencia a las 7:  %s", pelicula[c]);
		}
	}

	
	getch();
	return 0;
}
