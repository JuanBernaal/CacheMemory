/*
Autor: Oscar Vargas Pabon, Juan David Bernal
Fecha: 19/04/2024
*/

#include "cacheFA.h"
#include <iostream>

CacheFA::CacheFA( int sz, Memory *upperLevel ) : Memory() {
	this->upperLevel = upperLevel;	

	this->block.assign( sz, std::vector<Word>( BlockSize ) );

	this->validBit.assign( sz, false );

	this->tag.resize( sz );
	
	this->FIFOhead = 0;
}

CacheFA::~CacheFA(){
	delete this->upperLevel;
}
/*
###########################################################################
########################## funciones auxiliares ###########################
###########################################################################
*/

// funcion que retorna el tag de un address
int CacheFA::getTag( int address ){
	for ( int cnt = 1 ; cnt < BlockSize ; cnt <<= 1 ) {
		address >>= 1;
	}
	return address;
}
// funcion que retorna el offset de un address
int CacheFA::getOffset( int address ){
	return address & (BlockSize-1);
}

void CacheFA::handleMiss( int address ) {
	++this->missAmount;
	
	// borrar el elemento que ya estaba ahi
	if ( this->validBit[this->FIFOhead] ) {
		this->tagLocation.erase( this->tag[this->FIFOhead] );
	}
	
	//apago los bits que representan el blockSize
	int semiTag = address & ( ~(BlockSize-1) );
	
	for ( int i = 0 ; i < BlockSize ; ++i ) {
		this->block[this->FIFOhead][i] = this->upperLevel->read( semiTag|i );
	}
	
	// ya tengo los datos, modifico lo que falta
	this->tag[this->FIFOhead] = CacheFA::getTag( address );
	this->validBit[this->FIFOhead] = true;
	this->tagLocation.insert( std::pair<int,int>( this->tag[this->FIFOhead], this->FIFOhead ) );
	
	// modifico la nueva cabeza
	this->FIFOhead = ( this->FIFOhead + 1 ) % ( (int) this->tag.size() );
}

// escribe con Write Through
void CacheFA::write( int address, Word value ) {
	++this->processedQueries;
	
	//escribe en la memoria superior
	this->upperLevel->write( address, value );
	
	// verifica si esta en la cache
	int myTag = CacheFA::getTag( address );

	if ( this->tagLocation.count( myTag ) ) {
		// no hay un miss
		this->block[this->tagLocation[myTag]][CacheFA::getOffset( address )] = value;
	} else {
		// ocurre un miss
		this->handleMiss( address );
	}
}

// lee
int CacheFA::read( int address ) {
	++this->processedQueries;	
	
	int myTag = CacheFA::getTag( address );

	if ( !this->tagLocation.count( myTag ) ) {
		// ocurre un miss
		this->handleMiss( address );
	}
	
	// leo de la cache	
	int answer = this->block[this->tagLocation[myTag]][CacheFA::getOffset( address )];
	return answer;
}
//______________________________________________

std::list<std::pair<int,int>> CacheFA::getReport() {
	std::list<std::pair<int,int>> res = this->upperLevel->getReport();
	res.push_front( std::pair<int,int>( this->processedQueries, this->missAmount ) );
	return res;
}
