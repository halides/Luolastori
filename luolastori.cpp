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

void Luola::tee_huone(bool pinoa) {
	int x = rand() % 7 * 2 + 1;
	int y = rand() % 7 * 2 + 1;
	int sivu = rand() % 3 * 2 + 3;
	int sivu2 = rand() % 3 * 2 + 3;
	if (x+sivu > 20) return;
	if (y+sivu2 > 20) return;
	if (pinoa == false) {
		int xx = x;
		int yy = y;
		int xs = x+sivu;
		int ys = y+sivu2;
		if (x<3) xx = 3;
		if (y<3) yy = 3;
		if (x+sivu > 19) xs=19;
		if (y+sivu2 > 19) ys=19;

		for (int i = xx-2; i<xs+2; i++) {
			for (int j = yy-2; j<ys+2; j++) {
				if (!tila(i,j)) {
	std::cout << "en tehny: " << x << " " << y << " " << sivu << " " << sivu2 << " " << std::endl << "koska: " << i << " ja " << j << std::endl;
					return;
				}
			}
		}
	}
	std::cout << "    teen: " << x << " " << y << " " << sivu << " " << sivu2 << " " << std::endl;
	for (int i = x; i<x+sivu; i++) {
		for (int j = y; j<y+sivu2; j++) {
			vuole(i,j);
		}
	}
}

void Luola::tee_sokkelot() {
	for (int i = 1; i<20; i+=2) {
		for (int j = 1; j<20; j+=2) {
			if (tila(i,j) == 1) tee_sokkelo(i,j);
		}
	}
}

void Luola::tee_sokkelo(int x, int y) {
	vuole(x,y);
	if ((x+2<21) && tila(x+2,y) == 1) {
		vuole(x+1,y);
		tee_sokkelo(x+2,y);
	}
	if ((x-2>0) && tila(x-2,y) == 1) {
		vuole(x-1,y);
		tee_sokkelo(x-2,y);
	}
	if ((y+2<21) && tila(x,y+2) == 1) {
		vuole(x,y+1);
		tee_sokkelo(x,y+2);
	}
	if ((y-2>0) && tila(x,y-2) == 1) {
		vuole(x,y-1);
		tee_sokkelo(x,y-2);
	}
}
