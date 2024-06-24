#include<stdio.h>
#include<conio.h>
int main(void){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%i",a[i]);
    }
    getch();
    return 0;
}