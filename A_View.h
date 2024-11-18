#ifndef A_VIEW_H
#define A_VIEW_H

#include "A_controller.h"

class A_controller;

class A_View 
{
	private:
	A_controller& controlador;
	
	
	public:
	A_View(A_controller& controller);
	void Pagina_Principal();
	void titulo_almacen();
	void Error_nombre();
	void Error_codigo();
	void Operacion_exitosa();
	void Pedir_nombre();
	void Pedir_codigo();
	void Pedir_datos();
	void Confirmar_datos();
	void Mostrar_datos();
	void Establecer_fecha();
	void Ultimo_Acceso();
	void Imprimir_fecha();
};

#endif