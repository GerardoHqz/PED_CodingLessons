// #4 En una librería un cliente desea saber el número total de páginas de cierto libro, pero este se encuentra en 
// un montón de libros apilados sobre una mesa. Elaborar una función recursiva o normal que reciba la pila de libros y el título 
// del libro, y devuelva la cantidad de páginas de este. Utilice la siguiente estructura: 
/* 
    struct Libro { 
        string título; 
        int numPags; 
    };  
*/

#include <iostream>
#include <stdlib.h>
#include <string>
//Esta es la libreria para invocar los metodos de una pila
#include <stack>

using namespace std;

struct Libro{
    string titulo;
    int numPags;
};

void PushStack(stack<Libro>&, string, int);
void CantPages(stack<Libro>&, string);

int main(){
    stack<Libro> books;
    string title;

    //Dato Quemado: es un dato que "el programador ha definido" es decir no se le pide al usuario ya esta por defecto
    PushStack(books, "El señor de los anillos", 10);
    PushStack(books, "Harry Potter", 500);
    PushStack(books, "El principito", 200);
    PushStack(books, "Elenor y Park", 300);
    PushStack(books, "Cuentos de barro", 150);

    cout<<"***** BLIBLITECA UCA *****"<<endl;
    cout<<"Digite el titulo del libro: "; 
    getline(cin,title);

    CantPages(books, title);


    return 0;
}

void PushStack(stack<Libro>&books, string title, int numPages){
    Libro book;
    book.titulo = title;
    book.numPags = numPages;
    //con el .push() se invoca el metodo push de la libreria stack que sirve para añadir un dato
    books.push(book);
};

void CantPages(stack<Libro>&books, string title){
    while(!books.empty()){
        if(books.top().titulo == title){
            cout<<"El libro "<<books.top().titulo<<" tiene "<<books.top().numPags<<" paginas"<<endl;
            break;
        }
        else{
            books.pop();
        }
    }
};

