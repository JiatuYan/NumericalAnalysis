/**
 * @file function3.h
 * @brief The implementation of function 3
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

/**
 * @brief The function 3
 */
class function3: public ScalarFunction {
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

