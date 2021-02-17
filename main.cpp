#include "luolastori.hpp"

int main() {
	Luola l;
	for (int i=0; i<LUOLASTON_KOKO; i++)
		l.tee_huone(false);
	l.tulosta();
	l.tee_sokkelot();
	l.tulosta();
	l.puhko();
	l.tulosta();
	l.poista_umpikujat();
	l.tulosta();
}

