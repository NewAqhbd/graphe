#include <iostream>
#include <list>

#include "Matrice.hpp"

Matrice::Matrice(int _size)
{
    size = _size;
    tab = new int *[size];
    for (int id = 0; id < size; id++)
        tab[id] = new int[size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tab[i][j] = 0;
        }
    }
}

Matrice::~Matrice()
{
    for (int id = 0; id < size - 1; id++)
    {
        delete[] tab[id];
    }
    delete[] tab;
}

Matrice Matrice::IdentityMatrix(int _size)
{
    Matrice m = Matrice(_size);

        for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (i == j)
                m.setElement(i, j, 1);
        }
    }

    return m;
}

void Matrice::display()
{
    std::cout << "Matrice: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << tab[i][j];
        }
        std::cout << "" << std::endl;
    }
}

void Matrice::getRelatedComponent()
{

}

int Matrice::getElement(int x, int y)
{
    if (x < size && y < size)
        return tab[x][y];
    else
    {
        std::cout << "Coordonne invalide" << std::endl;
        return -1;
    }

}

void Matrice::setElement(int x, int y, int val)
{
    if (x < size && y < size)
        tab[x][y] = val;
}