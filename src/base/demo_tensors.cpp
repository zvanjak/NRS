#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "base/Tensor.h"

#include "core/CoordTransf.h"
#include "base/Geometry3D.h"
#include "core/MetricTensor.h"
#endif

using namespace NRS;

// TODO - BIG!!! - Demo tensors transformations, etc.
void Demo_Tensors()
{
    std::cout << std::endl;
    std::cout << "***********************************************************************" << std::endl;
    std::cout << "****                           TENSORS                             ****" << std::endl;
    std::cout << "***********************************************************************" << std::endl;
    
    Tensor2<3> t2(2,0);
    Tensor3<3> t3(1,2);
    Tensor4<3> t4(3,1);

}