#ifndef FORMAT_H
#define FORMAT_H

#include "../Log.h"

class Format {
public:
    virtual Log wrap(Log l) = 0;
};


#endif //FORMAT_H
