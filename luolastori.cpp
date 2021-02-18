#include "luolastori.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Luola::Luola() {
	srand(time(NULL));
	suunnat[0] = 0;
	suunnat[1] = 1;
	suunnat[2] = 2;
	suunnat[3] = 3;
	monesko = 1;

        for (int i = 0; i < LUOLASTON_KOKO; i++) {
                for (int j = 0; j < LUOLASTON_KOKO; j++) {
                        tayta(i,j);
                }
        }
}


void Luola::tulosta() {
        for (int i = 0; i < LUOLASTON_KOKO; i++) { 
                for (int j = 0; j < LUOLASTON_KOKO; j++) { 
//                        std::cout << char(47+tila(j,i)); 
                        std::cout << (tila(j,i)?" ":"X");
                } 
                std::cout << std::endl; 
        }
}


void Luola::vuole(int x, int y) {
	luola[x][y] = monesko;
}


void Luola::tayta(int x, int y) {
	luola[x][y] = 0;
}


int Luola::tila(int x, int y) {
	return luola[x][y];
}


void Luola::tee_huone(bool pinoa) {
	int x = ((rand() % ((LUOLASTON_KOKO-HUONEEN_KOKO-1)/2)) * 2 + 1);
	int y = ((rand() % ((LUOLASTON_KOKO-HUONEEN_KOKO-1)/2)) * 2 + 1);
	int sivu = rand() % HUONEEN_KOKO * 2 + 3;
	int sivu2 = rand() % HUONEEN_KOKO * 2 + 3;
	if (x+sivu > LUOLASTON_KOKO-1) return;
	if (y+sivu2 > LUOLASTON_KOKO-1) return;
	if (pinoa == false) {
		int xx = x;
		int yy = y;
		int xs = x+sivu;
		int ys = y+sivu2;
		if (x<3) xx = 3;
		if (y<3) yy = 3;
		if (x+sivu > LUOLASTON_KOKO-2) xs=LUOLASTON_KOKO-2;
		if (y+sivu2 > LUOLASTON_KOKO-2) ys=LUOLASTON_KOKO-2;

		for (int i = xx; i<xs; i++) {
			for (int j = yy; j<ys; j++) {
				if (tila(i,j)) {
//	std::cout << "en tehny: " << x << " " << y << " " << sivu << " " << sivu2 << " " << std::endl << "koska: " << i << " ja " << j << std::endl;
					return;
				}
			}
		}
	}
//	std::cout << "    teen: " << x << " " << y << " " << sivu << " " << sivu2 << " " << std::endl;
	for (int i = x; i<x+sivu; i++) {
		for (int j = y; j<y+sivu2; j++) {
			vuole(i,j);
		}
	}
	monesko++;
}


void Luola::tee_sokkelot() {
	for (int i = 1; i<LUOLASTON_KOKO-1; i+=2) {
		for (int j = 1; j<LUOLASTON_KOKO-1; j+=2) {
			if (tila(i,j) == 0) {
				tee_sokkelo(i,j);
				monesko++;
			}
		}
	}
}


void Luola::poista_umpikujat() {
	for (int i = 1; i<LUOLASTON_KOKO-1; i+=1) {
		for (int j = 1; j<LUOLASTON_KOKO-1; j+=1) {
//			if (i == 1 && j == 1) continue;
//			if (i == LUOLASTON_KOKO-1 && j == LUOLASTON_KOKO-1) continue;
			int laskuri = 0;
			if (tila(i,j) > 0) {
				if(tila(i+1,j) == 0) laskuri++;
				if(tila(i-1,j) == 0) laskuri++;
				if(tila(i,j+1) == 0) laskuri++;
				if(tila(i,j-1) == 0) laskuri++;
				if(laskuri > 2) {
					tayta(i,j);
					i--;
					j--;
				}
			}
		}
	}
}


void Luola::puhko() {
	for (int i = 1; i<LUOLASTON_KOKO-1; i+=1) {
		for (int j = 1; j<LUOLASTON_KOKO-1; j+=1) {
			if (tila(j,i) == 0) {
				int t = tila(j-1,i);
				int t2 = tila(j+1,i);
				if (t) {
					if (t2 && t2 != t) {
						monesko = t;
						fillaa(j,i);
					}
				}
			}
		}
	}
}


void Luola::fillaa(int x, int y) {
	vuole(x,y);
	if (tila(x+1,y) > 0 && tila(x+1,y) != monesko) fillaa(x+1,y);
	if (tila(x-1,y) > 0 && tila(x-1,y) != monesko) fillaa(x-1,y);
	if (tila(x,y+1) > 0 && tila(x,y+1) != monesko) fillaa(x,y+1);
	if (tila(x,y-1) > 0 && tila(x,y-1) != monesko) fillaa(x,y-1);
}


void Luola::fillaa_testille(int x, int y, int *laskuri) {
	vuole(x,y);
	if (tila(x+1,y) > 0 && tila(x+1,y) != monesko) {(*laskuri)++; fillaa_testille(x+1,y,laskuri);}
	if (tila(x-1,y) > 0 && tila(x-1,y) != monesko) {(*laskuri)++; fillaa_testille(x-1,y,laskuri);}
	if (tila(x,y+1) > 0 && tila(x,y+1) != monesko) {(*laskuri)++; fillaa_testille(x,y+1,laskuri);}
	if (tila(x,y-1) > 0 && tila(x,y-1) != monesko) {(*laskuri)++; fillaa_testille(x,y-1,laskuri);}
}


int* Luola::sotke() {
	int vali;
	if (rand()%2) {
		vali = suunnat[0];
		suunnat[0] = suunnat[3];
		suunnat[3] = vali;
	}
	if (rand()%2) {
		vali = suunnat[0];
		suunnat[0] = suunnat[2];
		suunnat[2] = vali;
	}
	if (rand()%2) {
		vali = suunnat[0];
		suunnat[0] = suunnat[1];
		suunnat[1] = vali;
	}
	return suunnat;
//	std::cout << suunnat[0] << suunnat[1] << suunnat[2] << suunnat[3] << std::endl;
}

void Luola::tee_sokkelo(int x, int y) {
	vuole(x,y);
	int* heh = sotke();
	int mun_suunnat[4];
	mun_suunnat[0] = heh[0];
	mun_suunnat[1] = heh[1];
	mun_suunnat[2] = heh[2];
	mun_suunnat[3] = heh[3];

	for (int i=0; i<4; i++) {
		int suunta = mun_suunnat[i];
		switch(suunta) {
		case 0:
			if ((x+2<LUOLASTON_KOKO) && tila(x+2,y) == 0) {
				vuole(x+1,y);
				tee_sokkelo(x+2,y);
			}
		break;
		case 1:
			if ((x-2>0) && tila(x-2,y) == 0) {
				vuole(x-1,y);
				tee_sokkelo(x-2,y);
			}
		break;
		case 2:
			if ((y+2<LUOLASTON_KOKO) && tila(x,y+2) == 0) {
				vuole(x,y+1);
				tee_sokkelo(x,y+2);
			}
		break;
		case 3:
			if ((y-2>0) && tila(x,y-2) == 0) {
				vuole(x,y-1);
				tee_sokkelo(x,y-2);
			}
		break;
		}
	}
}


int Luola::montako_tyhjaa() {
	int laskuri = 0;
	for(int i=0;i < LUOLASTON_KOKO; i++) {
		for(int j=0;j < LUOLASTON_KOKO; j++) {
			if (tila(j,i) > 0) laskuri++;
		}
	}
	return laskuri;
}


int Luola::moneenko_fillaa() {
	testi_laskuri = 0;
	monesko++;
	int jatka = 0;
	for (int i = 1; i < LUOLASTON_KOKO-1; i++) {
		for (int j = 1; j < LUOLASTON_KOKO-1; j++) {
			if (tila(i,j)>0) {
				testi_laskuri = 1;
				fillaa_testille(i,j,&testi_laskuri);
				jatka = 1;
			}
		if (jatka) break;
		}
	if (jatka) break;
	}
	monesko++;
	return testi_laskuri;
}
