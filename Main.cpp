#include "Persona.h"
#include "Arbol.h"

using namespace std;

int main() {

	Arbol arbol = Arbol();
	Persona persona =  Persona();

	persona.cargarPersona();
	persona.actualizarMontoBruto();
	persona.actualizarHoras();

	//arbol.insertar(persona);
	system("pause");
	return 0;
}


