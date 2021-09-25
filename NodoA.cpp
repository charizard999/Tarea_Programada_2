#include "NodoA.h"

NodoA::NodoA() {
	this->dato = 0;
	this->der = NULL;
	this->izq = NULL;
}

NodoA::NodoA(int dato, NodoA* izq, NodoA* der) {
	this->dato = dato;
	this->izq = izq;
	this->der = der;
}

void NodoA::setDato(int dato) {
	this->dato = dato;
}

void NodoA::setDer(NodoA* der) {
	this->der = der;
}

void NodoA::setIzq(NodoA* izq) {
	this->izq = izq;
}

int NodoA::getDato() {
	return this->dato;
}

NodoA* NodoA::getDer() {
	return this->der;
}

NodoA* NodoA::getIzq() {
	return this->izq;
}
