//
// Created by ritam on 09/06/20.
//

#include "SpreadsheetCellString.h"

void SpreadsheetCellString::set(const std::string &inString) {
    content = inString;
}

SpreadsheetCellString::SpreadsheetCellString(const std::string& value) {
    content = value;
}

std::string SpreadsheetCellString::getString() const {
    return content;
}
