Opinto-ohjelma: Tietojenkäsittelytiede
Projektin kieli: Suomi

Teen "Nystrom-tyylisen" luolastogeneraattorin C++:lla. Referenssiksi: http://journal.stuffwithstuff.com/2014/12/21/rooms-and-mazes/

Ainoana pysyvämpänä tietorakenteena tulenee olemaan kaksiulotteinen matriisi, jonka solut ovat joko "täytetty" tai "tyhjä". "Täysi" solu on "seinää" ja "tyhjä" solu on "käytävää tai huonetta".
Aputietorakenteina tulenee olemaan generoinnin aikana listat alueista sekä alueitten yhteyksistä.

Luolaston generointiin on monia tapoja. Nystrom-tyylissä ensin luodaan tietty määrä "huoneita", jonka jälkeen täytetään tyhjäksi jäävä tila sokkeloilla. Tämän jälkeen yhdistetään jokainen sokkelo ja huone toisiinsa. Viimeiseksi poistetaan sokkelot jotka ovat umpikujia.

Luodaan luolasto s.e. korkeus ja leveys on parillinen ja sanotaan että vasen yläkulma on origo (0,0). Leveys kasvaa oikealle ja korkeus kasvaa alaspäin mentäessä.
Luodaan huoneet s.e. huoneen alkupisteen koordinaatit (vasen yläkulma) ovat parittomat ja huoneen korkeus ja leveys ovat parittomat. Huoneiden määrä ja kokoluokka on parametroitavissa. Huoneet voivat valinnaisesti mennä päällekkäin, parametroitavissa.
Luodaan tyhjäksi jäävälle alueelle sokkeloa s.e. sokkelot alkavat parittomista koordinaateista ja haarautuvat ainoastaan parittomissa koordinaateissa.
E.m. huoneiden ja sokkeloiden parittomuus on rajoite, jota voidan hyödyntää kun haluamme yhdistää sokkelot ja huoneet (alueet) yhtenäiseksi kokonaisuudeksi. Jokaisella alueella on "yhteys" vähintään yhteen toiseen alueeseen.
Etsitään kaikki sokkelon yhteydet. Tämän jälkeen valitaan jokin alue, valitaan jokin sen yhteys, poistetaan seinä ja merkataan että nämä kaksi aluetta ovat nyt yhtenäiset. Iteroidaan kunnes on vain yksi alue.
Tämän jälkeen voidaan poistaa umpikujat. Operaatio on helppo, jos missä tahansa on tyhjä solu jonka ympärillä on kolme täyttä solua, täytetään tämä tyhjä solu ja iteroidaan kunnes ei enää löydy solua tällä ehdolla.
Nyt Nystrom-tyylinen luolasto on valmis.

Sokkelon generointiin ajattelin käyttää satunnaista depth-first searchia:
https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_depth-first_search

Luolaston testauksessa voi käyttää esim. Flood filliä:
https://en.wikipedia.org/wiki/Flood_fill

Aika- ja tilavaativuudesta en osaa vielä tarkkaan sanoa, mutta käytetyt algoritmit ovat suhteellisen kevyitä.
