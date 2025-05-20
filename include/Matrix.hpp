// #include <iostream>
// #include <list>

// class Matrix
// {
// private:
//     int size;
//     int** tab ;

// public:
//     Matrix(int _size);
//     ~Matrix();

//     // Renvoi une Matrix identité en fonction de la taille passé en parametre.
//     static Matrix IdentityMatrix(int _size);

//     //Affiche la Matrix:
//     void display();

//     //Multiplie 2 matrices et renvoi le résultat.
//     static Matrix matrixMultiply(Matrix A, Matrix B);

//     //Addition les de matrice avec une addition booleen.
//     static Matrix matrixAdd(Matrix A, Matrix B);

//     //Renvoi true si 2 matrices sont identiques false sinon.
//     static bool MatrixEqual(Matrix A, Matrix B);

//     //Renvoi la transposé de la matrice passé en paramétre.
//     static Matrix matrixTranspose(Matrix A);

//     //Renvoi une matrice correspondant a la fermeture transitive.
//     static Matrix matrixTransitiveClosure(Matrix A);

//     //Affiche et renvoi les composantes connexes.
//     static Matrix getRelatedComponent(Matrix A);

//     // Getters/Setters:

//     int getElement(int x, int y);
//     void setElement(int x, int y, int val);
//     int getSize();
//     void setTab(int* t, int pos);
    
// };

// Matrix.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
private:
    int size;
    int** tab;

public:
    // Constructeur de taille
    Matrix(int _size);
    // Constructeur de copie (deep copy)
    Matrix(const Matrix& other);
    // Opérateur d'affectation (deep copy)
    Matrix& operator=(const Matrix& other);
    // Destructeur
    ~Matrix();

    static Matrix IdentityMatrix(int _size);
    static Matrix matrixMultiply(const Matrix& A, const Matrix& B);
    static Matrix matrixAdd(const Matrix& A, const Matrix& B);
    static Matrix matrixTranspose(const Matrix& A);
    static Matrix matrixTransitiveClosure(const Matrix& A);
    static Matrix getRelatedComponent(const Matrix& A);
    static bool MatrixEqual(const Matrix& A, const Matrix& B);

    void display() const;
    int getSize() const;
    int getElement(int x, int y) const;
    void setElement(int x, int y, int val);
};

#endif // MATRIX_HPP
