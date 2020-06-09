/*

   Suppose that you want to build a class hierarchy to represent a spreadsheet. For simplicity, let us consider that
   spreadsheet cells can store only two types of values: string or double.

*/

#include "SpreadsheetCell.h"
#include "SpreadsheetCellDouble.h"
#include "SpreadsheetCellString.h"
#include <iostream>
#include <array>

/*

   a) Define the classes SpreadsheetCellString and SpreadsheetCellDouble, derived from class SpreadsheetCell, that will
   be used to store string or double cell values. For simplicity, assume that strings used as arguments of set() method
   to set the value of cells of type double represent valid double values (that is the string can be converted into
   a double).

*/

/*

   b) Write a program that creates a very simple spreadsheet, consisting of an unidimensional array/vector that stores
   both string and double values.

*/


void testB() {

    std::array<SpreadsheetCell*, 5> spread;
    spread[0] = new SpreadsheetCellDouble(3.1);
    spread[1] = new SpreadsheetCellString("asdsdf");
    spread[2] = new SpreadsheetCellString("dfdsfsf");
    spread[3] = new SpreadsheetCellDouble(-2.1);
    spread[4] = new SpreadsheetCellDouble(3.1);

    for (const auto &i : spread) {
        std::cout << i->getString() << "\n";
    }

}

/*

   Modify the definition of the classes so that you can have specific methods to set and get the value of a
   SpreadsheetCellDouble using values of type double.

*/

/*

   Modify the developed program to test the newly developed methods

*/

void testD() {
    std::array<SpreadsheetCell*, 5> spread;

    spread[0] = new SpreadsheetCellDouble;
    spread[1] = new SpreadsheetCellString;
    spread[2] = new SpreadsheetCellString;
    spread[3] = new SpreadsheetCellDouble;
    spread[4] = new SpreadsheetCellDouble;

    for (unsigned int i = 0; i < spread.size(); i ++) {
        SpreadsheetCellDouble* d = dynamic_cast<SpreadsheetCellDouble*>(spread[i]);
        if (d != NULL) {  // it is a double spreadsheet cell
            d->set(2.11);
            std::cout << d->getDouble() << "\n";
        } else {
            SpreadsheetCellString* s = dynamic_cast<SpreadsheetCellString*>(spread[i]);
            if (s != NULL) {
                s->set("asdsf");
                std::cout << s->getString() << "\n";
            }
        }
    }
}

int main() {
    //testB();
    testD();
    return 0;
}