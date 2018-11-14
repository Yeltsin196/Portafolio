#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main (){
	float porcentaje;
	char	inst [20][23], clas [20], copia_ins[20][23], copia_clas[20], veri_inst[23], resp;
	int	tot_alum[20], cant_doc [20];
	int i, cont1=0, cont2=0, cont3=0, cont4=0, cant_superior, conterror=0;
	for (i=0;i<2;i++){
		printf("\n\nNombre de la institucion:  ");
		fflush(stdin);
		scanf("%22[^\n]", inst[i]);
		
		printf("\nClasificacion:  ");
		scanf(" %c", &clas[i]);
		
		printf("\nNumero total de almunos:  ");
		scanf("%d", &tot_alum[i]);
		
		printf("\nCantidad de docentes ordinarios:  ");
		scanf("%d", &cant_doc[i]);
		
		cant_superior=cant_doc[i]*10;
		
		if(clas[i]=='a' && tot_alum[i]>cant_superior){
			cont1++;
		}
		
		if(tot_alum[i]>cant_doc[i]){
			strcpy(copia_ins[i],inst[i]);
			copia_clas[i]=clas[i];
			cont2++;
		}
		
	}

	porcentaje=cont1*100/2;
	printf("\n\nEl porcentaje de instituciones es: %.1f%%", porcentaje);
	
	for(i=0;i<cont2;i++){
	if(i==0){
		printf("\n\n\tINSTITUCIONES CON MAS ALUM QUE PROF.");
	}
	printf("\n%s %c\n\n\n\n", copia_ins[i], copia_clas[i]);

	}
	system("PAUSE");
	system("CLS");
	
	do{
	
	if(cont4==0){
	printf("\n\nConsulta de instituciones");
	}
	if(conterror>0){
		printf("\n\nInstitucion no existente");
	}
	
		
	printf("\nInstitucion:  ");
	fflush(stdin);
	scanf("%22[^\n]", veri_inst);	
	for(i=0;i<2;i++){
		
	
		if(strcmp(inst[i], veri_inst)==0){
		printf("\n\nclasificacion %c", clas[i]);
		cont3++;
		}else{
			conterror++;
		}
		
	}
	if(cont3>0){
		
	
	printf("\nDesea consultar otra institucion? S/N:  ");
	scanf(" %c", &resp);
	resp=tolower(resp);
	cont4=0;
	
	conterror=0;
	}
	cont4++;
	}while(resp=='s' || conterror>0);
	

	
	getch();
	return 0;
}
