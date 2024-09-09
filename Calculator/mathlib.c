#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Abs(double x) {
    double res;
    if (x > 0) {
        res = x;
        return res;
    } else {
        res = 0 - x;
        return res;
    }
}

//From Dr. Kerry Veenstra's assignment 4 pdf pages 4-5
double Sqrt(double x) {
    // Check domain.
    if (x < 0) {
        return nan("nan");
    }
    double old = 0.0;
    double new = 1.0;

    while (Abs(old - new) > EPSILON) {
        old = new;
        new = 0.5 * (old + (x / old));
    }

    return new;
}

double Sin(double x) {
    if (x > 2 * M_PI) {
        while (x > 2 * M_PI) {
            x -= 2 * M_PI;
        }
    }
    if (x < 0) {
        while (x < 0) {
            x += 2 * M_PI;
        }
    }

    double old = 0.0;
    double new = x;
    int counter = 0;
    double exp = x;
    double fact = 1.0;

    while (Abs(old - new) > EPSILON) {
        old = new;
        exp = exp * x * x;
        fact = fact * (counter * 2 + 2) * (counter * 2 + 3);
        if (counter % 2 == 0) {
            new = old - (exp / fact);
        }
        if (counter % 2 == 1) {
            new = old + (exp / fact);
        }
        counter += 1;
    }
    return new;
}

double Cos(double x) {
    if (x > 2 * M_PI) {
        while (x > 2 * M_PI) {
            x -= 2 * M_PI;
        }
    }
    if (x < 0) {
        while (x < 0) {
            x += 2 * M_PI;
        }
    }
    double old = 0.0;
    double new = 1.0;
    int counter = 0;
    double exp = 1;
    double fact = 1.0;

    while (Abs(old - new) > EPSILON) {
        old = new;
        exp = exp * x * x;
        fact = fact * (counter * 2 + 1) * (counter * 2 + 2);
        if (counter % 2 == 0) {
            new = old - (exp / fact);
        }
        if (counter % 2 == 1) {
            new = old + (exp / fact);
        }
        counter += 1;
    }
    return new;
}

double Tan(double x) {
    double res;
    res = Sin(x) / Cos(x);
    return res;
}
