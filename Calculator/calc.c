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

double parse_double_slot;
char bin_operators[] = "+-*/%";
char un_operators[] = "sctar";

#include <unistd.h>

#define OPTIONS "mh"

int main(int argc, char **argv) {
    int suc = 1;
    int trigf = 0;
    int checker;
    int t;
    int opt;
    char expr[1024];
    char *saveptr;
    bool error = false;
    opterr = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'm': trigf = 1; break;
        case 'h': printf(USAGE, argv[0]); return 0;
        default:
            fprintf(stderr, "./calc: invalid option -- '%c'\n", optopt);
            fprintf(stderr, USAGE, "./calc");
            return 1;
        }
    }

    while (1) {
        checker = 0;
        fprintf(stderr, "> ");
        if (fgets(expr, 1024, stdin) != NULL) {
            expr[strlen(expr) - 1] = 0;
        } else {
            return 0;
        }

        const char *token = strtok_r(expr, " ", &saveptr);
        while (token != NULL && !error) {
            suc = 1;
            if (checker == 0) {
                t = 0;

                if (parse_double(token, &parse_double_slot)) {
                    if (stack_size == STACK_CAPACITY) {
                        suc = 0;
                        fprintf(stderr, ERROR_NO_SPACE, parse_double_slot);
                        checker = 1;
                        t = 1;
                        break;
                    } else {
                        stack_push(parse_double_slot);
                        t = 1;
                    }
                }

                if (strlen(token) == 1) {

                    if (strchr(bin_operators, *token) != NULL) {
                        if (stack_size < 2) {
                            suc = 0;
                            checker = 1;
                            stack_clear();
                        }
                        apply_binary_operator(binary_operators[(int) *token]);
                        t = 1;
                    }
                    if (strchr(un_operators, *token) != NULL) {
                        if (stack_size < 1) {
                            checker = 1;
                            suc = 0; 
                            stack_clear();
                            t = 1;
                        }
                        if (trigf == 0) {
                            apply_unary_operator(my_unary_operators[(int) *token]);
                            t = 1;
                        }
                        if (trigf == 1) {
                            apply_unary_operator(libm_unary_operators[(int) *token]);
                            t = 1;
                        }
                    }
                    if (t == 0) {
                        suc = 0;
                        fprintf(stderr, ERROR_BAD_CHAR, *token);
                        checker = 1;
                        t = 1;
                        stack_clear();
                    }
                }
                if (t == 0) {
                    suc = 0;
                    fprintf(stderr, ERROR_BAD_STRING, token);
                    checker = 1;
                    stack_clear();
                }
                t = 1;
            }
            token = strtok_r(NULL, " ", &saveptr);
        }

        if (checker == 0) {
            stack_print();
            stack_clear();
        }

        if (suc == 1) {
            printf("\n");
        }
    }

    return 0;
}
