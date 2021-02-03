#include "luolastori.hpp"

void Luola::vuole(int x, int y) {
	luola[x][y] = 1;
}

void Luola::tayta(int x, int y) {
	luola[x][y] = 0;
}
