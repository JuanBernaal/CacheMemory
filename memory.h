/*
Autor: Oscar Vargas Pabon
Fecha: 19/04/2024

esta es una clase virtual que da los lineamientos para las operaciones basicas que
	deben de cumplir las memorias
*/

#ifndef MEMORY_H
#define MEMORY_H

#include <list>
#include <stdint.h>

typedef int8_t Word;

class Memory {
	protected:
	
	int processedQueries, missAmount;
	
	public:
	
	Memory() : processedQueries( 0 ), missAmount( 0 ) {};
	
	virtual void write( int, Word ) = 0;
	virtual int read( int ) = 0;
	virtual std::list<std::pair<int,int>> getReport() = 0;
};

#endif