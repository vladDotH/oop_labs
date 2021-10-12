#ifndef CONSOLEOBJECTVIEWER_H
#define CONSOLEOBJECTVIEWER_H

#include <map>
#include <vector>

template<class T>
class ConsoleObjectViewer {
protected:
    std::map<size_t, char> chars;

public:
    ConsoleObjectViewer(std::map<size_t, char> chars) : chars(chars) {};

    virtual char getChar(const T &) { return '\0'; };
};


#endif //CONSOLEOBJECTVIEWER_H
