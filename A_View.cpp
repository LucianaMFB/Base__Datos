
#include "A_View.h"
#include "A_controller.h"
#include <iostream>

A_View::A_View(A_controller& controller) : controlador(controller) {}

void A_View::Pagina_Principal()
{
	
    std::cout << "\x1B[H";          // Codigo para colocar el cursor en el canto superior izquierdo
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "\x1B[38;5;227m   _______  __   __  _______  ______    _______  _______  _______   _______  _______  __   __  _______  ___  ___     " << std::endl;
	std::cout << "\x1B[38;5;227m  |       ||  |_|  ||       ||    _ |  |       ||       ||   _   | |       ||       ||  |_|  ||       ||   ||   |  " << std::endl;
	std::cout << "\x1B[38;5;227m  |    ___||       ||    _  ||   | ||  |    ___||  _____||  |_|  | |_     _||    ___||       ||_     _||   ||   |      " << std::endl;
	std::cout << "\x1B[38;5;227m  |   |___ |       ||   |_| ||   |_||_ |   |___ | |_____ |       |   |   |  |   |___ |       |  |   |  |   ||   |" << std::endl;
	std::cout << "\x1B[38;5;227m  |    ___||       ||    ___||    __  ||    ___||_____  ||       |   |   |  |    ___| |     |   |   |  |   ||   |___ " << std::endl;
	std::cout << "\x1B[38;5;227m  |   |___ | ||_|| ||   |    |   |  | ||   |___  _____| ||   _   |   |   |  |   |___ |   _   |  |   |  |   ||       |" << std::endl;
	std::cout << "\x1B[38;5;227m  |_______||_|   |_||___|    |___|  |_||_______||_______||__| |__|   |___|  |_______||__| |__|  |___|  |___||_______|" << std::endl;
	std::cout << " \x1B[m" << std::endl;
}


void A_View::titulo_almacen()
{
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "\x1B[38;5;149m   _______  ___      __   __  _______  _______  _______  __    _ " << std::endl;
	std::cout << "\x1B[38;5;149m  |   _   ||   |    |  |_|  ||   _   ||       ||       ||  |  | |" << std::endl;
	std::cout << "\x1B[38;5;149m  |  |_|  ||   |    |       ||  |_|  ||      _||    ___||   |_| |" << std::endl;
	std::cout << "\x1B[38;5;149m  |       ||   |    |       ||       ||     |  |   |___ |       |" << std::endl;
	std::cout << "\x1B[38;5;149m  |       ||   |___ |       ||       ||     |  |    ___||  _    |" << std::endl;
	std::cout << "\x1B[38;5;149m  |   _   ||       || ||_|| ||   _   ||     |_ |   |___ | | |   |" << std::endl;
	std::cout << "\x1B[38;5;149m  |__| |__||_______||_|   |_||__| |__||_______||_______||_|  |__|" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " \x1B[m" << std::endl;
}

void A_View::Error_nombre()
{
	std::cout<< " ERROR AL LLENAR NOMBRE" <<std::endl;
}

void A_View::Error_codigo()
{
	std::cout<< " ERROR AL LLENAR CODIGO" <<std::endl;
}

void A_View::Operacion_exitosa()
{
	std::cout << " " << std::endl;
	std::cout << "	!! SE GUARDO CON EXITO EL ALMACEN !!" <<std::endl;
}

void A_View::Pedir_nombre()
{
	char temp[30] {"-"};
	int num{0};
	int tam_nom {1};
	
	std::cout << " " << std::endl; 
	std::cout << "\x1B[38;5;149m    *" <<"   NOMBRE DEL ALMACEN: \x1B[m" ;
	std::cin >> temp;
	
	if ((controlador.set_nombre(temp, tam_nom))!= true)
	{
		Error_codigo();
	}
	
}

void A_View::Pedir_codigo()
{
	char temp[30] {"-"};
	int num{0};
	int tam_codigo {1};
	
	std::cout << "\x1B[38;5;149m    *" << "   CODIGO DEL ALMACEN: \x1B[m";
	std::cin >> temp;
	
	if ((controlador.set_codigo(temp, tam_codigo))!= true)
	{
		Error_codigo();
	}
	
}

void A_View::Pedir_datos()
{
	Pedir_nombre();
	Pedir_codigo();
	
	Operacion_exitosa();
	
}

void A_View::Confirmar_datos()
{
	char respuesta {'-'};
	std::cout << " " << std::endl;
	std::cout << "	Se guardo un almacen con NOMBRE: \x1B[38;5;149m" << controlador.mostrar_nombre() << "\x1B[m y CODIGO: \x1B[38;5;149m" << controlador.mostrar_codigo() << std::endl;
	std::cout << " \x1B[m" << std::endl;
	std::cout << "	Hubo algun error que quiera modificar? (Y/N) ";
	std::cin >> respuesta;
	
	if ((respuesta == 'y') || (respuesta == 'Y'))
	{
		Pedir_datos();
	}	
}

void A_View::Mostrar_datos()
{
	std::cout << " " << std::endl;
	std::cout << "	-------------------------------------------------------------" << std::endl;
	std::cout << "		NOMBRE DEL ALMACEN: \t" << controlador.mostrar_nombre() << std::endl;
	std::cout << "		CODIGO DEL ALMACEN: \t" << controlador.mostrar_codigo() << std::endl;
	std::cout << "	-------------------------------------------------------------" << std::endl;
	std::cout << " " << std::endl;
}


void A_View::Establecer_fecha()
{
	char respuesta;
	std::cout << " " << std::endl;
	std::cout<<"	Desea inicializar fecha o por defecto? (Y/N): ";
	std::cin>>respuesta;

	if(respuesta == 'Y' || respuesta == 'y')
	{
		int day{0};
		int month{0};
		int year{0};
		int hour{0};
		int minute{0};
		int second{0};
		
		std::cout << " " << std::endl;
		std::cout << "	DIA: " ;
		std::cin >> day;
		std::cout << "	MES: ";
		std::cin >> month;
		std::cout << "	YEAR: ";
		std::cin >> year;
		std::cout << "	HORA: ";
		std::cin >> hour;
		std::cout << "	MINUTO: ";
		std::cin >> minute;
		std::cout << "	SEGUNDO: ";
		std::cin >> second;
		
		controlador.Fecha_llenada(day, month, year, hour, minute, second);
	}
	
	else
	{
		controlador.Fecha_pordefecto();
	}
	
}

void A_View::Imprimir_fecha()
{
	std::cout << "	dd/mm/yy : " << controlador.obtener_dia() << "/" << controlador.obtener_mes() << "/" << controlador.obtener_año() << std::endl;
    std::cout << "	hh:mm:ss : " << controlador.obtener_hora() << ":" << controlador.obtener_minuto() << ":" << controlador.obtener_segundo() << std::endl;
}


void A_View::Ultimo_Acceso()
{
	char respuesta {'N'};
	std::cout<<"	Desea conocer el ultimo acceso? (Y/N) ";
	std::cin>>respuesta;

	if(respuesta == 'Y' || respuesta == 'y')
	{
		char temp[40];
		bool flag = true;
		int i=0;
		std::cout<<"	Ingrese codigo: ";
		std::cin>>temp;
			
		if ((controlador.verificar_codigos(controlador.mostrar_codigo(), temp)) == true)
		{
			controlador.getUltimo_acceso();
			Imprimir_fecha();
		}
			
		else
		{
			std::cout << "	INCORRECTO" << std::endl;
		}
	}
}


































