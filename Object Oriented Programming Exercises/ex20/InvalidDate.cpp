
#include "InvalidDate.h"


InvalidDate::InvalidDate(const char *message) : m_message(message) {}

const char *InvalidDate::what() const noexcept {
    return m_message;
}
