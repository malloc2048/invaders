#include <cstring>
#include <cstdlib>
#include "opcodes.h"
#include "common/utilities.h"

struct OpCode opcodes[256];

void strToOpcode(const unsigned char* buffer) {
    char* ptr;
    char codeStr[3];
    memcpy(codeStr, &buffer[2], 2);
    codeStr[2] = '\0';
    long code = strtol(codeStr, &ptr, 16);
    opcodes[code].code = code;

    size_t index = 5;
    while(buffer[index] != '\t') {
        index++;
    }
    char instruction[index - 5];
    memcpy(instruction, &buffer[5], index - 5);
    instruction[index - 5] = '\0';
    opcodes[code].instruction = (char*)malloc(sizeof(char) * (index - 5));
    strcpy(opcodes[code].instruction, instruction);

    opcodes[code].size = strtol((char*)&buffer[index + 1], &ptr, 10);
}

void Load(FILE* cfgFile) {
    if(cfgFile == nullptr) {
        // add a log here
        return;
    }

    long int length = GetFileSize(cfgFile);
    unsigned char* buffer = ReadFile(cfgFile, length);

    unsigned char lines[256][256];
    size_t lineIndex = 0, position = 0;

    for (size_t i = 0; i < length; i++) {
        if (buffer[i] != '\n') {
            lines[lineIndex][position] = buffer[i];
            position++;
        } else {
            lines[lineIndex][position] = '\0';
            lineIndex++;
            position = 0;
        }
    }

    for(size_t i = 0; i < lineIndex; i++) {
        strToOpcode(lines[i]);
    }
}

struct OpCode* GetOpCode(uint8_t code) {
    return &opcodes[code];
}

