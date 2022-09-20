#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "funkcje.h"
#include "kolejka.h"

using namespace std;

/**
* \file funkcje.cpp
* \brief Wczytywanie mapy, znajdowanie ścieżki oraz odtworzenie mapy ze znalezioną ścieżką.
*/

/** \brief Konstruktor
*Nadaje wartości domyślne.
* \param wst wierzchołek startowy
* \param kst kolumna strtowa
* \param wwy wierzchołek wyjściowy
* \param kwy kolumna wyjściowa
* \param n liczba wierszy we wczytanej mapie
*/
Mapa::Mapa(int _wst, int _kst, int _wwy, int _kwy, int _n)
{
    wst=_wst;
    kst=_kst;
    wwy=_wwy;
    kwy=_kwy;
    n=_n;
    L = new string [n];
}

/** \brief Wczytywanie labiryntu
*
* Metoda wczytująca labirytnt i wyznaczająca wierzchołek startowy S i końcowy K.
* \param s wczytany wiersz
* \param *T tablica łańcuchów znakowych
* \param i licznik wierszy
*/
void Mapa::czytajL( )
{
    fstream plik;
/**
* \brief Ścieżka do pliku.
*/
    plik.open("wejscie1.txt", ios::in);
    string s, *T;
      int i, j;

      i = 0;            /// i- licznik wierszy.

      if(plik.good()==false)
      {
          cout<<"Nie udalo sie otworzyc pliku!"<<endl;
          exit(0);
      }
      else
      do
       {
        getline (plik,s);       /// Czytamy wiersz z wejścia.
        if( s!= "*")    /// Jeśli nie jest to wiersz końcowy, to
        {
          if( n<i+1 )
          {
              T = new string [i+10]; /// Ustawiamy powiększony rozmiar tablicy z wierszami o 10.
              for( j = 0; j<n; j++) T[j] = L[j];
                delete [] L;
                L = T;
                n = i+10;
          }
          L [i++] = s; /// Odczytany wiersz umieszczamy w tablicy.
        }
      } while( s != "*" );

      plik.close();

      n = i; /// Liczba wierszy w mapie.

      for( i=0; i<n; i++)
        for( j=0; j<1; j++)
        cout << L[i]<< endl; /// Wypisuje wczytaną ścieżkę.


      for( i=0; i<n; i++ )  /// Szuka S i W:
        for( j=0; j<(int)L[i].length(); j++)
          if( L [i][j]=='S' )
          {
            wst=i; kst=j;   /// S znalezione
          }
          else if( L[i][j]=='W' )
          {
            wwy=i; kwy=j;   /// W znalezione
            L[i][j] = '.';  /// Zastępuje W znakiem ".", żeby algotytm przejścia BFS mógł do niego dojść.
          }

}

/** \brief Główny algorytm przejścia BFS
*
* \param w wiersz bieżącego wierzchołka
* \param k kolumna bieżącego wierzchołka
*/
void Mapa::szukajW( )
{
    Kolejka Q;
    int w, k;
    int i, j;

    /// W kolejce umieszczamy wierzchołek startowy.
    Q.push (wst);
    Q.push (kst);    


    /// Dopóki kolejka nie jest pusta.
    while(!Q.empty())
    {
      w = Q.front(); Q.pop(); /// Pobieramy z kolejki wiersz.
      k = Q.front(); Q.pop(); /// I kolumnę bieżącego wierzchołka.

      // Sprawdzamy, czy osiągnęliśmy wyjście.

      if((w==wwy) && (k==kwy)) break;

        // Przeglądamy sąsiadów bieżącego wierzchołka.
      for( i = -1; i <= 1; i++ )
        for( j = -1; j <= 1; j++ )
          if((i!=j) && (!i||!j))
          {
            if( L [w+i][k+j]=='.' )
            {
                /// W komórce sąsiada zapisujemy, skąd przyszliśmy do niej.

              if     (i== -1) L[w+i][k+j] = 'd';  // z dołu
              else if(i==  1) L[w+i][k+j] = 'g';  // z góry
              else if(j== -1) L[w+i][k+j] = 'p';  // z prawej
              else            L[w+i][k+j] = 'l';  // z lewej

              /// Umieszczamy sąsiada w kolejce.
              Q.push (w+i);
              Q.push (k+j);
            }
          }
    }

}

/** \brief Metoda wypisująca mapę.
*
* Jeżeli ścieżka została znaleniona, wypisuje mapę ze znalezioną ścieżką znakami "+".
*/
void Mapa::piszL( )
{
  int i, j;
  char c;

  /// Najpierw sprawdzamy, czy ścieżka została znaleziona.
  if( L[wwy][kwy]!='.' )
  {
    i=wwy; j=kwy;

    /// Jeśli tak, to zastępujemy ją znakami +.
    while((i!=wst) || (j!=kst))
    {
      c = L[i][j];
      L [i][j] = '+';
      switch (c)
      {
        case 'd' : i++; break;
        case 'g' : i--; break;
        case 'p' : j++; break;
        case 'l' : j--; break;
      }
    }
  }

  /// Odtwarzamy znak wyjścia.
  L[wwy][kwy]='W';

  /// Usuwamy znaki kierunku i wypisujemy mapę.
  for( i=0; i<n; i++)
  {
    for( j=0; j<(int)L[i].length(); j++)
      switch(L[i][j])
      {
        case 'g': ;
        case 'd': ;
        case 'p': ;
        case 'l': L[i][j] = ' ';
      }
    cout << L[i]<< endl;
  }
  cout << endl;
}
