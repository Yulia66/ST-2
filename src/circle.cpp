// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

const double PI = 3.14159265358979323846;

Circle::Circle(double r) : radius(r) {
    updateFromRadius();
}

void Circle::setRadius(double r) {
    radius = r;
    updateFromRadius();
}

void Circle::setFerence(double f) {
    ference = f;
    updateFromFerence();
}

void Circle::setArea(double a) {
    area = a;
    updateFromArea();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::updateFromRadius() {
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

void Circle::updateFromFerence() {
    radius = ference / (2 * PI);
    area = PI * radius * radius;
}

void Circle::updateFromArea() {
    radius = std::sqrt(area / PI);
    ference = 2 * PI * radius;
}