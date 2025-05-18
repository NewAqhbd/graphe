#include <iostream>
#include "Matrix.hpp"
#include "Dijkstra.hpp"

using namespace std;

int main(){
    
    Matrix m = Matrix::IdentityMatrix(5);
    m.display();
    main_dijkstra();
    return 0;
}