#include <iostream>
#include "Lista.h"
#include <queue>
#include <stack>
#include <fstream>

void invertirStack(stack<int> &pila);
void insertarNumero (stack<int> &pila, int num);
queue<string> readFile (string);

int main() {
    Lista* lis = new Lista();
    stack<int> pila;
    queue<string> appleMusic;
    queue<string> spotifyMusic = readFile("Spotify.rtf");

    cout << "Ingresando datos..." << endl;

    lis->InsertarInicio(1);
    lis->InsertarInicio(2);
    lis->InsertarInicio(3);
    lis->InsertarInicio(4);
    lis->InsertarInicio(5);

    cout << "Imprimiendo lista..." << endl;
    lis->Imprimir(); std::cout<<std::endl;
    cout << "Imprimiendo lista recursiva..." << endl;
    lis->ImprimirRecurvio(lis->getNodoInicio());

    cout << endl<<endl;

    // Ingresarle datos a la pila
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);


    std::cout << "Displaying Pila" << std::endl;
    while (!pila.empty()){
        std::cout << pila.top()<< std::endl;
        pila.pop();
    }
    std::cout<<std::endl;

    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    invertirStack(pila);

    std::cout << "Displaying Pila reversed" << std::endl;
    while (!pila.empty()){
        std::cout << pila.top()<< std::endl;
        pila.pop();
    }
    std::cout<<std::endl;

    // -------------- Parte 4 y los extra -------------------------
    appleMusic.push("Song: Titi Me Pregunto\nArtist: Bad Bunny");
    appleMusic.push("Song: Ojitos Lindos\nArtist: Bad Bunny & Bomba Stereo");
    appleMusic.push("Song: Efecto\nArtist: Bad Bunny");

    std::cout << "Displaying Apple Music" << std::endl;
    while (!appleMusic.empty()){
        std::cout << appleMusic.front() << std::endl;
        std::cout << "--" << std::endl;
        appleMusic.pop();
    }

    std:: cout << "Displaying file text" << std::endl;
    std:: cout << "Spotify" << std::endl;
    while (!spotifyMusic.empty()){
        std::cout << spotifyMusic.front() << std::endl;
        std::cout << "--" << std::endl;
        spotifyMusic.pop();
    }

    return 0;
}
void insertarNumero (stack<int> &pila, int num){

    if(pila.empty()){
        pila.push(num);
        return;
    }

    int top = pila.top();
    pila.pop();
    insertarNumero(pila, num);

    pila.push(top);
}

void invertirStack(stack<int> &pila){
    if (pila.empty()){
        return;
    }
    int num = pila.top();
    pila.pop();
    invertirStack(pila);

    insertarNumero(pila, num);

}

queue<string> readFile (string fileName){
    ifstream file(fileName);
    string name;
    string artist;
    queue<string> myMusic;

    if (!file.is_open()){
        throw invalid_argument("There is not file available");
    }

    while (!file.eof()){
        string song = "";
        getline(file, name, '\n');
        getline(file, artist, '\n');
        song += name + "\n" + artist;

        myMusic.push(song);
    }
    file.close();

    return myMusic;


}
