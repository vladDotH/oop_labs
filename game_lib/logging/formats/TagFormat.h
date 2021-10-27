#ifndef TAGFORMAT_H
#define TAGFORMAT_H

#include "Format.h"

class TagFormat : public Format {
private:
    std::string tag;

public:
    TagFormat(const std::string tag) {
        this->tag = '[' + tag + ']';
    }

    Log wrap(Log l) override {
        return Log(l.lvl, tag + l.msg);
    }
};


#endif //TAGFORMAT_H
