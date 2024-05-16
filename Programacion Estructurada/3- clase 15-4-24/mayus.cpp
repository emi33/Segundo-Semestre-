#include<stdio.h>
#include<iostream>
std::string mistrcmp(char c1[]){
    
    int longitud=sizeof(c1);
	
for (int i = 0; i < longitud; i++)
{
    c1[i]= c1[i]- 32;
}
    
    return c1;
}
int main(){
    char cadena1[]= "hola a";
	


    std::cout <<cadena1<<" en mayuscula es " << mistrcmp(cadena1)<<std::endl;
}
