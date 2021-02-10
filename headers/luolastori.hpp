#pragma once

class Luola
{
	private:
		int luola[21][21];
		int suunnat[4];
		int monesko;
	public:
		Luola();
		void vuole(int x, int y);
		void tayta(int x, int y);
		int tila(int x, int y);
		void tee_huone(bool);
		void tee_sokkelot();
		void poista_umpikujat();
		void tee_sokkelo(int x, int y);
		int* sotke();
		void puhko();
		void tulosta();
		void fillaa(int x, int y);
};
