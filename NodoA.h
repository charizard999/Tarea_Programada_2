#pragma once
#include "Persona.h"
#include <cstddef>
#include <istream>

using namespace std;

class NodoA {
private:
	Persona dato;
	NodoA* izq;
	NodoA* der;

public:
	NodoA();
	NodoA(Persona dato, NodoA* izq, NodoA* der);
	void setDato(Persona dato);
	void setIzq(NodoA* izq);
	void setDer(NodoA* der);
	Persona getDato();
	NodoA* getIzq();
	NodoA* getDer();
};

