#include <gtest/gtest.h>
#include "src/class/Train.hpp"

TEST(TrainTest, InvalidTimeFormatThrows) {
    EXPECT_THROW(Train(123, "Moscow", "Express", "25:00", 240), std::invalid_argument);
    EXPECT_THROW(Train(123, "Moscow", "Express", "12:60", 240), std::invalid_argument);
    EXPECT_THROW(Train(123, "Moscow", "Express", "-01:30", 240), std::invalid_argument);
}

TEST(TrainTest, ValidTimeFormatDoesNotThrow) {
    EXPECT_THROW(Train(123, "Moscow", "Express", "23:59", 240), std::invalid_argument);
    EXPECT_THROW(Train(123, "Moscow", "Express", "00:00", 240), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
