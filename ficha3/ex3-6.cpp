/*
 * Write a function whose prototype is time_t timeElapsed() that returns the time (in seconds) that has elapsed since
 * the first time it was called
 */


#include <iostream>
#include <ctime>
#include <chrono>  // used to test
#include <thread>  // used to test
using namespace std;

time_t timeElapsed() {
    static time_t first_call = time(0);
    time_t current_call = time(0);
    return current_call - first_call;
}

int main() {
    cout << timeElapsed() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // wait for 1000 ms
    cout << timeElapsed() << endl;
}
