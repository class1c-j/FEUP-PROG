

#ifndef STUFY_SPREADSHEETCELLDOUBLE_H
#define STUFY_SPREADSHEETCELLDOUBLE_H

#include "SpreadsheetCell.h"

class SpreadsheetCellDouble : public SpreadsheetCell {
public:
    SpreadsheetCellDouble() = default;
    SpreadsheetCellDouble(double value);
    void set(const std::string& inString) override;
    void set(double inDouble);
    double getDouble() const;
    std::string getString() const override;
private:
    double content{};
};


#endif //STUFY_SPREADSHEETCELLDOUBLE_H
