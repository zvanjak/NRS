#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "base/VectorN.h"
#include "base/VectorSpace.h"

#endif

using namespace NRS;

void Demo_VectorSpaces()
{
    std::cout << "***********************************************************************" << std::endl;
    std::cout << "****                     VECTOR SPACES                             ****" << std::endl;
    std::cout << "***********************************************************************" << std::endl;
    
    VectorSpace<Real, VectorN<Real,3>> vecSpace;

    RealVectorSpaceN<3> s1;
    ComplexVectorSpaceN<3> vecSpaceComplex3;

    // how to define element of this vector space?
    VectorN<Real, 3> vec1{1.3, -2.3, 0.4};
    RealVectorSpaceN<3>::vector_type vec11{1.3, -2.3, 0.4};
    Vec3D vec2{-0.5, 1.7, 2.4};
    Real scal1 = 2.5;

    auto res1 = s1.add(vec1, vec2);
    auto res2 = s1.mul(scal1, vec1);

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;

}