#include "interfejs.h"
/**
* \file interfejs.cpp
* \brief Moduł interfejsu użytkownika.
*/


/**
* \brief Metoda1 interfejsu.
* Powitanie.
*/
void interfejs::interfejs_poczatek(){

    cout<<"---------------------------------"<<endl;
    cout<<"Program znajduje sciezke na mapie"<<endl;
    cout<<"**** Algorytm: przejscie BFS ****"<<endl;
    cout<<"---------------------------------"<<endl;

}

/**
* \brief Metoda2 interfejsu.
* Wyświetlenie wczytanej z pliku mapy.
*/
void interfejs::interfejs_mapa_przed(){

    cout<<"----------------------"<<endl;
    cout<<"Mapa wczytana z pliku:"<<endl;
    cout<<"----------------------"<<endl;
}

/**
* \brief Metoda3 interfejsu.
* Wyświetlenie mapy ze znalezioną ścieżką.
*/
void interfejs::interfejs_mapa_po(){

    cout<<"-------------------------"<<endl;
    cout<<"Mapa z wytyczona sciezka:"<<endl;
    cout<<"-------------------------"<<endl;
}


