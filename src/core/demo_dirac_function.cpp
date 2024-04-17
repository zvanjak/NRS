#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "core/DiracDeltaFunction.h"
#endif

using namespace NRS;

// TODO - HIGH, EMPTY!!! - dovršiti demo
void Demo_Dirac_function()
{
    std::cout << std::endl;
    std::cout << "***********************************************************************" << std::endl;
    std::cout << "****                       DIRAC FUNCTION                          ****" << std::endl;
    std::cout << "***********************************************************************" << std::endl;

    DiracExp dirac1(10);

    double v = 3.0 * dirac1(0.0);
}