#include <iostream>

#include "luolastori.hpp"

int main() {
	Luola l;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			l.tayta(i,j);
		}
	}
	l.vuole(10,10);
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			std::cout << (l.tila(i,j)?" ":"X");
		}
		std::cout << std::endl;
	}
}

