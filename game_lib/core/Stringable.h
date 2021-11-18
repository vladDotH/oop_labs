#ifndef STRINGABLE_H
#define STRINGABLE_H

#include <string>

class Stringable {
public:
    virtual std::string toString() const = 0;
};

#endif //STRINGABLE_H
