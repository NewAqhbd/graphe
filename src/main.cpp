#include <iostream>
#include "Matrix.hpp"
#include "Dijkstra.hpp"
#include "Coloration.hpp"

using namespace std;

int main(){
    
    Matrix m = Matrix::IdentityMatrix(5);
    m.display();
    cout << "\n" << endl;

    main_dijkstra();
    cout << "\n" << endl;

    main_coloration();
    cout << "\n" << endl;
    return 0;
}