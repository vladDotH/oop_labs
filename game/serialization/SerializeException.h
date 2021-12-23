#ifndef SERIALIZEEXCEPTION_H
#define SERIALIZEEXCEPTION_H

#include <stdexcept>

class SerializeException : public std::logic_error {
public:
    SerializeException(const std::string &arg) : logic_error(arg) {}

    SerializeException(const char *string) : logic_error(string) {}
};

#endif //SERIALIZEEXCEPTION_H
