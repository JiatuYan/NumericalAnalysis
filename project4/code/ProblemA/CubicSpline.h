/**
 * @file CubicSpline.h
 * @brief Calculate the function's natural cubic spline
 * @author XDDD
 * @version 
 * @date 2020-04-12
 */
#include "ScalarFunction.h"

#ifndef __PAISLEYPARK__CUBICSPLINE__
#define __PAISLEYPARK__CUBICSPLINE__

class CubicSpline{
public:
	/**
	 * @brief Set the __A
	 *
	 * @param _A
	 *
	 * @return 0
	 */
	int setA(std::vector<double> _A);
	/**
	 * @brief Set the __M
	 *
	 * @param B
	 *
	 * @return 0
	 */
	int setM(double *B);
	/**
	 * @brief Set the knots
	 *
	 * @param f The function
	 * @param _A The knots
	 *
	 * @return 0
	 */
	int set(const ScalarFunction& f, std::vector<double> _A);
	/**
	 * @brief Calculate the natural cubic spline
	 *
	 * @param f The function
	 * @param x
	 *
	 * @return The value on x
	 */
	double interpolate(const ScalarFunction& f, double x);
	/**
	 * @brief Find the knot with the max max-norm of error.
	 *
	 * @param f The function
	 *
	 * @return 
	 */
	double Max(const ScalarFunction& f);

private:
	int __N;
	std::vector<double> __M;
	std::vector<double> __A;
};

#else
//Do nothing
#endif
