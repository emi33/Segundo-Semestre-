#include<stdio.h>
float calcular(float a[], float b[], float c);
float calcular1 (float a[ ],float b[ ],float c[ ]);
float calcular2 (float a,float b,float c);

float calcular3 (float a,float b,float c[ ]) 
int main(){
    float n1, n2;
    float r1[2],r2[2];
    n1=calcular(r1,r2,n2);
    n1=calcular1(r1,r2,n2);// error en n2, mal 
    n1=calcular2(r1,r2,n2);// error en r1 y r2
    n1=calcular3(r1,r2,n2);
    return 0;
}
//cual de las siguientes es correcta
float calcular(float a[], float b[], float c){
    return 0.0;
};//la primera es la correcta
float calcular1 (float a[ ],float b[ ],float c[ ]){
    return 1.0;
};
float calcular2 (float a,float b,float c){
    return 2.0;
};

float calcular3 (float a,float b,float c[ ]) {
    return 3.0;
}