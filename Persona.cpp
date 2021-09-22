#include "Persona.h"

Persona::Persona(){
	this->idEmpleado = 0; 
	this->nombre = "";
	this->apellido = "";
	this->correo = "";
	this->tipoEmpleado = 0;
	this->idSupervisor = 0;
}
Persona::Persona(int idEmpleado, string nombre, string apellido, string correo,
	int tipoEmpleado, int idSupervisor) {
	this->idEmpleado = idEmpleado;
	this->nombre = nombre;
	this->apellido = apellido;
	this->correo = correo;
	this->tipoEmpleado = tipoEmpleado;
	this->idSupervisor = idSupervisor;
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
