// Construir una función recursiva que calcule la suma de los n primeros números naturales.
// suma(n) = 1 , n=1 -----> caso base o condicion de corte
// suma(n) = n + suma(n-1) , n>1 -----> caso recursivo

#include <iostream>
#include <stdlib.h>

using namespace std;

//Prototipo de funcione
int suma(int);

int main(){

    int number = 0;
    cout<<"****SUMADORA RECURSIVA****"<<endl;
    cout<<"Ingrese el numero natural hasta el que desea sumar: ";
    cin>>number;

    cout<<"La suma de los numeros naturales hasta "<<number<<" es: "<<suma(number)<<endl<<endl;

    system("pause");
    system("cls");

    return 0;
}

int suma(int number){
    if(number == 1){
        return 1;
    }
    else{
        return number + suma(number-1);
    }
}



