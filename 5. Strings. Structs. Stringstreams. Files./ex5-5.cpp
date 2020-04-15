/*
 
   Write a function string normalizeName(const string &name) to "normalize" a Portuguese name as follows:
   spaces at the beginning or at the end are suppressed; multiple spaces between two words are replaced by a single
   space; lowercase are converted to uppercase; the particles "DE", "DO", "DA", "DOS", "DAS", and "E" are
   removed. The return value  of  the  function is the "normalized" name. Example: the result of normalizing
   the name "Maria da  Felicidade dos Reis e Passos Dias de Aguiar" should be "MARIA FELICIDADE REIS PASSOS
   DIAS AGUIAR". Write a program for testing the function. Tips: use an array or vector of strings to store
   the particles to be removed; use auxiliar functions to implement each one of the steps (they can be useful
   in other occasions, for example, to remove spaces at the beginning or end of the string)

*/

#include <string>
#include <vector>
#include <iostream>

std::string upperCase(const std::string &name) {
    std::string res;
    for (char letter : name) {
        if (isalpha(letter)) res += toupper(letter); else res += ' ';
    }
    return res;
}

void removeExtraSpaces(std::string &name) {
    name.erase(std::unique(name.begin(), name.end(), [](char a, char b) {return isspace(a) && isspace(b);}),
               name.end());
}

void trimString(std::string &name) {
    int startName = name.find_first_not_of(' ');
    name = name.substr(startName);
    int endName = name.find_last_not_of(' ');
    name = name.substr(0, endName + 1);
}

void removeParticles(std::string &name, std::vector<std::string> &particles) {
    for (const std::string& par : particles) {
        size_t pos = name.find(par);
        while (pos != std::string::npos) {
            name.replace(pos, par.size(), " ");
            pos = name.find(par, pos);
        }
    }
}

std::string normalizeName(const std::string &name) {
    std::string result = name;
    result = upperCase(name);
    std::vector<std::string> particles = {" DE ", " DO ", " DA ", " DOS ", " DAS ", " E "};
    removeParticles(result, particles);
    removeExtraSpaces(result);
    trimString(result);
    return result;
}

void test() {
    std::string name;
    std::cout << "Insert name to normalize: ";
    std::getline(std::cin, name);
    std::cout << normalizeName(name) << std::endl;
}

int main() {
    test();
}
