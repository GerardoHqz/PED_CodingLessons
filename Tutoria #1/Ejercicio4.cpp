// #4. Dada una cadena de caracteres que ha sido ingresada por el usuario. 
// Crear una función que devuelva la posición de un carácter específico dentro de la cadena, 
// utilizando punteros.

#include <iostream>
#include <cstring>

using namespace std;

int SearchCharacter(char *, char );

int main(){

    char word[20] , *puntero,search;
    puntero = word;
    
    cout<<"Digite una palabra: "; cin>>puntero;
    cout<<"\nDigite el caracter que desea buscar: "; cin>>search;
    cout<<"\nLa posicion del caracter "<<search<<" es: "<<SearchCharacter(puntero,search);


    return 0;
}

int SearchCharacter(char *puntero, char search){
    int size = strlen(puntero);
    int position = 0;

    for (int i = 0; i < size; i++){
        if (puntero[i] == search){
            position = i;
            i = size;
        }
    }

    return position+1;
}