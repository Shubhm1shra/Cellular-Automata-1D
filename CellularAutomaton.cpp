#include "CellularAutomaton.hpp"

CellularAutomaton_1D::CellularAutomaton_1D() : rows(25), cols(25), cell_size(20), rule(30){
    initialize();
}

CellularAutomaton_1D::CellularAutomaton_1D(int _rows, int _cols, int _cell_size, int _rule) : rows(_rows), cols(_cols), cell_size(_cell_size), rule(_rule){
    initialize();
}

CellularAutomaton_1D::~CellularAutomaton_1D() = default;

void CellularAutomaton_1D::initialize(){
    window.create(sf::VideoMode(cols * cell_size, rows * cell_size), "Cellular Automaton!");
    window.setVerticalSyncEnabled(true);
}

void CellularAutomaton_1D::start(){
    std::string state;
    AutomataCal ac;

    int yPos = 0;

    for(int i = 0; i < cols; i++) state += '0';
    if(cols%2) state[(cols-1)/2] = '1';
    else{
        state[cols/2] = '1';
        state[cols/2 + 1] = '1';
    }

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
        }

        displayRow(state, yPos, sf::Color::White, sf::Color::Black);
        state = ac.getNextState(state, rule);

        if(yPos + cell_size < rows * cell_size) yPos += cell_size;
        else yPos = 0;

        /*
        for(int i = 0, yPos = 0; i < rows; i++, yPos += cell_size){
            displayRow(state, yPos);
            state = ac.getNextState(state, rule);

        }
        */

        window.display();

    }
}

void CellularAutomaton_1D::displayRow(std::string state, int yPos, sf::Color oneColored, sf::Color zeroColored){
    sf::RectangleShape rect(sf::Vector2f((float)cell_size, (float)cell_size));

    int xPos = 0;

    for(char ch : state){
        if(ch == '1') rect.setFillColor(oneColored);
        else rect.setFillColor(zeroColored);

        rect.setPosition(xPos, yPos);
        window.draw(rect);

        xPos += cell_size;
    }
}