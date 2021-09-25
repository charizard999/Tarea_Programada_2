#pragma once

#include <cstddef>
#include <istream>

using namespace std;

class NodoA {
private:
	int dato;
	NodoA* izq;
	NodoA* der;

public:
	NodoA();
	NodoA(int dato, NodoA* izq, NodoA* der);
	void setDato(int dato);
	void setIzq(NodoA* izq);
	void setDer(NodoA* der);
	int getDato();
	NodoA* getIzq();
	NodoA* getDer();



};

