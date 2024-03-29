# Object Pool

[![build-status][]][build-server]

[build-status]: https://travis-ci.com/Kautenja/object-pool.svg
[build-server]: https://travis-ci.com/Kautenja/object-pool

## Usage

Simply add [include/object_pool.hpp](include/object_pool.hpp) to your C++
project either by copying directly or using git submodules.

## Classes

There are two working implementations of the object pool, (1) the object
managed pool that stores objects on the stack using a vector, and (2) the
object pointer pool that stores objects dynamically in memory.
[benchmark/benchmark.cpp](benchmark/benchmark.cpp) contains code to benchmark
the objects (using doubles as the template object type).

| Class               | Object location   | `get` & `put` avg. time |
|:--------------------|:------------------|:------------------------|
| `ObjectManagedPool` | Stack             | 194_ns_ (267_ns_ std.)
| `ObjectPointerPool` | Heap              | 47_ns_ (2_ns_ std.)

The `ObjectPool` class defaults to the faster (and simpler) `ObjectPointerPool`
class.

## Testing

To compile and run the [test suite](test):

```shell
scons test
```

## Benchmarking

To run benchmarks:

```shell
scons benchmark/benchmark.cpp
```
