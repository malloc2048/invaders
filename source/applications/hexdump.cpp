#include "common/logger.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        LogError("wrong number of args\n");
    }
    return 0;
}
