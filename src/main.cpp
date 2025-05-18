#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main(){
    
    Matrix m = Matrix::IdentityMatrix(5);
    m.display();
    return 0;
}