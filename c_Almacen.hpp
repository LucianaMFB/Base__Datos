#ifndef C_ALMACEN_HPP  
#define C_ALMACEN_HPP  

#include "cFecha.hpp"

class cAlmacen
{
    public:

		~cAlmacen();//chau todo

		cAlmacen();
		cAlmacen(char *name , char *code , int tam_nom, int tam_cod) ;//
		cAlmacen(const cAlmacen &obj);
		cAlmacen& operator=(const cAlmacen &obj);

		void print();

		bool llenado_nombre(char *name, int size = 0);
		bool llenado_codigo(char *code, int size = 0);
		bool llenado_size_nom(int size, char * cadena = nullptr);
		bool llenado_size_cod(int size, char * cadena = nullptr);
		void fecha_defecto();
		void llenado_fecha(int day, int month, int year, int hour, int minute, int second);

		char * getFecha();
		char * getNombre();
		char * getCodigo();
		int getSize_nom();
		int getSize_cod();
		void ultimoAcceso();
		
		bool comparar_codigos(char* codigo, char*temp);

	private:
		cFecha fecha;
		char *cadena_fecha;
		char *nombre;
		char *codigo;
		int size_nom;
		int size_cod;

		
		
		void asignar_nullptr();
		void llenado_generalFecha();
		void generar_cadena_fecha();

		bool asignarValores(const cAlmacen *obj);
		void copiar(char *root, char *destino, int tam);
		int contador(const char *cadena);

		void crear_memoria(int tam, char ** destino);
		void liberar(char **target);
	
};

#endif
