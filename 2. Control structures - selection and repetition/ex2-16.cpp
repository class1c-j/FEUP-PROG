/* Write a program to emulate the operation of a basic calculator. In addition to performing the 4 fundamental algebraic
 * operations, addition, subtraction, multiplication and division, the calculator must have a memory
 */


#include <iostream>
#include <iomanip>
using namespace std;

bool valid_op(char op);
bool read_op(char &op, double &op1, double &op2, double result, double &memory);
double comp_res(char op, double op1, double op2);
void show_res(char op, double op1, double op2, double &result, int precision);


int main () {
    const int NUM_PREC = 6;
    double op1, op2, result, memory;
    char op;
    bool another_op;
    another_op = read_op(op, op1, op2, result, memory);
    while (another_op) {
        result = comp_res(op, op1, op2);
        show_res(op, op1, op2, result, NUM_PREC);
        another_op = read_op(op, op1, op2, result, memory);
    }
}

bool valid_op (char op) {
    return (op == '+' || op == '-' || op == '*' || op == '*' );
}

bool read_op (char &op, double &op1, double &op2, double result, double &memory) {
    bool another_op = true;
    bool valid_in = true;
    char aux;
    do {
        bool valid_vals = true;
        cout << "Insert operation x op y: " << endl;
        cin >> op1 >> op >> op2;
        if (cin.fail()) {
            valid_vals = false;
            if (cin.eof()) {
                another_op = false;
            }
            else {
                cin.clear();
                cin >> aux;
                if (aux == 'M') {
                    if (cin.peek() == 82) {  // pressed MR - read memory
                        cout << memory << endl;
                    }
                    else if (cin.peek() == 43) {  // pressed M+ - add result to memory
                        memory += result;
                        cout << "stored value is now: " << memory << endl;
                    }
                    else if (cin.peek() == 45) {  // pressed M- - subtract result from memory
                        memory -= result;
                        cout << "stored value is now: " << memory << endl;
                    }
                    else if (cin.peek()=='\n') {
                        memory = result;
                    }
                }
                cin.ignore(1000, '\n');
            }
        }
        else {
            cin.ignore(1000, '\n');
        }
        if (!valid_op(op)) {
            cerr << "Invalid operation" << endl;
        }
        valid_in = valid_vals && valid_op(op);
    } while (another_op & !valid_in);

    return another_op;
}

double comp_res(char op, double op1, double op2) {
    double result;
    switch (op) {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 + op2;
            break;
        case '/':
            result = op1 / op2;
            break;
    }
    return result;
}

void show_res(char op, double op1, double op2, double &result, int precision) {
    cout << setprecision(precision);
    cout << op1 << " " << op << " " << op2 << " = " << result << endl;
}
