/**
 * @file function.h
 * @brief The implementation of the function and the derivative of the function.
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

#define MAX 1000000

/**
 * @brief The function.
 */
class function: public ScalarFunction {
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

/**
 * @brief The derivation of the function
 */
class functiond: public ScalarFunction {
public:
	/**
	 * @brief operator() Redefine the operator()
	 *
	 * @param x The variable of f' 
	 *
	 * @return f'(x)
	 */
	double operator()(double x) const;
};
