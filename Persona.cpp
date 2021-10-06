#include "Persona.h"

Persona::Persona(){
	this->idEmpleado = 0; 
	this->nombre = "";
	this->apellido = "";
	this->correo = "";
	this->tipoEmpleado = 0;
	this->idSupervisor = 0;
	this->pagoMensualBruto = 0;
	this->montoxHora = 0;
	this->horasLaboradas = 0;
}
//Constructor con parametros
Persona::Persona(int idEmpleado, string nombre, string apellido, string correo,
	int tipoEmpleado, int idSupervisor, double pagoMensualBruto,double montoxHora, int horasLaboradas) {
	
	this->idEmpleado = idEmpleado;
	this->nombre = nombre;
	this->apellido = apellido;
	this->correo = correo;
	this->tipoEmpleado = tipoEmpleado;
	this->idSupervisor = idSupervisor;
	this->pagoMensualBruto = pagoMensualBruto;
	this->montoxHora = montoxHora;
	this->horasLaboradas = horasLaboradas;
}


void Persona::cargarPersona() {

	string valor;
	int contador = 1;
	int cont2 = 1;
	char caracter;

	ifstream fe("../Tarea_Programada_2/Personas.txt");

	vector<string> vLineas;
	string palabra;
	string linea = "";

	while (!fe.eof()) {
		fe >> palabra;

		if (contador < 6) {
			linea = linea + palabra + " ";
			contador = contador + 1;
		}
		else if (contador == 6) {
			linea = linea + palabra + " ";
			vLineas.push_back(linea);
			contador = 1;
			linea = "";
		}

	}
	for (int i = 0; i < vLineas.size(); i++) {
		//cout << "Persona #" << i+1 << endl;
		Persona persona = Persona();

		string linea = vLineas[i];
		for (int j = 0; j < linea.size(); j++) {
			caracter = linea[j];
			if (caracter != ' ') {
				valor = valor + caracter;

			}
			else {

				if (cont2 == 1) {
					/*cout << "entra" << endl;*/
					persona.setIdEmpleado(atoi(valor.c_str()));

				}
				else if (cont2 == 2) {
					persona.setNombre(valor);

				}
				else if (cont2 == 3) {
					persona.setApellido(valor);

				}
				else if (cont2 == 4) {
					persona.setCorreo(valor);

				}
				else if (cont2 == 5) {
					persona.setTipoEmpleado(atoi(valor.c_str()));

				}
				else if (cont2 == 6) {
					persona.setIdSupervisor(atoi(valor.c_str()));
					cont2 = 0;
				}
				cont2 = cont2 + 1;
				valor = "";
			}
		}
		personas.push_back(persona);
	}
/*cout << endl << endl;
	cout << "PERSONAS" << endl;
	for (int z = 0; z < personas.size(); z++) {
		if (z == 0) {
			personas[z].setIdEmpleado(1);
		}

		cout << "ID EMPLEADO: " << personas[z].idEmpleado << endl;
		cout << "NOMBRE: " << personas[z].nombre << endl;
		cout << "APELLIDO: " << personas[z].apellido << endl;
		cout << "CORREO: " << personas[z].correo << endl;
		cout << "TIPO EMPLEADO: " << personas[z].tipoEmpleado << endl;
		cout << "ID SUPERVISOR: " << personas[z].idSupervisor << endl;
		cout << endl << endl;
	}*/

	

	fe.close();

}


void Persona::actualizarMontoBruto() {
	string valor;
	int cont2 = 1;
	char caracter;

	vector<string>vLineasNomina;
	string palabra = "";
	int contador = 1;
	string linea = "";

	ifstream fe("../Tarea_Programada_2/Nomina.txt");
	
	while (!fe.eof()) {
		fe >> palabra;
		if (contador < 2) {
			linea = linea + palabra + " ";
			contador = contador + 1;
		}
		else if (contador == 2) {
			linea = linea + palabra + " ";
			vLineasNomina.push_back(linea);
			contador = 1;
			linea = "";
		}
	}

	for (int i = 0; i < vLineasNomina.size(); i++) {

		string linea = vLineasNomina[i];
		for (int j = 0; j < linea.size(); j++) {
			caracter = linea[j];
			if (caracter != ' ') {
				valor = valor + caracter;

			}
			else {

				if (cont2 == 2) {
					personas[i].setPagoMensualBruto(stod(valor));
					//persona.setNombre(valor);//
					cont2 = 0;
				}
				cont2 = cont2 + 1;
				valor = "";
			}
		}
	
	}
	/*cout << endl << endl;
	cout << "PERSONAS" << endl;
	for (int z = 0; z < personas.size(); z++) {
		if (z == 0) {
			personas[z].setIdEmpleado(1);
		}

		cout << "ID EMPLEADO: " << personas[z].idEmpleado << endl;
		cout << "NOMBRE: " << personas[z].nombre << endl;
		cout << "APELLIDO: " << personas[z].apellido << endl;
		cout << "CORREO: " << personas[z].correo << endl;
		cout << "TIPO EMPLEADO: " << personas[z].tipoEmpleado << endl;
		cout << "ID SUPERVISOR: " << personas[z].idSupervisor << endl;
		cout << "MONTO BRUTO: " << personas[z].pagoMensualBruto << endl;
		cout << endl << endl;
	}
	*/
	
	fe.close();

}

void Persona::actualizarHoras() {
	int cont3 = 450;
	string valor;
	int cont2 = 1;
	char caracter;

	vector<string>vLineasHoras;
	string palabra = "";
	int contador = 1;
	string linea = "";

	ifstream fe("../Tarea_Programada_2/HorasTrabajadas.txt");

	while (!fe.eof()) {
		fe >> palabra;
		if (contador < 3) {
			linea = linea + palabra + " ";
			contador = contador + 1;
		}
		else if (contador == 3) {
			linea = linea + palabra + " ";
			vLineasHoras.push_back(linea);
			contador = 1;
			linea = "";
		}
	}

	for (int i = 0; i < vLineasHoras.size(); i++) {
		
		cout << "contador " << cont3 << endl;
		string linea = vLineasHoras[i];
		for (int j = 0; j < linea.size(); j++) {
			caracter = linea[j];
			if (caracter != ' ') {
				valor = valor + caracter;

			}
			else {
				
				if (cont2 == 2) {
					personas[cont3].setMontoxHora(stod(valor));
					cout << "PRUEBAAAAAAAAAAA: " << personas[cont3].nombre << endl;

				}
				else if (cont2 == 3) {
					personas[cont3].setHorasLaboradas(atoi(valor.c_str()));
					cont2 = 0;
				}
				cont2 = cont2 + 1;
				valor = "";

			}

		}
		cont3 = cont3 + 1;

	}
	
	cout << endl << endl;
	cout << "PERSONAS" << endl;
	for (int z = 0; z < personas.size(); z++) {
		if (z == 0) {
			personas[z].setIdEmpleado(1);
		}

		cout << "ID EMPLEADO: " << personas[z].idEmpleado << endl;
		cout << "NOMBRE: " << personas[z].nombre << endl;
		cout << "APELLIDO: " << personas[z].apellido << endl;
		cout << "CORREO: " << personas[z].correo << endl;
		cout << "TIPO EMPLEADO: " << personas[z].tipoEmpleado << endl;
		cout << "ID SUPERVISOR: " << personas[z].idSupervisor << endl;
		cout << "MONTO BRUTO: " << personas[z].pagoMensualBruto << endl;
		cout << "MONTO POR HORA: " << personas[z].montoxHora << endl;
		cout << "HORAS LABORADAS: " << personas[z].horasLaboradas << endl;
		cout << endl << endl;
	}

	fe.close();

}
	

void Persona::setIdEmpleado(int idEmpleado) {
	this->idEmpleado = idEmpleado;
}
int Persona::getIdEmpleado() {
	return idEmpleado;
}

void Persona::setNombre(string nombre) {
	this->nombre = nombre;
}
string Persona::getNombre() {
	return nombre;
}

void Persona::setApellido(string apellido) {
	this->apellido = apellido;
}
string Persona::getApellido() {
	return apellido;
}

void Persona::setCorreo(string correo) {
	this->correo = correo;
}
string Persona::getCorreo() {
	return correo;
}

void Persona::setTipoEmpleado(int tipoEmpleado) {
	this->tipoEmpleado = tipoEmpleado;
}
int Persona::getTipoEmpleado() {
	return tipoEmpleado;
}

void Persona::setIdSupervisor(int idSupervisor) {
	this->idSupervisor = idSupervisor;
}
int Persona::getIdSupervisoro() {
	return idSupervisor;
}

void Persona::setPagoMensualBruto(double pagoMensualBruto) {
	this->pagoMensualBruto = pagoMensualBruto;
}
double Persona::getPagoMensualBruto() {
	return pagoMensualBruto;
}

void Persona::setMontoxHora(double montoxHora) {
	this->montoxHora = montoxHora;
}
double Persona::getMontoxHora() {
	return montoxHora;
}

void Persona::setHorasLaboradas(int horasLaboradas) {
	this->horasLaboradas = horasLaboradas;
}
int Persona::getHorasLaboradas() {
	return horasLaboradas;
}
