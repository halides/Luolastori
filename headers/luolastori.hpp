#pragma once

class Luola
{
	private:
		int luola[21][21];
	public:
		Luola();
		void vuole(int x, int y);
		void tayta(int x, int y);
		int tila(int x, int y);
		void tee_huone(bool);
		void tee_sokkelot();
		void tee_sokkelo(int x, int y);
};
