#include "Nodo.h"
#include "Persona.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
	Nodo::Nodo() {

	}
	Nodo::Nodo(int idSupervisor, Persona dato)
	{
		this->idSupervisor = idSupervisor;
		this->dato = dato;
	}

	vector<Nodo*> Nodo::getHijos() {
		return this->hijos;
	}

	void Nodo::setHijos(Nodo* hijos) {
		this->hijos.push_back(hijos);
	}

	void Nodo::setIdSupervisor(int idSupervisor) {
		this->idSupervisor = idSupervisor;
	}

	int Nodo::getIdSupervisor() {
		return this->idSupervisor;
	}

	Persona Nodo::getDato() {
		return this->dato;
	}

	void Nodo::setDato(Persona dato) {
		this->dato = dato;
	}


	Nodo* Nodo::getPadre() {
		return this->padre;
	}

	void Nodo::setPadre(Nodo* padre) {
		this->padre = padre;
	}



Nodo* raiz;

int Nodo::insert(Nodo* raiz, int idSupervisor, vector<Nodo*> vectorHijos)
{
	vector<Nodo*>aux2 = vectorHijos;
	if (raiz == NULL)
		return 0;

	if (raiz->getIdSupervisor() == idSupervisor)
	{
		for (int i = 0; i < aux2.size(); i++)
		{
			Nodo* node = aux2[i];
			node->setPadre(raiz);
			raiz->setHijos(node);

		}
		return 1;
	}
	else
	{
		for (int i = 0; i < raiz->getHijos().size(); i++)
		{
			vector<Nodo*> aux = raiz->getHijos();
			int resultFlag = insert(aux[i], idSupervisor, vectorHijos);
			if (resultFlag == 1)
			{
				return 1;
			}

		}
	}
	return -1;
}

void Nodo::muestraNiveles(Nodo* raiz)
{
	if (raiz == NULL)
	{
		return;
	}

	cout << raiz->getDato().getHorasLaboradas()<< " " <<raiz->getDato().getNombre() << " " << raiz->getIdSupervisor() << endl;
	vector<Nodo*>aux4 = raiz->getHijos();

	for (int i = 0; i < aux4.size(); i++) {
		muestraNiveles(aux4[i]);
	}

}


//Imprime el árbol por niveles.
void Nodo::imprimeNiveles(Nodo* raiz)
{

	if (raiz == NULL)
		return;

	queue<Nodo*> cola;
	cola.push(raiz);

	while (!cola.empty()) {
		int n = cola.size();

		//Si el nodo tiene hijos
		while (n > 0)
		{
			//Elimina un elemento de la cola y lo imprime
			Nodo* p = cola.front();
			cola.pop();
			cout << p->getDato().getIdEmpleado() << " ";
			vector<Nodo*>aux5 = p->getHijos();
			//Agrego a la cola a las hijos del nodo eliminado.
			for (int i = 0; i < aux5.size(); i++)
				cola.push(aux5[i]);
			n--;
		}

		cout << endl; //Realiza salto de línea por cada nivel.
	}
}

void Nodo::prueba(Persona persona) {
	vector<Persona> personas = persona.getPersonas();
	vector<int> supervisores = persona.getSupervisores();


}
void Nodo::agregar(Persona persona) {

	vector<Persona> personas = persona.getPersonas();
	vector<int> supervisores = persona.getSupervisores();

	int idPadre;

	for (int i = 0; i < supervisores.size(); i++) {
		for (int j = 0; j < personas.size(); j++) {
			if (supervisores[i] == 0){
				
				raiz = new Nodo(supervisores[i], personas[0]);
				idPadre = supervisores[i];
				if (personas[j].getIdSupervisoro() == supervisores[i]) {
					vector<Nodo*> nuevosHijos;
					nuevosHijos.push_back(new Nodo(supervisores[i], personas[j]));
					insert(raiz, supervisores[i], nuevosHijos);
				}
				
			}
			else {
				
				if (supervisores[i] == personas[j].getIdSupervisoro()) {
					//cout << "entra" << endl;
					idPadre = supervisores[i];
					vector<Nodo*> nuevosHijos;
					nuevosHijos.push_back(new Nodo(supervisores[i], personas[j]));
					insert(raiz, supervisores[i], nuevosHijos);
				}
			}
			
		}
	}

	imprimeNiveles(raiz);
}



/*
//EJEMPLO
class Datos {
private:
	int idEmpleado;
	int idSupervisor;

public:
	Datos(int idEmpleado, int idSupervisor) {
		this->idEmpleado = idEmpleado;
		this->idSupervisor = idSupervisor;
	}
	void setIdEmpleado(int idEmpleado) {
		this->idEmpleado = idEmpleado;
	}

	void setIdSupervisor(int idSupervisor) {
		this->idSupervisor = idSupervisor;
	}

	int getIdEmpleado() {
		return this->idEmpleado;
	}

	int getIdSupervisor() {
		return this->idSupervisor;
	}
};

int main() {

	vector<Nodo*> datos;
	//                padre                          data
	// 0 es el padre(id supervisor) y 1 es la raiz(id empleado)
	//raiz
	datos.push_back(new Nodo(0, 1));

	datos.push_back(new Nodo(1, 2));
	datos.push_back(new Nodo(1, 3));
	datos.push_back(new Nodo(1, 4));
	datos.push_back(new Nodo(2, 5));
	datos.push_back(new Nodo(2, 6));
	datos.push_back(new Nodo(5, 7));

	int padreId = 0;

	vector<Nodo*>aux;
	for (int i = 0; i < datos.size(); i++) {
		if (i == 0) {//raiz
			raiz = datos[0];
			int padreId = raiz->getPadre();//Empleado 1, supervisor 0
		}
		else {
			if (raiz->getData() == datos[i]->getPadre()) {
				vector<Nodo*>nuevos1;
				nuevos1.push_back(datos[i]);
				insert(raiz, padreId, nuevos1);
				aux = nuevos1;
			}
			else {
				cout << "datos else" << datos[i]->getPadre();
				int padre = datos[i]->getPadre();
				for (int j = 0; j < aux.size(); j++) {
					if (padre == aux[j]->getData()) {
						cout << "ENTRA" << endl;
						int padreId = padre;
						vector<Nodo*>nuevos2;
						nuevos2.push_back(datos[i]);
						insert(raiz, padreId, nuevos2);
					}
				}
				/*cout<<"nuevo: "<<nuevos1[i]->getPadre()<<endl;
				padreId = nuevos1[i]->getPadre();
				if(padreId==datos[i]->getPadre()){
					vector<Nodo*>nuevos2;
					nuevos2.push_back(datos[i]);
					insert(raiz, padreId, nuevos2);
				}

			}

		}
	}

	//Ingresa datos manualmente (PRUEBA)
	
	raiz = datos[0];
	int padreId = raiz->getPadre();//Empleado 1, supervisor 0

	vector<Nodo*>nuevos1;
	nuevos1.push_back(datos[1]);
	nuevos1.push_back(datos[2]);
	nuevos1.push_back(datos[3]);
	insert(raiz, padreId, nuevos1);
	cout<<"padre id"<<padreId<<endl;

	padreId = datos[1]->getPadre();
	vector<Nodo*>nuevos2;
	nuevos2.push_back(datos[4]);
	nuevos2.push_back(datos[5]);
	insert(raiz, padreId, nuevos2);*/


	//PRUEBA de inserción 

	/*for(int i=0;i<datos.size();i++){
		if(datos[i]->getPadre()==0){
			//NODO RAIZ (jefe)
			raiz = datos[i];
			padreId = raiz->getPadre();
			cout<<"PADRE ID"<<padreId<<endl;
		}else{
			//nodo actual id empleado == datos id supervisor
			//if(raiz->getData()==datos[i]->getPadre()){
			if(raiz->getData()==datos[i]->getPadre()){
				cout<<"empleado #"<<datos[i]->getData()<<endl;
				vector<Nodo*>nuevos;
				nuevos.push_back(datos[i]);
				insert(raiz, padreId, nuevos);

			}else{

				cout<<raiz->getPadre()<<" padre(id supervisor)"<<endl;
				cout<<raiz->getData()<<" dato(id empleado)"<<endl;
				padreId = datos[i]->getPadre();

				cout<<padreId<<" padreId del else"<<endl;

					if(datos[i]->getPadre()==padreId){

						vector<Nodo*>nuevos;
						nuevos.push_back(datos[i]);
						insert(raiz, padreId, nuevos);
					}
			}

		}
	}	


	muestraNiveles(raiz);
	cout << endl << endl << endl;
	imprimeNiveles(raiz);

	return 0;
}*/
