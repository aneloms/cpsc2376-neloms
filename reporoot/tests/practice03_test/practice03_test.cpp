#include <gtest/gtest.h>
#include "practice03.cpp"

TEST(MathUtilsTest, SumRange) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15);
    EXPECT_EQ(MathUtils::sumRange(0, 0), 0);
    EXPECT_EQ(MathUtils::sumRange(-3, 3), 0);
}

TEST(MathUtilsTest, ContainsNegative) {
    EXPECT_TRUE(MathUtils::containsNegative({1, -2, 3}));
    EXPECT_FALSE(MathUtils::containsNegative({1, 2, 3}));
    EXPECT_FALSE(MathUtils::containsNegative({}));
}

TEST(MathUtilsTest, FindMax) {
    EXPECT_EQ(MathUtils::findMax({1, 2, 3, 4, 5}), 5);
    EXPECT_EQ(MathUtils::findMax({-1, -2, -3, -4}), -1);
    EXPECT_EQ(MathUtils::findMax({}), INT_MIN);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
