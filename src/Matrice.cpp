#include <iostream>
#include <list>

#include "Matrice.hpp"

Matrice::Matrice(int _taille){
    taille = _taille;
    grille = new int* [taille];
    for (int i = 0; i < taille-1; i++){
        grille[i] = new int [taille];
    }
}

Matrice::~Matrice(){
    for (int i = 0; i < taille-1; i++){
       delete[] grille[i];
    }
    delete[] grille;
}