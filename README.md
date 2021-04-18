# ProgramskiPrevodioci
#Leksicki, Sintaksni, Semanticki analizator miniC jezika

Uputstva za pokretanje:
-----------------------
../semantic - path za pokretanje
make - da napravi leksicki, sintaksni i semanticki generator (SEMANTIC)

./semantic < test.txt - za testiranje analize na txt fajlu
make test - za pokretanje svih testnih fajlova odjednom moraju imati specificne nazive

Primeri:
test-sanity - za provjeru svih analiza zajedno
test-ok.mc - za testove koji ne bi trebali da imaju gresaka
test.semerr.mc - za provjeru semantickih gresaka
test.synerr.mc - za provjeru sintaksnih gresaka

