#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "base/Algebra.h"

#endif

using namespace NRS;

// TODO - demo of Z6 group, with its multiplication table
// TODO - demo of permutation group and its operations
// TODO - demo linear operators
void Demo_GroupZ()
{
    GroupZ groupZ;
}

void Demo_Algebra()
{
    std::cout << std::endl;
    std::cout << "***********************************************************************" << std::endl;
    std::cout << "****                          ALGEBRA                              ****" << std::endl;
    std::cout << "***********************************************************************" << std::endl;

    Demo_GroupZ();
}