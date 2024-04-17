#if !defined NRS_LINEAR_ALG_EQ_SYSTEMS_SINGULAR_DEFS_H
#define NRS_LINEAR_ALG_EQ_SYSTEMS_SINGULAR_DEFS_H

#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "base/Matrix.h"
#include "base/MatrixSym.h"
#endif

namespace NRS::TestBeds
{
	const static inline NRS::Matrix<Real>     mat_5x5_singular1{ 5, 5, { 1.4, 2.1, 2.1, 7.4, 9.6,
																																1.6, 1.5, 1.1, 0.7, 5.0,
																																1.6, 1.5, 1.1, 0.7, 5.0,
																																4.6, 8.2, 8.4, 0.4, 8.0,
																																2.6, 2.9, 0.1, 9.6, 7.7 } };

	const static inline NRS::Matrix<Real>     mat_5x5_almost_singular1{ 5, 5, { 1.4, 2.1, 2.1, 7.4, 9.6,
																																			 1.6, 1.5, 1.1, 0.7, 5.0,
																																			 1.6, 1.5, 1.1, 0.7, 5.000001,
																																			 4.6, 8.2, 8.4, 0.4, 8.0,
																																			 2.6, 2.9, 0.1, 9.6, 7.7 } };

}

#endif 