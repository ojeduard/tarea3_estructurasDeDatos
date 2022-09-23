//
// Created by Eduardo Ojeda on 21/9/22.
//

#include "Nodo.h"

Nodo::Nodo(int x, Nodo* sig, Nodo* ant) { valor = x;
    next = sig;
    anterior = ant;
}
Nodo::~Nodo(){}
Nodo* Nodo::getAnterior() { return anterior; }
void Nodo::setSiguiente(Nodo* n) { next = n; }
Nodo* Nodo::getSiguiente() { return next; }
void Nodo::setAnterior(Nodo* n) { anterior = n; }
int Nodo::getValor() { return valor; }