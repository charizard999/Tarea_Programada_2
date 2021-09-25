#pragma once
#include "NodoA.h"
#include <stdio.h>
#include <iostream>

class Arbol {
private:

	NodoA* raiz;

public:
	Arbol();
	void setRaiz(NodoA* raiz);
	NodoA* getRaiz();
	void insertar(int dato);
	void verArbol(NodoA* arbol, int n);
	void eliminar(NodoA* arbol, int dato);

};

