
// #5. Escribir un programa en C++ que reciba una cadena de caracteres, luego escribir 
// una función que reciba la dirección de inicio de la cadena y devuelva el número de vocales 
// que hay en la cadena.

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int CountVowels(char *);

int main(){

    char word[20] , *puntero;
    puntero = word;

    cout<<"Digite una palabra: "; cin>>puntero;
    cout<<"\nEl numero de vocales es: "<<CountVowels(puntero) << endl;


    system("pause");
    system("cls");

    return 0;
}

int CountVowels(char *puntero){
    int cont = 0;
    for (int i = 0 ; i < strlen(puntero) ; i++){
        // if (puntero[i] == 'a' || puntero[i] == 'e' || puntero[i] == 'i' || puntero[i] == 'o' || puntero[i] == 'u'){
        //     cont++;
        // }

        switch (puntero[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cont++;
                break;
            default:
                break;
        }

    }

    return cont;
}