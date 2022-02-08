// Se le solicita hacer un programa con uso de colas (queue), donde el programa consta en que se quiere hacer una cola de 
// canciones, el programa tendra que tener 3 playlist (colas), una para cuando estas feliz, una de canciones tristes y una playlist 
// para estudiar, cada playlist debe tener las opciones de agregar cancion, elminar una cancion, vaciar la playlist, mostrar 
// todas las canciones en la playlist. Cada canion debe tener un titulo, el nombre del autor, el genero musical y la duracion en segundos

#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

//creando la estrcuctura Cancion
struct Canciones{
    string title;
    string author;
    string gen;
    int duration;
};

void ShowQueue(queue<Canciones>);

int main (){

    //Declaracion de variables y estructuras
    Canciones playList;
    
    //Creando las 3 colas que seran nuestras playlist
    queue<Canciones>PlaylistHappy;
    queue<Canciones>PlayListSad;
    queue<Canciones>PlayListStudy;

    bool status = true;
    int option = 0, option2 = 0;

    do{
        system("cls");
        cout<<"************SPOTIFY UCA************";
        cout<<"\n1. Ingresar una cancion";
        cout<<"\n2. Eliminar una cancion";
        cout<<"\n3. Vaciar la playlist";
        cout<<"\n4. Mostrar playlist";
        cout<<"\n5. Salir\n";
        cout<<"\nElija una opcion: "; cin>> option;

        switch(option){
            case 1:
                cin.ignore();
                do{
                    cout<<"\nTitulo: "; getline(cin,playList.title);
                }while(playList.title.empty());
                do{
                    cout<<"Autor: "; getline(cin,playList.author);
                }while(playList.author.empty());
                do{
                    cout<<"Genero: "; getline(cin,playList.gen);
                }while(playList.gen.empty());
                do{
                    cout<<"Duracion (seg): "; cin>>playList.duration;
                }while(playList.duration <= 0);

                cout<<endl;
                cout<<"****PlayList Disponibles****";
                cout<<"\n1. PlayList Feliz";
                cout<<"\n2. PlayList Triste";
                cout<<"\n3. PlayList para Estudiar";
                cout<<"\nA que playlist desea agregar la cancion: "; cin>>option2;
                cout<<"\nCancion guardada exitosamente\n\n";

                switch (option2){
                    case 1:
                        PlaylistHappy.push(playList);
                        break;
                    case 2:
                        PlayListSad.push(playList);
                        break;
                    case 3:
                        PlayListStudy.push(playList);
                        break;
                    default:
                        cout<<"\nOpcion no valida...";
                        break;
                }

                system("pause");
                break;

            case 2:
                cout<<endl;
                cout<<"****PlayList Disponibles****";
                cout<<"\n1. PlayList Feliz";
                cout<<"\n2. PlayList Triste";
                cout<<"\n3. PlayList para Estudiar";
                cout<<"\nA que playlist desea eliminar una cancion: "; cin>>option2;
                cout<<"\nCancion borrada exitosamente\n";

                switch (option2){
                    case 1:
                        if(PlaylistHappy.empty()){
                            cout<<"\nLa Playlist esta vacia...\n";
                        }
                        else{
                            PlaylistHappy.pop();
                        }
                        break;
                    case 2:
                        if(PlayListSad.empty()){
                            cout<<"\nLa Playlist esta vacia\n";
                        }else{
                            PlayListSad.pop();
                        }
                        break;
                    case 3:
                        if(PlayListStudy.empty()){
                            cout<<"\nLa Playlist esta vacia\n";
                        }else{
                            PlayListStudy.pop();
                        }
                        break;
                    default:
                        cout<<"\nOpcion no valida...\n";
                        break;
                }

                system("pause");
                break;

            case 3:
                cout<<endl;
                cout<<"****PlayList Disponibles****";
                cout<<"\n1. PlayList Feliz";
                cout<<"\n2. PlayList Triste";
                cout<<"\n3. PlayList para Estudiar";
                cout<<"\nQue playlist desea vaciar: "; cin>>option2;

                switch (option2) {
                    case 1:
                        if(PlaylistHappy.empty()){
                            cout<<"\nLa playlist ya esta vacia!\n";
                        }
                        else{
                            while(!PlaylistHappy.empty()){
                                PlaylistHappy.pop();
                            }
                            cout<<"\nVaciando playlist........ LISTO!\n";
                        }

                        system("pause");
                        break;
                    case 2: 
                        if(PlayListSad.empty()){
                            cout<<"\nLa playlist ya esta vacia!\n";
                        }
                        else{
                            while(!PlayListSad.empty()){
                                PlayListSad.pop();
                            }
                            cout<<"\nVaciando playlist........ LISTO!\n";
                        }

                        system("pause");
                        break;
                    case 3:
                        if(PlayListStudy.empty()){
                            cout<<"\nLa playlist ya esta vacia!\n";
                        }
                        else{
                            while(!PlayListStudy.empty()){
                                PlayListStudy.pop();
                            }
                            cout<<"\nVaciando playlist........ LISTO!\n";
                        }
                        break;
                    default:
                        cout<<"\nOpcion no valida.";
                        system("pause");
                        break;
                }
                break;

            case 4:
                cout<<endl;
                cout<<"****PlayList Disponibles****";
                cout<<"\n1. PlayList Feliz";
                cout<<"\n2. PlayList Triste";
                cout<<"\n3. PlayList para Estudiar";
                cout<<"\nQue playlist desea ver: "; cin>>option2;

                switch(option2){
                    case 1:
                        cout<<endl;
                        ShowQueue(PlaylistHappy);
                        break;
                    case 2:
                        cout<<endl;
                        ShowQueue(PlayListSad);
                        break;
                    case 3:
                        cout<<endl;
                        ShowQueue(PlayListStudy);
                        break;
                    default:
                        cout<<endl;
                        cout<<"\nOpcion no valida\n";
                        break;
                }

                system("pause");
                break;

            case 5:
                cout<<"\nSaliendo...... Spotify UCA.\n\n";
                status = false;
                system("pause");
                break;

            default:
                cout<<"\nOpcion no valida\n";
                system("pause");
                break;
        }

    }while(status);



    return 0;
}

void ShowQueue(queue<Canciones>Playlist){
    queue<Canciones>clone = Playlist;
    if(clone.empty()){
        cout<<"\nLa playlist esta vacia.";
    }
    else{
        while(!clone.empty()){
            cout<<"* "<<clone.front().title<<", "<<clone.front().author<<", "<<clone.front().gen<<", "<<clone.front().duration<<" segundos\n";
            clone.pop();
        }
        cout<<endl;
    }
}

