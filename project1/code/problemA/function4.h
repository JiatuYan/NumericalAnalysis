/**
 * @file function4.h
 * @brief The implementation of function 4
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

#define MAX 1000000     //In case the function is undefined on some points.

/**
 * @brief The function4
 */
class function4: public ScalarFunction {
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

