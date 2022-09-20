#ifndef KOLEJKA_H
#define KOLEJKA_H

/**
* \file kolejka.h
* \brief Plik nagłówkowy modułu kolejka.
*/

/** \brief Element listy dynamicznej.
* Definicja elementu jednokierunkowej listy.
*/
struct lista
{
  lista * next;
  int v;
};

/**
* \brief Definicja kolejki wykorzystującej listę jednokierunkową.
*/
class Kolejka
{
private:
  lista * head;
  lista * tail;

public:
  Kolejka( );      // konstruktor
  ~Kolejka( );     // destruktor
  bool empty ( void );  //sprawdza, czy kolejka jest pusta
  int  front ( void );  //odczyt element z poczatku kolejki
  void push ( int v );  //dopisuje nowy element na koniec
  void pop ( void );    //usuwa pierwszy element
};

#endif // KOLEJKA_H
