//
// Created by Eduardo Ojeda on 21/9/22.
//

#include "Lista.h"
Lista::Lista(){
    Inicio = nullptr;
    Final = nullptr;
    cuentaNodos = 0;
}
Lista::~Lista() { eliminarLista(); }
void Lista::InsertarInicio(int x){
    if (!Inicio) {
        Inicio = new Nodo(x);
        Final = Inicio;
        cuentaNodos++;
    }
    else {
        Nodo* p = new Nodo(x,Inicio);

        Inicio = p;
        Inicio->getSiguiente()->setAnterior(Inicio);
        cuentaNodos++;
    }

}
void Lista::Borrar(int pos){
    Nodo* p = Inicio;
    if (pos > 0 && pos <= cuentaNodos) {
        if (pos == 1 && cuentaNodos >= 1) {
            Inicio = Inicio->getSiguiente();
            Inicio->setAnterior(p->getAnterior());
            delete p;
            cuentaNodos--;
        }
        else if (pos > 1 && cuentaNodos > 1) {
            while (pos > 1) {
                p = p->getSiguiente();
                pos--;
            }
            Nodo* aux = p->getAnterior();
            aux->setSiguiente(p->getSiguiente());
            if(p)
                delete p;
            cuentaNodos--;
        }


    }
    else
        cout << "Posicion Incorrecta" << endl;
}


Nodo* Lista::Buscar(int pos){
    Nodo* p = Inicio;
    if (pos > 0 && pos <= cuentaNodos) {
        if (pos == 1 && cuentaNodos >= 1) {
            return Inicio;
        }
        else if (pos > 1 && cuentaNodos > 1) {
            while (pos > 1) {
                p = p->getSiguiente();
                pos--;
            }
            return p;
        }
    }
    else {
        //throw invalid_argument("Posicion Incorrect");
        return nullptr;
    }
}
void Lista::eliminarLista(){
    Nodo* p = Inicio;
    while (p) {

        Inicio = Inicio->getSiguiente();
        delete p;
        p = Inicio;
    }

}
void Lista::Imprimir() {
    Nodo* p = Inicio;
    while (p) {
        cout << "Valor: " << p->getValor() << " ";
        p = p->getSiguiente();
    }

}

void Lista::ImprimirRecurvio(Nodo * node) {

    if (node->getSiguiente() == nullptr){
        cout << "Valor: " << node->getValor() << " ";
        return;
    }
    ImprimirRecurvio(node->getSiguiente());
    cout << "Valor: " << node->getValor() << " ";

}

Nodo *Lista::getNodoInicio() {
    return Inicio;
}
