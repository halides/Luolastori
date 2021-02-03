#include "luolastori.hpp"

Luola::Luola() {
        for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 21; j++) {
                        tayta(i,j);
                }
        }
}

void Luola::vuole(int x, int y) {
	luola[x][y] = 1;
}

void Luola::tayta(int x, int y) {
	luola[x][y] = 0;
}

int Luola::tila(int x, int y) {
	return luola[x][y]?1:0;
}
