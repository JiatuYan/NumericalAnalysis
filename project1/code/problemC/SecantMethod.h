/**
 * @file SecantMethod.h
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

#ifndef __PAISLEYPARK__SECANTMETHOD__
#define __PAISLEYPARK__SECANTMETHOD__

class SecantMethod {
public:
	/**
	 * @brief solve Find the root of function _f by Secant Method.
	 *				_f, _x0, _x1 are the preconditions.
	 *				The iteration will stop if the postcondition
	 *				|_f(xn)| < __fe or |(xn) - (xm-1)| < __e or iterating times > __T are reached.
	 *
	 * @param _f	The function we calculate.
	 * @param _x0	The beginning point of the iteration.
	 * @param _x1	The beginning point of the iteration.
	 *
	 * @return The root of function _f 
	 */
	double solve(ScalarFunction& _f, double _x0, double _x1);
	/**
	 * @brief set Set the postconditions of the Secant Method.
	 *
	 * @param _e	The postcondition of |(xn)-(xn-1)|.
	 * @param _fe	The postcondition of |f(xn)|.
	 * @param _t	The maximum iterating times.
	 *
	 * @return 0
	 */
	int set(double _e, double _fe, int _t);
	/**
	 * @brief SecantMethod Default construct function. 
	 */
	SecantMethod(){};
	/**
	 * @brief SecantMethod Set the postconditions when construct a SecantMethod.
	 *
	 * @param _e	The postcondition of |(xn)-x(n-1)|.
	 * @param _fe	The postcondition of |f(xn)|.
	 * @param _t	The maximum iterating times.
	 */
	SecantMethod(double _e, double _fe, int _t);
	/**
	 * @brief num Return the iterating times of one SecantMethod calculation.
	 *
	 * @return __num
	 */
	int num();
private:
	/**
	 * @brief The postcondition of |(xn)-(xn-1)|, default 0.00001.
	 */
	double __error = 0.00001;
	/**
	 * @brief The postcondition of |f(xn)|, default 0.00001.
	 */
	double __ferror = 0.00001;
	/**
	 * @brief The maximum iterating times.
	 */
	int __T = 100;
	/**
	 * @brief The iterating times of one Secant Method, will be reset to 0 at the beginning of solve function.
	 */
	int __num = 0;
}; 

#else

#endif
