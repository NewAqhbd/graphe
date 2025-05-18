#include <iostream>
#include <list>

#include "Matrix.hpp"

Matrix::Matrix(int _size)
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

Matrix::~Matrix()
{
    for (int id = 0; id < size - 1; id++)
    {
        delete[] tab[id];
    }
    delete[] tab;
}

Matrix Matrix::IdentityMatrix(int _size)
{
    Matrix m = Matrix(_size);

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

void Matrix::display()
{
    std::cout << "Matrix: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << tab[i][j];
        }
        std::cout << "" << std::endl;
    }
}

void Matrix::getRelatedComponent()
{

}

int Matrix::getElement(int x, int y)
{
    if (x < size && y < size)
        return tab[x][y];
    else
    {
        std::cout << "Coordonne invalide" << std::endl;
        return -1;
    }

}

void Matrix::setElement(int x, int y, int val)
{
    if (x < size && y < size)
        tab[x][y] = val;
}