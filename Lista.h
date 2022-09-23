//
// Created by Eduardo Ojeda on 21/9/22.
//

#ifndef TAREA3_LISTA_H
#define TAREA3_LISTA_H
#include "Nodo.h"


class Lista {
private:
    Nodo* Inicio;
    Nodo* Final;
    int cuentaNodos;
public:
    Lista();
    virtual~Lista();
    void InsertarInicio(int);
    void Borrar(int);
    Nodo* Buscar(int);
    void eliminarLista();
    void Imprimir();
    Nodo* getNodoInicio();
    void ImprimirRecurvio(Nodo* node);


};


#endif //TAREA3_LISTA_H
