#include <iostream>

/*
g++ CellularAutomaton.cpp AutomataCal.cpp -o main main.cpp -I\"C:\\msys64\\mingw64\\include\" -L\"C:\\msys64\\mingw64\\lib\" -lsfml-graphics -lsfml-window -lsfml-system
*/

#include <SFML/Graphics.hpp>
#include "CellularAutomaton.hpp"

int main(){
    CellularAutomaton_1D ca1d(100, 200, 3, 167);

    ca1d.start();

    return 0;
}