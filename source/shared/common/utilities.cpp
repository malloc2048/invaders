#include <cstdlib>
#include "utilities.h"

long GetFileSize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    long fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    printf("the file is %ld bytes long\n", fileLength);

    return fileLength;
}

uint8_t *ReadFile(FILE *file, long fileLength) {
    uint8_t* buffer = (uint8_t*)malloc(sizeof(unsigned char) * (fileLength + 1));
    fread(buffer, sizeof(char), fileLength, file);
    buffer[fileLength + 1] = '\0';

    return buffer;
}
