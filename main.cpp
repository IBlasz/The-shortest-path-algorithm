#include <iostream>
#include "funkcje.h"
#include "kolejka.h"
#include "interfejs.h"

using namespace std;

/**
* \mainpage
* \par Projekt z przedmiotu ZAP II
* Program znajdujący najkrótszą ścieżkę w labiryncie.
* \author Izabella Błaszkiewicz
* \date 01.06.2020
* \version Gamma
* \par Kontakt:
* \a izabella.blaszkiewicz.stud@pw.edu.pl
*
* \par Opis pomysłu na program i sposób jego zrealizowania
* Program powstał w celu realizacji Projektu z przedmiotu ZAP II.
* Jego ideą znalezienie najkrótszej trasy pozwalającej na przejście z miejsca oznaczonego jako „start” do miejsca oznaczonego jako „meta”.
* Program dane pobiera z pliku tekstowego, pozwala to na dużą wygodę i uniwersalność w doborze mapy do analizy.
* Program znajduje najkrótszą ścieżkę od wybranego punktu startowego na mapie do wybranego puntu docelowego za pomocą algorytmu BFS (przejście grafu wszerz).
* Do przechowywania labiryntu program wykorzystuje dynamiczną tablicę łańcuchów znakowych.
*
* \par Opis działania algorytmu
* Każdy znak odpowiada wierzchołkowi grafu. Znaki mapy „.”, to wierzchołki połączone krawędziami po których można się poruszać zaś znaki „#” to wierzchołki izolowane.
* Krawędzie istnieją pomiędzy sąsiadującymi wierzchołkami (góra, dół, lewo, prawo).
* Algorytm szukania ścieżki do przechowywania współrzędnych odwiedzanych wierzchołków wykorzystuje kolejkę w postaci listy jednokierunkowej.
* Na początku na koniec kolejki wstawiony zostaje wierzchołek startowy.
* Wewnątrz pętli wierzchołek ten zostanie odczytany jako początkowy, a algorytm umieści w niej wszystkich nieodwiedzonych sąsiadów.
* W kolejnych obiegach pętli sąsiedzi ci (z poziomu 1) zostaną odczytani z początku kolejki, a na jej koniec trafią sąsiedzi z poziomu2 itd.
* Sąsiad nieodwiedzony jest znakiem korytarza(„.”) i jego współrzędne trafiają do kolejki po wstawieniu znaku kierunku przejścia (g,d,l,p).
* Wyszukiwanie drogi trwa aż algorytm dojdzie do pola zawierającego współrzędne wyjścia W lub odwiedzi wszystkie wierzchołki.
*
* \par Instrukcja obsługi
* Na początku należy upewnić się, że podaliśmy w ścieżce do pliku mapę, którą program ma poddać analizie.
* Jeżeli ścieżka do pliku jest podana nieprawidłowo, lub plik jest uszkodzony program wyświetli informację o błędzie.
* W przeciwnym wypadku na ekranie wyświetli się mapa przed i po znalezieniu nakrótszej ścieżki łączącej wierzchołek startowy S oraz wierzchołek końcowy W.
*
*/

/**
* \file main.cpp
* \brief Wywoływanie metod, tworzenie obiektów.
*/
int main()
{
    interfejs i;
    i.interfejs_poczatek();
    Mapa map;
    i.interfejs_mapa_przed();
    map.czytajL();    //wczytuje labirynt
    map.szukajW();    //szuka wyjscia
    i.interfejs_mapa_po();
    map.piszL();     //wyswietla

return 0;
}
