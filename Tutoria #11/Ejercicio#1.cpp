//Crear un programa donde por medio de arboles agregue numeros enteros
//luego a su vez crear una lista enlazada donde se almacenen los numeros
//que el usuario desea añadir y por ultimo mostrar el promedio de la lista
#include <iostream>
//Libreria para "listas"
#include <vector>



using namespace std;

struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

Arbol crearNodo(int valor) {
    Arbol h = new Nodo;
    h->dato = valor;
    h->izq = NULL;
    h->der = NULL;
    return h;
}

void agregarNodo(Arbol a, int valor) {
    Arbol temp = a;
    while(true) {
        if(temp->dato == valor) {
            cout  << "El dato ya existe" << endl;
            return;
        }else if(temp->dato > valor) {
            if(temp->izq == NULL) {
                temp->izq = crearNodo(valor);
                break;
            }else {
                temp = temp->izq;
            }
        }else {
            if(temp->der == NULL) {
                temp->der = crearNodo(valor);
                break;
            }else {
                temp = temp->der;
            }
        }
    }
}

void preOrder(Arbol a) {
    if(a != NULL) {
        cout << a->dato << " ";
        preOrder(a->izq);
        preOrder(a->der);
    }
}

void inOrder(Arbol a) {
    if(a != NULL) {
        inOrder(a->izq);
        cout << a->dato << " ";
        inOrder(a->der);
    }
}

void postOrder(Arbol a) {
    if(a != NULL) {
        postOrder(a->izq);
        postOrder(a->der);
        cout << a->dato << " ";
    }
}

bool searchDato(Arbol a, int dato){
    if(a == NULL) {
        return false;
    }else if(a->dato == dato) {
        return true;
    }else if(a->dato > dato) {
        return searchDato(a->izq, dato);
    }else {
        return searchDato(a->der, dato);
    }
}



int main(){
    Arbol a = crearNodo(8);
    //agregando datos de manera quemada
    agregarNodo(a, 3);
    agregarNodo(a, 10);
    agregarNodo(a, 1);
    agregarNodo(a, 6);
    agregarNodo(a, 14);
    agregarNodo(a, 4);
    agregarNodo(a, 7);
    agregarNodo(a, 13);
    vector<int> lista;

    bool status = true, status2 = true;
    int option,dato;
    int suma,promedio;

    while(status){
        cout<<"\n";
        cout<<"\n*****MENU*****\n";
        cout<<"1. Mostrar el arbol\n";
        cout<<"2. Buscar un dato y agregarlo a la lista\n";
        cout<<"3. Mostrar la lista\n";
        cout<<"4. Mostrar el promedio de la lista\n";
        cout<<"5. Salir del programa\n";
        cout<<"\nIngrese una opcion: "; cin>>option;

        switch(option){
            case 1:
                status2 = true;
                while(status2){
                    cout<<"\nFORMAS DE MOSTRAR EL ARBOL\n";
                    cout<<"1. Pre orden\n";
                    cout<<"2. In orden\n";
                    cout<<"3. Post Orden\n";
                    cout<<"4. Regresar\n";
                    cout<<"\nIngrese una opcion: "; cin>>option;
                    switch(option){
                        case 1:
                            cout<<"\nPre orden\n";
                            preOrder(a);
                            break;
                        case 2:
                            cout<<"\nIn orden\n";
                            inOrder(a);
                            break;
                        case 3:
                            cout<<"\nPost orden\n";
                            postOrder(a);
                            break;
                        case 4:
                            status2 = false;
                            break;
                        default:
                            cout<<"\nOpcion no valida\n";
                            break;
                    }
                }
                break;

            case 2:
                cout<<"Ingrese el valor a buscar y agregar: ";
                cin>>dato;
                if(searchDato(a,dato)){
                    lista.push_back(dato);
                    cout<<"Dato agregado a la lista\n";
                }
                else{
                    cout<<"Dato no encontrado\n";
                }
                break;

            case 3: 
                cout<<"Lista: ";
                for(int i=0;i<lista.size();i++){
                    cout<<lista[i]<<" ";
                }
                break;

            case 4:
                suma = 0;
                promedio = 0;
                for(int i=0;i<lista.size();i++){
                    suma += lista[i];
                }

                promedio = suma / lista.size();
                cout<<"Promedio: "<<promedio;
                break;

            case 5:
                status = false;
                break;

            default:
                cout<<"\nOpcion no valida\n";
                break;
        }
    }


    return 0;
}
