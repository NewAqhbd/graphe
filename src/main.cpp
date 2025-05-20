#include <iostream>
#include "Matrix.hpp"
#include "Dijkstra.hpp"
#include "Coloration.hpp"

using namespace std;

int main(){
    
    Matrix m = Matrix(5);

    m.setElement(0, 0, 0);
    m.setElement(0, 1, 1);
    m.setElement(0, 2, 0);
    m.setElement(0, 3, 1);
    m.setElement(0, 4, 0);

    m.setElement(1, 0, 0);
    m.setElement(1, 1, 1);
    m.setElement(1, 2, 1);
    m.setElement(1, 3, 0);
    m.setElement(1, 4, 0);

    m.setElement(2, 0, 0);
    m.setElement(2, 1, 0);
    m.setElement(2, 2, 0);
    m.setElement(2, 3, 0);
    m.setElement(2, 4, 1);

    m.setElement(3, 0, 0);
    m.setElement(3, 1, 0);
    m.setElement(3, 2, 1);
    m.setElement(3, 3, 0);
    m.setElement(3, 4, 1);

    m.setElement(4, 0, 0);
    m.setElement(4, 1, 0);
    m.setElement(4, 2, 0);
    m.setElement(4, 3, 1);
    m.setElement(4, 4, 1);

    m.display();
    std::cout << std::endl;

    Matrix tmp = Matrix::matrixTransitiveClosure(m);
    tmp.display();

    std::cout << std::endl;

    tmp = Matrix::getRelatedComponent(m);
    tmp.display();

    std::cout << std::endl;

    cout << "\n" << endl;

    main_dijkstra();
    cout << "\n" << endl;

    main_coloration();
    cout << "\n" << endl;

    
    return 0;
}