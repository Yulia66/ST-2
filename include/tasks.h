// Copyright 2025 UNN-IASR
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct CostReport {
  double concrete_expense;
  double fencing_expense;
};

double computeEarthGap();
CostReport computePoolExpenses();

#endif  // INCLUDE_TASKS_H_
