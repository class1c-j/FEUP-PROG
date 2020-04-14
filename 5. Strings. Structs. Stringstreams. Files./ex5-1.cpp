#include <iostream>
#include <string>
 
 /*
  
   In cryptography, a Caesar cipher is one of the simplest and most widely known encryption techniques. It is a
   type of substitution cipher, in which each letter in the plain text is replaced by a letter some fixed number
   of positions up (a right shift) or down (a left shift) the alphabet. For example: with a right shift of 3,
   A would be replaced by D, B would become E, ..., and Z would  become C;
   with a left shift of 3, a would become x, d would become a, and so on. The method is named after Julius Caesar,
   who used it in his private correspondence (adapted from Wikipedia)
   
   a) Write a function char encryptChar(char c, int key) that encrypts a character using the Caesar cipher,
   where c is the character to encrypt and key is the shift, or encryprion key. A positive or negative value of
   the parameter key indicates a right or left shift, respectively.
   
*/
 
 
 char encryptChar(char c, int key) {
    if (isalpha(c)) {
        char result = (c + key);
        if (isupper(c)) {
            while (result < 'A') result += 26;
            while (result > 'Z') result -= 26;
        } else {
            while (result < 'a') result += 26;
            while (result > 'z') result -= 26;
        }
        c = result;
    }
    return c;
}

void testA() {
    std::cout << encryptChar('d', -3) << '\n';
    std::cout << encryptChar('r', 3) << '\n';
    std::cout << encryptChar('A', 5) << '\n';
}


/*
 
   b) Write a function string encryptString(string s, int key) that encrypts a C++ string using the above mentioned technique
   
*/


std::string encryptString(const std::string& s, int key) {
    std::string result;
    for (char i : s) {
        result += encryptChar(i, key);
    }
    return result;
}


/*
 
   c) Write a program that reads a string from the keyboard and shows its encryption, using encryptString().
   
*/


void testB() {
    std::string str;
    int key;
    std::cout << "Insert string: "; getline(std::cin, str);
    std::cout << "Insert key: "; std::cin >> key;
    std::cout << encryptString(str, key);
}


/*
 
   d) Redo the program, using a C string instead of a C++ string parameter. Modify the prototype of encryptString() accordingly.
   
*/

void encryptString(char s[], int key) {
    for (int i = 0; i < strlen(s); i ++) {
        s[i] = encryptChar(s[i], key);
    }
}

void testC() {
    int key;
    const int MAX_LEN = 50;
    char str[MAX_LEN];
    std::cout << "Insert string: "; std::cin.getline(str, MAX_LEN);
    std::cout << "Insert key: "; std::cin >> key;
    encryptString(str, key);
    std::cout << str << std::endl;
}




int main() {
    testA();
    testB();
    testC();
}
