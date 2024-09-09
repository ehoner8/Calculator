#include "mathlib.h"
#include "messages.h"
#include "operators.h"
#include "stack.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    double y;
    double z;

    printf("Abs test: 9: %.10f\n", Abs(9.0));
    printf("Abs test: -4: %.10f\n", Abs(-4.0));
    printf("Sqrt test: 9: %.10f\n", Sqrt(9.0));
    printf("Sqrt test: -3: %.10f\n", Sqrt(-3.0));
    printf("Sin test: 4: %.10f\n", Sin(4.0));
    printf("Sin test: -8: %.10f\n", Sin(-8.0));
    printf("Cos test: 2: %.10f\n", Cos(2.0));
    printf("Cos test: -3: %.10f\n", Cos(-3.0));
    printf("Tan test: 6.1: %.10f\n", Tan(6.1));
    printf("Tan test: -3: %.10f\n", Tan(-3.0));
    printf("Pushing 4 to stack\n");
    printf("Pushing 8 to stack\n");
    printf("Pushing -3 to stack\n");
    printf("Stack: ");
    stack_push(4.0);
    stack_push(8.0);
    stack_push(-3.0);
    stack_print();
    printf("\n");
    printf("Applying binary operator +\n");
    apply_binary_operator(operator_add);
    stack_print();
    printf("\n");
    printf("Pushing 5 7 6 36 6 7 5\n");
    stack_push(5.0);
    stack_push(7.0);
    stack_push(6.0);
    stack_push(36.0);
    stack_push(6.0);
    stack_push(7.0);
    stack_push(5.0);
    printf("Applying binary operator -\n");
    apply_binary_operator(operator_sub);
    stack_print();
    printf("\n");
    printf("Applying binary operator *\n");
    apply_binary_operator(operator_mul);
    stack_print();
    printf("\n");
    printf("Applying binary operator /\n");
    apply_binary_operator(operator_div);
    stack_print();
    printf("\n");
    printf("Popping the last element in the stack\n");
    stack_pop(&y);
    stack_print();
    printf("\n");
    printf("Applying unary operator sin\n");
    apply_unary_operator(Sin);
    stack_print();
    printf("\n");
    printf("Peek top of stack: ");
    stack_peek(&z);
    printf("%.10f", z);
    printf("\n");
    printf("Clearing the stack then trying to print it.\n");
    stack_clear();
    stack_print();
    printf("\n");
    printf("If nothing printed, then it was a success\n\n");
    printf("If all results seem right, then it looks like all of the functions work!\n");

    return 0;
}
