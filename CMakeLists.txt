cmake_minimum_required(VERSION 3.5)
project(xtest)



add_definitions(-DXTENSOR_ENABLE_XSIMD)
add_definitions(-DXTENSOR_USE_XSIMD)
add_compile_options( -ffast-math -mtune=generic)

set(XTENSOR_USE_TBB 0)
set(XTENSOR_USE_OPENMP 0)
set(XTENSOR_USE_XSIMD 1)

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

message(STATUS "xtensor found at: ${xtensor_DIR}")
message(STATUS "xsimd found at: ${xsimd_DIR}")


add_executable(xtest xtest.cpp)

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

target_link_libraries(xtest xtensor xtensor::optimize xtensor::use_xsimd)