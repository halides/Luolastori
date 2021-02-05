#include "luolastori.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Luola::Luola() {
	srand(time(NULL));
        for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 21; j++) {
                        tayta(i,j);
                }
        }
}

void Luola::vuole(int x, int y) {
	luola[x][y] = 0;
}

void Luola::tayta(int x, int y) {
	luola[x][y] = 1;
}

int Luola::tila(int x, int y) {
	return luola[x][y]?1:0;
}

void Luola::tee_huone() {
	int x = rand() % 7 * 2 + 1;
	int y = rand() % 7 * 2 + 1;
	int sivu = rand() % 3 * 2 + 3;
	int sivu2 = rand() % 3 * 2 + 3;
	std::cout << x << " " << y << " " << sivu << " " << sivu2 << " " << std::endl;
	if (x+sivu > 20) return;
	if (y+sivu2 > 20) return;
	for (int i = x; i<x+sivu; i++) {
		for (int j = y; j<y+sivu2; j++) {
			vuole(i,j);
		}
	}
}
