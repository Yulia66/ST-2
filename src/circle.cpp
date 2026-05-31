// Copyright 2025 UNN-IASR
#include "circle.h"
#include <cmath>

const double PI_VAL = 3.14159265358979323846;

Circle::Circle() : r_val(0.0) {
    refreshFromRadius();
}

Circle::Circle(double r) : r_val(r) {
    refreshFromRadius();
}

void Circle::assignRadius(double r) {
    r_val = r;
    refreshFromRadius();
}

void Circle::assignCircumference(double c) {
    circ_val = c;
    refreshFromCircumference();
}

void Circle::assignArea(double a) {
    sq_val = a;
    refreshFromArea();
}

double Circle::retrieveRadius() const {
    return r_val;
}

double Circle::retrieveCircumference() const {
    return circ_val;
}

double Circle::retrieveArea() const {
    return sq_val;
}

void Circle::refreshFromRadius() {
    circ_val = 2.0 * PI_VAL * r_val;
    sq_val = PI_VAL * r_val * r_val;
}

void Circle::refreshFromCircumference() {
    r_val = circ_val / (2.0 * PI_VAL);
    sq_val = PI_VAL * r_val * r_val;
}

void Circle::refreshFromArea() {
    r_val = std::sqrt(sq_val / PI_VAL);
    circ_val = 2.0 * PI_VAL * r_val;
}
