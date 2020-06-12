
#include "BetSet.h"


BetSet::BetSet() {

    while (m_mainNumbers.size() < 5) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1,50);
        m_mainNumbers.insert(dist(rng));
    }

    while (m_starNumbers.size() < 2) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1,12);
        m_starNumbers.insert(dist(rng));
    }

}

void BetSet::show() {
    std::cout << "Main numbers: ";
    for (const auto &i : m_mainNumbers) {
        std::cout << i << ' ';
    }
    std::cout << "\nStar numbers: ";
    for (const auto &i : m_starNumbers) {
        std::cout << i << ' ';
    }
}

std::set<unsigned> BetSet::getMainNumbers() {
    return m_mainNumbers;
}

std::set<unsigned> BetSet::getStarNumbers() {
    return m_starNumbers;
}
