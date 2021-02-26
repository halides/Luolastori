* Ohjelman yleisrakenne

Luola-luokka sisältää kaksiulotteisen tietorakenteen (luola[][]) ja metodeita jolla ko. tietorakennetta käsitellään. Käännöksen aikana on määritelty LUOLASTON_KOKO ja HUONEEN_KOKO joita käytetään rajoina sekä käännöksen aikana luola[][]:lle tilavarausta laskettaessa että algortimeissä ajoaikana.

Luola(int) eli konstuktori ottaa kokonaislukuparamterin, jos kokonaisluku on 0 otetaan satunnaislukugeneraattorin siemen kellosta, muuten käytetään siemenenä passattua kokonaislukua. Tällöin esimerkiksi testejä varten luotavien luolastojen tekeminen voidaan toteuttaa epäsatunnaisesti. Konstruktori alustaa tietorakenteet.

tee_huone(bool) kaivertaa luolastoon alueen jonka sivun pituus on minimissään 3:n ja maksimissaan headerissa määritelty HUONEEN_KOKO:n perusteella laskettu yläraja. Jos bool-parametri on tosi, voivat huoneet mennä päällekkäin, muuten päällekkäin tuleva uusi huone hylätään.

tee_sokkelot() on apufunktio joka lähtee luomaan tee_sokkelo():n avulla jokaisesta kaivertamattomasta kohdasta sokkeloa.

puhko() yhdistää edellä luodut alueet toisiinsa.

poista_umpikujat() poistaa sokkelot jotka eivät johda huoneesta toisiin huoneisiin.

https://github.com/halides/Luolastori/blob/c4259aad7f1199eaa8f44860e4ed1b14c3df03a3/main.cpp esittää kuinka em. metodeita käytetään tuottamaan valmis sokkelo. Se myös tulostaa välivaiheita.


* Tilavaativuudet eri tietorakenteille

luola[][] = Theta(N^2).

suunnat = 4*sizeof(int).

monesko = sizeof(int).

* Aikavaativuudet ei-triviaaleille ei-tulostaville algoritmeille

Luola() eli konstruktori: Theta(N^2)

tee_huone(): O(N^2)

tee_sokkelot(): Theta(N^2)

tee_sokkelo(): Theta(N^2) (O(N^2) jos oletetaan että ei olla täysin tyhjässä luolastossa, eli huoneita on luotu)

poista_umpikujat(): Theta(N^2)

puhko(): Theta(N^2)

fillaa(): O(N^2) (Theta(N^2) jos oletaan että ollaan täysin kaiverretussa luolastossa)


Testejä varten:

montako_tyhjaa(): Theta(N^2)

moneenko_fillaa(): O(N^2)

fillaa_testille(): O(N^2) (Theta(N^2) jos oletaan että ollaan täysin kaiverretussa luolastossa)


* Puutteita / parannusehdotuksia

Rakenne ei ole testiystävällinen mutta mielummin toteutuin ylimääräisiä funktioita testejä varten kuin lähdin refaktoroimaan.

Muita algoritmejä esimerkiksi sokkelon luontiin olisi helppo lisätä. 


* Lähteet

https://journal.stuffwithstuff.com/2014/12/21/rooms-and-mazes/

https://en.wikipedia.org/wiki/Maze_generation_algorithm
