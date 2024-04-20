/*
Autor: Oscar Vargas Pabon
Fecha: 19/04/2024

representa 
*/

#ifndef CACHE_FA_H
#define CACHE_FA_H

#include "memory.h"
#include <vector>
#include <map>

class CacheFA : public Memory {
	private:
	
	std::map<int,int> tagLocation;
	// ¿de esta manera vamos a manejar el bloque?
	std::vector<int> block;
	
	int FIFOhead;
	Memory *upperLevel;
	
	public:
	// constructor
	CacheFA ( int, Memory * );
	
	// metodos
	void write( int, int ) override;
	int read( int ) override;
	std::list<std::pair<int,int>> getReport() override;
	
	~CacheFA();
};

#endif