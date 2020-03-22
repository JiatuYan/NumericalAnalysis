/**
 * @file function2.h
 * @brief The implementation of function 2
 * @author XDDD 
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

/**
 * @brief The function 2
 */
class function2: public ScalarFunction {
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

