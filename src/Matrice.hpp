#include <iostream>
#include <list>

class Matrice
{
private:
    int taille;
    int** grille ;

public:
    Matrice(int _taille);
    ~Matrice();
};