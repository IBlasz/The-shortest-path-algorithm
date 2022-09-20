#include "kolejka.h"
#include <iostream>
#include <string>
/**
* \file kolejka.cpp
* \brief Kolejka utworzona za pomocją listy jednokierunkowej.
*/

///Konstruktor-tworzy pustą listę z wartościami początkowymi null.
Kolejka::Kolejka()
{
    head=tail=NULL;
}

///Destruktor - usuwa listę z pamięci.
Kolejka::~Kolejka()
{
    while (head)
    pop();
}

/**
* \brief Metoda empty.
* Sprawdza, czy kolejka jest pusta.
*/
bool Kolejka::empty(void)
{
    return !head;
}

/**
* \brief Metoda front.
* Czyta element z początku kolejki.
*/
int Kolejka::front (void)
{
    if (head) return head->v;
    else return 0;
}

/**
* \brief Metoda push.
* Dopisuje element na koniec kolejki.
*/
void Kolejka::push ( int v )
{
    lista *p=new lista;
    p->next = NULL;
    p->v=v;
    if (tail) tail->next = p;
    else head = p;
    tail = p;
}

/**
* \brief Metoda pop.
* Usuwa pierwszy element z kolejki.
*/
void Kolejka::pop ( void )
{
  if( head )
  {
    lista * p = head;
    head = head->next;
    if( !head ) tail = NULL;
    delete p;
  }
}
