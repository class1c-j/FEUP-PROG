//
// Created by ritam on 09/06/20.
//

#include "SpreadsheetCellDouble.h"

SpreadsheetCellDouble::SpreadsheetCellDouble(double value) {
    content = value;
}

void SpreadsheetCellDouble::set(const std::string &inString) {
    content = std::stod(inString);
}

std::string SpreadsheetCellDouble::getString() const {
    return std::to_string(content);
}

void SpreadsheetCellDouble::set(double inDouble) {
    content = inDouble;
}

double SpreadsheetCellDouble::getDouble() const {
    return content;
}
