#pragma once

#include <string>

class AutomataCal{
public:
    AutomataCal();
    ~AutomataCal();

    std::string getNextState(std::string state, int rule);

private:
    std::string toBinary(int num, int padTo=8);
    int binaryToInt(std::string s);
};