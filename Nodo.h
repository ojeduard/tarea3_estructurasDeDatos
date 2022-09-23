//
// Created by Eduardo Ojeda on 21/9/22.
//

#ifndef TAREA3_NODO_H
#define TAREA3_NODO_H
#include <iostream>
using namespace std;

class Nodo {
private:
    int valor;
    Nodo* next;
    Nodo* anterior;
public:
    Nodo(int = 0, Nodo* = nullptr,Nodo* = nullptr);
    virtual~Nodo();
    void setAnterior(Nodo*);
    int getValor();
    void setSiguiente(Nodo*);
    Nodo* getAnterior();
    Nodo* getSiguiente();

};


#endif //TAREA3_NODO_H
