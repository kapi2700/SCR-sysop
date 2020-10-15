LC_ALL=C

dzien=$(date +%u)

#echo "$dzien"

if [ $dzien -gt 5 ]; then
    echo "Milego weekendu!"
else
    echo "Milej pracy!"
fi
