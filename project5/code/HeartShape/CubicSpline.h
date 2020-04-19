/**
 * @file CubicSpline.h
 * @brief Calculate the function's complete cubic spline
 * @author XDDD
 * @version 
 * @date 2020-04-19
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
	int setM(double x1, double x2, double *B);
	/**
	 * @brief Set the knots
	 *
	 * @param f The function
	 * @param _A The knots
	 *
	 * @return 0
	 */
	int set(const ScalarFunction& f, double _x1, double _x2, std::vector<double> _A);
	/**
	 * @brief Calculate the complete cubic spline
	 *
	 * @param f The function
	 * @param x
	 *
	 * @return The value on x
	 */
	double interpolate(const ScalarFunction& f, double x);

private:
	int __N;
	std::vector<double> __M;
	std::vector<double> __A;
};

#else
//Do nothing
#endif
