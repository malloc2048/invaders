#ifndef INVADERS_DATA_TRANSFER_TEST_FIXTURE_H
#define INVADERS_DATA_TRANSFER_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "hardware/i8080/operations/data_transfer.h"

class DataTransferTestFixture: public testing::Test {
public:
    DataTransferTestFixture() = default;
    ~DataTransferTestFixture() override = default;

protected:
    hardware::Flags flags;
    hardware::Memory memory;
    hardware::Registers registers;
    hardware::DataTransfer dataTransfer = hardware::DataTransfer(flags, memory, registers);
};
#endif
