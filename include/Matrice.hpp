#include <iostream>
#include <list>

class Matrice
{
private:
    int size;
    int** tab ;

public:
    Matrice(int _size);
    ~Matrice();

    // Renvoit une matrice identité en fonction de la taille passé en parametre.
    static Matrice IdentityMatrix(int _size);

    //Affiche la Matrice:
    void display();

    //Affiche et renvoit les composantes connexes.
    void getRelatedComponent();

    // Getters/Setters:

    int getElement(int x, int y);
    void setElement(int x, int y, int val);
    
};