
#ifndef FICHA_INVALIDDATE_H
#define FICHA_INVALIDDATE_H

#include <stdexcept>

class InvalidDate : public std::exception {
public:
    explicit InvalidDate(const char * message = "Invalid date");
    const char * what() const noexcept override;
private:
    const char * m_message{};
};


#endif //STUFY_INVALIDDATE_H
