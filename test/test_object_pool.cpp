// Test cases for the binary search tree module.
// Copyright 2019 Christian Kauten
//

#include "catch.hpp"
#include "object_pool.hpp"

//
// MARK: constructor
//

TEST_CASE("initialize object pool with default constructor") {
    REQUIRE_NOTHROW(new OBJP::ObjectPool<double>);
}
