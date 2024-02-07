# Cadex Curves Task

This repository contains a completed test task for the position of a C++ developer at Cadex.

## Task Description

Design a small program in C++ that implements support for a hierarchy of 3D curves with the following requirements:
1. Support a few types of 3D geometric curves – circles, ellipses, and 3D helixes. Each curve should be able to return a 3D point and a first derivative (3D vector) per parameter t along the curve.
2. Populate a container (e.g. vector or list) of objects of these types created in a random manner with random parameters.
3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populate a second container that contains only circles from the first container, ensuring the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container.
7. (Optional) Split implementation into a library of curves (.dll or .so) and an executable which uses the API of this library.
8. (Optional) Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel TBB library).

## Implementation Details

- The task was implemented as a CMake project.
- Smart pointers was used for memory management instead of new/delete.
- For parallel computing, the OpenMP extension for gcc was used.
- The GTest framework was used for unit testing.

## Building

### Linux

```bash
git clone https://github.com/ilia-barynkin/cadex-curves-task.git
cd cadex-curves-task
mkdir build
cd build
cmake ..
cmake --build .
ctest --rerun-failed --output-on-failure
```

## Windows

- To create Visual Studio sulution, you can use CMake gui.


## TODO

Add data visualization to the python directory for greater clarity.