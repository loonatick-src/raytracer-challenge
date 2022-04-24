#include "util.hpp"

#include <gtest/gtest.h>


// TODO: enclose in a test suite(?)
TEST(TupleTest, BasicAssertions) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 1.0f);
    EXPECT_EQ(a.x(), 4.3f);
    EXPECT_EQ(a.y(), -4.2f);
    EXPECT_EQ(a.z(), 3.1f);
    EXPECT_EQ(a.w(), 1.0f);
    // ASSERT_TRUE(rtc::is_point(a));
    // ASSERT_FALSE(rtc::is_vector(a));
}

TEST(TupleTest, IsPoint) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 1.0f);
    ASSERT_TRUE(rtc::is_point(a));
    ASSERT_FALSE(rtc::is_vector(a));
}

TEST(TupleTest, IsVector) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 0.0f);
    ASSERT_TRUE(rtc::is_vector(a));
    ASSERT_FALSE(rtc::is_point(a));
}

TEST(TupleTest, VectorEqTest) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 0.0f);
    EXPECT_EQ(a.x(), 4.3f);
    EXPECT_EQ(a.y(), -4.2f);
    EXPECT_EQ(a.z(), 3.1f);
    EXPECT_EQ(a.w(), 0.0f);
    // ASSERT_FALSE(rtc::is_point(a));
    // ASSERT_TRUE(rtc::is_vector(a));
}

TEST(TupleTest, PointEqTest) {
    const auto p = rtc::point<float>(4, -4, 3);
    ASSERT_EQ(p, rtc::tuple<float>(4, -4, 3, 1));
    auto v = rtc::vector<float>(4, -4, 3);
    ASSERT_EQ(v, rtc::tuple<float>(4, -4, 3, 0));
}

TEST(TupleTest, SubtractPoints) {
    const rtc::point<float> p1(3, 2, 1);
    const rtc::point<float> p2(5, 6, 7);
    ASSERT_EQ(p1 - p2, rtc::vector<float>(-2, -4, -6));
}

TEST(TupleTest, SubtractVectorPoint) {
    const rtc::point<float> p(3, 2, 1);
    const rtc::vector<float> v(5, 6, 7);
    ASSERT_EQ(p - v, rtc::point<float>(-2, -4, -6));
}

TEST(TupleTest, SubtractVectors) {
    const rtc::vector<float> v1(3, 2, 1);
    const rtc::vector<float> v2(5, 6, 7);
    ASSERT_EQ(v1 - v2, rtc::vector<float>(-2, -4, -6));
}

TEST(TupleTest, Negate) {
    const rtc::tuple<float> a(1, -2, 3, -4);
    ASSERT_EQ(-a, rtc::tuple<float>(-1, 2, -3, 4));
}

TEST(TupleTest, Scaling) {
    const rtc::tuple<float> a(1, -2, 3, -4);
    ASSERT_EQ(a*3.5, rtc::tuple<float>(3.5, -7, 10.5, -14));
    ASSERT_EQ(a*0.5, rtc::tuple<float>(0.5, -1, 1.5, -2));
}

