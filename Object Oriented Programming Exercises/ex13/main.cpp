#include <iostream>
#include <vector>
#include <set>

/*

   a) Extend the program developed in problem 12.a to do the following:
   -automatically generate a lot of N simple bets in EuroMillions, storing them into a vector<Bet>;
   N must be specified interactively by the user;
   -then, simulate the generation of the key, storing it into a Bet object;
   -finally, show the results for each one of the bets, taking into account the simulated key (suggestion: use the
   STL algorithm set_intersection()). Note: the last parameter of the call to set_intersection() must be an
   insert iterator as returned from to std::inserter()
   -see example at the end of the exercise list. Alternatively, you can implement your own code to do the intersection
   of 2 vectors.

*/

#include "Bet.h"

void testA() {

    int n{};
    std::cout << "How many bets to generate ? ";
    std::cin >> n;

    std::cout << "\nGenerating key ...\n";
    Bet key{};
    key.sort();

    std::cout << "Generating bets and calculating scores ...\n\n";
    for (int i = 0; i < n; i++) {
        Bet temp{};
        temp.sort();
        std::cout << "Bet " << i + 1 << ": \n";
        temp.show();
        std::vector<unsigned> mainNumbersResult;
        std::vector<unsigned> mainNumbers = temp.getMainNumbers();
        std::vector<unsigned> mainKey = key.getMainNumbers();
        std::vector<unsigned> starNumbersResult;
        std::vector<unsigned> starNumbers = temp.getStarNumbers();
        std::vector<unsigned> starKey = key.getStarNumbers();

        std::set_intersection(mainNumbers.begin(), mainNumbersResult.end(),
                              mainKey.begin(), mainKey.end(),
                              std::back_inserter(mainNumbersResult));

        std::set_intersection(starNumbers.begin(), starNumbersResult.end(),
                              starKey.begin(), starKey.end(),
                              std::back_inserter(starNumbersResult));

        std::cout << "\nScored " << mainNumbersResult.size() + starNumbersResult.size() << "\n\n";
    }

    std::cout << "The key was: \n";
    key.show();
    std::cout << '\n';
}

/*

   b) Do the same for the program developed in problem 12.b.

*/

#include "BetSet.h"

void testB() {

    int n{};
    std::cout << "How many bets to generate ? ";
    std::cin >> n;

    std::cout << "\nGenerating key ...\n";
    BetSet key{};

    std::cout << "Generating bets and calculating scores ...\n\n";
    for (int i = 0; i < n; i++) {
        BetSet temp{};
        std::cout << "Bet " << i + 1 << ": \n";
        temp.show();

        std::set<unsigned> mainNumbers = temp.getMainNumbers();
        std::set<unsigned> mainKey = key.getMainNumbers();
        std::set<unsigned> mainNumbersResult{};

        std::set<unsigned> starNumbers = temp.getStarNumbers();
        std::set<unsigned> starKey = key.getStarNumbers();
        std::set<unsigned> starNumbersResult{};

        std::set_intersection(mainNumbers.begin(), mainNumbers.end(),
                              mainKey.begin(), mainKey.end(),
                              std::inserter(mainNumbersResult, mainNumbersResult.end()));

        std::set_intersection(starNumbers.begin(), starNumbers.end(),
                              starKey.begin(), starKey.end(),
                              std::inserter(starNumbersResult, starNumbersResult.end()));

        std::cout << "\nScored " << mainNumbersResult.size() + starNumbersResult.size() << "\n\n";
    }

    std::cout << "The key was: \n";
    key.show();
    std::cout << '\n';
}

int main() {
    // testA();
    testB();
    return 0;
}
