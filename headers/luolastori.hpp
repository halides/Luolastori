#pragma once

#define LUOLASTON_KOKO 61	//THIS HAS TO BE ODD
#define HUONEEN_KOKO 7

class Luola
{
	private:
		int luola[LUOLASTON_KOKO][LUOLASTON_KOKO];	//vuoltava luolasto array-of-array
		int suunnat[4];	//array suunnille joihin käytäväalgo voi mennä
		int monesko;	//id luotavalle alueelle

		void tee_sokkelo(int x, int y);	//lähtee luomaan sokkeloa kohdasta (x,y) jos siinä on seinää
		int* sotke();			//tämä  kuljettavan suunnan käytäväalgolle
		void fillaa(int x, int y);	//flood fill
		int tila(int x, int y);		//palauttaa onko ko. kohdassa seinää (0) tai alueen id:n (>0) johon kohta kuuluu
		void vuole(int x, int y);	//tekee ko. kohdasta aluetta "monseko" muuttujan mukaan
		void tayta(int x, int y);	//tekee ko. kohdasta seinää (käytetään ainoastaan konstruktorissa

		//testejä varten
		int testi_laskuri;
		void fillaa_testille(int x, int y, int *laskuri);
	public:
		Luola(int seed);
		void tee_huone(bool);	//luo huoneen, bool määrittelee stäkkääkö huoneita päällekkäin vai ei
		void tee_sokkelot();	//kutsuu tee_sokkeloa jokaiselle parittomalle (x,y)-parille
		void puhko();		//yhdistää alueet toisiinsa
		void tulosta();		//tulostaa sokkelon
		void poista_umpikujat();

		//testejä varten
		int montako_tyhjaa();
		int moneenko_fillaa();
		void tulosta_huoneet();		//tulostaa luotujen alueitten määrän
		void tulosta_vuollut();		//tulostaa tyhjien neliöitten määrän
};
