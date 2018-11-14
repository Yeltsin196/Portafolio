#include "libro.h"

libro::libro()
{
}
libro::libro(char *nom, int codigo){
	strcpy(nom,nom);
	this->codigo=codigo;
}
