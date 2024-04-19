/*
Autor: Oscar Vargas Pabon
Fecha: 18/04/2024

una simulacion de la DRAM
*/

#include "memDRam.h"

DRam::DRam( int n ) {
	this->mem.resize( n );
}
DRam::DRam( const std::vector<int> &copy ) {
	this->mem = copy;
}
	
void DRam::write( int address, int value ) {
	this->mem[address] = value;
}

int DRam::read( int address ) {
	return this->mem[address];
}
