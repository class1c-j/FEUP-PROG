
#ifndef STUFY_SPREADSHEETCELLSTRING_H
#define STUFY_SPREADSHEETCELLSTRING_H

#include "SpreadsheetCell.h"


class SpreadsheetCellString : public SpreadsheetCell {
public:
    SpreadsheetCellString() = default;
    SpreadsheetCellString(const std::string& value);
    void set(const std::string& inString) override;
    std::string getString() const override;
private:
    std::string content{};
};


#endif //STUFY_SPREADSHEETCELLSTRING_H
