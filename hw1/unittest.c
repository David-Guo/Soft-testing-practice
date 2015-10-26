#include <gtest/gtest.h>
#include "tobetest.c"

// WeakNormal test for Triangle
TEST(TrianglTest, WeakNormal) {
    EXPECT_STREQ("Equilateral", Triangle(5, 5, 5));
    EXPECT_STREQ("Isosceles", Triangle(2, 2, 3));
    EXPECT_STREQ("Scalene", Triangle(3, 4, 5));
    EXPECT_STREQ("NotATriangle", Triangle(4, 1, 2));
}

// WeakRobust test for Triangle
TEST(Triangle, WeakRobust) {
    EXPECT_STREQ("Invalid input", Triangle(-1, 5, 5));
    EXPECT_STREQ("Invalid input", Triangle(5, -1, 5));
    EXPECT_STREQ("Invalid input", Triangle(5, 5, -1));
}

// StrongRobust test for Triangle
TEST(Triangle, StrongRobust) {
    EXPECT_STREQ("Invalid input", Triangle(-1, -1, 5));
    EXPECT_STREQ("Invalid input", Triangle(-1, 5, -1));
    EXPECT_STREQ("Invalid input", Triangle(5, -1, -1));
}

// WR for NextDay
TEST(NextDay, WeakRobust) {
    EXPECT_STREQ("1912/6/16", NextDay(1912, 6, 15));
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



