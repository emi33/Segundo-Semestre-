#include<stdio.h>
#include<iostream>
int mistrcmp(char c1[],char c2[]){
int diff=0, i=0;
bool flag=true;
    while (flag){
		i++;
        if (c1[i]!=c2[i]){
            diff= c1[i]-c2[i];
            flag=false;
        }
    }
    return diff;
}
int main(){
    std::string valor = "0";
    char cadena1[]= "hola a";
    char cadena2[]="hola a";

    int v=0;
    v= mistrcmp(cadena1,cadena2);
    if( v < 0 )  {
		valor="menor";
	}
	else if( v > 0 )  {
		valor="mayor";
	}
	else if (v=0) {
		valor="igual";
	}
    std::cout <<cadena1<<" es " << valor << " a "<<cadena2<<std::endl;
}
