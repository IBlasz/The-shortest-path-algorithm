#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <string>

/**
* \file funkcje.h
* \brief Plik nagłówkowy modułu funkcje.
*/

using namespace std;

/**
* \brief Klasa Mapa służąca do analizy mapy.
*/
class Mapa
{
private:
    int wst, kst;  // Współrzędne startowe - wiersz, kolumna
    int wwy, kwy;  // Współrzędne wyjścia  - wiersz, kolumna
    int n;    // Liczba wierszy

public:
    string * L;
    Mapa (int _wst=1, int _kst=1, int _wwy=1, int _kwy=1, int _n=10);  //konstruktor-nadaje wsp początkowe
    void czytajL( );    //wczytuje mapę
    void szukajW( );    //szuka wyjscia
    void piszL( );  //wypisuje mapę ze sciezka

};

#endif // FUNKCJE_H
