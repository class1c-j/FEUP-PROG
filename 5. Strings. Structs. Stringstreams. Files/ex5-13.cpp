/*
 
   Remember problem 5.8. Consider that the bets for a given draw are stored in a text file, using the format illustrated
   on the right, consisting of the name of the players, followed by the bets they have done. Develop a program that reads,
   from the keyboard, the key of that draw, and produces another file containing the name of the players, their bets,
   the number of "main numbers" and  "lucky stars" of each bet, as well as the number of correct "main numbers" and
   "lucky stars" for each bet. The output must be formated so that: the key is written at the top of the file;
   every number occupies a field 2 characters wide.
   Suggestion: read each bet into a single string and use stringstreams to extract the numbers of the bet.
  
*/ 

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

// doesnt work with multiple bets from the same person, maybe someday it will, who knows

void removeDuplicates(std::vector<int> &v) {
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

std::vector<int> vectorIntersection(const std::vector<int> &v1, const std::vector<int> &v2) {
    std::vector<int> v3;
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

struct Bet {
    std::string name;
    std::vector<int> numbers;
    std::vector<int> stars;
    std::vector<int> score;
};


void readFile(const std::string& fileName, std::vector<std::string> &result) {
    std::ifstream f_in(fileName);
    std::string line;
    while (!f_in.eof()) {
        std::string toBet{};
        toBet += line;
        getline(f_in, line);
        if (isalpha(line.front())) {
            toBet += line;
        } else if (isdigit(line.front())) {
            while (isdigit(line.front())) {
                toBet += '\n' + line;
                getline(f_in, line);
            }
            result.push_back(toBet);
        }
    }
}

std::vector<Bet> processBets(const std::vector<std::string> &read) {
    std::vector<Bet> bets;
    for (const std::string& b : read) {
        Bet bet;
        int nAux, sAux;
        std::string name, nstr, sstr;
        std::vector<unsigned> nums, stars;
        std::istringstream s_in(b);
        getline(s_in, name);
        getline(s_in, nstr, '-');
        getline(s_in, sstr);
        std::istringstream numbersStream(nstr);
        std::istringstream starsStream(sstr);
        while (numbersStream >> nAux) {
            bet.numbers.push_back(nAux);
        }
        while (starsStream >> sAux) {
            bet.stars.push_back(sAux);
        }
        bet.name = name;
        bets.push_back(bet);
    }
    return bets;
}

Bet readKey() {
    Bet key;
    std::string keyRead;
    std::cout << "Insert key: ";
    getline(std::cin, keyRead);
    int nAux, sAux;
    std::string nstr, sstr;
    std::vector<unsigned> nums, stars;
    std::istringstream s_in(keyRead);
    getline(s_in, nstr, '-');
    getline(s_in, sstr);
    std::istringstream numbersStream(nstr);
    std::istringstream starsStream(sstr);
    while (numbersStream >> nAux) {
        key.numbers.push_back(nAux);
    }
    while (starsStream >> sAux) {
        key.stars.push_back(sAux);
    }
    return key;
}

void computeScore(Bet& bet, const Bet& key) {
    std::vector<int> score(2);
    score.at(0) = vectorIntersection(bet.numbers, key.numbers).size();
    score.at(1) = vectorIntersection(bet.stars, key.stars).size();
    bet.score = score;
}

void writeFile(const std::string& fileName, const std::vector<Bet>& bets, const Bet& key) {
    std::ofstream f_out(fileName);
    f_out << std::setw(2);
    f_out << "KEY = ";
    for (int i = 0; i < key.numbers.size(); i ++) {
        if (i == key.numbers.size() - 1) {
            f_out << key.numbers.at(i);
        } else {
            f_out << key.numbers.at(i) << " ";
        }
    }
    f_out << " - ";
    for (int i = 0; i < key.stars.size(); i ++) {
        if (i == key.stars.size() - 1) {
            f_out << key.stars.at(i);
        } else {
            f_out << key.stars.at(i) << " ";
        }
    }
    f_out << '\n';
    for (const Bet &bet : bets) {
        f_out << bet.name << "\n";
        for (int i = 0; i < bet.numbers.size(); i ++) {
            if (i == bet.numbers.size() - 1) {
                f_out << std::setw(2) << bet.numbers.at(i);
            } else {
                f_out << std::setw(2) << bet.numbers.at(i) << " ";
            }
        }
        f_out << " - ";
        for (int i = 0; i < bet.stars.size(); i ++) {
            if (i == bet.stars.size() - 1) {
                f_out << std::setw(2) << bet.stars.at(i);
            } else {
                f_out << std::setw(2) << bet.stars.at(i) << " ";
            }
        }
        f_out << " => ";
        f_out << std::setw(2) << bet.numbers.size() << "-" << bet.stars.size() << " | "
        << bet.score.at(0) << "-" << bet.score.at(1) << "\n";
    }
}

int main() {
    Bet key = readKey();
    std::cout << "Read key\n";
    std::vector<std::string> betsRaw;
    readFile("bets.txt", betsRaw);
    std::cout << "Read bets\n";
    std::vector<Bet> betsProc = processBets(betsRaw);
    std::cout << "Processed" << betsProc.size() << "bets\n";
    std::vector<std::vector<int>> scores;
    for (Bet& bet : betsProc) {
        computeScore(bet, key);
    }
    std::cout << "Computed score\n";
    writeFile("Testing", betsProc, key);
    std::cout << "Wrote to the file\n";
}


