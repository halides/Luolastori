#include <iostream>

#include "luolastori.hpp"

int main() {
	Luola l;
	l.tee_huone();
	l.tee_huone();
	l.tee_huone();
	l.tee_huone();
	l.tee_huone();
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			std::cout << (l.tila(i,j)?"X":" ");
		}
		std::cout << std::endl;
	}
}

