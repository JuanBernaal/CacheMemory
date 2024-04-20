/*
Autor: Oscar Vargas Pabon
Fecha: 18/04/2024

una simulacion de la DRAM
*/

#ifndef MEM_DRAM_H
#define MEM_DRAM_H

#include <vector>
#include "memory.h"

class DRam : public Memory {
	private:
	std::vector<int> mem;
	public:
	// constructores
	DRam( int );
	DRam( const std::vector<int> & );
	
	// metodos
	void write( int, int ) override;
	int read( int ) override;
	std::list<std::pair<int,int>> getReport() override;
};



#endif