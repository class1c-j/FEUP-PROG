/*

   Write a template function that determines the minimum and maximum values of a vector of numbers that it receives
   as parameter.

*/

#include <iostream>
#include <vector>

template<typename T>
std::pair<T, T> minMax(std::vector<T> v) {
    std::pair<T, T> result{};
    result.first = *std::min_element(v.begin(), v.end());
    result.second = *std::max_element(v.begin(), v.end());
    return result;
}

void testA() {
    std::vector<int> nums = {2, -1, 56, 3, 1};
    std::vector<char> letters = {'a', 'B', 'z', 'X'};

    std::cout << "Max: " << minMax(nums).second << " " << minMax(letters).second << "\n";
    std::cout << "Min: " << minMax(nums).first << " " << minMax(letters).first << "\n";
}

int main() {
    testA();
    return 0;
}
 
