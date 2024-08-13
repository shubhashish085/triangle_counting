cmake_minimum_required(VERSION 2.8)
project(DistributedTriangleCounting)

include_directories(
        ${PROJECT_SOURCE_DIR}/
)

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -std=c++11  -O3 -g -Wall -march=native -pthread")

set(TRIANGLE_COUNT_FILE_LIST
        commandparser.h
        commandparser.cpp
        matchingcommand.h
        matchingcommand.cpp
        backtracking.cpp
        backtracking.h
        graph.cpp
        graph.h
        utilities.cpp
        utilities.h
        types.h
        util.h
        wtime.h
        TriangleEnumeration.h
        TriangleEnumeration.cpp
        StudyPerformance.cpp)


add_executable(DistributedTriangleCounting.out ${TRIANGLE_COUNT_FILE_LIST})

# MPI
find_package(MPI REQUIRED)
target_link_libraries(DistributedTriangleCounting.out PUBLIC MPI::MPI_CXX)

