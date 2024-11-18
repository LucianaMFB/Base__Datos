#ifndef A_CONTROLLER_H
#define A_CONTROLLER_H

#include "c_Almacen.hpp"
#include "A_View.h"

class A_View;

class A_controller 
{
	private:
	cAlmacen& modelo;
	cFecha& modelo2;

	public:
	A_controller(cAlmacen& model, cFecha& model2);
	bool set_nombre(char *name, int size);
	bool set_codigo(char *code, int size);
	bool Crear_almacen(char* name, int size, char* code);
	char* mostrar_nombre();
	char* mostrar_codigo();
	void Fecha_llenada(int day, int month, int year, int hour, int minute, int second);
	void Fecha_pordefecto();
	bool verificar_codigos(char* codigo, char*temp);
	void getUltimo_acceso();
	int obtener_dia();
	int obtener_mes();
	int obtener_año();
	int obtener_hora();
	int obtener_minuto();
	int obtener_segundo();

};

#endif
