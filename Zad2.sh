#!/bin/bash

#opcja -a pozwala zalaczenie pliku
#opcja -s pozwala na nadanie tematu wiadomosci

for adres in $(cat $(pwd)/Zad2_pliki/adresy.txt)
do
    cat $(pwd)/Zad2_pliki/tresc.txt | mutt -s "Okna PCV" $adres -a $(pwd)/Zad2_pliki/spec*.pdf
done

