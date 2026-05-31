// Copyright 2025 UNN-IASR
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double TOLERANCE = 1e-9;

TEST(CircleSuite, DefaultConstructor) {
    Circle obj;
    EXPECT_NEAR(obj.retrieveRadius(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), 0.0, TOLERANCE);
}

TEST(CircleSuite, ParameterizedConstructor) {
    Circle obj(4.0);
    EXPECT_NEAR(obj.retrieveRadius(), 4.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 2.0 * M_PI * 4.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), M_PI * 16.0, TOLERANCE);
}

TEST(CircleSuite, RadiusAssignment) {
    Circle obj(1.0);
    obj.assignRadius(5.0);
    EXPECT_NEAR(obj.retrieveRadius(), 5.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 2.0 * M_PI * 5.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), M_PI * 25.0, TOLERANCE);
}

TEST(CircleSuite, CircumferenceAssignment) {
    Circle obj(2.0);
    obj.assignCircumference(4.0 * M_PI);
    EXPECT_NEAR(obj.retrieveCircumference(), 4.0 * M_PI, TOLERANCE);
    EXPECT_NEAR(obj.retrieveRadius(), 2.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), M_PI * 4.0, TOLERANCE);
}

TEST(CircleSuite, AreaAssignment) {
    Circle obj(3.0);
    obj.assignArea(9.0 * M_PI);
    EXPECT_NEAR(obj.retrieveArea(), 9.0 * M_PI, TOLERANCE);
    EXPECT_NEAR(obj.retrieveRadius(), 3.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 2.0 * M_PI * 3.0, TOLERANCE);
}

TEST(CircleSuite, ZeroRadiusHandling) {
    Circle obj(10.0);
    obj.assignRadius(0.0);
    EXPECT_NEAR(obj.retrieveRadius(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), 0.0, TOLERANCE);
}

TEST(CircleSuite, ZeroCircumferenceHandling) {
    Circle obj(5.0);
    obj.assignCircumference(0.0);
    EXPECT_NEAR(obj.retrieveCircumference(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveRadius(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), 0.0, TOLERANCE);
}

TEST(CircleSuite, ZeroAreaHandling) {
    Circle obj(7.0);
    obj.assignArea(0.0);
    EXPECT_NEAR(obj.retrieveArea(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveRadius(), 0.0, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 0.0, TOLERANCE);
}

TEST(CircleSuite, VeryLargeRadius) {
    Circle obj(1e12);
    EXPECT_NEAR(obj.retrieveRadius(), 1e12, TOLERANCE);
    EXPECT_NEAR(obj.retrieveCircumference(), 2.0 * M_PI * 1e12, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), M_PI * 1e24, TOLERANCE);
}

TEST(CircleSuite, MultipleAssignments) {
    Circle obj(2.0);
    obj.assignRadius(3.0);
    EXPECT_NEAR(obj.retrieveRadius(), 3.0, TOLERANCE);

    obj.assignCircumference(25.0);
    EXPECT_NEAR(obj.retrieveCircumference(), 25.0, TOLERANCE);

    obj.assignArea(60.0);
    EXPECT_NEAR(obj.retrieveArea(), 60.0, TOLERANCE);
}

TEST(CircleSuite, ConsistencyCheck) {
    Circle obj(1.5);
    double rad = obj.retrieveRadius();

    EXPECT_NEAR(obj.retrieveCircumference(), 2.0 * M_PI * rad, TOLERANCE);
    EXPECT_NEAR(obj.retrieveArea(), M_PI * rad * rad, TOLERANCE);
}

TEST(EarthRopeSuite, GapIsPositive) {
    double gap = computeEarthGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeSuite, GapFormulaCorrect) {
    double gap = computeEarthGap();
    double expected = 1.0 / (2.0 * M_PI);
    EXPECT_NEAR(gap, expected, 1e-6);
}

TEST(EarthRopeSuite, GapValueVerified) {
    double gap = computeEarthGap();
    EXPECT_NEAR(gap, 0.1591549430918953, 1e-9);
}

TEST(EarthRopeSuite, GapDoesNotDependOnRadius) {
    double gap1 = computeEarthGap();

    Circle customEarth(5000.0);
    double initFer = customEarth.retrieveCircumference();
    Circle enlargedCustom(0.0);
    enlargedCustom.assignCircumference(initFer + 1.0);
    double gap2 = enlargedCustom.retrieveRadius() -
                  customEarth.retrieveRadius();

    EXPECT_NEAR(gap1, gap2, 1e-8);
}

TEST(PoolSuite, CostsArePositive) {
    CostReport result = computePoolExpenses();
    EXPECT_GT(result.concrete_expense, 0.0);
    EXPECT_GT(result.fencing_expense, 0.0);
}

TEST(PoolSuite, ConcreteCostCalculationAccurate) {
    CostReport result = computePoolExpenses();
    double walkArea = M_PI * ((4.0 * 4.0) - (3.0 * 3.0));
    double expected = walkArea * 1000.0;
    EXPECT_NEAR(result.concrete_expense, expected, 1e-6);
}

TEST(PoolSuite, FenceCostCalculationAccurate) {
    CostReport result = computePoolExpenses();
    double fenceLen = 2.0 * M_PI * 4.0;
    double expected = fenceLen * 2000.0;
    EXPECT_NEAR(result.fencing_expense, expected, 1e-6);
}

TEST(PoolSuite, ConcreteCostExactValue) {
    CostReport result = computePoolExpenses();
    double expected = M_PI * 7.0 * 1000.0;
    EXPECT_NEAR(result.concrete_expense, expected, 1e-6);
}

TEST(PoolSuite, FenceCostExactValue) {
    CostReport result = computePoolExpenses();
    double expected = 2.0 * M_PI * 4.0 * 2000.0;
    EXPECT_NEAR(result.fencing_expense, expected, 1e-6);
}

TEST(PoolSuite, PoolWithDifferentWidth) {
    Circle pool(3.0);
    Circle outer(5.0);
    double walkArea = outer.retrieveArea() - pool.retrieveArea();
    double concreteExp = walkArea * 1000.0;
    double fenceExp = outer.retrieveCircumference() * 2000.0;

    EXPECT_GT(concreteExp, 0.0);
    EXPECT_GT(fenceExp, 0.0);
}

