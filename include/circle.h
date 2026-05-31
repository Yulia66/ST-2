// Copyright 2025 UNN-IASR
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
  double r_val;
  double circ_val;
  double sq_val;

 public:
  Circle();
  explicit Circle(double r);

  void assignRadius(double r);
  void assignCircumference(double c);
  void assignArea(double a);

  double retrieveRadius() const;
  double retrieveCircumference() const;
  double retrieveArea() const;

 private:
  void refreshFromRadius();
  void refreshFromCircumference();
  void refreshFromArea();
};

#endif  // INCLUDE_CIRCLE_H_
