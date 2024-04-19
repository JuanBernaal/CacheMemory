/*
Autor: Oscar Vargas Pabon
Fecha: 18/04/2024

para hacer el test que bota el generador
*/

#include <iostream>
#include <vector>
#include "memDRam.h"

const int tamano = 4; // hay que revisarlo bien

int main() {
	
	std::vector<int> strt( tamano );
	for ( int i = 0 ; i < tamano; ++i ) std::cin >> strt[i];
	
	DRam memory( strt );
	
	int inst; std::cin >> inst;
	for ( int i = 0 ; i < inst ; ++i ) {
		int type, addr; std::cin >> type >> addr;
		if ( type == 0 ) {
			int val; std::cin >> val;
			
			memory.write( addr, val );
		} else {
			std::cout << memory.read( addr ) << '\n';
		}
	}
	
	return 0;
}

