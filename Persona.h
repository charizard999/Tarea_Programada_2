#pragma once
#include <string>
using namespace std;

class Persona {
private:
	int idEmpleado;
	string nombre;
	string apellido;
	string correo;
	int tipoEmpleado;
	int idSupervisor;

public:
	Persona();
	Persona(int idEmpleado,string nombre,string apellido,string correo,
		int tipoEmpleado,int idSupervisor);

	void setIdEmpleado(int idEmpleado);
	int getIdEmpleado();

	void setNombre(string nombre);
	string getNombre();

	void setApellido(string apellido);
	string getApellido();

	void setCorreo(string correo);
	string getCorreo();

	void setTipoEmpleado(int tipoEmpleado);
	int getTipoEmpleado();

	void setIdSupervisor(int idSupervisor);
	int getIdSupervisoro();
};