cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER "/usr/bin/g++" CACHE STRING "g++ compiler" FORCE)
set(CMAKE_C_COMPILER "/usr/bin/gcc" CACHE STRING "gcc compiler" FORCE)
set(CMAKE_C_FLAG "${CMAKE_C_FLAGS} -g -O0 -fmax-errors=5 -Wfatal-erros")
set(CMAKE_CXX_FLAG "${CMAKE_C_FLAGS} -g -O0 -fmax-errors=5 -Wfatal-erros -std=c++17")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(OPTICS_LIB LANGUAGES C CXX)

# find packages
find_package(Eigen3 REQUIRED)

# add library for optics
file(GLOB LIB_SOURCES src/*.cpp)
add_library(optics STATIC ${LIB_SOURCES})
target_include_directories(optics PRIVATE
        include_private
    )
target_include_directories(optics PUBLIC
        ${EIGEN3_INCLUDE_DIR}
        include
        external/unit/include
    )

# add test executables
file(GLOB TEST_SOURCES testsuite/*.cpp)
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_include_directories(${TEST_NAME} PRIVATE include)
    target_link_libraries(${TEST_NAME} optics)
endforeach()
