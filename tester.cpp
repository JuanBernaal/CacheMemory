/*
Autor: Oscar Vargas Pabon, Juan David Bernal
Fecha: 18/04/2024

para hacer el test que bota el generador
*/

#include <iostream>
#include <vector>
#include <stdio.h>

#include "cacheFA.h"
#include "memDRam.h"

const int cantidadBloques = 64;

void leerReporte( std::list<std::pair<int,int>> &report ) {
	int i = 0;
	while ( !report.empty() ) {
		std::cerr << "El nivel " << ++i << " reporta " << report.front().first;
		std::cerr << " queries manejadas y " << report.front().second << " misses" << std::endl;;
		report.pop_front();
	}
}

const int numeroPrueba = 2;

int main() {
	
	int tamano;
	std::cin >> tamano;
	std::vector<Word> strt( tamano );
	for ( int i = 0 ; i < tamano; ++i ) scanf("%d", &strt[i]);
	
	Memory *memory;
	if ( numeroPrueba == 1 ) {
		std::cerr << "Leyendo directamente de la DRam...\n" << std::endl;
		memory = new DRam( strt );
	} else if ( numeroPrueba == 2 ) {
		std::cerr << "Leyendo de la memoria Cache...\n" << std::endl;
		memory = new CacheFA( cantidadBloques, new DRam( strt ) );
	} else {
		std::cerr << "No se reconoce el numero de la prueba...\n" << std::endl;
		return 0;
	}
	
	int inst; std::cin >> inst;
	for ( int i = 0 ; i < inst ; ++i ) {
		int type, addr; std::cin >> type >> addr;
		if ( type == 0 ) {
			int val; std::cin >> val;
			
			memory->write( addr, val );
		} else {
			std::cout << memory->read( addr ) << '\n';
		}
	}
	std::list<std::pair<int,int>> tmp = memory->getReport();
	leerReporte( tmp );
	
	delete memory;
	
	return 0;
}

