#include <gtest/gtest.h>
#include <stdexcept>
#include <pficommon/lang/scoped_ptr.h>

#include "regression_factory.hpp"
#include "regression.hpp"
#include "../storage/local_storage.hpp"
#include "../common/exception.hpp"

namespace jubatus {
namespace regression {

TEST(regression_factory, trivial) {
  regression::regression_factory f;
  storage::local_storage s;
  pfi::text::json::json param;
  pfi::lang::scoped_ptr<regression::regression_base> r(f.create_regression("PA", param, &s));
  EXPECT_EQ(typeid(*r), typeid(regression::PA&));
}

TEST(regression_factory, unknown) {
  regression::regression_factory f;
  storage::local_storage s;
  pfi::text::json::json param;
  ASSERT_THROW(f.create_regression("unknown_regression", param, &s), unsupported_method);
}

}
}
