#include<stdio.h>
#include<conio.h>
int main(){
    int a=-1,b=0;
    //condiciones equivalentes
    if (a>b){
        printf("verdadero 1\n"); 
    }
    if (a>b!=0)
    {
        printf("verdadero 2");
    }
    getch();
    return 0;
}