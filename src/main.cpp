#include <iostream>
#include "Matrice.hpp"

using namespace std;

int main(){
    
    Matrice m = Matrice::IdentityMatrix(5);
    m.display();
    return 0;
}