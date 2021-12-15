#ifndef INSTANCEOF_H
#define INSTANCEOF_H

#include "memory"

template<class T, class V>
bool instanceof(V* p) {
    return dynamic_cast<T*>(p) != nullptr;
}

#endif //INSTANCEOF_H
