#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>


void color(int c){
	
	HANDLE consol;
	consol=	GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(consol,c);
}	

int main(){


for(int i=0;i<256;i++){
	
	
	color(i);

	printf("%d",i);
 printf(" hola mundo\n" );
 	
 

	
}



system("pause");
 return 0;
	
	
}

 
