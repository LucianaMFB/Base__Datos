#include "c_Almacen.hpp"
#include "cFecha.hpp"

#include <iostream>
#include <ctime>

cAlmacen::cAlmacen()
{
	asignar_nullptr();
	size_nom = -1;
	size_cod =-1;
	//llenado_generalFecha();
}

cAlmacen::cAlmacen(char *name, char *code, int tam_nom, int tam_cod)
{	
	asignar_nullptr();
	//llenado_generalFecha();
	
	if(llenado_codigo(code, tam_cod))
	{
		std::cout<<"CODIGO LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"CODIGO no LLENADO CON EXITO"<<std::endl;
		size_cod = -1;
	}

	if(llenado_nombre(name, tam_nom))
	{
		std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
		size_nom = -1;
	}
}

cAlmacen::cAlmacen(const cAlmacen &obj) // Constructor de copia
{
	asignar_nullptr();

	if(asignarValores(&obj)) {
		std::cout << "SE LOGRO" << std::endl;
	} else {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cAlmacen& cAlmacen::operator=(const cAlmacen &obj) // Operador de asignación
{
	if(&obj != this) {
		if(asignarValores(&obj)) {  // Pasamos la dirección de `obj` para cumplir con el tipo
			std::cout << "SE LOGRO" << std::endl;
		} else {
			std::cout << "NO SE LOGRO" << std::endl;
		}
	} else {
		std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
	}

	std::cout << "SOBRECARGA DE OPERADOR" << std::endl;
	return *this;//devolver la referencia
}

bool cAlmacen::asignarValores(const cAlmacen *obj)
{
	fecha.actualizarFecha();
	fecha = (*obj).fecha;

	if(llenado_codigo((*obj).codigo, (*obj).size_cod))
	{
		std::cout<<"CODIGO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"CODIGO no LLENO"<<std::endl;
		return false;
	}

	if(llenado_nombre((*obj).nombre, (*obj).size_nom))
	{
		std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE no LLENO"<<std::endl;
		return false;
	}

	return true;
}

void cAlmacen::print()
{
	char respuesta {'N'};
	bool valido = true;

	if (nombre != nullptr)
	{
		std::cout<<"NOMBRE : " <<nombre<<" tam:"<<size_nom<<std::endl;
	}
	else
	{
		std::cout << "Nombre no asignado (nullptr)" << std::endl;
		valido = false;
	}

	if (codigo!= nullptr)
	{
    std::cout<<"CODIGO: " <<codigo<<" tam:"<<size_cod<<std::endl;
	}
	else
	{
		std::cout << "Codigo no asignado (nullptr)" << std::endl;
		valido = false;
	}

	if(!valido)
	{
		std::cout<<"NO SE ACCEDERA A SU ULTIMO ACCESO";
	}
	else
	{
		std::cout<<"¿Desea conocer el ultimo acceso? (Y/N) ";
		std::cin>>respuesta;

		if(respuesta == 'Y' || respuesta == 'y')
		{
			ultimoAcceso();
		}
	}
}

void cAlmacen::ultimoAcceso()
{
	fecha.actualizarFecha();
}


bool cAlmacen::comparar_codigos(char* codigo, char*temp)
{
	int i {0};
	bool flag {true};
	
	while( *(codigo+i) !='\0')
	{
		if (*(temp+i) != *(codigo+i))
		{
			flag = false;
			break;
		}
		i++;
	}
	
	if(flag)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void cAlmacen::asignar_nullptr()
{
	nombre = nullptr;
    codigo = nullptr;
	cadena_fecha = nullptr;
}

/*void cAlmacen::llenado_generalFecha()
{
	char respuesta;
	
	std::cout<<"Desea inicializar fecha o por defecto? (Y/N): ";
	std::cin>>respuesta;

	if(respuesta == 'Y' || respuesta == 'y')
	{
		llenado_fecha(int day, int month, int year, int hour, int minute, int second);
	}
	else
	{	fecha.actualizarFecha();	}

}*/

void cAlmacen::fecha_defecto()
{
	fecha.actualizarFecha();
}

void cAlmacen::llenado_fecha(int day, int month, int year, int hour, int minute, int second)
{
	fecha.setDia(day);
	fecha.setMes(month);
	fecha.setYear(year);
	fecha.setSeg(hour);
	fecha.setMin(minute);
	fecha.setHora(second);
}

bool cAlmacen::llenado_size_nom(int size, char * cadena)
{
	if(size <= 1)
	{
		size = contador(cadena);
		if(size<=1)
		{
			return false;
		}
	}

	size_nom = size;
	return true;
}

bool cAlmacen::llenado_size_cod(int size, char * cadena)
{
	if(size <= 1)
	{
		size = contador(cadena);
		if(size<=1)
		{
			return false;
		}
	}

	size_cod = size;
	return true;
}

bool cAlmacen::llenado_nombre(char *name, int size)
{
	fecha.actualizarFecha();

	if(name != nullptr)
	{
		if(nombre != nullptr) 
			{  liberar(&nombre); }

		if(llenado_size_nom(size, name))
		{
			crear_memoria(size_nom, &nombre);
			copiar(name, nombre, size_nom);
			return true;
		}
	}
	return false;
}


bool cAlmacen::llenado_codigo(char *code, int size)
{
	fecha.actualizarFecha();
	if(code != nullptr)
	{
		if(codigo != nullptr) 
			{  liberar(&codigo); }

		if(llenado_size_cod(size, code))
		{
			crear_memoria(size_cod, &codigo);
			copiar(code, codigo, size_cod);
			return true;
		}
	}
	return false;
	
}

char * cAlmacen::getNombre()
{
	return nombre;
}

char * cAlmacen::getCodigo()
{
	return codigo;
}

void cAlmacen::generar_cadena_fecha()
{
    if(cadena_fecha != nullptr)
    {
       liberar(&cadena_fecha);
    }
    crear_memoria(8,&cadena_fecha);

    cadena_fecha[0] = fecha.getDia();
    cadena_fecha[1] = fecha.getMes();
    cadena_fecha[2] = fecha.getYear() / 100;
    cadena_fecha[3] = fecha.getYear() % 100;
    cadena_fecha[4] = fecha.getSeg();
    cadena_fecha[5] = fecha.getMin();
    cadena_fecha[6] = fecha.getHora();
    cadena_fecha[7] = '\0';

}

char * cAlmacen::getFecha()
{
	generar_cadena_fecha();
	return cadena_fecha;
}

int cAlmacen::getSize_nom()
{
	return size_nom;
}

int cAlmacen::getSize_cod()
{
	return size_cod;
}


int cAlmacen::contador(const char * cadena)
{
	int fin =0;
	while( *(cadena+fin) != '\0')
	{
		fin++;
	}
	return fin+1;
}

void cAlmacen::crear_memoria(int tam, char ** destino)
{
	if (tam > 0) 	//nombre
	{	*destino = new char[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

void cAlmacen::copiar( char *root, char *destino, int tam)
{
	for(int i=0;i<tam;i++)
	{
		*(destino+i) = *(root+i);
	}
	*(destino+(tam-1)) = '\0';//asegurar
}

void cAlmacen::liberar(char **target)
{
	if (*target != nullptr) {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
}

cAlmacen::~cAlmacen()
{
    fecha.actualizarFecha();
	liberar(&nombre);
	liberar(&codigo);
	liberar(&cadena_fecha);
}


