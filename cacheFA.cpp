/*
Autor: Oscar Vargas Pabon
Fecha: 19/04/2024
*/

#include "cacheFA.h"
//Nota: no sé si lo que hize para apagar el bit de validez es correcto porque no he
//		pensado si de esta manera se va a manejar el bloque
CacheFA::CacheFA( int sz, Memory *cp ) : Memory() {
	this->upperLevel = cp;
	this->block.resize( sz );
	
	// apagar el primer bit ( el de validez)
	for ( int i = 0 ; i < sz ; ++i ) this->block[i] &= ~1;
	
	this->FIFOhead = 0;
}

CacheFA::~CacheFA(){
	delete this->upperLevel;
}

//_________________ falta terminar estos dos
void CacheFA::write( int address, int value ) {
	++this->processedQueries;
}

int CacheFA::read( int address ) {
	++this->processedQueries;	
}
//______________________________________________

std::list<std::pair<int,int>> CacheFA::getReport() {
	std::list<std::pair<int,int>> res = this->upperLevel->getReport();
	res.push_front( std::pair<int,int>( this->processedQueries, this->missAmount ) );
	return res;
}
