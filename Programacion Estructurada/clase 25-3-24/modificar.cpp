#include<stdio.h>
#include <iostream>
#include <string>
void modificar (int x){
    x=10;
}
int main(){
    int n=5;
    modificar(n);
    std::string s = std::to_string(n);
    std::cout << s << std::endl;
    return 0;
}
