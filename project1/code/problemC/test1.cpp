#include "function1.h"
#include "SecantMethod.h"

int main(int argc, char *argv[])
{
	function1 f;
	SecantMethod S;
	std::cout << S.solve(f, 0, M_PI_2);
	return 0;
}
