#ifndef EMPTYFORMAT_H
#define EMPTYFORMAT_H

#include "Format.h"

class EmptyFormat : public Format {
public:
    Log wrap(Log l) override {
        return l;
    }
};


#endif //EMPTYFORMAT_H
