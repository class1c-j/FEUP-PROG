/*
 
   The process of betting on EuroMillions requires that the player choosesfive or more "main numbers"
   from 1 to 50 and two or more "lucky stars" from 1 to 12. The key of EuroMillions is made of five
   "main numbers" and two "lucky stars". So both a bet and a key can be represented by the following struct:
   struct EuroMillionsBet{
        vector<unsigned> mainNumbers;
        vector<unsigned> luckyStars;
   };
   Write a program that, using variables of type EuroMillionsBet to represent bets and keys,does the following:
   -reads the bet of a player;
   -generates a random key;
   -shows the result of the bet, by computing the number of coincident values in "main numbers" and the
    "lucky stars" in the bet and the key. Tip: reuse the code of problem 4.6.
  
*/

 #include <iostream>
#include <vector>
#include <ctime>

void removeDuplicates(std::vector<unsigned> &v) {
    for (int i = 0; i < v.size(); i ++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v.at(i) == v.at(j)) {
                for (int k = j + 1; k < v.size(); k ++) {
                    v.at(k - 1) = v.at(k);
                }
                v.resize(v.size() - 1);
                j --;
            }
        }
    }
}

std::vector<unsigned> vectorIntersection(const std::vector<unsigned> &v1, const std::vector<unsigned> &v2) {
    std::vector<unsigned> v3;
    for (unsigned i : v1) {
        for (unsigned j : v2) {
            if (i == j) {
                v3.push_back(i);
            }
        }
    }
    removeDuplicates(v3);
    return v3;
}

struct EuroMillionsBet {
    std::vector<unsigned> mainNumbers;
    std::vector<unsigned> luckyStars;
};

void readBet(EuroMillionsBet &bet) {
    int nNumbers, nStars;
    unsigned temp;
    std::cout << "How many NUMBERS do you want to bet on (minimum 5): ";
    std::cin >> nNumbers;
    while (std::cin.fail() || nNumbers < 5) {
        std::cout << "Invalid! Try again: ";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cin >> nNumbers;
    }
    while (nNumbers) {
        std::cout << "Insert number (1 - 50): ";
        std::cin >> temp;
        while (std::cin.fail() || temp < 1 || temp > 50) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "Invalid! Try again: ";
            std::cin >> temp;
        }
        bet.mainNumbers.push_back(temp);
        nNumbers --;
    }

    std::cout << "How many STARS do you want to bet on (minimum 2): ";
    std::cin >> nStars;
    while (std::cin.fail() || nStars < 2) {
        std::cout << "Invalid! Try again: ";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cin >> nStars;
    }
    while (nStars) {
        std::cout << "Insert number (1 - 12): ";
        std::cin >> temp;
        while (std::cin.fail() || temp < 1 || temp > 12) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "Invalid! Try again: ";
            std::cin >> temp;
        }
        bet.luckyStars.push_back(temp);
        nStars --;
    }
}

void generateKey(EuroMillionsBet &key) {
    for (int i = 0; i < 5; i ++) {
        key.mainNumbers.push_back(rand() % 50 + 1);
    }
    for (int i = 0; i < 2; i ++) {
        key.luckyStars.push_back(rand() % 12 + 1);
    }
}

void showResult(const EuroMillionsBet &bet, const EuroMillionsBet &key) {
    int score = vectorIntersection(bet.mainNumbers, key.mainNumbers).size()
            + vectorIntersection(bet.luckyStars, key.luckyStars).size();
    std::cout << "You played:\nNumbers: ";
    for (unsigned n : bet.mainNumbers) {
        std::cout << n << " ";
    }
    std::cout << "\nStars: ";
    for (unsigned s : bet.luckyStars) {
        std::cout << s << " ";
    }
    std::cout << "\n\nKey was: ";
    for (unsigned n : key.mainNumbers) {
        std::cout << n << " ";
    }
    std::cout << "\nStars: ";
    for (unsigned s : key.luckyStars) {
        std::cout << s << " ";
    }
    std::cout << "\nWhich gives you a score of " << score << std::endl;

}

int main() {
    std::srand(NULL);
    EuroMillionsBet bet;
    EuroMillionsBet key;
    readBet(bet);
    generateKey(key);
    showResult(bet, key);
}
