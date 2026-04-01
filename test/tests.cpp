// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPS = 1e-9;

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, EPS);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 3.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 9.0, EPS);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    c.setFerence(2 * M_PI);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI, EPS);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI, EPS);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    c.setArea(M_PI);
    EXPECT_NEAR(c.getArea(), M_PI, EPS);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI, EPS);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, UpdateFromRadius) {
    Circle c(2.0);
    double expectedFerence = 2 * M_PI * 2.0;
    double expectedArea = M_PI * 4.0;
    EXPECT_NEAR(c.getFerence(), expectedFerence, EPS);
    EXPECT_NEAR(c.getArea(), expectedArea, EPS);
}

TEST(CircleTest, UpdateFromFerence) {
    Circle c(1.0);
    c.setFerence(10.0);
    double expectedRadius = 10.0 / (2 * M_PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_NEAR(c.getArea(),
                M_PI * expectedRadius * expectedRadius,
                EPS);
}

TEST(CircleTest, UpdateFromArea) {
    Circle c(1.0);
    c.setArea(50.0);
    double expectedRadius = std::sqrt(50.0 / M_PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_NEAR(c.getFerence(),
                2 * M_PI * expectedRadius,
                EPS);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e10);
    EXPECT_NEAR(c.getRadius(), 1e10, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e10, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 1e20, EPS);
}

TEST(CircleTest, MultipleUpdates) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, EPS);

    c.setFerence(20.0);
    EXPECT_NEAR(c.getFerence(), 20.0, EPS);

    c.setArea(100.0);
    EXPECT_NEAR(c.getArea(), 100.0, EPS);
}

TEST(EarthAndRopeTest, GapPositive) {
    double gap = solveEarthAndRope();
    EXPECT_GT(gap, 0.0);
    EXPECT_LT(gap, 1.0);
}

TEST(EarthAndRopeTest, GapFormula) {
    double gap = solveEarthAndRope();
    double expectedGap = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, expectedGap, 1e-6);
}

TEST(EarthAndRopeTest, GapIndependentOfRadius) {
    double gap = solveEarthAndRope();
    double expectedGap = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, expectedGap, 1e-6);
}

TEST(EarthAndRopeTest, GapValue) {
    double gap = solveEarthAndRope();
    EXPECT_NEAR(gap, 0.1591549430918953, 1e-9);
}

TEST(EarthAndRopeTest, GapWithCustomEarth) {
    Circle earth(6378000.0);
    double initialFerence = earth.getFerence();
    double newFerence = initialFerence + 1.0;
    Circle newCircle(0);
    newCircle.setFerence(newFerence);
    double gap = newCircle.getRadius() - earth.getRadius();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
}

TEST(PoolTest, PathAreaPositive) {
    auto result = solvePool();
    EXPECT_GT(result.first, 0.0);
    EXPECT_GT(result.second, 0.0);
}

TEST(PoolTest, ConcreteCostCalculation) {
    auto result = solvePool();
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double pathArea = M_PI *
        ((poolRadius + pathWidth) * (poolRadius + pathWidth) -
         poolRadius * poolRadius);
    double expectedCost = pathArea * 1000.0;
    EXPECT_NEAR(result.first, expectedCost, 1e-6);
}

TEST(PoolTest, FenceCostCalculation) {
    auto result = solvePool();
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double fenceLength = 2 * M_PI * (poolRadius + pathWidth);
    double expectedCost = fenceLength * 2000.0;
    EXPECT_NEAR(result.second, expectedCost, 1e-6);
}

TEST(PoolTest, ConcreteCostValue) {
    auto result = solvePool();
    double expectedConcreteCost =
        M_PI * ((4.0 * 4.0) - (3.0 * 3.0)) * 1000.0;
    EXPECT_NEAR(result.first, expectedConcreteCost, 1e-6);
}

TEST(PoolTest, FenceCostValue) {
    auto result = solvePool();
    double expectedFenceCost = 2 * M_PI * 4.0 * 2000.0;
    EXPECT_NEAR(result.second, expectedFenceCost, 1e-6);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(CircleTest, ConsistencyAfterMultipleUpdates) {
    Circle c(2.0);
    double r1 = c.getRadius();
    double f1 = c.getFerence();
    double a1 = c.getArea();

    c.setFerence(f1 + 1.0);
    double r2 = c.getRadius();
    double a2 = c.getArea();

    EXPECT_NEAR(c.getFerence(), f1 + 1.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * r2 * r2, EPS);

    c.setRadius(r2);
    EXPECT_NEAR(c.getRadius(), r2, EPS);
    EXPECT_NEAR(c.getFerence(), f1 + 1.0, EPS);
    EXPECT_NEAR(c.getArea(), a2, EPS);
}

TEST(EarthAndRopeTest, GapIndependence) {
    Circle earth1(1000.0);
    double initialFerence1 = earth1.getFerence();
    double newFerence1 = initialFerence1 + 1.0;
    Circle newCircle1(0);
    newCircle1.setFerence(newFerence1);
    double gap1 = newCircle1.getRadius() - earth1.getRadius();

    Circle earth2(1000000.0);
    double initialFerence2 = earth2.getFerence();
    double newFerence2 = initialFerence2 + 1.0;
    Circle newCircle2(0);
    newCircle2.setFerence(newFerence2);
    double gap2 = newCircle2.getRadius() - earth2.getRadius();

    EXPECT_NEAR(gap1, gap2, EPS);
}
