#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "core/Function.h"

#include "algorithms/RootFinding.h"
#include "algorithms/RootFindingMultidim.h"
#endif

using namespace std;
using namespace NRS;

void Docs_Demo_Root_finding()
{
	std::cout << endl;
	std::cout << "***********************************************************************" << endl;
	std::cout << "****                       ROOT FINDING                            ****" << endl;
	std::cout << "***********************************************************************" << endl;

	RealFunction f([](Real x) { return x * x - 2; });
	double a = 0.0;
	double b = 2.0;
	bool isBracketed = RootFinding::zbrac(f, a, b);
}