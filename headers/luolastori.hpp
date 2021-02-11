#pragma once

#define LUOLASTON_KOKO 71
#define HUONEEN_KOKO 7

class Luola
{
	private:
		int luola[LUOLASTON_KOKO][LUOLASTON_KOKO];
		int suunnat[4];
		int monesko;

		void vuole(int x, int y);
		void tayta(int x, int y);
		void tee_sokkelo(int x, int y);
		int* sotke();
		void fillaa(int x, int y);
		int tila(int x, int y);
	public:
		Luola();
		void tee_huone(bool);
		void tee_sokkelot();
		void puhko();
		void tulosta();
		void poista_umpikujat();
};
