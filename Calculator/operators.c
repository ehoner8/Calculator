#include "operators.h"

#include "mathlib.h"
#include "messages.h"
#include "stack.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double operator_add(double lhs, double rhs) {
    double res = lhs + rhs;
    return res;
}

double operator_sub(double lhs, double rhs) {
    double res = lhs - rhs;
    return res;
}

double operator_mul(double lhs, double rhs) {
    double res = lhs * rhs;
    return res;
}

double operator_div(double lhs, double rhs) {
    double res = lhs / rhs;
    return res;
}

//From Dr. Kerry Veenstra's assignment 4 pdf pages 6-7
bool parse_double(const char *s, double *d) {
    char *endptr;
    double result = strtod(s, &endptr);
    if (endptr != s) {
        *d = result;
        return true;
    } else {
        return false;
    }
}

bool apply_binary_operator(binary_operator_fn op) {
    if (stack_size < 2) {
        fprintf(stderr, ERROR_BINARY_OPERATOR);
        return false;
    }
    double a;
    double b;

    assert(stack_pop(&a));
    assert(stack_pop(&b));
    double result = op(b, a);
    assert(stack_push(result));
    return true;
}

//From Dr. Kerry Veenstra's assignment 4 pdf page 6
bool apply_unary_operator(unary_operator_fn op) {
    if (stack_size < 1) {
        fprintf(stderr, ERROR_UNARY_OPERATOR);
        return false;
    }

    double x;
    assert(stack_pop(&x));
    double result = op(x);
    assert(stack_push(result));
    return true;
}
