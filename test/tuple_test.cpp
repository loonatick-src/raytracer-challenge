#include "util.hpp"

#include <cmath>
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
    EXPECT_EQ(p, rtc::tuple<float>(4, -4, 3, 1));
    auto v = rtc::vector<float>(4, -4, 3);
    EXPECT_EQ(v, rtc::tuple<float>(4, -4, 3, 0));
}

TEST(TupleTest, SubtractPoints) {
    const rtc::point<float> p1(3, 2, 1);
    const rtc::point<float> p2(5, 6, 7);
    EXPECT_EQ(p1 - p2, rtc::vector<float>(-2, -4, -6));
}

TEST(TupleTest, SubtractVectorPoint) {
    const rtc::point<float> p(3, 2, 1);
    const rtc::vector<float> v(5, 6, 7);
    EXPECT_EQ(p - v, rtc::point<float>(-2, -4, -6));
}

TEST(TupleTest, SubtractVectors) {
    const rtc::vector<float> v1(3, 2, 1);
    const rtc::vector<float> v2(5, 6, 7);
    EXPECT_EQ(v1 - v2, rtc::vector<float>(-2, -4, -6));
}

TEST(TupleTest, Negate) {
    const rtc::tuple<float> a(1, -2, 3, -4);
    EXPECT_EQ(-a, rtc::tuple<float>(-1, 2, -3, 4));
}

TEST(TupleTest, Scaling) {
    const rtc::tuple<float> a(1, -2, 3, -4);
    EXPECT_EQ(a*3.5, rtc::tuple<float>(3.5, -7, 10.5, -14));
    EXPECT_EQ(a*0.5, rtc::tuple<float>(0.5, -1, 1.5, -2));
}

TEST(TupleTest, ScalarDivision) {
    const rtc::tuple<float> a(1, -2, 3, -4);
    EXPECT_EQ(a/2, rtc::tuple<float>(0.5, -1, 1.5, -2));
}

TEST(TupleTest, Magnitude) {
    rtc::vector<float> v(1, 0, 0);
    // ASSERT_TRUE(rtc::approx_eqf(static_cast<float>(1), rtc::magnitude(v), 1.0e-10));
    EXPECT_EQ(rtc::magnitude(v), 1.0f);
    v = rtc::vector<float>(0, 1, 0);
    EXPECT_EQ(rtc::magnitude(v), 1.0f);
    v = rtc::vector<float>(0, 0, 1);
    EXPECT_EQ(rtc::magnitude(v), 1.0f);
    v = rtc::vector<float>(1, 2, 3);
    EXPECT_EQ(rtc::magnitude(v), sqrtf(14.0f));
    v = rtc::vector<float>(-1, -2, -3);
    EXPECT_EQ(rtc::magnitude(v), sqrtf(14.0f));
}

TEST(TupleTest, Normalize) {
    rtc::vector<float> v(4, 0, 0);
    rtc::vector<float> vn = rtc::normalize(v);
    EXPECT_EQ(vn, rtc::vector<float>(1, 0, 0)) << "normalize({4, 0, 0}) = " << vn.x() << ' ' << vn.y() << ' ' << vn.z() << '\n';
    v = rtc::vector<float>(1, 2, 3);
    vn = normalize(v);
    const float base_component = sqrtf(14.0f); 
    const float eps = 1.0e-20;
    EXPECT_EQ(vn.x(), 1.0f/base_component);
    EXPECT_EQ(vn.y(), 2.0f/base_component);
    EXPECT_EQ(vn.z(), 3.0f/base_component);
}

TEST(TupleTest, Dot) {
    const rtc::vector<float> a(1, 2, 3);
    const rtc::vector<float> b(2, 3, 4);
    EXPECT_EQ(rtc::dot(a, b), static_cast<float>(20));
}

TEST(TupleTest, Cross) {
    const rtc::vector<float> a(1,2,3);
    const rtc::vector<float> b(2,3,4);
    EXPECT_EQ(rtc::cross(a, b), rtc::vector<float>(-1, 2, -1));
    EXPECT_EQ(rtc::cross(b, a), rtc::vector<float>(1, -2, 1));
}
