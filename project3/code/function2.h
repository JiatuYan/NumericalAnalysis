/**
 * @file function2.h
 * @brief The implementation of function2
 * @author XDDD 
 * @version 
 * @date 2020-04-04
 */

#include "ScalarFunction.h"

/**
 * @brief Function 2
 */
class function2 : public ScalarFunction {
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
