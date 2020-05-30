/*
  
   Repeat problem 5.5, using stringstreams to do the normalization. Tip: use an istringstream to decompose the name
   into its components and an ostringstream to build the normalized name
   
 */

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

void normalizeName(std::string &name) {
    std::istringstream components(name);
    std::ostringstream result{};
    std::vector<std::string> particles = {"DA", "DAS", "DE", "DO", "DOS", "E"};
    std::string tempName{};
    while (components >> tempName) {
        std::transform(tempName.begin(), tempName.end(), tempName.begin(), ::toupper);
        if (std::find(particles.begin(), particles.end(), tempName) == particles.end()) {
            result << tempName << " ";
        }
    }
    name = result.str().substr(0, result.str().length()-1);
}

void test() {
    std::string nameTest1 = "  Maria da Felicidade dos  Reis   e  Passos Dias de Aguiar   ";
    normalizeName(nameTest1);
    std::cout << nameTest1;
}

int main() {
    test();
} 
