#pragma once

#include <SFML/Graphics.hpp>
#include "AutomataCal.hpp"

#define cellSize 10

class CellularAutomaton_1D{
public:
    CellularAutomaton_1D();
    CellularAutomaton_1D(int _rows, int _cols, int _cell_size, int _rule);

    ~CellularAutomaton_1D();

    void initialize();
    
    void start();

    void displayRow(std::string state, int yPos, sf::Color oneColored, sf::Color zeroColored);

private:
    int rows;
    int cols;
    int cell_size;
    sf::RenderWindow window;
    int rule;
};