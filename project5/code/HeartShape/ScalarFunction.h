/**
 * @file ScalarFunction.h
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-04-12
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <lapacke.h>

#ifndef __PAISLEYPARK__SCALARFUNCTION__
#define __PAISLEYPARK__SCALARFUNCTION__

class ScalarFunction {
public:
        /**
         * @brief Redefine the operator() for the function. Here is a virtual function.
         *
         * @param x The variable of f. 
         *
         * @return f(x)
         */
        virtual double operator()(double x) const = 0;
};

#else
//Do nothing
#endif

