/*
Autor: Oscar Vargas Pabon, Juan David Bernal
Fecha: 18/04/2024

una simulacion de la DRAM
*/
#include <iostream>
#include "memDRam.h"

DRam::DRam( int n ) : Memory() {
	this->mem.resize( n );
}
DRam::DRam( const std::vector<Word> &copy ) : DRam( copy.size() ) {
	for ( int i = 0 ; i < (int)copy.size() ; ++i ) {
		this->mem[i] = copy[i];
	}
}
	
void DRam::write( int address, Word value ) {
	++this->processedQueries;
	this->mem[address] = value;
}

int DRam::read( int address ) {
	++this->processedQueries;
	return this->mem[address];
}

std::list<std::pair<int,int>> DRam::getReport() {
	std::list<std::pair<int,int>> res;
	res.push_back( std::pair<int,int>( this->processedQueries, this->missAmount ) );
	return res;
}
