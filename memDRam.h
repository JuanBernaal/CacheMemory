/*
Autor: Oscar Vargas Pabon
Fecha: 18/04/2024

una simulacion de la DRAM
*/

#ifndef MEM_DRAM_H
#define MEM_DRAM_H

#include <vector>

class DRam {
	private:
	std::vector<int> mem;
	public:
	// constructores
	DRam( int );
	DRam( const std::vector<int> & );
	
	// metodos
	void write( int, int );
	int read( int );	
};



#endif