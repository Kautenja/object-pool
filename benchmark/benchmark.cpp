// Test cases for the object_pool module.
// Copyright Christian Kauten 2019
//

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <random>
#include <vector>
#include "catch.hpp"
#include "object_pool.hpp"

//
// MARK: ObjectPointerPool stack
//

TEST_CASE("POOL::ObjectPointerPool get") {
    auto pool = POOL::ObjectPointerPool<double>();
    BENCHMARK("get") {
        pool.get();
    };
}

TEST_CASE("POOL::ObjectPointerPool put") {
    auto pool = POOL::ObjectPointerPool<double>();
    auto generator = std::default_random_engine();
    auto bool_dist = std::uniform_int_distribution<int>(0, 1);
    std::vector<double*> used;
    BENCHMARK("put") {
        if (used.empty() || bool_dist(generator)) {
            used.push_back(pool.get());
        } else {
            std::size_t index =
                std::uniform_int_distribution<int>(0, used.size()-1)(generator);
            pool.put(used.at(index));
            used.erase(used.begin() + index);
        }
    };
}

//
// MARK: ObjectPointerPool heap
//

TEST_CASE("POOL::ObjectPointerPool* get") {
    auto pool = new POOL::ObjectPointerPool<double>();
    BENCHMARK("get") {
        pool->get();
    };
}

TEST_CASE("POOL::ObjectPointerPool* put") {
    auto pool = new POOL::ObjectPointerPool<double>();
    auto generator = std::default_random_engine();
    auto bool_dist = std::uniform_int_distribution<int>(0, 1);
    std::vector<double*> used;
    BENCHMARK("put") {
        if (used.empty() || bool_dist(generator)) {
            used.push_back(pool->get());
        } else {
            std::size_t index =
                std::uniform_int_distribution<int>(0, used.size()-1)(generator);
            pool->put(used.at(index));
            used.erase(used.begin() + index);
        }
    };
}

//
// MARK: ObjectPool stack
//

TEST_CASE("POOL::ObjectPool get") {
    auto pool = POOL::ObjectPool<double>();
    BENCHMARK("get") {
        pool.get();
    };
}

TEST_CASE("POOL::ObjectPool put") {
    auto pool = POOL::ObjectPool<double>();
    auto generator = std::default_random_engine();
    auto bool_dist = std::uniform_int_distribution<int>(0, 1);
    std::vector<double*> used;
    BENCHMARK("put") {
        if (used.empty() || bool_dist(generator)) {
            used.push_back(pool.get());
        } else {
            std::size_t index =
                std::uniform_int_distribution<int>(0, used.size()-1)(generator);
            pool.put(used.at(index));
            used.erase(used.begin() + index);
        }
    };
}

//
// MARK: ObjectPool heap
//

TEST_CASE("POOL::ObjectPool* get") {
    auto pool = new POOL::ObjectPool<double>();
    BENCHMARK("get") {
        pool->get();
    };
}

TEST_CASE("POOL::ObjectPool* put") {
    auto pool = new POOL::ObjectPool<double>();
    auto generator = std::default_random_engine();
    auto bool_dist = std::uniform_int_distribution<int>(0, 1);
    std::vector<double*> used;
    BENCHMARK("put") {
        if (used.empty() || bool_dist(generator)) {
            used.push_back(pool->get());
        } else {
            std::size_t index =
                std::uniform_int_distribution<int>(0, used.size()-1)(generator);
            pool->put(used.at(index));
            used.erase(used.begin() + index);
        }
    };
}
