
#include "Bet.h"

Bet::Bet() {

    for (int i = 1; i < 51; i++) {
        m_mainNumbers.push_back(i);
    }

    for (int i = 1; i < 13; i++) {
        m_starNumbers.push_back(i);
    }

    std::shuffle(m_mainNumbers.begin(), m_mainNumbers.end(), std::mt19937(std::random_device()()));
    std::shuffle(m_starNumbers.begin(), m_starNumbers.end(), std::mt19937(std::random_device()()));

    m_mainNumbers.resize(5);
    m_starNumbers.resize(2);

}

void Bet::show() const {

    std::cout << "Main numbers: ";
    for (const auto &i : m_mainNumbers) {
        std::cout << i << " ";
    }
    std::cout << "\nStar numbers: ";
    for (const auto &i : m_starNumbers) {
        std::cout << i << " ";
    }

}

void Bet::sort() {
    std::sort(m_mainNumbers.begin(), m_mainNumbers.end());
    std::sort(m_starNumbers.begin(), m_starNumbers.end());
}

std::vector<unsigned> Bet::getMainNumbers() {
    return m_mainNumbers;
}

std::vector<unsigned> Bet::getStarNumbers() {
    return m_starNumbers;
}

