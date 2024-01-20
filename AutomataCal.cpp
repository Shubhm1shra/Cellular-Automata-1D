#include "AutomataCal.hpp"

AutomataCal::AutomataCal(){}
AutomataCal::~AutomataCal() = default;

std::string AutomataCal::toBinary(int num, int padTo){
    std::string result;

    while(num){
        if(num & 1) result += '1';
        else result += '0';

        num >>= 1;
    }

    while(padTo > result.size()) result += '0';

    std::string reverse;

    for(int i = result.size() - 1; i >= 0; i--) reverse += result[i];

    return reverse;
}

int AutomataCal::binaryToInt(std::string binaryString) {
    int result = 0;

    for (char digit : binaryString) {
        if (digit == '1') result = (result << 1) | 1;
        else result = result << 1;
    }

    return result;
}

std::string AutomataCal::getNextState(std::string state, int rule){
    std::string nextState;
    nextState += state[0];
    std::string root = toBinary(rule, 8);

    for(int i = 1; i < state.size(); i++) nextState += root[7 - binaryToInt(state.substr(i-1, 3))];

    nextState += state[state.size() - 1];

    return nextState;
}