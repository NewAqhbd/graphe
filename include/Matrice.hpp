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
    void display();
};