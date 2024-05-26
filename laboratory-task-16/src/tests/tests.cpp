#include <gtest/gtest.h>
#include "src/func/func.hpp"
#include <sstream>

TEST(SecondPartOfTheTaskTest, Test)
{
    EXPECT_NO_THROW(secondPartOfTheTask());
}

TEST(FillingTheVectorForThirdTaskTest, TestFileReading)
{
    std::vector<std::string> vec;
    std::string expected_word = "word";
    EXPECT_NO_THROW(fillingTheVectorForThirdTask(vec));
}

TEST(FothPartOfTheTaskTest, Test)
{
    EXPECT_NO_THROW(thirdPartOfTheTask());
}

TEST(FourthPartOfTheTaskTest, TestMatrixManipulation)
{
    std::stringstream input_ss, output_ss;
    input_ss << "3 3\n1 10";
    std::cin.rdbuf(input_ss.rdbuf());
    std::cout.rdbuf(output_ss.rdbuf());

    EXPECT_NO_THROW(fourthPartOfTheTask());
}

TEST(FifthPartOfTheTaskTest, Test)
{
    EXPECT_NO_THROW(fifthPartOfTheTask());
}

TEST(SixthPartOfTheTaskTest, Test)
{
    EXPECT_NO_THROW(sixthPartOfTheTask());
}

TEST(TrainTest, InvalidTimeFormatThrows)
{
    EXPECT_THROW(Train(123, "Moscow", "Express", "25:00", 240), std::invalid_argument);
    EXPECT_THROW(Train(123, "Moscow", "Express", "12:60", 240), std::invalid_argument);
    EXPECT_THROW(Train(123, "Moscow", "Express", "-01:30", 240), std::invalid_argument);
}

TEST(TrainTest, ValidTimeFormatDoesNotThrow)
{
    EXPECT_THROW(Train(123, "Moscow", "Express", "23:59", 240), std::invalid_argument);
    EXPECT_THROW(Train(123, "Moscow", "Express", "00:00", 240), std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
