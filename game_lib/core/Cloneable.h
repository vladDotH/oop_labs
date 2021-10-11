#ifndef _CLONEABLE_H
#define _CLONEABLE_H

#include <memory>

template<class T>
class Cloneable {
public:
    virtual T clone() = 0;
};

#endif //CLONEABLE_H
