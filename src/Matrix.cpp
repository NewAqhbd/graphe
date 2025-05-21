#include "Matrix.hpp"
#include <iostream>

//Constructeur.
Matrix::Matrix(int _size) : size(_size)
{
    tab = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        tab[i] = new int[size];
        for (int j = 0; j < size; ++j)
            tab[i][j] = 0;
    }
}

//Constructeur secondaire qui utilise une matrice pour en créer une autre.
Matrix::Matrix(const Matrix &other) : size(other.size)
{
    tab = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        tab[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            tab[i][j] = other.tab[i][j];
        }
    }
}

//Surcharge de l'operateur = pour éviter les fuites mémoires.
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < size; ++i)
        delete[] tab[i];
    delete[] tab;

    size = other.size;

    tab = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        tab[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            tab[i][j] = other.tab[i][j];
        }
    }
    return *this;
}

//Destructeur
Matrix::~Matrix()
{
    for (int i = 0; i < size; ++i)
        delete[] tab[i];
    delete[] tab;
}

Matrix Matrix::IdentityMatrix(int _size)
{
    Matrix m(_size);
    for (int i = 0; i < _size; ++i)
        m.setElement(i, i, 1);
    return m;
}

void Matrix::display() const
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            std::cout << tab[i][j] << " ";
        std::cout << std::endl;
    }
}

Matrix Matrix::matrixMultiply(const Matrix &A, const Matrix &B)
{
    int n = A.getSize();
    Matrix res(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (A.getElement(i, k) && B.getElement(k, j))
                {
                    res.setElement(i, j, 1);
                    break;
                }
            }
        }
    }
    return res;
}

Matrix Matrix::matrixAdd(const Matrix &A, const Matrix &B)
{
    int n = A.getSize();
    Matrix res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (A.getElement(i, j) || B.getElement(i, j))
                res.setElement(i, j, 1);
    return res;
}

bool Matrix::MatrixEqual(const Matrix &A, const Matrix &B)
{
    int n = A.getSize();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (A.getElement(i, j) != B.getElement(i, j))
                return false;
    return true;
}

Matrix Matrix::matrixTranspose(const Matrix &A)
{
    int n = A.getSize();
    Matrix res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res.setElement(j, i, A.getElement(i, j));
    return res;
}

Matrix Matrix::matrixTransitiveClosure(const Matrix &A)
{
    Matrix B = matrixAdd(IdentityMatrix(A.getSize()), A);
    Matrix power = A;
    while (true)
    {
        power = matrixMultiply(power, A);
        Matrix newB = matrixAdd(B, power);
        if (MatrixEqual(newB, B))
            break;
        B = newB;
    }
    return B;
}

int Matrix::getSize() const { return size; }
int Matrix::getElement(int x, int y) const { return (x < size && y < size) ? tab[x][y] : -1; }
void Matrix::setElement(int x, int y, int val)
{
    if (x < size && y < size)
        tab[x][y] = val;
}
