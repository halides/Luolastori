#include "luolastori.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: ./luolastori <int>\njos <int> on 0, tulostetaan satunnainen sokkelo" << std::endl;
		return 1;
	}
	Luola l(atoi(argv[1]));
	for (int i=0; i<LUOLASTON_KOKO; i++)
		l.tee_huone(false);
	l.tulosta_huoneet();
	l.tulosta();
	l.tee_sokkelot();
	l.tulosta();
	l.puhko();
	l.tulosta();
	l.poista_umpikujat();
	l.tulosta_vuollut();
	l.tulosta();
	std::cout << std::endl;
}

