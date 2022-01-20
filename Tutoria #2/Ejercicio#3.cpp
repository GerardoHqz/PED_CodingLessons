// Escriba programas que resuelvan los siguientes problemas clásicos: El problema de las torres 
// de Hanói. Consiste en mover una torre de discos, de una aguja hacia otra, nada más con la ayuda
// de una aguja auxiliar. La torre consiste de n discos de diferente tamaño, que van colocados uno 
// sobre otro, iniciando en la base con el más grande y terminando en la parte superior con el más 
// pequeño. Solo puede moverse un disco a la vez y en ningún momento un disco puede estar sobre otro 
// más pequeño que él

// hanoi(n,x,y,z) , n == 1 --> Caso base
// hanoi(n,x,y,z) , n > 1 --> Caso recursivo

#include <iostream>
#include <stdlib.h>

using namespace std;

void hanoi(int,int,int,int);

int main(){

    int cant = 0, inicio = 1, aux = 2, fin = 3;
    cout<<"****TORRES DE HANOI****"<<endl<<endl;
    cout<<"Ingrese la cantidad de discos: ";
    cin>>cant;

    hanoi(cant,inicio,aux,fin);


    system("pause");
    system("cls");

    return 0;
}

void hanoi(int cant, int inicio, int aux, int final){
    //caso base o condicion de corte
    if(cant == 1){
        cout<<"El disco "<<cant<<" se mueve de la torre "<<inicio<<" a la torre "<<final<<endl;
    }
    else{
        hanoi(cant-1,inicio,final,aux);
        cout<<"El disco "<<cant<<" se mueve de la torre "<<inicio<<" a la torre "<<final<<endl;
        hanoi(cant-1,aux,inicio,final);
    }
}

