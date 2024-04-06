#include<stdio.h>
#include <iostream>
#include <string>
void modificar(int *p){
    *p=10;
}
int main(){
    int n=6;
    modificar(&n);
    std::string s = std::to_string(n);
    std::cout << s << std::endl;
    return 0;
}
