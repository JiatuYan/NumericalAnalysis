#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#ifndef __PAISLEYPARK__SCALARFUNCTION__
#define __PAISLEYPARK__SCALARFUNCTION__

class ScalarFunction {
public:
	/**
	 * @brief operator()  Redefine the operator() for the function. Here is a virtual function.
	 *
	 * @param x	The variable of f.
	 *
	 * @return f(x)
	 */
	virtual double operator()(double x) const = 0;
};

#else

#endif
