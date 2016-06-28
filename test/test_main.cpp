//  (C) Copyright Kirill Lykov 2012.
//
// Distributed under the FreeBSD Software License (See accompanying file license.txt)

#include <vector>
#include <algorithm>
#include <assert.h>
#include <iostream>

#include <gtest/gtest.h>

#include <math_vector.h>

namespace
{
  using namespace ls;
  using namespace geometry_utils;

  double testFunction1(const MathVector3D& point) {
    double r = 0.5;
    double res = sqrt(pow(point.getX(), 2) + pow(point.getY(), 2) ) - r;
    return res;
  }

  double testFunction2(const MathVector3D& point) {
    double res = sin(point.getX()) + cos(point.getY()) - log(fabs(point.getZ())) / (point.getZ() + 1.0);
    return res;
  }
}

// to run all tests from one point
// corresponding cpp files must be excluded from build
// otherwise "duplicate symbol" linker error happens

#include "test_grid.cpp"

#ifdef USE_HDF5
#include "test_hdf5.cpp"
#endif

#ifdef USE_VTK
#include "test_vtk.cpp"
#endif

#ifdef USE_VDB
#include "test_vdb.cpp"
#endif

#include "test_geometry_utils.cpp"

#include "test_linear_interpolator.cpp"

#include "test_implicit_functions.cpp"

#include "test_grid_operations.cpp"

#include "test_grad.cpp"

#include "test_collision.cpp"

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
