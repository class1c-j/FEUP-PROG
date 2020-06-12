
/*

   The process of betting on EuroMillions requires you to choose five "main numbers" from 1 to 50 and two "lucky stars"
   from 1 to 12.
   Write two versions a program to choose the "main numbers" and the "lucky stars" of a simple bet in EuroMillions and
   show the numbers on the screen.

   a) Define a class Bet to represent a simple bet. Use two STL vectors to represent the "main numbers" and the "star
   numbers" and implement its constructor. Suggestion to implement the constructor: start by filling the "main numbers"
   vector with all the numbers from 1 to 50 and the "star numbers" vector with all the numbers from 1 to 12.
   Then shuffle the two vectors using STL algorithm random_shuffle(). Finally, keep only the first 5 numbers of the
   "main numbers" vector and the first 2 numbers of the "star numbers"vector

*/

#include "Bet.h"

void testA() {
    Bet bet{};
    bet.show();
}

/*

   b) Modify the definition of class Bet in order to use two STL sets to represent the "main numbers" and the "star
   numbers". Suggestion to implement the constructor:
   generate random numbers and insert them in the sets until the "main set" contains 5 numbers and the "star set"
   contains 2 numbers

*/

#include "BetSet.h"

void testB() {
    BetSet bs;
    bs.show();
}

int main() {
    // testA();
    testB();
    return 0;
}