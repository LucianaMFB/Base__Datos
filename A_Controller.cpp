#include "c_Almacen.hpp"
#include "cFecha.hpp"
#include "A_controller.h"
#include "A_View.h"

A_controller::A_controller(cAlmacen& model, cFecha& model2 )
    : modelo(model), modelo2(model2){ }
	
bool A_controller::set_nombre(char* name, int size)
{
	if (modelo.llenado_nombre(name, size) != true)
	{
		return false;
	}
	
	return true;
}

bool A_controller::set_codigo(char* code, int size)
{
	if (modelo.llenado_codigo(code,size) != true)
	{
		return false;
	}
	
	return true;
}

bool A_controller::Crear_almacen(char* name, int size, char* code)
{
	set_nombre(name, size);
	set_codigo(code,size);
	
	return true;
}	
	
char* A_controller::mostrar_nombre()
{
	return modelo.getNombre();
}

char* A_controller::mostrar_codigo()
{
	return modelo.getCodigo();
}	
	
	
void A_controller::Fecha_llenada(int day, int month, int year, int hour, int minute, int second)
{
	modelo.llenado_fecha(day, month, year, hour, minute, second);
}	

void A_controller::Fecha_pordefecto()
{
	modelo2.actualizarFecha();
}
	
bool A_controller::verificar_codigos(char* codigo, char*temp)
{
	return modelo.comparar_codigos(modelo.getCodigo(), temp);
}
	
void A_controller::getUltimo_acceso()
{
	modelo.ultimoAcceso();
}

int A_controller::obtener_dia()
{
	return modelo2.getDia();
}
	
int A_controller::obtener_mes()
{
	return modelo2.getMes();
}

int A_controller::obtener_año()
{
	return modelo2.getYear();
}

int A_controller::obtener_hora()
{
	return modelo2.getHora();
}

int A_controller::obtener_minuto()
{
	return modelo2.getMin();
}
	
int A_controller::obtener_segundo()
{
	return modelo2.getSeg();
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
