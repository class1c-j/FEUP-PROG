

#ifndef FICHA_BET_H
#define FICHA_BET_H

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

class Bet {
public:
    Bet();

    void show() const;

    void sort();

    std::vector<unsigned> getMainNumbers();

    std::vector<unsigned> getStarNumbers();

private:
    std::vector<unsigned> m_mainNumbers{};
    std::vector<unsigned> m_starNumbers{};
};


#endif //FICHA_BET_H
