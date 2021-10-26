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
	void insertar(Persona dato);
	void verArbol(NodoA* arbol, int n);
	Persona buscar(NodoA* arbol, int id);
	void recorrerPersonas(vector<Persona> vectorPersonas);
};

