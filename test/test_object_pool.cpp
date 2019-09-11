// Test cases for the binary search tree module.
// Copyright 2019 Christian Kauten
//

#include "catch.hpp"
#include "object_pool.hpp"

//
// MARK: ObjectPointerPool::ObjectPointerPool
//

TEST_CASE("initialize ObjectPointerPool with default constructor") {
    REQUIRE_NOTHROW(new POOL::ObjectPointerPool<double>);
}


//
// MARK: ObjectPointerPool::get, ObjectPointerPool::put
//

TEST_CASE("operate an ObjectPointerPool of doubles") {
    auto pool = POOL::ObjectPointerPool<double>();
    double* number = pool.get();
    REQUIRE(*number == 0);
    *number = 5;
    pool.put(number);
    REQUIRE(*pool.get() == 5);
}


//
// MARK: ObjectManagedPool::ObjectManagedPool
//

TEST_CASE("initialize ObjectManagedPool with default constructor") {
    REQUIRE_NOTHROW(new POOL::ObjectManagedPool<double>);
}


//
// MARK: ObjectManagedPool::get, ObjectManagedPool::put
//

TEST_CASE("operate an ObjectManagedPool of doubles") {
    auto pool = POOL::ObjectManagedPool<double>();
    double* number = pool.get();
    REQUIRE(*number == 0);
    *number = 5;
    pool.put(number);
    REQUIRE(*pool.get() == 5);
}
