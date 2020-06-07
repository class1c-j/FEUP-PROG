 /*
   
   Define two functions: void cout(const string &s) and bool endl(const string  &s). The first one shows string s on
   standard output, removing all "non-letter" characters from s; the second one returns true if s ends in a lowercase
   letter. Place both functions in a namespace whose name myfuncs. Write a program to test the developed functions.

*/

#include <iostream>
#include <string>

namespace myfuncs {
    void cout(const std::string &s) {
        for (const auto &i : s) {
            if (isalpha(i)) std::cout << i;
        }
    }
    bool endl(const std::string &s) {
        return tolower(s.back()) == s.back();
    }
}

void testA() {
    myfuncs::cout("sdsfsd 11213 dsfsd $%");
    std::cout << "\n";
    std::cout << myfuncs::endl("ADFGHJnD");
}

int main() {
    testA();
    return 0;
}
