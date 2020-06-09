/*

   The STL template function template<class ForwardIterator, class UnaryPredicate>
   ForwardIterator remove_if (ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
   transforms the range [first,last[ into a range with all the elements for which pred returns true removed, and returns
   an iterator to the new end of that range. pred is a unary function that accepts an element in the range as argument,
   and returns a value convertible to bool; the value returned indicates whether the element is to be removed (if true,
   it is removed); the function shall not modify its argument; this can either be a function pointer
   or a function object. Given a vector<int>, containing positive an negative values, write two programs that use
   remove_if () to:

*/

#include <vector>
#include <iostream>

/*

   a) remove all the negative values; use a "common" function to implement the UnaryPredicate.

*/

void testA() {
    std::vector<int> numbers = {2, -1, 5, -12, 0, 1};
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int i) {return i < 0;}), numbers.end());
    for (const auto &i : numbers) std::cout << i << "\n";
}

/*
  
   b) Remove all the values in a range specified by the user of the program; use a function object to implement the
   Unary Predicate and explain why a function object is necessary, in this case
  
   in this case we need to use a function object because otherwise it would not be possible to change the bounds'
   values on runtime - a function object allows for the function to have a state 

  
*/

class Compare {
public:
    Compare(int lbound, int ubound);
    int operator()(int i);
private:
    int lower, upper;
};

Compare::Compare(int lbound, int ubound) {
    lower = lbound, upper = ubound;
}

int Compare::operator()(int i) {
    return i <= upper && i >= lower;
}

void testB() {
    int lower, upper;
    std::cout << "Lower Bound ? "; std::cin >> lower;
    std::cout << "Upper Bound ? "; std::cin >> upper;
    Compare c(lower, upper);
    std::vector<int> numbers = {2, -1, 5, -12, 0, 1};
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), c), numbers.end());
    for (const auto &i : numbers) std::cout << i << "\n";
}


int main() {
    //testA();
    testB();
    return 0;
} 
