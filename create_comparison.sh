#!/bin/bash
make
i=1; while [ $i -le 1000 ]; do ./luolastori $i; let "i=i+1"; done | grep -e "huoneita" -e "vuollut" > dataa
grep huoneita dataa | sort | uniq -c > dataa_huoneita
grep vuollut dataa | sort | uniq -c > dataa_vuollut
