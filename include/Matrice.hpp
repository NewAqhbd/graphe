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
    int getElement(int x, int y);
    void setElement(int x, int y, int val);
};