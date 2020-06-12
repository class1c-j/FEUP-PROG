

#ifndef FICHA_BET_H
#define FICHA_BET_H

#include <vector>


class Bet {
public:
    Bet();
    void show();
private:
    std::vector<unsigned> m_mainNumbers{};
    std::vector<unsigned> m_starNumbers{};
};


#endif //FICHA_BET_H
