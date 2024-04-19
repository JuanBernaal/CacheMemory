/*
Autor: Oscar Vargas Pabon
Fecha: 18/04/2024

Un generador con queries aleatorias para probar la implementacion de la cache
*/

#include <iostream>
#include <random>
#include <ctime>

const int Tope = (1<<10); // esto no lo he revisado bien
const int Instrucciones = 10;
const int tamano = 4;

int main(  ) {
	
	std::mt19937 mt( time(NULL) );
	
	for ( int i = 0 ; i < tamano ; ++i ) std::cout << ' ' << mt();
	std::cout << '\n';
	
	std::cout << Instrucciones << '\n';
	
	for ( int i = 0 ; i < Instrucciones ; ++i ) {
		int type = mt()&1, addr = mt()%tamano;
		
		std::cout << type << ' ' << addr;
		if ( type == 0 ) {
			int val = mt();
			std::cout << ' ' << val;
		}
		std::cout << '\n';
	}
	
	return 0;
}