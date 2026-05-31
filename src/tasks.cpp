// Copyright 2025 UNN-IASR
#include "tasks.h"
#include "circle.h"

namespace {
constexpr double EARTH_RADIUS_METERS = 6378100.0;
constexpr double ROPE_EXTRA = 1.0;
constexpr double POOL_RADIUS = 3.0;
constexpr double WALK_WIDTH = 1.0;
constexpr double CONCRETE_PRICE = 1000.0;
constexpr double FENCE_PRICE = 2000.0;
}

double computeEarthGap() {
  Circle earthSphere(EARTH_RADIUS_METERS);
  Circle enlargedSphere(0.0);
  enlargedSphere.assignCircumference(earthSphere.retrieveCircumference() + ROPE_EXTRA);
  return enlargedSphere.retrieveRadius() - earthSphere.retrieveRadius();
}

CostReport computePoolExpenses() {
  Circle poolCircle(POOL_RADIUS);
  Circle outerCircle(poolCircle.retrieveRadius() + WALK_WIDTH);

  double walkwayArea = outerCircle.retrieveArea() - poolCircle.retrieveArea();
  double concreteExpense = walkwayArea * CONCRETE_PRICE;
  double fencingExpense = outerCircle.retrieveCircumference() * FENCE_PRICE;

  return {concreteExpense, fencingExpense};
}
