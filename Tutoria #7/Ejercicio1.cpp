//Realizar un programa en el cual exponga la mayoria de las funcionalidad principales de un vector, brindarle
//al usuario la mayor cantidad de opciones posibles, y permitirle realizar las operaciones que desee.
//NOTA: el vector puede ser de lo que usted desea numeros, palabras, etc.

#include <iostream>
#include <stdlib.h>
#include <string>
//Podemos agregarle color al texto de la consola
#include <windows.h>
//Con esta libreria importamos vector
#include <vector>

using namespace std;

int main(){

    //Los comandos mas usados o comunes son: at, push_back, pop_back, empty, clear, size, begin, end, front, erase

    //Declaramos nuestro vector
    vector<int>numbers;
    
    int option = 0, num=0, search = 0, contDelete = 0;
    string option2 = "";
    bool status = true, validation = false, validation2 = false, status2 = true, validation3 = true;

    do{
        //Estamos definiendo el color del fondo
        system("color 0f");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        cout<<"*****MENU DE VECTOR*****\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout<<"\n1. Ingresar un numero ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"\n2. Consultar cantidad de numeros";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n3. Buscar un numero especifico";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout<<"\n4. Eliminar un numero especifico";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
        cout<<"\n5. Eliminar el ultimo numero";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        cout<<"\n6. Eliminar todos los numeros";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"\n7. Mostrar todos los numeros";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
        cout<<"\n8. Salir";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        cout<<"\n\nElija una opcion: "; cin>>option;

        switch(option)
        {
            case 1:
                cout<<"\nIngrese un numero: "; 
                cin>>num;
                cout<<"\nNumero guardado exitosamente!\n";
                numbers.push_back(num);
                cout<<endl;
                system("pause");
                break;
            
            case 2:
                cout<<"\nEn el vector se encuentran: "<<numbers.size()<<" numeros\n";
                cout<<endl;
                system("pause");
                break;

            case 3:
                cout<<"\nIngrese el numero a buscar: ";
                cin>>search;
                for(int i = 0; i < numbers.size(); i++){
                    if(search == numbers[i]){
                        cout<<"\nEl numero ha sido encontrado en la posicion: "<<i++<<"\n";
                        i = numbers.size() + 1;
                        validation = true;
                    }
                }

                if(!validation){
                    cout<<"\nEl numero no ha sido encontrado....\n";
                }

                cout<<endl;
                system("pause");
                break;

            case 4:
                if(numbers.empty()){
                    cout<<"\nEl vector se encuentra vacio!\n";
                }
                else{
                    cout<<"\nNumero que desea eliminar: ";
                    cin>>search;
                    for(int i = 0; i < numbers.size(); i++){
                        if(search == numbers[i]){
                            numbers.erase(numbers.begin() + contDelete);
                            cout<<"\nNumero eliminado correctamente!\n";
                            i = numbers.size() + 1;
                            validation2 = true;
                        }
                        contDelete++;
                    }

                    if(!validation2){
                        cout<<"\nEl numero que usted ingreso no se encuentra!\n";
                    }

                    cout<<endl;
                    system("pause");
                    break;
                }

            case 5:
                if(numbers.empty()){
                    cout<<"\nEl vector se encuentra vacio!\n";
                }
                else{
                    numbers.pop_back();
                    cout<<"\nEl ultimo numero ha sido eliminado\n";
                }
                cout<<endl;
                system("pause");
                break;

            case 6:
                do{
                    cin.ignore();
                    cout<<"\nEsta seguro que desea eliminar todos los datos? (S/N): ";
                    getline(cin,option2);

                    if(option2 == "s" || option2 == "S"){
                        numbers.clear();
                        cout<<"\nEl vector ha sido vaciado!\n";
                        validation3 = false;
                    }
                    else if(option2 == "n" || option2 == "N"){
                        cout<<"\nRegresando al menu principal.....\n";
                        validation3 = false;
                    }
                    else{
                        validation3 = true;
                    }
                }while(validation3);

                cout<<endl;
                system("pause");
                break;

            case 7:
                if(numbers.empty()){
                    cout<<"\nEl vector se encuentra vacio\n";
                }
                else{
                    for(int i = 0; i < numbers.size(); i++){
                        cout<<numbers[i]<<"  ";
                    }
                }
                cout<<endl<<endl;
                system("pause");
                break;

            case 8:
                cout<<"\nSaliendo...... Fin del programa\n";
                cout<<endl<<endl;
                status = false;
                system("pause");
                break;

            default:
                cout<<"\nOpcion no valida\n";
                cout<<endl;
                system("pause");
                break;

        }
    }while(status);

    return 0;
}


//ALGUNOS COLORES:
//      black=0,
// 		dark_blue=1,
// 		dark_green=2,
// 		dark_aqua,dark_cyan=3,
// 		dark_red=4,
// 		dark_purple=5,dark_pink=5,dark_magenta=5,
// 		dark_yellow=6,
// 		dark_white=7,
// 		gray=8,
// 		blue=9,
// 		green=10,
// 		aqua=11,cyan=11,
// 		red=12,
// 		purple=13,pink=13,magenta=13,
// 		yellow=14,
// 		white=15
