#include <iostream>
#include <list>

class Matrix
{
private:
    int size;
    int** tab ;

public:
    Matrix(int _size);
    ~Matrix();

    // Renvoit une Matrix identité en fonction de la taille passé en parametre.
    static Matrix IdentityMatrix(int _size);

    //Affiche la Matrix:
    void display();

    //Affiche et renvoit les composantes connexes.
    void getRelatedComponent();

    // Getters/Setters:

    int getElement(int x, int y);
    void setElement(int x, int y, int val);
    
};