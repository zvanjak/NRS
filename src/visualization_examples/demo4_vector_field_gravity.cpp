#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "core/Function.h"

#include "core/Fields.h"
#endif


using namespace NRS;

void Demo4_vector_field_gravity()
{

// konstruirati multibod konfiguraciju on spot

    // GravityMultibodyConfigCart config;
    // config.AddBody(100, Vector3Cartesian{-100.0, 0.0, 0.0});
    // config.AddBody(200, Vector3Cartesian{100.0, 0.0, 0.0});
    // config.AddBody(100, Vector3Cartesian{0.0, 0.0, 100.0});

    // MultibodyGravityForceFieldCart gravity_force_field(20.0, config);
}

