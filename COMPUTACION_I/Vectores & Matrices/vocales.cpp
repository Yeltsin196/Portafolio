// almacene las vocales en un arreglo de caracteres y las consonantes en otro distinto 

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


int main(){
	
	char melo[10], vocales[9], consonantes[9];
	int i, x=0, y=0;
	
	printf("\nIngrese cadena de caracteres:  ");
	fflush(stdin);
	scanf("%9[^\n]", melo);
	
	for(i=0;i<strlen(melo);i++){
		melo[i]=tolower(melo[i]);
		if(melo[i]=='a' || melo[i]=='e' || melo[i]=='i' || melo[i]=='o' || melo[i]=='u'){
			vocales[x]=melo[i];
			x++;			
		}else{
			consonantes[y]=melo[i];
			y++;
		}


		
		
	}
		
	consonantes[x]='\0';
	vocales[y]='\0';
	

	printf("\nVocales: %s", vocales);
	

	printf("\nConsonantes: %s", consonantes);

		
	
	
	
	getch();
	return 0;
}
