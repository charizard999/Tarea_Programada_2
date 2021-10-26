#include "Persona.h"
#include "Nodo.h"

using namespace std;

int main() {

	
	Persona persona =  Persona();
	
	persona.cargarPersona();
	persona.actualizarMontoBruto();
	persona.actualizarHoras();
	persona.obtenerSupervisores();
	
	Nodo* nodo = new Nodo();
	nodo->agregar(persona);

	nodo->prueba(persona);

	system("pause");
	return 0;
}


