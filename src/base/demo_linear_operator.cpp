// TODO - BIG, EMPTY!!! - Demo functionals
#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"    

#include "base/LinearOperator.h"
#endif

using namespace NRS;

// TODO - BIG!
void Demo_LinearOperators()
{
    std::cout << std::endl;
    std::cout << "***********************************************************************" << std::endl;
    std::cout << "****                     LINEAR OPERATORS                          ****" << std::endl;
    std::cout << "***********************************************************************" << std::endl;

    RealLinearOperatorN<3> lin_oper;
}
