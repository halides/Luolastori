* Yleistä testauksesta:

Testejä varten meillä on ylimääräisiä funktioita: montako_tyhjaa(), moneenko_fillaa(), tulosta_huoneet() ja tulosta_vuollut().

montako_tyhjaa() käy jokaisen luolaston kohdan läpi ja laskee moniko kohta on luolastoa. 

moneenko_fillaa() etsii jonkun kohdan joka on luolastoa ja kutsuu siihen flood fillin joka laskee moneenko kohtaan ko. flood fill leviää.

tulosta_huoneet() yksinkertaisesti katsoo int monesko:n perusteella montako huonetta on luotu. Tämä täytyy ajaa heti huoneitten luonnin jälkeen, muuten tulos ei pidä paikkaansa.

tulosta_vuollut() yksinkertaisesti tulostaa montako_tyhjaa():n palauttaman arvon.


* Yksikkötestaus:

Yksikkötestauksessa ajetaan luolaston luonnille tarpeellisia algoritmeja ja soveltuvissa kohdin tarkastellaan että tulokset jotka saadaan montako_tyhjaa():sta ja moneenko_fillaa():sta ovat samat.

Yksikkötestit voi ajaa seuraavasti
```
make test
./test_luolastori
```

* Vertailutestaus:

Luolastorin voi ajaa kokonaislukuargumentilla jota käytetään siemenenä satunnaislukugeneraattorille, jolloin esimerkiksi ajamalla ./luolastori 1 saadaan joka kerta samanlainen sokkelo aikaiseksi. Jos argumentti on 0, käytetään siemenenä "sekunteja epochista".

Ajettaessa Luolastori tulostaa luotujen huoneiden lukumäärän sekä montako vuoltua neliötä luolastossa on käyttämällä em. funktioita.

Ajettiin kolmesta eri luolastokoko-huonekoko yhdistelmästä (21-3, 41-5, 61-7) kustakin 1000 aineistoa (argumentteina kokonaisluvut 1-1000), https://github.com/halides/Luolastori/blob/main/create_comparison.sh skriptillä

https://github.com/halides/Luolastori/tree/main/vertailua löytyvät PDF:t joissa myös data joista ao. kuvat luotiin.

Kuvaajista näkee montako huonetta parametreilla luotiin, sekä kuinka monta tyhjää neliötä lopulliseen sokkeloon tuli. Näitä tietoja voisi käyttää esimerkiksei analyysissä kuinka hyvin tämä generaattori sopisi vaikka peleihin tai esimerkiksei tutkimyskäyttöön polunhakualgoritmeja testattaessa.

![21-3](https://github.com/halides/Luolastori/blob/main/doc/img/21-3.png?raw=true)

![41-5](https://github.com/halides/Luolastori/blob/main/doc/img/41-5.png?raw=true)

![61-7](https://github.com/halides/Luolastori/blob/main/doc/img/61-7.png?raw=true)


* Testikattavuusraportti:

Testikattavuuden luonnille on oma skriptinsä:
`./create_coverage`

Skripti ilmoittaa:

```
File 'luolastori.cpp'
Lines executed:92.22% of 167
Creating 'luolastori.cpp.gcov'
```

Kurkkamalla luolastori.cpp.gcov saadaan tarkempi katsaus kattavuudesta:

```

```
