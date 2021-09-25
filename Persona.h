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
	double pagoMensualBruto;//sin calculo de retencion 
	double montoxHora;
	int horasLaboradas;

public:
	Persona();
	Persona(int idEmpleado, string nombre, string apellido, string correo,
		int tipoEmpleado, int idSupervisor, double pagoMensualBruto,
		double montoxHora, int horasLaboradas);

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

	void setPagoMensualBruto(double pagoMensualBruto);
	double getPagoMensualBruto();

	void setMontoxHora(double montoxHora);
	double getMontoxHora();

	void setHorasLaboradas(int horasLaboradas);
	int getHorasLaboradas();
};