#include<stdio.h>
int main(){
    int A[3][4], i, j;
    for (i=0;i<3;i++){
        for (j=0; j<4; j++){
            A[i][j]= i+j;
        }
    }
    return 0;
}