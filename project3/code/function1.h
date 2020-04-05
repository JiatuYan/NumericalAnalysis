/**
 * @file function1.h
 * @brief The implementation of function1
 * @author XDDD 
 * @version 
 * @date 2020-03-29
 */

#include "ScalarFunction.h"

/**
 * @brief Function 1
 */
class function1 : public ScalarFunction {
public:
	/**
	 * @brief operator() Redefine the operator()
	 *
	 * @param x The variable of f
	 *
	 * @return f(x)
	 */
	double operator()(double x) const;
};
