#pragma once

#include <iostream>
#include <string>
#include <list>

#include "../Stack/PriorityStack.cpp"

enum token_type {
  none,
  number,
  float_number,
  action_plus,
  action_minus,
  action_unary_plus,
  action_unary_minus,
  action_multiply,
  action_divide,
  bracket_open,
  bracket_close,
  float_point
};

struct math_token {
  std::string value;
  token_type  type;
};

struct priority_token {
  size_t priority;
  std::list<math_token>::iterator it;

  inline bool operator<(const priority_token& rhs) const {
    return priority < rhs.priority;
  }
};

typedef long long Number;
typedef long double Float;

std::string execute_expression(std::string input);