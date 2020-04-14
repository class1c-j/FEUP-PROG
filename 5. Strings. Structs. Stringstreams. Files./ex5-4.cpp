/*

    Write a function a boolsequenceSearch(const string &s, int nc, char c) that
    checks whether string s has a sequence of n consecutive characters equal to c.
    Example: sequenceSearch("abcddeedddf", 3,'d') must return true, but
    sequenceSearch("abcddeedddf", 4, 'd') must return false.
    
    a) Using your own algorithm.

*/

bool sequenceSearch(const std::string &s, int nc, char c) {
    for (int i = 0; i < s.length(); i ++) {
        int curr = i, count = 0;
        while (curr < s.size() && s.at(curr) == c) {
            count ++;
            curr ++;
        }
        if (count == nc) return true;
    }
    return false;
}

void testA() {
    std::string str = "abcddeedddf";
    std::cout << sequenceSearch(str, 4, 'd') << std::endl;
}

/*

    b) Using one of the find methods of class string. Tip: build a string made
    of nc characters equal to c

*/

bool sequenceSearchB(const std::string &s, int nc, char c) {
    std::string seq(nc, c);
    return s.find(seq) != -1;
}

void testB() {
    std::string str = "abcddeedddf";
    std::cout << sequenceSearchB(str, 3, 'd') << std::endl;
}





int main() {
    testA();
    testB();
}
