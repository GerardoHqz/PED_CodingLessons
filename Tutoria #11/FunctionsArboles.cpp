#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};
typedef struct nodo *ABB;

ABB CrearNodo(int);
void AsignarNodo(ABB,int);
void PreOrder(ABB);
void InOrder(ABB);
void PostOrder(ABB);
int AlturArbol(ABB);
int CalcularNodos(ABB);
int SumaDeNodos(ABB);
int NodosPares(ABB);
int NodosImpares(ABB);
int SumaPares(ABB);
int SumaImpares(ABB);

int main(){
    ABB arbol;
    bool status = true,status2 = true;
    int opcion,opcion2,raiz,dato;

    cout<<"\nIngrese la riaz del nodo: "; cin>>raiz;
    arbol = CrearNodo(raiz);

    do{
        system("cls");
        cout<<"\n*****MENU*****\n";
        cout << "1. Ingresar nodo al arbol\n";
        cout << "2. Mostrar árbol\n";
        cout << "3. Mostrar la cantidad de niveles del árbol\n";
        cout << "4. Mostrar la cantidad de nodos del árbol\n";
        cout << "5. Mostrar la suma de los valores de todos los nodos del árbol\n";
        cout << "6. Mostrar la cantidad de nodos pares en el arbol\n";
        cout << "7. Mostrar la cantidad de nodos impares en al arbol\n";
        cout << "8. Mostrar la suma de los datos pares del arbol\n";
        cout << "9. Mostrar la suma de los datos impares del arbol\n";
        cout << "10. Salir del programa\n";
        cout << "\nIngrese una opcion: "; cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"\nIngrese un dato: "; cin>>dato;
                AsignarNodo(arbol,dato);
                system("pause");
                break;
            case 2:
                do{
                    cout<<"\nFORMAS DE MOSTRAR EL ARBOL\n";
                    cout<<"1. Pre orden\n";
                    cout<<"2. In orden\n";
                    cout<<"3. Post Orden\n";
                    cout<<"4. Regresar\n";
                    cout<<"Elija una opcion: "; cin>>opcion2;

                    switch(opcion2){
                        case 1:
                            PreOrder(arbol);
                            cout<<endl;
                            break;
                        case 2:
                            InOrder(arbol);
                            cout<<endl;
                            break;
                        case 3:
                            PostOrder(arbol);
                            cout<<endl;
                            break;
                        case 4:
                            status2 = false;
                            break;
                        default:
                            cout<<"\nOpcion no valida\n";
                            break;
                    }
                }while(status2); 
                break;
            case 3:
                cout<<"\nEl arbol tiene una altura de "<<AlturArbol(arbol)<<" nodos"<<endl;
                system("pause");
                break;
            case 4:
                cout<<"\nEl arbol tiene: "<<CalcularNodos(arbol)<<" nodos"<<endl;
                system("pause");
                break;
            case 5:
                cout<<"La suma de los datos de los nodos es: "<<SumaDeNodos(arbol)<<" nodos"<<endl;
                system("pause");
                break;
            case 6:
                cout<<"La cantidad de nodos pares son "<<NodosPares(arbol)<<" nodos"<<endl;
                system("pause");
                break;
            case 7:
                cout<<"La cantidad de nodos impares son "<<NodosImpares(arbol)<<" nodos"<<endl;
                system("pause");
                break;
            case 8:
                cout<<"La suma de los datos pares es "<<SumaPares(arbol)<<endl;
                system("pause");
                break;
            case 9:
                cout<<"La suma de los datos impares son "<<SumaImpares(arbol)<<endl;
                system("pause");
                break;
            case 10:
                status = false;
                cout<<"\nFin del programa\n";
                system("pause");
                break;      
            default:
                cout<<"\nOpcion no valida\n";
                break;
        }
    }while(status);


    return 0;
}

ABB CrearNodo(int valor){
    ABB hijo = new nodo();
    hijo->dato = valor;
    hijo->izq = NULL;
    hijo->der = NULL;
    return hijo;
}

void AsignarNodo(ABB arbol,int valor){
    ABB temporal = arbol;

    while(true){
        if(temporal->dato == valor){
            cout<<"\nEl dato ya existe\n";
            break;
        }
        else if(temporal->dato > valor){
            if(temporal->izq == NULL){
                temporal->izq = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->izq;
            }
        }
        else{
            if(temporal->der == NULL){
                temporal->der = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->der;
            }
        }
    }
}

void PreOrder(ABB arbol){
    if(arbol != NULL){
        cout<< arbol->dato << " ";
        PreOrder(arbol->izq);
        PreOrder(arbol->der);
    }
}

void InOrder(ABB arbol){
    if(arbol != NULL){
        InOrder(arbol->izq);
        cout<<arbol->dato<<" ";
        InOrder(arbol->der);
    }
}

void PostOrder(ABB arbol){
    if(arbol != NULL){
        PostOrder(arbol->izq);
        PostOrder(arbol->der);
        cout<<arbol->dato<<"";
    }
}

int AlturArbol(ABB arbol){
    int alturaIzq = 0, alturaDer = 0;
    if(arbol == NULL){
        return 0;
    }
    else{
        alturaIzq = AlturArbol(arbol->izq);
        alturaDer = AlturArbol(arbol->der);
        
        int altura = max(alturaIzq,alturaDer)+1;

        return altura;
    }
}

int CalcularNodos(ABB arbol){
    if(arbol != NULL){
        int nodos = 1;

        if(arbol->izq != NULL){
            nodos += CalcularNodos(arbol->izq);
        }
        if(arbol->der != NULL){
            nodos += CalcularNodos(arbol->der);
        }
        return nodos;
    }
    else{
        return 0;
    }
}

int SumaDeNodos(ABB arbol){
    if(arbol != NULL){
        int suma = arbol->dato;

        if(arbol->izq != NULL){
            suma += SumaDeNodos(arbol->izq);
        }
        if(arbol->der != NULL){
            suma += SumaDeNodos(arbol->der);
        }
        return suma;
    }
    else{
        return 0;
    }
}

int NodosPares(ABB arbol){
    int pares = 0;
    if( arbol != NULL){
        if(arbol->dato%2 == 0){
            pares++;
        }
        if(arbol->izq != NULL){
            pares += NodosPares(arbol->izq);
        }
        if(arbol->der != NULL){
            pares += NodosPares(arbol->der);
        }
        return pares;
    }
    else{
        return 0;
    }
}

int NodosImpares(ABB arbol){
    int impares = 0;
    if(arbol != NULL){
        if(arbol->dato%2 != 0){
            impares++;
        }
        if(arbol->izq != NULL){
            impares += NodosImpares(arbol->izq);
        }
        if(arbol->der != NULL){
            impares += NodosImpares(arbol->der);
        }
        return impares;
    }
    else{
        return 0;
    }
}

int SumaPares(ABB arbol){
    int suma = 0;
    if(arbol != NULL){
        if(arbol->dato%2 == 0){
            suma += arbol->dato;
        }
        if(arbol->izq != NULL){
            suma += SumaPares(arbol->izq);
        }
        if(arbol->der != NULL){
            suma += SumaPares(arbol->der);
        }
        return suma;
    }
    else{
        return 0;
    }
}

int SumaImpares(ABB arbol){
    int impares = 0;
    if(arbol != NULL){
        if(arbol->dato%2 != 0){
            impares += arbol->dato;
        }
        if(arbol->izq != NULL){
            impares += SumaImpares(arbol->izq);
        }
        if(arbol->der != NULL){
            impares += SumaImpares(arbol->der);
        }
    }
}