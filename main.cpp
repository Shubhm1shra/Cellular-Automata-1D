#include <iostream>

#include <SFML/Graphics.hpp>
#include "CellularAutomaton.hpp"

int main(){
    int rows = 100;
    int cols = 200;
    int cell_size = 3;
    int rule = 167;
    
    CellularAutomaton_1D ca1d(rows, cols, cell_size, rule);

    ca1d.start();

    return 0;
}
