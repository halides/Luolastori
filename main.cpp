#include <iostream>

#include "luolastori.hpp"

int main() {
	Luola l;
	if (true) {
	l.tee_huone(true);
	l.tee_huone(true);
	l.tee_huone(true);
	l.tee_huone(true);
	l.tee_huone(true); } else {
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	l.tee_huone(false);
	}
	l.tee_sokkelot();
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			std::cout << char(32+l.tila(j,i));
		}
		std::cout << std::endl;
	}
}

