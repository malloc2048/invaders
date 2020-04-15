#include <cstdlib>
#include "common/utilities.h"

long GetFileSize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    long fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    printf("the file is %ld bytes long\n", fileLength);

    return fileLength;
}

int Parity(int number, int size) {
    int parity = 0;
    for(int i = 0; i < size; i++) {
        parity += number & (0x01 << i);
    }
    return parity & 0x01;
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
