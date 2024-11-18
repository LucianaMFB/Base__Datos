#include "A_View.h"
//#include "cListaAlmacen.hpp"
#include "c_Almacen.hpp"
#include "cFecha.hpp"

#include <iostream>
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif


int main()
{
	std::system(CLEAR_COMMAND); 
	cAlmacen almacen1;
	cFecha fecha1;
	A_controller controlador(almacen1, fecha1);
	A_View vista(controlador);
	
	vista.Pagina_Principal();
	vista.Establecer_fecha();
	
	std::system(CLEAR_COMMAND); 
	vista.titulo_almacen();
	vista.Pedir_datos();
	vista.Confirmar_datos();
	vista.Mostrar_datos();
	vista.Ultimo_Acceso();
	
	
	
	
	
	
	
	
	
	return 0;
}