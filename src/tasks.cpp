// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include "circle.h"
#include <cmath>
#include <utility>

const double EARTH_RADIUS_KM = 6378.1;
const double EARTH_RADIUS_M = EARTH_RADIUS_KM * 1000;
const double ADDITIONAL_ROPE = 1.0;

double solveEarthAndRope() {
    Circle earth(EARTH_RADIUS_M);
    double initialFerence = earth.getFerence();
    double newFerence = initialFerence + ADDITIONAL_ROPE;
    Circle newCircle(0);
    newCircle.setFerence(newFerence);
    double gap = newCircle.getRadius() - earth.getRadius();
    return gap;
}

std::pair<double, double> solvePool() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double CONCRETE_COST = 1000.0;
    const double FENCE_COST = 2000.0;

    Circle pool(POOL_RADIUS);
    Circle poolWithPath(POOL_RADIUS + PATH_WIDTH);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * CONCRETE_COST;
    double fenceCost = poolWithPath.getFerence() * FENCE_COST;

    return std::make_pair(concreteCost, fenceCost);
}
