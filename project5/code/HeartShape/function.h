/**
 * @file function.h
 * @brief The implementation of function
 * @author XDDD 
 * @version 
 * @date 2020-04-12
 */

#include "ScalarFunction.h"

/**
 * @brief Function 
 */
class function : public ScalarFunction {
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
