#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <list>

class Matrix
{
private:
    int size;
    int** tab ;

public:
    //Conbstructeurs
    Matrix(int _size);
    Matrix(const Matrix& other);     
    ~Matrix();
          
    Matrix& operator=(const Matrix& other);

    //Renvoi une Matrix identité en fonction de la taille passé en parametre.
    static Matrix IdentityMatrix(int _size);

    //Affiche la Matrix:
    void display() const;

    //Multiplie 2 matrices et renvoi le résultat.
    static Matrix matrixMultiply(const Matrix& A, const Matrix& B);

    //Addition les de matrice avec une addition booleen.
    static Matrix matrixAdd(const Matrix& A, const Matrix& B);

    //Renvoi true si 2 matrices sont identiques false sinon.
    static bool MatrixEqual(const Matrix& A, const Matrix& B);

    //Renvoi la transposé de la matrice passé en paramétre.
    static Matrix matrixTranspose(const Matrix& A);

    //Renvoi une matrice correspondant a la fermeture transitive.
    static Matrix matrixTransitiveClosure(const Matrix& A);

    //Getters/Setters:
    int getElement(int x, int y) const;
    void setElement(int x, int y, int val);
    int getSize() const;
};

#endif
