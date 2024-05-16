
#include <stdio.h>
#include <string.h>
#include <iostream>
int main(){
    //usar strcmp, escribir dos cadenas. determinar si son iguales, mayores o menores;
    char cadena1[]="HOLA A";
    char cadena2[]="HOLA B";
	
	int i=0;
	int v=0;

	v = strcmp(cadena1, cadena2);
	if( v < 0 )  {
		printf( " menor que " );
	}
	else if( v > 0 )  {
		printf( " mayor que " );
	}
	else  {
		printf( " igual a " );
	}
	
	std::cout<< cadena2 <<std::endl	;
	
	std::cout<< " valor: " << v <<std::endl;
	
	return 0;
	
}
