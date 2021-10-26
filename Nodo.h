#pragma once
#include <stdio.h>
#include <iostream>
#include "Persona.h"
using namespace std;
class Nodo {
private:
	Persona dato;
	int idSupervisor;
	vector<Nodo*> hijos;
	Nodo* padre;

public:
	Nodo* raiz;
	Nodo();
	Nodo(int idSupervisor, Persona dato);
	void setDato(Persona dato);
	Persona getDato();
	void setIdSupervisor(int idSupervisor);
	int getIdSupervisor();
	void setHijos(Nodo* hijos);
	vector<Nodo*> getHijos();
	void setPadre(Nodo* padre);
	Nodo* getPadre();

	int insert(Nodo* raiz, int idSupervisor, vector<Nodo*> vectorHijos);
	void muestraNiveles(Nodo* raiz);
	void imprimeNiveles(Nodo* raiz);
	void agregar(Persona persona);
	void prueba(Persona persona);
};

