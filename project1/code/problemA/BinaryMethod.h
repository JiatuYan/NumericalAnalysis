/**
 * @file BinaryMethod.h
 * @brief The class that use the Binary Method to find the root.
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "ScalarFunction.h"

#ifndef __PAISLEYPARK__BINARYMETHOD__
#define __PAISLEYPARK__BINARYMETHOD___

class BinaryMethod {
public:
	/**
	 * @brief solve Find the root of function f by Binary Method.
	 *				f,a,b are the preconditions.
	 *				The iteration will stop if 
	 *				the postcondition |(xn)-(xn-1)| < __e, or |f(xn)| < __fe, or iterating times > __T are reached.
	 *
	 * @param f	The function we calculate.
	 * @param a The first number of the primitive interval.
	 * @param b The second number of the primitive interval.
	 *					
	 * @return The root of the function f in [a,b].
	 */
	double solve(const ScalarFunction& f, double a, double b);
	/**
	 * @brief set_error Set the postconditions of the Binary Method.  
	 *
	 * @param e	The postcondition of |(xn)-(xn-1)|
	 * @param fe The postcondition of |f(xn)|
	 * @param t	The maximum iterating times.
	 *
	 * @return 0
	 */
	int set_error(double e, double fe, int t);
	/**
	 * @brief BinaryMethod default construct function.
	 */
	BinaryMethod(){};
	/**
	 * @brief BinaryMethod Set the postcondition when construt a BinaryMethod.
	 *
	 * @param e The postcondition of |(xn)-(xn-1)|
	 * @param fe The postcondition of |f(xn)|
	 * @param t The maximum iterating times.
	 */
	BinaryMethod(double e, double fe, int t);
	/**
	 * @brief num Return the iteration times of one Binary Method calculation.
	 *
	 * @return __num
	 */
	int num();
private:
	/**
	 * @brief The postcondition of |(xn)-(xn-1)|, defaut 0.00001
	 */
	double __error = 0.00001;
	/**
	 * @brief The postcondition of |f(xn)|, default 0.00001
	 */
	double __ferror = 0.00001;
	/**
	 * @brief The maximum iterating times, default 100
	 */
	int __T = 100;
	/**
	 * @brief The iterating times of one Binary Method, will be reset to 0 at the beginning of solve function. 
	 */
	int __num = 0;
};

int sgn(double a);

#else
//Do nothing
#endif
