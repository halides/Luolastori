#pragma once

#define LUOLASTON_KOKO 21	//THIS HAS TO BE ODD
#define HUONEEN_KOKO 3

class Luola
{
	private:
		int luola[LUOLASTON_KOKO][LUOLASTON_KOKO];
		int suunnat[4];
		int monesko;

		void tee_sokkelo(int x, int y);
		int* sotke();
		void fillaa(int x, int y);
		int tila(int x, int y);
		void vuole(int x, int y);
		void tayta(int x, int y);

		//for tests
		int testi_laskuri;
		void fillaa_testille(int x, int y, int *laskuri);
	public:
		Luola();
		void tee_huone(bool);
		void tee_sokkelot();
		void puhko();
		void tulosta();
		void poista_umpikujat();

		//for tests
		int montako_tyhjaa();
		int moneenko_fillaa();
};
