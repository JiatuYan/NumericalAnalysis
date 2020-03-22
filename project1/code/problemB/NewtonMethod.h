/**
 * @file NewtonMethod.h
 * @brief The class that use the Newton's Method to find the root. 
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

#ifndef __PAISLEYPARK__NEWTONMETHOD__
#define __PAISLEYPARK__NEWTONMETHOD__

class NewtonMethod {
public:
	/**
	 * @brief solve Find the root of funtion _f by Newton Method.
	 *				_f,_fd,_x0 are the preconditions.
	 *				The iteration will stop if the postcondition
	 *				|_f(xn)| < __e or iterating times > __T are reached.
	 *
	 * @param _f	The function we calculate.
	 * @param _fd	The derivative of _f
	 * @param _x0	The beginning point of the iteration.
	 *
	 * @return	The root of function _f near _x0
	 */
	double solve(const ScalarFunction& _f, const ScalarFunction& _fd, double _x0);
	/**
	 * @brief set Set the postconditions of the Newton Method.
	 *
	 * @param _e	The postcondition of |f(xn)|.
	 * @param _t	The maximum iterating times.
	 *
	 * @return 0
	 */
	int set(double _e, int _t);
	/**
	 * @brief num Return the iterating times of one Newton Method calculation.
	 *
	 * @return __num
	 */
	int num();
	/**
	 * @brief NewtonMethod Default construct function.
	 */
	NewtonMethod(){};
	/**
	 * @brief NewtonMethod Set the postconditions whe construct a NewtonMethod.
	 *
	 * @param _e	The postcondition of |f(xn)|.
	 * @param _t	The maximum iterating times.
	 */
	NewtonMethod(double _e, int _t);
private:
	/**
	 * @brief The postcondition of |f(xn)|, default 0.00001.
	 */
	double __error = 0.00001;
	/**
	 * @brief The maximum iterating times, default 100.
	 */
	double __T = 100;
	/**
	 * @brief The iterating times of one Newton Method, will be reset to 0 at the beginning of solve function.
	 */
	int __num = 0;
};

#else
//Do nothing.
#endif
