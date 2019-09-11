// An object pool structure.
// Copyright 2019 Christian Kauten
//

#ifndef OBJECT_POOL_HPP
#define OBJECT_POOL_HPP

#include <list>

namespace POOL {

/// An object pool for arbitrary typed objects
template<typename T>
class ObjectPointerPool {
 private:
    /// the free objects in the pool
    std::list<T*> free;

 public:
    /// initialize a new object pool.
    ObjectPointerPool() : free() { }

    /// Return an object from the pool.
    T* get() {
        if (free.empty())  // no objects are free
            return new T();
        // get the last object in the list
        auto obj = free.back();
        free.pop_back();
        return obj;
    }

    /// Mark the given object for reuse in the future.
    inline void put(T* obj) { free.emplace_back(obj); }
};


/// An object pool for arbitrary typed objects
template<typename T>
class ObjectManagedPool {
 private:
    /// the objects in the pool
    std::list<T> objs;
    /// the free objects in the pool
    std::list<T*> free;
    /// the used objects in the pool
    std::list<T*> used;

 public:
    /// initialize a new object pool.
    ObjectManagedPool() : free(), used() { }

    /// Return an object from the pool.
    T* get() {
        if (free.empty()) {  // no objects are free
            // create a new object in the list of objects
            objs.push_back(T());
            // push the objects pointer onto the list of used objects
            used.push_back(&objs.back());
        } else {  // at least one object is free
            // push the last free object pointer onto the list of used objects
            used.push_back(free.back());
            // remove the last free object from the free list
            free.pop_back();
        }
        // return the pointer to the object to use
        return used.back();
    }

    /// Mark the given object for reuse in the future.
    inline void put(T* obj) {
        // add the item to the list of free items
        used.remove(obj);
        // remove the item from the list of used items
        free.push_back(obj);
    }
};

}  // namespace POOL

#endif  // OBJECT_POOL_HPP
