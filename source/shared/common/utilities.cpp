#include <cstdlib>
#include "common/utilities.h"

namespace utilities {
    void swap(uint8_t& x, uint8_t& y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
}

long GetFileSize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    long fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    printf("the file is %ld bytes long\n", fileLength);

    return fileLength;
}

uint8_t Parity(uint32_t number, uint8_t size) {
    uint32_t parity = 0;
    for(uint8_t i = 0; i < size; i++) {
        if(number & (0x01u << i))
            parity++;
    }
    return parity & 0x01u;
}

uint8_t *ReadFile(FILE *file, long fileLength) {
    uint8_t* buffer = (uint8_t*)malloc(sizeof(unsigned char) * (fileLength + 1));
    fread(buffer, sizeof(char), fileLength, file);
    buffer[fileLength + 1] = '\0';

    return buffer;
}

long ReadRomFile(FILE *file, uint8_t* buffer) {
    long fileLength = GetFileSize(file);
    fread(buffer, sizeof(char), fileLength, file);
    return fileLength;
}
