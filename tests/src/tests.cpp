#include "circle.h"
#include "ellipse.h"
#include "helix.h"
#include <gtest/gtest.h>

// Circle tests
TEST(CircleTest, ConstructorValidRadius) {
    ASSERT_NO_THROW(Circle circle(5.0));
}

TEST(CircleTest, ConstructorInvalidRadius) {
    ASSERT_THROW(Circle circle(0), std::invalid_argument);
}

TEST(CircleTest, CalculatePoint) {
    Circle circle(3.0);
    std::vector<double> point = circle.calculatePoint(1.5);
    ASSERT_DOUBLE_EQ(point[0], 3.0 * cos(1.5));
    ASSERT_DOUBLE_EQ(point[1], 3.0 * sin(1.5));
    ASSERT_DOUBLE_EQ(point[2], 0.0);
}

TEST(CircleTest, CalculateDerivative) {
    Circle circle(2.0);
    std::vector<double> derivative = circle.calculateDerivative(0.3);
    ASSERT_DOUBLE_EQ(derivative[0], -2.0 * sin(0.3));
    ASSERT_DOUBLE_EQ(derivative[1], 2.0 * cos(0.3));
    ASSERT_DOUBLE_EQ(derivative[2], 0.0);
}

TEST(CircleTest, GetRadius) {
    Circle circle(4.0);
    ASSERT_DOUBLE_EQ(circle.getRadius(), 4.0);
}

// Ellipse tests
TEST(EllipseTest, ConstructorValidRadii) {
    ASSERT_NO_THROW(Ellipse ellipse(3.0, 2.0));
}

TEST(EllipseTest, CalculatePoint) {
    Ellipse ellipse(3.0, 2.0);
    std::vector<double> expected = {3.0, 0.0, 0.0};
    EXPECT_EQ(expected, ellipse.calculatePoint(0.0));
}

TEST(EllipseTest, CalculateDerivative) {
    Ellipse ellipse(3.0, 2.0);
    double tolerance = 1e-9;
    auto derivative = ellipse.calculateDerivative(M_PI_2);
    ASSERT_NEAR(derivative[0], -3.0, tolerance);
    ASSERT_NEAR(derivative[1], 0.0, tolerance);
    ASSERT_NEAR(derivative[2], 0.0, tolerance);
}

// Helix tests
TEST(HelixTest, ConstructorValidRadiiAndStep) {
    ASSERT_NO_THROW(Helix helix(3.0, 0.1));
}

TEST(HelixTest, CalculatePoint) {
    Helix helix(3.0, 0.1);
    std::vector<double> point = helix.calculatePoint(0.0);
    EXPECT_DOUBLE_EQ(point[0], 3.0);
    EXPECT_DOUBLE_EQ(point[1], 0.0);
    EXPECT_DOUBLE_EQ(point[2], 0.0);
}

TEST(HelixTest, CalculateDerivative) {
    Helix helix(3.0, 0.1);
    double tolerance = 1e-9;
    std::vector<double> derivative = helix.calculateDerivative(0.0);

    ASSERT_NEAR(derivative[0], 0.0, tolerance);
    ASSERT_NEAR(derivative[1], 3.0, tolerance);
    ASSERT_NEAR(derivative[2], 0.015915494309189534, tolerance);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}