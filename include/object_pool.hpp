// An object pool structure.
// Copyright 2019 Christian Kauten
//

#ifndef OBJECT_POOL_HPP
#define OBJECT_POOL_HPP

#include <unordered_set>

namespace OBJP {

template<typename T>
class ObjectPool {
 private:
    /// the available objects in the pool
    std::unordered_set<T> available;
    /// the used objects in the pool
    std::unordered_set<T> used;

 public:
    /// Create a new object pool.
    ObjectPool() : available(), used() { }
};

}  // namespace OBJP

#endif  // OBJECT_POOL_HPP
