#include <iostream>
using namespace std;
double menor(double num1,double num2,double num3,double num4);
double mayor(double num1,double num2,double num3,double num4);
double promedio(double num1,double num2,double num3,double num4);
int main() {
    double num1, num2, num3, num4;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    cout << "Ingrese el tercer numero: ";
    cin >> num3;
    cout << "Ingrese el cuarto numero: ";
    cin >> num4;

    cout << "El menor es: " << menor(num1, num2, num3, num4) << endl;
    cout << "El mayor es: " << mayor(num1, num2, num3, num4) << endl;
    cout << "El promedio es: " << promedio(num1, num2, num3, num4) << endl;

    return 0;
}
double menor(double num1,double num2,double num3,double num4){
      
      double menor = num1;
    if (num2 < menor)
    {
          menor = num2;
    }
    else if (num3 < menor)
    {
        menor = num3;
    }
    else if (num4 < menor)
    {
          menor = num4;
    }
    return menor;
}
double mayor(double num1,double num2,double num3,double num4){
      double mayor = num1;
       if (num2 > mayor)
    {
          mayor = num2;
    }
    else if (num3 > mayor)
    {
        mayor = num3;
    }
    else if (num4 > mayor)
    {
          mayor = num4;
    }
    return mayor;
}
double promedio(double num1,double num2,double num3,double num4){
  double promedio = (num1 + num2 + num3 + num4) / 4.0;
  return promedio;
}