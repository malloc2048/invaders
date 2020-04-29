#ifndef NESEMU_MNEMONICS_H
#define NESEMU_MNEMONICS_H

#include <map>
#include <string>

class Mnemonics {
public:
    Mnemonics() = default;
    ~Mnemonics() = default;

    static const std::map<uint8_t, std::string> mnemonics;
};
#endif
