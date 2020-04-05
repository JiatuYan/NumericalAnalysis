/**
 * @file NewtonFormula.h
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-03-29
 */
#include "ScalarFunction.h"

#ifndef __PAISLEYPARK__NEWTONFORMULA__
#define __PAISLEYPARK__NEWTONFORMULA__

class NewtonFormula{
public:
	int set(const ScalarFunction& _f, std::vector<double> _X);
	double pn(std::vector<double> _A, double _x);
private:
	std::vector<double> __B;
	int __flag = 0;
};

#else
//Do nothing
#endif

