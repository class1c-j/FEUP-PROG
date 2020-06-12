
#ifndef FICHA_BETSET_H
#define FICHA_BETSET_H

#include <set>
#include <iostream>
#include <random>

class BetSet {
public:
    BetSet();
    void show();
    std::set<unsigned> getMainNumbers();
    std::set<unsigned> getStarNumbers();
private:
    std::set<unsigned> m_mainNumbers{};
    std::set<unsigned> m_starNumbers{};
};


#endif //FICHA_BETSET_H
