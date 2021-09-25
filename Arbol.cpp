#include "Arbol.h";

Arbol::Arbol() {
	this->raiz = NULL;
}

void Arbol::setRaiz(NodoA* raiz) {
	this->raiz = raiz;
}

NodoA* Arbol::getRaiz() {
	return this->raiz;
}

void Arbol::insertar(int dato) {
	//Inserta el primer nodo
	if (raiz == NULL) {
		raiz = new NodoA(dato, NULL, NULL);
	}
	else {
		NodoA* aux = raiz;
		while (aux != NULL) {
			//Inserta al lado izquierdo
			if (dato < aux->getDato()) {
				if (aux->getIzq() != NULL) {
					aux = aux->getIzq();
				}
				else {
					aux->setIzq(new NodoA(dato, NULL, NULL));
					aux = NULL;
				}
			}
			else { //Inserta al lado derecho
				if (dato > aux->getDato()) {
					if (aux->getDer() != NULL) {
						aux = aux->getDer();
					}
					else {
						aux->setDer(new NodoA(dato, NULL, NULL));
						aux = NULL;
					}
				}
			}
		}
	}
}

//Arreglar
void Arbol::eliminar(NodoA* arbol, int dato) {
	//Mientras el arbol contenga nodos.
	if (arbol != NULL) {

		if (arbol->getDato() > dato) {
			eliminar(arbol->getIzq(), dato);

		}
		else {
			if (arbol->getDato() < dato) {
				eliminar(arbol->getDer(), dato);
			}
			else {
				NodoA* aux = arbol;
				//Si es una hoja
				if (aux->getDer() == NULL) {
					arbol = aux->getIzq();
				}
				//Si es una hoja
				else if (aux->getIzq() == NULL) {
					arbol = aux->getDer();
				}
				else {
					//Elimina el dato
					NodoA* aux2 = arbol->getIzq();
					NodoA* aux3 = NULL;
					bool bandera = false;

					while (aux2->getDer() != NULL) {
						aux3 = aux2;
						aux2 = aux2->getDer();
						bandera = true;
					}
					arbol->setDato(aux2->getDato());
					aux = aux2;
					if (bandera) {
						aux3->setDer(aux2->getIzq());
					}
					else {
						arbol->setIzq(aux->getIzq());
					}
				}
			}
		}

	}
}

void Arbol::verArbol(NodoA* arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	verArbol(arbol->getDer(), n + 1);
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}

	cout << arbol->getDato() << endl;

	verArbol(arbol->getIzq(), n + 1);
}

